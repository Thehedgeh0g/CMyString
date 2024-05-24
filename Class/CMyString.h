//
// Created by flipd on 08.05.2024.
//

#ifndef CMYSTRING_CMYSTRING_H
#define CMYSTRING_CMYSTRING_H

#include <string>
#include <cstring>
#include <iostream>
#include "CMyStringIterator.h"

const char SYMBOL_END_OF_STRING = '\0';

class CMyString
{
public:
    CMyString();

    // конструктор, инициализирующий строку данными строки
    // с завершающим нулевым символом
    CMyString(const char *pString);

    // конструктор, инициализирующий строку данными из
    // символьного массива заданной длины
    CMyString(const char *pString, size_t length);

    // конструктор копирования
    CMyString(CMyString const& other);

    // перемещающий конструктор
    //  реализуется совместно с перемещающим оператором присваивания
    CMyString(CMyString&& other) noexcept;

    // конструктор, инициализирующий строку данными из
    // строки стандартной библиотеки C++
    CMyString(std::string const& stlString);

    // деструктор класса - освобождает память, занимаемую символами строки
    ~CMyString();

    // возвращает длину строки (без учета завершающего нулевого символа)
    size_t GetLength() const;

    // возвращает указатель на массив символов строки.
    // В конце массива обязательно должен быть завершающий нулевой символ
    // даже если строка пустая
    const char *GetStringData() const;

    // возвращает подстроку с заданной позиции длиной не больше length символов
    CMyString SubString(size_t start, size_t length = SIZE_MAX) const;

    // очистка строки (строка становится снова нулевой длины)
    void Clear();

    CMyString& operator=(CMyString const& other);

    CMyString& operator+=(CMyString const& other);

    CMyString operator+(CMyString const& other);

    const char& operator[](size_t index) const;

    char& operator[](size_t index);

    bool operator==(CMyString const& string) const;

    bool operator!=(const CMyString& string) const;

    bool operator<(CMyString const& string) const;

    bool operator<=(CMyString const& string) const;

    bool operator>(CMyString const& string) const;

    bool operator>=(CMyString const& string) const;

    friend std::ostream& operator<<(std::ostream& stream, const CMyString& string);

    friend std::istream& operator>>(std::istream& stream, CMyString& string);

    CMyStringIterator begin();

    CMyStringIterator end();

    const CMyStringIterator begin() const;

    const CMyStringIterator end() const;

    CMyStringIterator rbegin();

    CMyStringIterator rend();

private:
    char *m_string;
    size_t m_size;
};


#endif //CMYSTRING_CMYSTRING_H
