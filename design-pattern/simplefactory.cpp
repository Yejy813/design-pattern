#include "simplefactory.h"
#include <iostream>

namespace SIMPLE_FACTORY
{

CAbstractProduct::CAbstractProduct()
{

}

CAbstractProduct::~CAbstractProduct()
{

}

void CAbstractProduct::operation()
{
    std::cout << "simple factory abstract product operation." << std::endl;
}


CConcreteProduct::CConcreteProduct()
{

}

CConcreteProduct::~CConcreteProduct()
{

}

void CConcreteProduct::operation()
{
    std::cout << "simple factory concrete product operation." << std::endl;
}


CFactory::CFactory()
{

}

CFactory::~CFactory()
{

}

CAbstractProduct* CFactory::createProduct(PRODUCT_TYPE eType)
{
    CAbstractProduct* product = nullptr;
    switch(eType)
    {
    case PRODUCT_TYPE::PRODUCT_ABSTRACT:
        product = new CAbstractProduct();
        break;
    case PRODUCT_TYPE::PRODUCT_CONCRETE:
        product = new CConcreteProduct();
        break;
    }

    return product;
}

} // namespace SIMPLE_FACTORY
