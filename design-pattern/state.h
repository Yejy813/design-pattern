#ifndef __STATE_H__
#define __STATE_H__

/***
 * This is state pattern
 * @brief It lets you change the behavior of a class when the state changes.
 * @time 2019/11/04
 * @authr yejy
 */

class CStateContext;
class CState
{
public:
    virtual ~CState();
    virtual void Handle(CStateContext* context) = 0;

protected:
    CState();
};

class CConcreteStateA : public CState
{
public:
    ~CConcreteStateA();
    CConcreteStateA();
    void Handle(CStateContext* context);
};

class CConcreteStateB : public CState
{
public:
    ~CConcreteStateB();
    CConcreteStateB();
    void Handle(CStateContext* context);
};

class CConcreteStateC : public CState
{
public:
    ~CConcreteStateC();
    CConcreteStateC();
    void Handle(CStateContext* context);
};


class CStateContext
{
public:
    ~CStateContext();
    CStateContext(CState* state);

    void Request();
    void SetState(CState* state);

private:
    CState* m_state;
};
#endif // __STATE_H__
