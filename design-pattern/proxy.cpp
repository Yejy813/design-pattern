#include <iostream>
#include "proxy.h"

CSubject::CSubject()
{

}

CSubject::~CSubject()
{

}

void CSubject::Request()
{

}

CConcreteSubject::CConcreteSubject()
{

}

CConcreteSubject::~CConcreteSubject()
{

}

void CConcreteSubject::Request()
{
   std::cout << "CConcreteSubject Request" << std::endl;
}

CProxy::CProxy(CSubject* subject)
    : m_pSubject(subject)
{

}

CProxy::~CProxy()
{

}

void CProxy::Request()
{
   std::cout << "CProxy Request" << std::endl;
   if(m_pSubject)
   {
       m_pSubject->Request();
   }
}
