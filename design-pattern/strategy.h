#ifndef __STRATEGY_H__
#define __STRATEGY_H__

/***
 * This is strategy pattern
 * @brief Strategy pattern allows you to switch the algorithm or strategy based upon the situation.
 * @time 2019/11/04
 * @authr yejy
 *
 */

class CStrategy
{
public:
    virtual ~CStrategy();
    virtual void AlgorithmInterface() = 0;

protected:
    CStrategy();
};

class CConcreteStrategyA : public CStrategy
{
public:
    ~CConcreteStrategyA();
    CConcreteStrategyA();
    void AlgorithmInterface();
};

class CConcreteStrategyB : public CStrategy
{
public:
    ~CConcreteStrategyB();
    CConcreteStrategyB();
    void AlgorithmInterface();
};

class CContext
{
public:
    ~CContext();
    CContext(CStrategy* strategy);
    void DoAction();

private:
    CStrategy* m_strategy;
};

#endif // __STRATEGY_H__
