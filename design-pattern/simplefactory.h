#ifndef __SIMPLE_FACTORY_H__
#define __SIMPLE_FACTORY_H__

/**
 * This is simple factory pattern
 * @brief Wrap object creation logic
 * @time 2019/10/8
 * @authr yejy
 */

namespace SIMPLE_FACTORY
{

/// product type
enum class PRODUCT_TYPE
{
    PRODUCT_ABSTRACT,
    PRODUCT_CONCRETE,
};

/// abstract product
class CAbstractProduct
{
public:
    CAbstractProduct();
    virtual ~CAbstractProduct();
    virtual void operation();
};

/// concrete product
class CConcreteProduct : public CAbstractProduct
{
public:
    CConcreteProduct();
    virtual ~CConcreteProduct();
    virtual void operation();
};

/// factory
class CFactory
{
public:
    CFactory();
    ~CFactory();
    CAbstractProduct* createProduct(PRODUCT_TYPE eType);
};

} // namespace SIMPLE_FACTORY
#endif // __SIMPLE_FACTORY_H__
