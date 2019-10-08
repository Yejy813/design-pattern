#include <iostream>
#include "factorymethod.h"

namespace FACTORY_METHOD
{

CAbstractProduct::CAbstractProduct()
{

}

CAbstractProduct::~CAbstractProduct()
{

}

CConcreteProduct::CConcreteProduct()
{
   std::cout << "factory method CConcreteProduct::CConcreteProduct()" << std::endl;
}

CConcreteProduct::~CConcreteProduct()
{

}

CAbstractFactory::CAbstractFactory()
{

}

CAbstractFactory::~CAbstractFactory()
{

}

CConcreteFactory::CConcreteFactory()
{

}

CConcreteFactory::~CConcreteFactory()
{

}

CAbstractProduct* CConcreteFactory::CreateProduct()
{
   return new CConcreteProduct();
}

} // namespace FACTORY_METHOD
