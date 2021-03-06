#pragma once
#include <iostream>
#include <cassert>

template <class T>
class linetor
{
public:
    typedef T * iterator;
    linetor()
        : m_length(0)
        , m_date(nullptr)
    {
    }
    linetor(int length)
        : m_length(length)
    {
        m_date = new T[length];
    }
    linetor(std::initializer_list<T> list)
    {
        m_length = list.size();
        m_date = new T[m_length];
        int i=0;
        for(auto& item : list)
        {
            m_date[i] = item;
            i++;
        }
    }
    linetor(const linetor &linetor1)
        : m_length(linetor1.m_length)
        , m_date(linetor1.m_date)
    {
    }

    ~linetor()
    {
        erase();
    }

    iterator begin();
    iterator end();

    //операция присваивания
   linetor& operator=(const linetor &line);

    bool operator< (const linetor<T> &lineRight);
    bool operator<= (const linetor<T> &lineRight);
    bool operator> (const linetor<T> &lineRight);
    bool operator>= (const linetor<T> &lineRight);
    bool operator== (const linetor<T> &lineRight);
    bool operator!= (const linetor<T> &lineRight);
    T& operator[](const int index);

    void push_back(const T symb);
    T& at(const int index);
    T& front(){ return m_date[0]; }
    T& back(){ return m_date[m_length]; }


    bool empty();

    int length()
    {
        return m_length;
    }

    void clear();
    void insert(const int index, const T& symb);
    void erase();
    void pop_back();;
    void swap(linetor& linetor2);
    //временная
    T* getDate() { return m_date; }

private:
    size_t m_length = 0;
    T * m_date = nullptr;

};

template<class T>
linetor<T>& linetor<T>::operator=(const linetor<T> & line)
{
    if(&line != this)
    {
        this->m_date = line.m_date;
        this->m_length = line.m_length;
    }
    return *this;
}

template<class T>
typename linetor<T>::iterator linetor<T>::begin()
{
    return m_date;
}

template<class T>
typename linetor<T>::iterator linetor<T>::end()
{
    return m_date + m_length;
}


template<class T>
bool linetor<T>::operator<(const linetor<T> &lineRight)
{
    return (this->m_length < lineRight.m_length);
}

template<class T>
bool linetor<T>::operator<=(const linetor<T> &lineRight)
{
    return (this->m_length <= lineRight.m_length);
}

template<class T>
bool linetor<T>::operator>(const linetor<T> &lineRight)
{
    return (this->m_length > lineRight.m_length);
}

template<class T>
bool linetor<T>::operator>=(const linetor<T> &lineRight)
{
    return (this->m_length >= lineRight.m_length);
}


template<class T>
bool linetor<T>::operator==(const linetor<T> &lineRight)
{
    if (this->m_length == lineRight.m_length)
    {
        for(int i = 0; i<this->m_length; i++)
        {
            if (this->m_date[i] != lineRight.m_date[i])
            {
                return false;
            }
        }
        return true;
    }else
        {
            return false;
        }

}

template<class T>
bool linetor<T>::operator!=(const linetor<T> &lineRight)
{
    if (this->m_length == lineRight.m_length)
    {
        for(int i = 0; i<this->m_length;i++)
            if (this->m_date[i] != lineRight.m_date[i])
                return true;
        return false;
    }else
        {
            return true;
        }
}

template<class T>
T &linetor<T>::operator[](const int index){


    assert (index >= 0 && index <= m_length && "Array out of bounds!" );

    return m_date[index];
}

template<class T>
void linetor<T>::push_back(const T value)
{
    T * temp = new T[m_length+1];
    if (m_date != nullptr)
    {
        for(int i = 0; i<m_length; i++)
        {
            temp[i] = m_date[i];
        }
        delete[] m_date;
        m_date = nullptr;
    }
    m_date = temp;
    m_date[m_length] = value;
    m_length++;
}

template<class T>
T &linetor<T>::at(const int index)
{
    assert (index >= 0 && index <= m_length && "Array out of bounds!" );
    return m_date[index];
}

template<class T>
bool linetor<T>::empty(){

    return (m_length == 0 && m_date==nullptr);

}

template<class T>
void linetor<T>::clear(){

    for(int run=0; run <= length(); run++)
        m_date[run] = T();

}

template<class T>
void linetor<T>::insert(const int index, const T &symb)
{
    this->m_date[index] = symb;
}

template<class T>
void linetor<T>::erase()
{
    delete[] m_date;
    m_date = nullptr;
    m_length = 0;
}
template<class T>
void linetor<T>::pop_back()
{
    if (m_length == 0)
    {
        m_date = nullptr;
    }
    else
    {
        T *temp = new T[m_length-1];
        for( int i=0 ; i < m_length; i++)
            temp[i] = m_date[i];
        delete[] m_date;
        m_length--;
        m_date = new T [m_length];
        m_date = temp;
    }
}

template<class T>
void linetor<T>::swap(linetor<T> & linetor2)
{
    if (this != &linetor2)
    {
        linetor<T> lineTemp;
        lineTemp = *this;
        *this = linetor2;
        linetor2 = lineTemp;
        lineTemp.m_date = nullptr;
        lineTemp.m_length = 0;
    }

}
