#include <iostream>
#include "visitor.h"

CAniaml::CAniaml()
{

}

CAniaml::~CAniaml()
{

}

void CAniaml::shout()
{

}

void CAniaml::Accept(CAniamlOperation* operation)
{

}

CMonkey::CMonkey()
{

}

CMonkey::~CMonkey()
{

}

void CMonkey::shout()
{
    std::cout << "Ooh oo aa aa!" << std::endl;
}

void CMonkey::Accept(CAniamlOperation* operation)
{
    operation->visitMonkey(this);
}

CLion::CLion()
{

}

CLion::~CLion()
{

}

void CLion::shout()
{
    std::cout << "Roaaar!" << std::endl;
}

void CLion::Accept(CAniamlOperation* operation)
{
    operation->visitLion(this);
}

CAniamlOperation::CAniamlOperation()
{

}

CAniamlOperation::~CAniamlOperation()
{

}

void CAniamlOperation::visitMonkey(CAniaml* monkey)
{

}

void CAniamlOperation::visitLion(CAniaml* lion)
{

}

CSpeakOperation::CSpeakOperation()
{

}

CSpeakOperation::~CSpeakOperation()
{

}

void CSpeakOperation::visitMonkey(CAniaml* monkey)
{
    monkey->shout();
}

void CSpeakOperation::visitLion(CAniaml* lion)
{
    lion->shout();
}

CJumpOperation::CJumpOperation()
{

}

CJumpOperation::~CJumpOperation()
{

}

void CJumpOperation::visitMonkey(CAniaml* monkey)
{
    std::cout << "Jumped 20 feet high! on to the tree!" << std::endl;
}

void CJumpOperation::visitLion(CAniaml* lion)
{
    std::cout << "Jumped 7 feet! Back on the ground!" << std::endl;
}


