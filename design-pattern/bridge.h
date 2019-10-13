#ifndef __BRIDGE_H__
#define __BRIDGE_H__

class CAbstraction
{
public:
    virtual ~CAbstraction();
    virtual void operation() = 0;

protected:
    CAbstraction();
};

class CImplementor;
class CRefinedAbstraction : public CAbstraction
{
public:
    ~CRefinedAbstraction();
    CRefinedAbstraction(CImplementor* imp);
    void operation();

private:
    CImplementor* m_imp;
};

class CImplementor
{
public:
    virtual ~CImplementor();
    virtual void operationimp() = 0;

protected:
    CImplementor();
};

class CConcreteImplementorA : public CImplementor
{
public:
    ~CConcreteImplementorA();
    CConcreteImplementorA();
    void operationimp();
};

class CConcreteImplementorB : public CImplementor
{
public:
    ~CConcreteImplementorB();
    CConcreteImplementorB();
    void operationimp();
};

#endif // __BRIDGE_H__
