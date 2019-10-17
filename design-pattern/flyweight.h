#ifndef __FLY_WEIGHT_H__
#define __FLY_WEIGHT_H__

/***
 * This is flyweight pattern
 * @brief It is used to minimize memory usage or computational expenses by sharing
 *        as much as possible with similar objects.
 *
 * @time 2019/10/17
 * @authr yejy
 */

#include <string>
#include <vector>

class CFlyWeight
{
public:
    virtual ~CFlyWeight();
    virtual void Operation(const std::string& strExternalState);
    std::string GetInternalState();

protected:
    CFlyWeight(std::string strInternalState);

private:
    std::string m_strInternalState;
};

class CConcreteFlyWeight : public CFlyWeight
{
public:
    ~CConcreteFlyWeight();
    CConcreteFlyWeight(std::string strInternalState);
    void Operation(const std::string& strExternalState);
};

class CFlyWeightFactory
{
public:
    ~CFlyWeightFactory();
    CFlyWeightFactory();
    CFlyWeight* GetFlyWeight(const std::string& strInternalState);

private:
    std::vector<CFlyWeight*> m_vecFlyWeight;
};

#endif // __FLY_WEIGHT_H__
