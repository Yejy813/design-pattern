#ifndef __ITERATOR_H__
#define __ITERATOR_H__

/***
 * This is iterator pattern
 * @brief iterator (Traverse object elements)
 * @time 2019/10/25
 * @authr yejy
 */

// http://www.voidcn.com/article/p-wfmwbcgi-sg.html

#include <vector>
#include <string>
#include <iostream>

template<class Item>
class CIterator;

template<class Item>
class CAggregate
{
public:
    virtual ~CAggregate(){}
    virtual CIterator<Item>* CreateIterator() = 0;
    virtual void Pop() = 0;
    virtual void Push(const Item& value) = 0;
    virtual int Size() = 0;
    virtual Item& operator[](int iIndex) = 0;
};

template<class Item>
class CConcreteIterator;

template<class Item>
class CConcreteAggregate : public CAggregate<Item>
{
public:
    ~CConcreteAggregate()
    {

    }

    CConcreteAggregate()
    {

    }

    CIterator<Item>* CreateIterator()
    {
        return new CConcreteIterator<Item>(this);
    }

    void Pop()
    {
        m_vecItem.pop_back();
    }

    void Push(const Item& value)
    {
        m_vecItem.push_back(value);
    }

    int Size()
    {
        return m_vecItem.size();
    }

    Item& operator[](int iIndex)
    {
        return m_vecItem[iIndex];
    }

private:
    std::vector<Item> m_vecItem;
};

template<class Item>
class CIterator
{
public:
    virtual ~CIterator(){}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Item CurrentItem() = 0;
};

template<class Item>
class CConcreteIterator : public CIterator<Item>
{
public:
    ~CConcreteIterator(){}
    CConcreteIterator(CAggregate<Item>* aggregate) : m_Aggregate(aggregate), m_iCurIndex(0){}
    void First()
    {
        m_iCurIndex = 0;
    }

    void Next()
    {
        if(m_iCurIndex < m_Aggregate->Size())
        {
            ++m_iCurIndex;
        }
    }

    bool IsDone()
    {
        if(m_iCurIndex == m_Aggregate->Size())
        {
            return true;
        }

        return false;
    }

    Item CurrentItem()
    {
        return (*m_Aggregate)[m_iCurIndex];
    }

private:
    int m_iCurIndex;
    CAggregate<Item>* m_Aggregate;
};

#endif // __ITERATOR_H__
