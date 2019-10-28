#ifndef __COMMAND_H__
#define __COMMAND_H__

/***
 * This is command pattern
 * @brief The key idea behind this pattern is to provide the means to decouple client from receiver.
 *
 * @time 2019/10/19
 * @authr yejy
 */

class CReciever
{
public:
    ~CReciever();
    CReciever();

    void Action();
};

class CCommand
{
public:
    virtual ~CCommand();
    virtual void Excute() = 0;
protected:
    CCommand();
};

class CConcreteCommand : public CCommand
{
public:
    ~CConcreteCommand();
    CConcreteCommand(CReciever* pRec);
    void Excute();

private:
    CReciever* m_pRec;
};

class CInvoker
{
public:
    ~CInvoker();
    CInvoker(CCommand* pCommand);

    void Invoke();
private:
    CCommand* m_pCommand;
};

#endif // __COMMAND_H__
