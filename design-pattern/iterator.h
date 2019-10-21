#ifndef __ITERATOR_H__
#define __ITERATOR_H__

class CIterator;
class CAggregate
{
public:
    virtual ~CAggregate()
    virtual CIterator* CreateIterator() = 0;
    virtual std::string Pop() = 0;
    virtual void Push(const std::string& strValue);
protected:
    CAggregate();
};

class CConcreteAggregate : public
{

};


class CIterator
{

};

class CConcreteIterator : public CIterator
{

};

#endif // __ITERATOR_H__
