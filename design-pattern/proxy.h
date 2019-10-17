#ifndef __PROXY_H__
#define __PROXY_H__

/***
 * This is proxy pattern
 * @brief Using the proxy pattern, a class represents the functionality of another class.
 *        or can provide additional logic.
 *
 * @time 2019/10/17
 * @authr yejy
 */

class CSubject
{
public:
    virtual ~CSubject();
    virtual void Request() = 0;
protected:
    CSubject();
};

class CConcreteSubject : public CSubject
{
public:
    ~CConcreteSubject();
    CConcreteSubject();
    void Request();
};

class CProxy : public CSubject
{
public:
    ~CProxy();
    CProxy(CSubject* subject);
    void Request();

private:
    CSubject* m_pSubject;
};

#endif // __PROXY_H__
