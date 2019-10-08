#include <iostream>
#include "abstractfactory.h"

namespace ABSTRACT_FACTORY
{
CAbstractProductA::~CAbstractProductA()
{

}

CAbstractProductA::CAbstractProductA()
{

}

CAbstractProductB::~CAbstractProductB()
{

}

CAbstractProductB::CAbstractProductB()
{

}

CConcreteProductA1::~CConcreteProductA1()
{

}

CConcreteProductA1::CConcreteProductA1()
{
    std::cout << "Abstract factory CConcreteProductA1::ConcreteProductA1()" << std::endl;
}

CConcreteProductA2::~CConcreteProductA2()
{

}

CConcreteProductA2::CConcreteProductA2()
{
    std::cout << "Abstract factory CConcreteProductA2::CConcreteProductA2()" << std::endl;
}

CConcreteProductB1::~CConcreteProductB1()
{

}

CConcreteProductB1::CConcreteProductB1()
{
    std::cout << "Abstract factory CConcreteProductB1::CConcreteProductB1()" << std::endl;
}

CConcreteProductB2::~CConcreteProductB2()
{

}

CConcreteProductB2::CConcreteProductB2()
{
    std::cout << "Abstract factory CConcreteProductB2::CConcreteProductB2()" << std::endl;
}


CAbstractFactory::~CAbstractFactory()
{

}

CAbstractFactory::CAbstractFactory()
{

}

CAbstractProductA* CAbstractFactory::CreateProductA()
{
    return nullptr;
}

CAbstractProductB* CAbstractFactory::CreateProductB()
{
    return nullptr;
}

CConcreteFactory1::~CConcreteFactory1()
{

}

CConcreteFactory1::CConcreteFactory1()
{

}

CAbstractProductA* CConcreteFactory1::CreateProductA()
{
    return new CConcreteProductA1();
}

CAbstractProductB* CConcreteFactory1::CreateProductB()
{
    return new CConcreteProductB1();
}

CConcreteFactory2::~CConcreteFactory2()
{

}

CConcreteFactory2::CConcreteFactory2()
{

}

CAbstractProductA* CConcreteFactory2::CreateProductA()
{
    return new CConcreteProductA2();
}

CAbstractProductB* CConcreteFactory2::CreateProductB()
{
    return new CConcreteProductB2();
}

} // namespace ABSTRACT_FACTORY
