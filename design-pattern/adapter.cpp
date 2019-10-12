#include <iostream>
#include "adapter.h"

// target
CTarget::~CTarget()
{

}

CTarget::CTarget()
{

}

void CTarget::Request()
{

}

// adapter
CAdapter::~CAdapter()
{

}

CAdapter::CAdapter(CAdaptee* adaptee)
    : m_pAdaptee(adaptee)
{

}

void CAdapter::Request()
{
    if(m_pAdaptee)
    {
        m_pAdaptee->specificRequest();
    }
}

// adaptee
CAdaptee::~CAdaptee()
{

}

CAdaptee::CAdaptee()
{

}

void CAdaptee::specificRequest()
{
    std::cout << "Real Request CAdaptee::specificRequest." << std::endl;
}
