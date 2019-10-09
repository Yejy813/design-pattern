#ifndef __SINGLETON_H__
#define __SINGLETON_H__

/// (C++11, GCC > 4.3, VS2015) support Thread-safe Local Static Variables
/// https://stackoverflow.com/questions/449436/singleton-instance-declared-as-static-variable-of-getinstance-method-is-it-thre/449823#449823

/// If control enters the declaration concurrently while the variable is being initialized,
/// the concurrent execution shall wait for completion of the initialization.

#include <iostream>

/**
 * This is singleton pattern
 * @brief singleton
 * @time 2019/10/9
 * @authr yejy
 */


class CSingleton
{
public:
    static CSingleton& GetInstance();
    CSingleton(const CSingleton& singleton) = delete;
    CSingleton& operator=(const CSingleton& singleton) = delete;

private:
    CSingleton();
    ~CSingleton();
};

#define g_refSingleton CSingleton::GetInstance()

/// do not use pointer, So as not to be delete
CSingleton& CSingleton::GetInstance()
{
    static CSingleton instance;
    return instance;
}

CSingleton::CSingleton()
{
    std::cout << "CSingleton  constructor called! " << std::endl;
}

CSingleton::~CSingleton()
{
    std::cout << "CSingleton  destructor called! " << std::endl;
}

#endif // __SINGLETON_H__
