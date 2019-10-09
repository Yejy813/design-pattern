#include <iostream>
#include "builder.h"

CProduct::CProduct()
    : m_iType(-1) , m_iStatus(-1), m_iStyle(-1)
{

}

CProduct::~CProduct()
{

}

void CProduct::show()
{
    std::cout << "builder pattern : product type [" << m_iType << "] status [ "<< m_iStatus <<"] style ["<< m_iStyle <<"]." << std::endl;
}

CAbstractBuild::~CAbstractBuild()
{

}

CAbstractBuild::CAbstractBuild()
{
    m_pProduct = new CProduct();
}

void CAbstractBuild::BuildPartA()
{

}

void CAbstractBuild::BuildPartB()
{

}

void CAbstractBuild::BuildPartC()
{

}

CProduct* CAbstractBuild::GetProduct()
{
    return m_pProduct;
}

CConcreteBuild::CConcreteBuild()
{

}

CConcreteBuild::~CConcreteBuild()
{

}

void CConcreteBuild::BuildPartA()
{
    if(m_pProduct)
    {
        std::cout << "Step1:Build PartA." << std::endl;
        m_pProduct->SetType(1);
    }
}

void CConcreteBuild::BuildPartB()
{
    if(m_pProduct)
    {
        std::cout << "Step1:Build PartB." << std::endl;
        m_pProduct->SetStatus(2);
    }
}

void CConcreteBuild::BuildPartC()
{
    if(m_pProduct)
    {
        std::cout << "Step1:Build PartC." << std::endl;
        m_pProduct->SetStyle(3);
    }
}

CDirector::CDirector()
    : m_pBuild(nullptr)
{

}

CDirector::~CDirector()
{

}

void CDirector::SetBuild(CAbstractBuild* pBuild)
{
    m_pBuild = pBuild;
}

CProduct* CDirector::Construct()
{
    m_pBuild->BuildPartA();
    m_pBuild->BuildPartB();
    m_pBuild->BuildPartC();

    return m_pBuild->GetProduct();
}
