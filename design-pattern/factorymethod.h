#ifndef __FACTORY_METHOD_H__
#define __FACTORY_METHOD_H__

/**
 * This is factory method pattern
 * @brief Create object work delays to subclasses
 * @time 2019/10/8
 * @authr yejy
 */

namespace FACTORY_METHOD
{

// product abstract
class CAbstractProduct
{
public:
    virtual ~CAbstractProduct() = 0;

protected:
    CAbstractProduct();
};

// concrete product
class CConcreteProduct : public CAbstractProduct
{
public:
    ~CConcreteProduct();
    CConcreteProduct();
};

// factory abstract
class CAbstractFactory
{
public:
    virtual ~CAbstractFactory() = 0;
    virtual CAbstractProduct* CreateProduct() = 0;

protected:
    CAbstractFactory();
};

// concrete factory
class CConcreteFactory : public CAbstractFactory
{
public:
    ~CConcreteFactory();
    CConcreteFactory();
    CAbstractProduct* CreateProduct();
};

} // namespace FACTORY_METHOD
#endif //__FACTORY_METHOD_H__
