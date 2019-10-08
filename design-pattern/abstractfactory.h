#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

/**
 * This is abstract factory pattern
 * @brief Create a series of related or interdependent objects
 * @time 2019/10/8
 * @authr yejy
 */

namespace ABSTRACT_FACTORY
{

/// product
class CAbstractProductA
{
public:
    virtual ~CAbstractProductA() = 0;

protected:
    CAbstractProductA();
};

class CAbstractProductB
{
public:
    virtual ~CAbstractProductB() = 0;

protected:
    CAbstractProductB();
};

class CConcreteProductA1 : public CAbstractProductA
{
public:
    ~CConcreteProductA1();
    CConcreteProductA1();
};

class CConcreteProductA2 : public CAbstractProductA
{
public:
    ~CConcreteProductA2();
    CConcreteProductA2();
};

class CConcreteProductB1 : public CAbstractProductB
{
public:
    ~CConcreteProductB1();
    CConcreteProductB1();
};

class CConcreteProductB2 : public CAbstractProductB
{
public:
    ~CConcreteProductB2();
    CConcreteProductB2();
};


/// factory
class CAbstractFactory
{
public:
    virtual ~CAbstractFactory() = 0;
    virtual CAbstractProductA* CreateProductA() = 0;
    virtual CAbstractProductB* CreateProductB() = 0;
protected:
    CAbstractFactory();
};

class CConcreteFactory1 : public CAbstractFactory
{
public:
    ~CConcreteFactory1();
    CConcreteFactory1();
    CAbstractProductA* CreateProductA();
    CAbstractProductB* CreateProductB();
};

class CConcreteFactory2 : public CAbstractFactory
{
public:
    ~CConcreteFactory2();
    CConcreteFactory2();
    CAbstractProductA* CreateProductA();
    CAbstractProductB* CreateProductB();
};

} // namespace ABSTRACT_FACTORY

#endif // __ABSTRACT_FACTORY_H__
