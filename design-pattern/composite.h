#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

/***
 * This is composite pattern
 * @brief composite (handly-body; Part-whole)
 * @time 2019/10/16
 * @authr yejy
 */

#include <vector>

class CEmployee
{
public:
    virtual ~CEmployee();
    virtual void SetSalary(int iSalary) = 0;
    virtual int GetSalary() = 0;
protected:
    CEmployee(int iSalary);

public:
    int m_iSalary;
};

class CDeveloper : public CEmployee
{
public:
    ~CDeveloper();
    CDeveloper(int iSalary);
    void SetSalary(int iSalary);
    int GetSalary();
};

class CDesign : public CEmployee
{
public:
    ~CDesign();
    CDesign(int iSalary);
    void SetSalary(int iSalary);
    int GetSalary();
};

class COrganization
{
public:
    ~COrganization();
    COrganization();
    void AddEmployee(CEmployee* pEmployee);
    void DelEmployee(CEmployee* pEmployee);
    int GetNetSalaries();

private:
    std::vector<CEmployee*> m_vecEmployee;
};


#endif // __COMPOSITE_H__
