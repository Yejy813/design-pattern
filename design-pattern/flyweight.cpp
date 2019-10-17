#include <iostream>
#include "flyweight.h"

CFlyWeight::~CFlyWeight()
{

}

CFlyWeight::CFlyWeight(std::string strInternalState)
    : m_strInternalState(strInternalState)
{

}

std::string CFlyWeight::GetInternalState()
{
    return m_strInternalState;
}

void CFlyWeight::Operation(const std::string& strExternalState)
{
    // change external state
}

CConcreteFlyWeight::~CConcreteFlyWeight()
{

}

CConcreteFlyWeight::CConcreteFlyWeight(std::string strInternalState)
    : CFlyWeight(strInternalState)
{
    std::cout << "CConcreteFlyWeight construct " << strInternalState << std::endl;
}

void CConcreteFlyWeight::Operation(const std::string& strExternalState)
{
    std::cout << "internal state: " << GetInternalState() <<";  external state:  " << strExternalState << std::endl;
}

CFlyWeightFactory::CFlyWeightFactory()
{
    m_vecFlyWeight.clear();
}

CFlyWeightFactory::~CFlyWeightFactory()
{
    for(auto& element : m_vecFlyWeight)
    {
        if(element)
        {
            delete element;
            element = nullptr;
        }
    }

    m_vecFlyWeight.clear();
}

CFlyWeight* CFlyWeightFactory::GetFlyWeight(const std::string& strInternalState)
{
    for(const auto& element : m_vecFlyWeight)
    {
        if(element->GetInternalState() == strInternalState)
        {
            std::cout << " already created !" << std::endl;
            return element;
        }
    }

    CFlyWeight* flyweight = new CConcreteFlyWeight(strInternalState);
    m_vecFlyWeight.push_back(flyweight);

    return flyweight;
}
