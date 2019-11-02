#include <iostream>
#include "observer.h"

CObserverSubject::CObserverSubject()
{
    m_vecObserver.clear();
}

CObserverSubject::~CObserverSubject()
{

}

void CObserverSubject::Attach(CObserver* observer)
{
    if(observer)
    {
        m_vecObserver.push_back(observer);
    }
}

void CObserverSubject::Detach(CObserver* observer)
{
    if(observer)
    {
        for(std::vector<CObserver*>::iterator itrBegin = m_vecObserver.begin(); itrBegin != m_vecObserver.end();)
        {
            if(*itrBegin == observer)
            {
                m_vecObserver.erase(itrBegin);
            }
            else
            {
                ++itrBegin;
            }
        }
    }
}

void CObserverSubject::Notify()
{
    for(const auto& element : m_vecObserver)
    {
        if(element->GetStatus() == GetStatus())
        {
            element->Update();
            return ;
        }
    }

    std::cout << "no observer match"<< std::endl;
}

void CObserverSubject::SetStatus(std::string strStatus)
{

}

std::string CObserverSubject::GetStatus()
{
    return "";
}

CConcreteObserverSubject::CConcreteObserverSubject()
    : m_strStatus("")
{

}

CConcreteObserverSubject::~CConcreteObserverSubject()
{

}

void CConcreteObserverSubject::SetStatus(std::string strStatus)
{
    m_strStatus = strStatus;
}

std::string CConcreteObserverSubject::GetStatus()
{
    return m_strStatus;
}

CObserver::CObserver(std::string strStatus)
    : m_strStatus(strStatus)
{

}

CObserver::~CObserver()
{

}

void CObserver::Update()
{

}

std::string CObserver::GetStatus()
{
    return m_strStatus;
}

CConcreteObserverA::CConcreteObserverA(std::string strStatus)
    : CObserver(strStatus)
{

}

CConcreteObserverA::~CConcreteObserverA()
{

}

void CConcreteObserverA::Update()
{
    std::cout << "CConcreteObserverA Update() status: " << m_strStatus << std::endl;
}

CConcreteObserverB::CConcreteObserverB(std::string strStatus)
    : CObserver(strStatus)
{

}

CConcreteObserverB::~CConcreteObserverB()
{

}

void CConcreteObserverB::Update()
{
    std::cout << "CConcreteObserverB Update() status: " << m_strStatus << std::endl;
}



