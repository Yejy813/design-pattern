#ifndef __OBSERVER_H__
#define __OBSERVER_H__

/***
 * This is observer pattern
 * @brief Defines a dependency between objects so that whenever an object changes its state, all its dependents are notified.
 *
 * @time 2019/11/01
 * @authr yejy
 */

#include <vector>
#include <string>

class CObserver;
class CObserverSubject
{
public:
    virtual ~CObserverSubject();
    virtual void Attach(CObserver* observer);
    virtual void Detach(CObserver* observer);
    virtual void Notify();
    virtual void SetStatus(std::string strStatus) = 0;
    virtual std::string GetStatus() = 0;

protected:
    CObserverSubject();

private:
    std::vector<CObserver*> m_vecObserver;
};

class CConcreteObserverSubject : public CObserverSubject
{
public:
    CConcreteObserverSubject();
    ~CConcreteObserverSubject();

    void SetStatus(std::string strStatus);
    std::string GetStatus();

private:
    std::string m_strStatus;
};


class CObserver
{
public:
    virtual ~CObserver();
    virtual void Update() = 0;
    std::string GetStatus();

protected:
    CObserver(std::string strStatus);

public:
    std::string m_strStatus;
};

class CConcreteObserverA : public CObserver
{
public:
    CConcreteObserverA(std::string strStatus);
    ~CConcreteObserverA();

    void Update();
};

class CConcreteObserverB : public CObserver
{
public:
    CConcreteObserverB(std::string strStatus);
    ~CConcreteObserverB();

    void Update();
};
#endif // __OBSERVER_H__
