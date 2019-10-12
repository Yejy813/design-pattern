#ifndef __ADAPTER_H__
#define __ADAPTER_H__

/***
 * This is adapter pattern
 * @brief adapter (Inheritance and composition)
 * @time 2019/10/12
 * @authr yejy
 */

/// client will call it
class CTarget
{
public:
    virtual ~CTarget() = 0;
    virtual void Request() = 0;

protected:
    CTarget();
};

class CAdaptee;
// adapter
class CAdapter : public CTarget
{
public:
    ~CAdapter();
    CAdapter(CAdaptee* adaptee);
    void Request(); // adapter request

private:
    CAdaptee* m_pAdaptee;
};

class CAdaptee
{
public:
    ~CAdaptee();
     CAdaptee();
     void specificRequest(); // real request
};

#endif // __ADAPTER_H__
