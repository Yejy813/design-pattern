#ifndef __DECORATOR_H__
#define __DECORATOR_H__

/***
 * This is decorator pattern
 * @brief the decorator pattern is a design pattern that allows behavior to be added to an individual object,
 *        either statically or dynamically, without affecting the behavior of other objects from the same class.
 * @time 2019/10/17
 * @authr yejy
 */

 // abstract class
class CComponent
{
public:
    virtual ~CComponent();
    virtual void Operation() = 0;
protected:
    CComponent();
};


class CConcreteComponent : public CComponent
{
public:
    ~CConcreteComponent();
    CConcreteComponent();
    void Operation();
};

// abstract decorator
class CDecorator : public CComponent
{
public:
    ~CDecorator();
    CDecorator(CComponent* comp);
    virtual void Operation();

public:
    CComponent* m_Comp;
};

// decorator add behavior
class CConcreteDecorator : public CDecorator
{
public:
    ~CConcreteDecorator();
    CConcreteDecorator(CComponent* comp);
    void Operation();
    void AddBehavior();
};

#endif // __DECORATOR_H__
