#include <iostream>
#include "prototype.h"

CAbstractPrototype::CAbstractPrototype()
{

}

CAbstractPrototype::~CAbstractPrototype()
{

}


CAbstractPrototype* CAbstractPrototype::clone()
{
    return nullptr;
}

void CAbstractPrototype::PrintStatus()
{
    std::cout << "prototype pattern, my status: " << m_iStatus << std::endl;
}


CConcretePrototypeA::CConcretePrototypeA()
{

}

CConcretePrototypeA::~CConcretePrototypeA()
{

}

CAbstractPrototype* CConcretePrototypeA::clone()
{
    return new CConcretePrototypeA(*this);
}

CConcretePrototypeB::CConcretePrototypeB()
{

}

CConcretePrototypeB::~CConcretePrototypeB()
{

}

CAbstractPrototype* CConcretePrototypeB::clone()
{
    return new CConcretePrototypeB(*this);
}
