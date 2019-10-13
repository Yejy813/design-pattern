#include <iostream>
#include "bridge.h"

CAbstraction::~CAbstraction()
{

}

CAbstraction::CAbstraction()
{

}

void CAbstraction::operation()
{

}


CRefinedAbstraction::~CRefinedAbstraction()
{

}

CRefinedAbstraction::CRefinedAbstraction(CImplementor* imp)
    : m_imp(imp)
{

}

void CRefinedAbstraction::operation()
{
    m_imp->operationimp();
}


CImplementor::~CImplementor()
{

}

CImplementor::CImplementor()
{

}

void CImplementor::operationimp()
{

}


CConcreteImplementorA::~CConcreteImplementorA()
{

}

CConcreteImplementorA::CConcreteImplementorA()
{

}

void CConcreteImplementorA::operationimp()
{
    std::cout << "CConcreteImplementorA::operationimp " << std::endl;
}

CConcreteImplementorB::~CConcreteImplementorB()
{

}

CConcreteImplementorB::CConcreteImplementorB()
{

}

void CConcreteImplementorB::operationimp()
{
    std::cout << "CConcreteImplementorB::operationimp " << std::endl;
}
