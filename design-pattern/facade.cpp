#include <iostream>
#include "facade.h"

CSubSystemA::~CSubSystemA()
{

}

CSubSystemA::CSubSystemA()
{

}

void CSubSystemA::Operation()
{
    std::cout << "CSubSystemA::Operation()" << std::endl;
}

CSubSystemB::~CSubSystemB()
{

}

CSubSystemB::CSubSystemB()
{

}

void CSubSystemB::Operation()
{
    std::cout << "CSubSystemB::Operation()" << std::endl;
}

CFacade::~CFacade()
{
    delete m_pSubSystemA;
    delete m_pSubSystemB;
}

CFacade::CFacade()
{
    m_pSubSystemA = new CSubSystemA();
    m_pSubSystemB = new CSubSystemB();
}

void CFacade::OperationWrapper()
{
    m_pSubSystemA->Operation();
    m_pSubSystemB->Operation();
}


