#include "SqStack.h"
#include <stdio.h>

template <typename T>
SqStack<T>::SqStack(int len) : m_len(len)
{
    m_data = new T[len];
    m_top = -1;
}

template <typename T>
SqStack<T>::~SqStack()
{
    delete[] data;
}

template <typename T>
bool SqStack<T>::Push(T x)
{
    if (m_top == m_len - 1)
    {
        return false;
    }
    
    m_data[++m_top] = x;
    return true;
}

template <typename T>
T SqStack<T>::Pop()
{
    if (m_top < 0)
    {
        throw m_top;
    }
    

    return m_data[m_top--];
}

template <typename T>
T &SqStack<T>::operator[](unsigned i)
{
    return m_data[i];
}

template <typename T>
const T &SqStack<T>::operator[](unsigned i) const
{
    return m_data[i];
}

template <typename T>
void SqStack<T>::display() const
{
    for (int i = 0; i < m_len; i++)
    {
        printf("%d ", m_data[i]);
    }
    printf("\n");
}