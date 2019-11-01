#include <iostream>
#include "memento.h"

CEditMemento::~CEditMemento()
{

}

CEditMemento::CEditMemento(std::string strStatus)
    : m_strStatus(strStatus)
{

}

std::string CEditMemento::GetStatus()
{
    return m_strStatus;
}


CEdit::~CEdit()
{

}

CEdit::CEdit(std::string strStatus)
    : m_strStatus(strStatus)
{

}

CEditMemento* CEdit::CreateMemento()
{
    return new CEditMemento(m_strStatus);
}

void CEdit::restore(CEditMemento* pMemento)
{
    m_strStatus = pMemento->GetStatus();
}

void CEdit::PrintStatus()
{
    std::cout << "edit status: " << m_strStatus << std::endl;
}

void CEdit::SetStatus(std::string strStatus)
{
    m_strStatus = strStatus;
}
