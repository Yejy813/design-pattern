#ifndef __SIMPLE_FACTORY_H__
#define __SIMPLE_FACTORY_H__

/// 产品类型
enum class PRODUCT_TYPE
{
    PRODUCT_ABSTRACT,
    PRODUCT_CONCRETE,
};

/// 产品抽象类
class CAbstractProduct
{
public:
    CAbstractProduct();
    virtual ~CAbstractProduct();
    virtual void operation();
};

/// 产品子类
class CConcreteProduct : public CAbstractProduct
{
public:
    CConcreteProduct();
    virtual ~CConcreteProduct();
    virtual void operation();
};

/// 工厂类
class CFactory
{
public:
    CFactory();
    ~CFactory();
    CAbstractProduct* createProduct(PRODUCT_TYPE eType);
};

#endif // __SIMPLE_FACTORY_H__
