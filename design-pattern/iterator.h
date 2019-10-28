#ifndef __ITERATOR_H__
#define __ITERATOR_H__

/***
 * This is iterator pattern
 * @brief iterator (Traverse object elements)
 * @time 2019/10/25
 * @authr yejy
 */

// http://www.voidcn.com/article/p-wfmwbcgi-sg.html
class CIterator;

template<class Item>
class CAggregate
{
public:
    virtual ~CAggregate();
    virtual CIterator begin() = 0;
    virtual CIterator end() = 0;
    virtual Item Pop() = 0;
    virtual void Push(const Item& value) = 0;
protected:
    CAggregate();
};

template<class Item>
class CConcreteAggregate : public CAggregate<Item>
{
public:
    ~CConcreteAggregate();
    CConcreteAggregate();
    CIterator begin() = 0;
    CIterator end() = 0;
    Item Pop();
    void Push(const Item& value);

private:
    static const int iMaxSize = 6;
    Item arr[iMaxSize];
};

template<class Item>
class CIterator
{
public:
    virtual ~CIterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Item CurrentItem() = 0;

protected:
    CIterator();
};

template<class Item>
class CConcreteIterator : public CIterator<Item>
{
public:
    ~CConcreteIterator();
    CConcreteIterator();
    void First();
    void Next();
    bool IsDone();
    Item CurrentItem();

private:
    int m_iCurIndex;
    CAggregate<Item> m_Aggregate;
};

#endif // __ITERATOR_H__
