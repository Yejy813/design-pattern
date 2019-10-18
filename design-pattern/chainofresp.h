#ifndef __CHAIN_OF_RESP__
#define __CHAIN_OF_RESP__

/***
 * This is chain of responsibility pattern
 * @brief It helps building a chain of objects.
 *        Request enters from one end and keeps going from object to object till it finds the suitable handler.
 *
 * @time 2019/10/18
 * @authr yejy
 */

#include <string>

class CAccount
{
public:
    virtual ~CAccount();
    virtual std::string GetAccountName() = 0;
    void SetNextHandle(CAccount* pHandle);
    void Pay(int iAmountToPay);
    bool CanPay(int iAmountToPay);

protected:
    CAccount(int iBalance);

private:
    int m_iBalance;
    CAccount* m_pHandle;
};

class CBank : public CAccount
{
public:
    CBank(int iBalance);
    ~CBank();
    std::string GetAccountName();
};

class CAliPay : public CAccount
{
public:
    CAliPay(int iBalance);
    ~CAliPay();
    std::string GetAccountName();
};

#endif // __CHAIN_OF_RESP__
