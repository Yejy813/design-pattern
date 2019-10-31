#include <iostream>
#include "mediator.h"

CChatRoomMediator::~CChatRoomMediator()
{

}

CChatRoomMediator::CChatRoomMediator()
{

}

void CChatRoomMediator::ShowMessage(CUser* user, std::string strMessge)
{

}


CChatRoom::~CChatRoom()
{

}

CChatRoom::CChatRoom()
{

}

void CChatRoom::ShowMessage(CUser* user, std::string strMessge)
{
    std::cout << "[" << user->GetName() << "]:" << " " << strMessge << " "  << std::endl;
}

CUser::~CUser()
{

}

CUser::CUser(std::string strName, CChatRoomMediator* pChat)
    : m_strName(strName), m_pChat(pChat)
{

}

std::string CUser::GetName()
{

}

void CUser::SendMessage(std::string strMessge)
{

}

CUserJohn::~CUserJohn()
{

}

CUserJohn::CUserJohn(std::string strName, CChatRoomMediator* pChat)
    : CUser(strName, pChat)
{

}

std::string CUserJohn::GetName()
{
    return m_strName;
}

void CUserJohn::SendMessage(std::string strMessge)
{
    m_pChat->ShowMessage(this, strMessge);
}

CUserJame::~CUserJame()
{

}

CUserJame::CUserJame(std::string strName, CChatRoomMediator* pChat)
    : CUser(strName, pChat)
{

}

std::string CUserJame::GetName()
{
    return m_strName;
}

void CUserJame::SendMessage(std::string strMessge)
{
    m_pChat->ShowMessage(this, strMessge);
}


