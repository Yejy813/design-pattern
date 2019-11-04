#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

/***
 * This is template pattern
 * @brief Template method defines the skeleton of how a certain algorithm could be performed,
 *        but defers the implementation of those steps to the children classes.
 *
 * @time 2019/11/04
 * @authr yejy
 */

class CBuilder
{
public:
    virtual ~CBuilder();

    void build();
    virtual void test() = 0;
    virtual void lint() = 0;
    virtual void assemble() = 0;
    virtual void deploy() = 0;

protected:
    CBuilder();
};

class CAndroidBuilder : public CBuilder
{
public:
    ~CAndroidBuilder();
    CAndroidBuilder();

    void test();
    void lint();
    void assemble();
    void deploy();
};

class CIOSBuilder : public CBuilder
{
public:
    ~CIOSBuilder();
    CIOSBuilder();

    void test();
    void lint();
    void assemble();
    void deploy();
};

#endif // __TEMPLATE_H__
