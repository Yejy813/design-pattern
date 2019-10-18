#include <iostream>
#include "chainofresp.h"

CAccount::~CAccount()
{

}

CAccount::CAccount(int iBalance)
    : m_iBalance(iBalance), m_pHandle(nullptr)
{

}

bool CAccount::CanPay(int iAmountToPay)
{
    return m_iBalance >= iAmountToPay;
}

std::string CAccount::GetAccountName()
{
    return "";
}

void CAccount::SetNextHandle(CAccount* pHandle)
{
    m_pHandle = pHandle;
}

void CAccount::Pay(int iAmountToPay)
{
    if(CanPay(iAmountToPay))
    {
        std::cout << GetAccountName() << " can pay it! pay " << iAmountToPay << " dollors." << std::endl;
    }
    else if(m_pHandle)
    {
        std::cout << GetAccountName() << " can not pay it! use next account." << std::endl;
        m_pHandle->Pay(iAmountToPay);
    }
    else
    {
        std::cout << "no account can pay it! stop!" << std::endl;
    }
}


CBank::~CBank()
{

}

CBank::CBank(int iBalance)
    : CAccount(iBalance)
{

}

std::string CBank::GetAccountName()
{
    return "CBank Account";
}

CAliPay::~CAliPay()
{

}

CAliPay::CAliPay(int iBalance)
    : CAccount(iBalance)
{

}

std::string CAliPay::GetAccountName()
{
    return "CAliPay Account";
}
