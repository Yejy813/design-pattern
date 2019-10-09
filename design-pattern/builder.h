#ifndef __BUILDER_H__
#define __BUILDER_H__

/**
 * This is builder pattern
 * @brief Creating an object is a multi-step process
 * @time 2019/10/9
 * @authr yejy
 */

class CProduct
{
public:
    CProduct();
    ~CProduct();

    inline void SetType(int iType)
    {
        m_iType = iType;
    }

    inline void SetStatus(int iStatus)
    {
        m_iStatus = iStatus;
    }

    inline void SetStyle(int iStyle)
    {
        m_iStyle = iStyle;
    }

    void show();

private:
    int m_iType;
    int m_iStatus;
    int m_iStyle;
};

class CAbstractBuild
{
public:
    virtual ~CAbstractBuild() = 0;
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual void BuildPartC() = 0;
    CProduct* GetProduct();

protected:
    CAbstractBuild();

protected:
    CProduct* m_pProduct;
};

class CConcreteBuild : public CAbstractBuild
{
public:
    ~CConcreteBuild();
    CConcreteBuild();
    void BuildPartA();
    void BuildPartB();
    void BuildPartC();
};

class CDirector
{
public:
    CDirector();
    ~CDirector();

    void SetBuild(CAbstractBuild* pBuild);
    CProduct* Construct();
private:
    CAbstractBuild* m_pBuild;
};

 #endif // __BUILDER_H__
