#include <iostream>
#include "strategy.h"

CStrategy::CStrategy()
{

}

CStrategy::~CStrategy()
{

}

void CStrategy::AlgorithmInterface()
{

}

CConcreteStrategyA::CConcreteStrategyA()
{

}

CConcreteStrategyA::~CConcreteStrategyA()
{

}

void CConcreteStrategyA::AlgorithmInterface()
{
    std::cout << "Algorithm A" << std::endl;
}

CConcreteStrategyB::CConcreteStrategyB()
{

}

CConcreteStrategyB::~CConcreteStrategyB()
{

}

void CConcreteStrategyB::AlgorithmInterface()
{
    std::cout << "Algorithm B" << std::endl;
}

CContext::CContext(CStrategy* strategy)
    : m_strategy(strategy)
{

}

CContext::~CContext()
{

}

void CContext::DoAction()
{
    m_strategy->AlgorithmInterface();
}
