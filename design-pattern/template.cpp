#include <iostream>
#include "template.h"

CBuilder::CBuilder()
{

}

CBuilder::~CBuilder()
{

}

void CBuilder::build()
{
    test();
    lint();
    assemble();
    deploy();
}

void CBuilder::test()
{

}

void CBuilder::lint()
{

}

void CBuilder::assemble()
{

}

void CBuilder::deploy()
{

}

CAndroidBuilder::CAndroidBuilder()
{

}

CAndroidBuilder::~CAndroidBuilder()
{

}

void CAndroidBuilder::test()
{
    std::cout << "Running android tests" << std::endl;
}

void CAndroidBuilder::lint()
{
    std::cout << "Linting the android code" << std::endl;
}

void CAndroidBuilder::assemble()
{
    std::cout << "Assembling the android build" << std::endl;
}

void CAndroidBuilder::deploy()
{
    std::cout << "Deploying android build to server" << std::endl;
}

CIOSBuilder::CIOSBuilder()
{

}

CIOSBuilder::~CIOSBuilder()
{

}

void CIOSBuilder::test()
{
    std::cout << "Running IOS tests" << std::endl;
}

void CIOSBuilder::lint()
{
    std::cout << "Linting the IOS code" << std::endl;
}

void CIOSBuilder::assemble()
{
    std::cout << "Assembling the IOS build" << std::endl;
}

void CIOSBuilder::deploy()
{
    std::cout << "Deploying IOS build to server" << std::endl;
}


