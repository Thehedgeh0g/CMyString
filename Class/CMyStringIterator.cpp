//
// Created by flipd on 10.05.2024.
//

#include "CMyStringIterator.h"

CMyStringIterator::CMyStringIterator(char *ptr, bool isReversed) : m_ptr(ptr), m_isReversed(isReversed)
{
}

CMyStringIterator::CMyStringIterator(const CMyStringIterator& other) : m_ptr(other.m_ptr),
                                                                       m_isReversed(other.m_isReversed)
{
}

CMyStringIterator::CMyStringIterator(CMyStringIterator&& other) noexcept: m_ptr(other.m_ptr),
                                                                          m_isReversed(other.m_isReversed)
{
    other.m_ptr = nullptr;
}

CMyStringIterator::~CMyStringIterator()
{
}

CMyStringIterator& CMyStringIterator::operator=(const CMyStringIterator& other)
{
    m_ptr = other.m_ptr;
    return *this;
}

char& CMyStringIterator::operator*() const
{
    return *m_ptr;
}

bool CMyStringIterator::operator==(const CMyStringIterator& other) const
{
    return m_ptr == other.m_ptr;
}

bool CMyStringIterator::operator!=(const CMyStringIterator& other) const
{
    return !(*this == other);
}

bool CMyStringIterator::operator<(const CMyStringIterator& other) const
{
    return m_ptr < other.m_ptr;
}

bool CMyStringIterator::operator>(const CMyStringIterator& other) const
{
    return (*this != other) && !(*this < other);
}

bool CMyStringIterator::operator<=(const CMyStringIterator& other) const
{
    return (*this < other) || (*this == other);
}

bool CMyStringIterator::operator>=(const CMyStringIterator& other) const
{
    return (*this > other) || (*this == other);
}

CMyStringIterator& CMyStringIterator::operator++()
{
    if (m_isReversed)
    {
        --m_ptr;
    }
    else
    {
        ++m_ptr;
    }
    return *this;
}

CMyStringIterator CMyStringIterator::operator++(int)
{
    CMyStringIterator temp = *this;
    ++(*this);
    return temp;
}

CMyStringIterator& CMyStringIterator::operator--()
{
    if (m_isReversed)
    {
        ++m_ptr;
    }
    else
    {
        --m_ptr;
    }
    return *this;
}

CMyStringIterator CMyStringIterator::operator--(int)
{
    CMyStringIterator temp = *this;
    --(*this);
    return temp;
}

char& CMyStringIterator::operator[](size_t index) const
{
    return *(m_ptr + index);
}

CMyStringIterator CMyStringIterator::operator+(int num)
{
    *this = {m_ptr + num};
    return *this;
}

CMyStringIterator CMyStringIterator::operator-(int num)
{
    *this = {m_ptr - num};
    return *this;
}

CMyStringIterator operator+(int num, CMyStringIterator iter)
{
    return iter + num;
}

CMyStringIterator operator-(int num, CMyStringIterator iter)
{
    return iter - num;
}

CMyStringIterator CMyStringIterator::operator+=(int num)
{
    *this = {m_ptr + num};
    return *this;
}

CMyStringIterator CMyStringIterator::operator-=(int num)
{
    *this = {m_ptr - num};
    return *this;
}
