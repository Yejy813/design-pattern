#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

/**
 * This is prototype pattern
 * @brief clone object
 * @time 2019/10/9
 * @authr yejy
 */

class CAbstractPrototype
{
public:
    virtual ~CAbstractPrototype();
    virtual CAbstractPrototype* clone() = 0;

    inline void SetStatus(int iStatus)
    {
        m_iStatus = iStatus;
    }

    void PrintStatus();

protected:
    CAbstractPrototype();

private:
    int m_iStatus;
};

class CConcretePrototypeA : public CAbstractPrototype
{
public:
    ~CConcretePrototypeA();
    CConcretePrototypeA();
    virtual CAbstractPrototype* clone();
};

class CConcretePrototypeB : public CAbstractPrototype
{
public:
    ~CConcretePrototypeB();
    CConcretePrototypeB();
    virtual CAbstractPrototype* clone();
};


#endif // __PROTOTYPE_H__
