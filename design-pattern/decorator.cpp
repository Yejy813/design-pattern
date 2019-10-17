#include <iostream>
#include "decorator.h"

CComponent::~CComponent()
{

}

CComponent::CComponent()
{

}

void CComponent::Operation()
{

}

CConcreteComponent::~CConcreteComponent()
{

}

CConcreteComponent::CConcreteComponent()
{

}

void CConcreteComponent::Operation()
{
    std::cout << "CConcreteComponent::Operation()" << std::endl;
}

CDecorator::~CDecorator()
{

}

CDecorator::CDecorator(CComponent* comp)
    : m_Comp(comp)
{

}

void CDecorator::Operation()
{

}

CConcreteDecorator::~CConcreteDecorator()
{

}

CConcreteDecorator::CConcreteDecorator(CComponent* comp)
    : CDecorator(comp)
{

}

void CConcreteDecorator::Operation()
{
    AddBehavior();
    m_Comp->Operation();
}

void CConcreteDecorator::AddBehavior()
{
    std::cout << "CConcreteDecorator add behavior" << std::endl;
}
