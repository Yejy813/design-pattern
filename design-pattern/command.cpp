#include <iostream>
#include "command.h"

CReciever::CReciever()
{

}

CReciever::~CReciever()
{

}

void CReciever::Action()
{
    std::cout << "CReciever::Action(). truely action " << std::endl;
}

CCommand::CCommand()
{

}

CCommand::~CCommand()
{

}

void CCommand::Excute()
{

}

CConcreteCommand::CConcreteCommand(CReciever* pRec)
    : m_pRec(pRec)
{

}

CConcreteCommand::~CConcreteCommand()
{

}

void CConcreteCommand::Excute()
{
    std::cout << "CConcreteCommand::Excute() ." << std::endl;
    m_pRec->Action();
}

CInvoker::CInvoker(CCommand* pCommand)
    : m_pCommand(pCommand)
{

}

CInvoker::~CInvoker()
{

}

void CInvoker::Invoke()
{
    m_pCommand->Excute();
}

