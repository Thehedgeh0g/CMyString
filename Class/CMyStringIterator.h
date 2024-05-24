//
// Created by flipd on 10.05.2024.
//

#ifndef CMYSTRING_CMYSTRINGITERATOR_H
#define CMYSTRING_CMYSTRINGITERATOR_H


#include <iterator>

class CMyStringIterator : public std::iterator<std::random_access_iterator_tag, char>
{
public:
    CMyStringIterator(char *ptr, bool isReversed = false);

    CMyStringIterator(const CMyStringIterator& other);

    CMyStringIterator(CMyStringIterator&& other) noexcept ;

    ~CMyStringIterator();

    CMyStringIterator& operator=(const CMyStringIterator& other);

    char& operator[](size_t index) const;

    char& operator*() const;

    bool operator==(const CMyStringIterator& other) const;

    CMyStringIterator operator+(int num);

    CMyStringIterator operator-(int num);

    CMyStringIterator operator+=(int num);

    CMyStringIterator operator-=(int num);

    friend CMyStringIterator operator+(int offset, CMyStringIterator iter);

    friend CMyStringIterator operator-(int offset, CMyStringIterator iter);

    bool operator!=(const CMyStringIterator& other) const;

    bool operator<(const CMyStringIterator& other) const;

    bool operator>(const CMyStringIterator& other) const;

    bool operator<=(const CMyStringIterator& other) const;

    bool operator>=(const CMyStringIterator& other) const;

    CMyStringIterator& operator++();

    CMyStringIterator operator++(int);

    CMyStringIterator& operator--();

    CMyStringIterator operator--(int);

private:
    char *m_ptr;
    bool m_isReversed;
};


#endif //CMYSTRING_CMYSTRINGITERATOR_H
