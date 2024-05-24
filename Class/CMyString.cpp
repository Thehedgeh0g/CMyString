//
// Created by flipd on 08.05.2024.
//

#include "CMyString.h"
#include "CMyStringIterator.h"
#include <algorithm>

CMyString::CMyString() : m_string(new char[1]), m_size(0)
{
    m_string[0] = SYMBOL_END_OF_STRING;
}

CMyString::CMyString(const char *pString, size_t length)
{
    if (pString == nullptr)
    {
        length = 0;
    }

    m_string = new char[length + 1];
    m_size = length;
    memcpy(m_string, pString, length);
    m_string[m_size] = SYMBOL_END_OF_STRING;
}

CMyString::CMyString(const char *pString) : CMyString(pString, std::strlen(pString))
{
}

CMyString::CMyString(const CMyString& other) : CMyString(other.GetStringData(), other.GetLength())
{
}

CMyString::CMyString(CMyString&& other) noexcept: m_string(other.m_string), m_size(other.m_size)
{
    other.m_string = nullptr;
    other.m_size = 0;
}

CMyString::CMyString(const std::string& stlString) : CMyString(stlString.c_str(), stlString.size())
{
}

CMyString::~CMyString()
{
    delete[] m_string;
}

size_t CMyString::GetLength() const
{
    return m_size;
}

const char *CMyString::GetStringData() const
{
    return m_string ? m_string : "";
}

CMyString CMyString::SubString(size_t start, size_t length) const
{
    if (start > m_size)
    {
        throw std::invalid_argument("Invalid start position");
    }

    if (m_size - start < length)
    {
        length = m_size - start;
    }

    return {&m_string[start], length};
}

void CMyString::Clear()
{
    delete[] m_string;
    m_size = 0;
    m_string = new char[1];
    m_string[0] = SYMBOL_END_OF_STRING;
}

CMyString& CMyString::operator=(const CMyString& other)
{
    if (std::addressof(other) != this)
    {
        CMyString tmpCopy(other);
        std::swap(m_string, tmpCopy.m_string);
        std::swap(m_size, tmpCopy.m_size);
    }

    return *this;
}

CMyString& CMyString::operator+=(const CMyString& other)
{
    if (std::addressof(other) != this)
    {
        char newString[m_size + other.m_size];
        strcpy(newString, m_string);
        strcat(newString, other.m_string);
        CMyString tmpCopy(newString);
        std::swap(m_string, tmpCopy.m_string);
        std::swap(m_size, tmpCopy.m_size);
    }
    return *this;
}


CMyString CMyString::operator+(const CMyString& other)
{
    if (std::addressof(other) != this)
    {
        char newString[m_size + other.m_size];
        strcpy(newString, m_string);
        strcat(newString, other.m_string);
        return {newString};
    }
    return *this;
}

const char& CMyString::operator[](size_t index) const
{
    if (index > m_size)
    {
        throw std::invalid_argument("Refer to a non-existent element");
    }

    return m_string[index];
}

char& CMyString::operator[](size_t index)
{
    if (index > m_size)
    {
        throw std::invalid_argument("Refer to a non-existent element");
    }

    return m_string[index];
}

bool CMyString::operator==(const CMyString& string) const
{
    return (
        (GetLength() == string.GetLength()) &&
        (std::memcmp
             (
                 GetStringData(),
                 string.GetStringData(),
                 GetLength()
             )
         == 0)
    );
}

bool CMyString::operator!=(const CMyString& string) const
{
    return !(*this == string);
}

bool CMyString::operator<(const CMyString& string) const
{
    size_t minSize = std::min(GetLength(), string.GetLength());
    return (
        (std::memcmp
             (
                 GetStringData(),
                 string.GetStringData(),
                 minSize
             )
         < 0)
    );
}

bool CMyString::operator<=(const CMyString& string) const
{
    return (*this < string) || (*this == string);
}

bool CMyString::operator>(const CMyString& string) const
{
    return !(*this < string);
}

bool CMyString::operator>=(const CMyString& string) const
{
    return (*this > string) || (*this == string);
}

std::ostream& operator<<(std::ostream& stream, const CMyString& string)
{
    stream << string.GetStringData();
    return stream;
}

std::istream& operator>>(std::istream& stream, CMyString& string)
{
    size_t stringDataSize = 1;
    size_t stringDataLength = 0;
    char* stringData = new char[stringDataSize];
    char ch;

    while (stream.get(ch) && ch != ' ' && ch != '\n')
    {
        stringData[stringDataLength] = ch;
        stringDataLength++;

        if (stringDataLength == stringDataSize)
        {
            try
            {
                char* newStringData = new char[stringDataSize * 2];
                memcpy(newStringData, stringData, stringDataSize);
                delete[] stringData;
                stringData = newStringData;

                stringDataSize *= 2;
            }
            catch (const std::exception&)
            {
                delete[] stringData;
                throw;
            }
        }
    }
    stringData[stringDataLength] = SYMBOL_END_OF_STRING;

    delete[] string.m_string;
    string.m_size = stringDataLength;
    string.m_string = stringData;

    return stream;
}

CMyStringIterator CMyString::begin()
{
    return {m_string};
}

CMyStringIterator CMyString::end()
{
    return {m_string + m_size};
}

CMyStringIterator CMyString::rbegin()
{
    return {m_string + m_size, true};
}

CMyStringIterator CMyString::rend()
{
    return {m_string, true};
}

const CMyStringIterator CMyString::begin() const
{
    return CMyStringIterator(const_cast<char*>(m_string));
}

const CMyStringIterator CMyString::end() const
{
    return CMyStringIterator(const_cast<char*>(m_string) + m_size);
}
