#include <iostream>
#include "state.h"


CState::CState()
{

}

CState::~CState()
{

}

void CState::Handle(CStateContext* context)
{

}


CConcreteStateA::CConcreteStateA()
{

}

CConcreteStateA::~CConcreteStateA()
{

}

void CConcreteStateA::Handle(CStateContext* context)
{
    std::cout << "CConcreteStateA" << std::endl;
    context->SetState(new CConcreteStateB());
}

CConcreteStateB::CConcreteStateB()
{

}

CConcreteStateB::~CConcreteStateB()
{

}

void CConcreteStateB::Handle(CStateContext* context)
{
    std::cout << "CConcreteStateB" << std::endl;
    context->SetState(new CConcreteStateC());
}

CConcreteStateC::CConcreteStateC()
{

}

CConcreteStateC::~CConcreteStateC()
{

}

void CConcreteStateC::Handle(CStateContext* context)
{
    std::cout << "CConcreteStateC" << std::endl;
    context->SetState(new CConcreteStateA());
}

CStateContext::CStateContext(CState* state)
    : m_state(state)
{

}

CStateContext::~CStateContext()
{
    delete m_state;
}

void CStateContext::Request()
{
    m_state->Handle(this);
}

void CStateContext::SetState(CState* state)
{
    // state change
    if(m_state)
    {
        delete m_state;
        m_state = nullptr;
    }

    m_state = state;
}
