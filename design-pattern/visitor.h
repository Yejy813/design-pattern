#ifndef __VISITOR_H__
#define __VISITOR_H__

/***
 * This is visitor pattern
 * @brief Visitor pattern lets you add further operations to objects without having to modify them.
 * @time 2019/11/02
 * @authr yejy
 */

class CAniamlOperation; // visitor
class CAniaml
{
public:
    virtual ~CAniaml();
    virtual void shout() = 0;
    virtual void Accept(CAniamlOperation* operation) = 0;

protected:
    CAniaml();
};

class CMonkey : public CAniaml
{
public:
    CMonkey();
    ~CMonkey();
    void shout();
    void Accept(CAniamlOperation* operation);
};

class CLion : public CAniaml
{
public:
    CLion();
    ~CLion();
    void shout();
    void Accept(CAniamlOperation* operation);
};

// visitor
class CAniamlOperation
{
public:
    virtual ~CAniamlOperation();
    virtual void visitMonkey(CAniaml* monkey) = 0;
    virtual void visitLion(CAniaml* lion) = 0;

protected:
    CAniamlOperation();
};

class CSpeakOperation : public CAniamlOperation
{
public:
    ~CSpeakOperation();
    CSpeakOperation();
    void visitMonkey(CAniaml* monkey);
    void visitLion(CAniaml* lion);
};

class CJumpOperation : public CAniamlOperation
{
public:
    ~CJumpOperation();
    CJumpOperation();
    void visitMonkey(CAniaml* monkey);
    void visitLion(CAniaml* lion);
};

#endif // __VISITOR_H__
