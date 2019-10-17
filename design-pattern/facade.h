#ifndef __FACADE_H__
#define __FACADE_H__

/***
 * This is facade pattern
 * @brief Facade pattern provides a simplified interface to a complex subsystem.
 *
 * @time 2019/10/17
 * @authr yejy
 */

class CSubSystemA
{
public:
    ~CSubSystemA();
    CSubSystemA();
    void Operation();
};

class CSubSystemB
{
public:
    ~CSubSystemB();
    CSubSystemB();
    void Operation();
};

class CFacade
{
public:
    ~CFacade();
    CFacade();
    void OperationWrapper();

private:
    CSubSystemA* m_pSubSystemA;
    CSubSystemB* m_pSubSystemB;
};


#endif // __FACADE_H__
