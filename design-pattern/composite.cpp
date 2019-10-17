#include <iostream>
#include "composite.h"


CEmployee::~CEmployee()
{

}

CEmployee::CEmployee(int iSalary)
    : m_iSalary(iSalary)
{

}

void CEmployee::SetSalary(int iSalary)
{

}


int CEmployee::GetSalary()
{
    return -1;
}


CDeveloper::~CDeveloper()
{

}

CDeveloper::CDeveloper(int iSalary)
    : CEmployee(iSalary)
{
    std::cout << "developer Salary : " << m_iSalary << std::endl;
}

int CDeveloper::GetSalary()
{
    return m_iSalary;
}

void CDeveloper::SetSalary(int iSalary)
{
    m_iSalary = iSalary;
}


CDesign::~CDesign()
{

}

CDesign::CDesign(int iSalary)
    : CEmployee(iSalary)
{
    std::cout << "design Salary : " << m_iSalary << std::endl;
}

int CDesign::GetSalary()
{
    return m_iSalary;
}

void CDesign::SetSalary(int iSalary)
{
    m_iSalary = iSalary;
}


COrganization::~COrganization()
{

}

COrganization::COrganization()
{
    m_vecEmployee.clear();
}

void COrganization::AddEmployee(CEmployee* pEmployee)
{
    if(pEmployee)
    {
        m_vecEmployee.push_back(pEmployee);
    }
}

void COrganization::DelEmployee(CEmployee* pEmployee)
{
    if(pEmployee)
    {
        std::vector<CEmployee*>::iterator itrBegin = m_vecEmployee.begin();
        for(;itrBegin != m_vecEmployee.end();)
        {
            if(*itrBegin == pEmployee)
            {
                m_vecEmployee.erase(itrBegin);
            }
            else
            {
                ++ itrBegin;
            }
        }
    }
}

int COrganization::GetNetSalaries()
{
    int iSalary = 0;
    for(const auto& element : m_vecEmployee)
    {
        iSalary += element->GetSalary();
    }

    return iSalary;
}
