## 概要
本仓库会将 [`design-patterns-for-humans`](https://github.com/kamranahmedse/design-patterns-for-humans)  内容翻译一遍，并且将里面涉及到的设计模式使用 `C++` 实现。

## 介绍
设计模式是对反复出现的问题的解决方案。有关如何解决某些问题的指南。它们不是您可以插入应用程序并等待魔法发生的类，包或库。它们是在某些情况下如何解决某些问题的指南。

> Design patterns are solutions to recurring problems; guidelines on how to tackle certain problems

维基百科将其描述为
>在软件工程中，软件设计模式是在软件设计中给定上下文中对常见问题的通用可重用解决方案。 它不是可以直接转换为源代码或机器代码的最终设计。它是关于如何解决可以在许多不同情况下使用的问题的描述或模板。

**Be Careful**
1. 设计模式并不是解决所有问题的灵丹妙药。
2. 不要试图强制使用他们。如果这样做，应该会发生坏事。
3. 请记住，设计模式是解决问题的方法，而不是发现问题的解决方案；所以不要想太多。
4. 如果在正确的地方以正确的方式使用它们，它们可以证明是救星；否则会导致代码混乱。

## 设计原则

## 一. 创建型设计模式
### 1. 简单工厂
现实世界的例子：
考虑一下，您正在盖房子，需要门。 您可以穿上木匠的衣服，带些木头，胶水，钉子和所有用来建造门的工具，然后开始在您家中建造它，也可以直接致电工厂并把建造好的门交付给您，以便您不需要学习任何有关门的制作或处理门所带来的混乱的知识。

简而言之：
>简单工厂只需为客户端生成一个实例，而无需向客户端公开任何实例化逻辑。

维基百科：
>在面向对象编程（OOP）中，工厂是用于创建其他对象的对象；形式上，工厂是一种函数或方法，该函数或方法从某个方法调用（假定为“新”）返回不同原型或类的对象。

代码示例：

simplefactory.h 文件
```C++
#ifndef __SIMPLE_FACTORY_H__
#define __SIMPLE_FACTORY_H__

/// 产品类型
enum class PRODUCT_TYPE
{
    PRODUCT_ABSTRACT,
    PRODUCT_CONCRETE,
};

/// 产品抽象类
class CAbstractProduct
{
public:
    CAbstractProduct();
    virtual ~CAbstractProduct();
    virtual void operation();
};

/// 产品子类
class CConcreteProduct : public CAbstractProduct
{
public:
    CConcreteProduct();
    virtual ~CConcreteProduct();
    virtual void operation();
};

/// 工厂类
class CFactory
{
public:
    CFactory();
    ~CFactory();
    CAbstractProduct* createProduct(PRODUCT_TYPE eType);
};

#endif // __SIMPLE_FACTORY_H__
```

simplefactory.cpp 文件
```C++
#include "simplefactory.h"
#include <iostream>

CAbstractProduct::CAbstractProduct()
{

}

CAbstractProduct::~CAbstractProduct()
{

}

void CAbstractProduct::operation()
{
    std::cout << "simple factory abstract product operation." << std::endl;
}


CConcreteProduct::CConcreteProduct()
{

}

CConcreteProduct::~CConcreteProduct()
{

}

void CConcreteProduct::operation()
{
    std::cout << "simple factory concrete product operation." << std::endl;
}


CFactory::CFactory()
{

}

CFactory::~CFactory()
{

}

CAbstractProduct* CFactory::createProduct(PRODUCT_TYPE eType)
{
    CAbstractProduct* product = nullptr;
    switch(eType)
    {
    case PRODUCT_TYPE::PRODUCT_ABSTRACT:
        product = new CAbstractProduct();
        break;
    case PRODUCT_TYPE::PRODUCT_CONCRETE:
        product = new CConcreteProduct();
        break;
    }

    return product;
}
```

客户程序
```
/// 简单工厂模式
CFactory factory;
CAbstractProduct* product = factory.createProduct(PRODUCT_TYPE::PRODUCT_CONCRETE);
product->operation();
```

使用时机：
>当创建一个对象时，不仅仅是分配一些任务，而且涉及一些逻辑，将它放在专用工厂中而不是在各处重复相同的代码是有意义的。

### 2. 工厂方法
现实世界的例子：
考虑招聘经理的情况。一个人不可能对每个职位进行面试。根据职位空缺，她必须决定面试步骤并将其委托给其他人。

简而言之
> 它提供了一种将实例化逻辑委托给子类的方法。

维基百科:
>在基于类的编程中，工厂方法模式是一种创建模式，该模式使用工厂方法来处理创建对象的问题，而不必指定将要创建的对象的确切类。这是通过调用工厂方法来创建对象的，而不是通过调用构造函数，该工厂方法在接口中指定并由子类实现，或者在基类中实现，并且可以选择由派生类覆盖。

代码示例：
factorymethod.h 文件
```C++
// product abstract
class CAbstractProduct
{
public:
    virtual ~CAbstractProduct() = 0;

protected:
    CAbstractProduct();
};

// concrete product
class CConcreteProduct : public CAbstractProduct
{
public:
    ~CConcreteProduct();
    CConcreteProduct();
};

// factory abstract
class CAbstractFactory
{
public:
    virtual ~CAbstractFactory() = 0;
    virtual CAbstractProduct* CreateProduct() = 0;

protected:
    CAbstractFactory();
};

// concrete factory
class CConcreteFactory : public CAbstractFactory
{
public:
    ~CConcreteFactory();
    CConcreteFactory();
    CAbstractProduct* CreateProduct();
};
```
factorymethod.cpp 文件
```C++
CAbstractProduct::CAbstractProduct()
{

}

CAbstractProduct::~CAbstractProduct()
{

}

CConcreteProduct::CConcreteProduct()
{
   std::cout << "factory method CConcreteProduct::CConcreteProduct()" << std::endl;
}

CConcreteProduct::~CConcreteProduct()
{

}

CAbstractFactory::CAbstractFactory()
{

}

CAbstractFactory::~CAbstractFactory()
{

}

CConcreteFactory::CConcreteFactory()
{

}

CConcreteFactory::~CConcreteFactory()
{

}

CAbstractProduct* CConcreteFactory::CreateProduct()
{
   return new CConcreteProduct();
}
```
客户程序：
```C++
FACTORY_METHOD::CAbstractFactory* mfactory = new FACTORY_METHOD::CConcreteFactory();
FACTORY_METHOD::CAbstractProduct* mproduct = nullptr;
/// No need to change
mproduct = mfactory->CreateProduct();
delete mfactory;
delete mproduct;
```

使用时机：
在类中有一些泛型处理但是需要在运行时动态地决定所需的子类时是有用的。或者换句话说，当客户机不知道它可能需要什么子类时。

### 3. 抽象工厂
现实世界的例子：
> 数据库有多种类型，mysql、oracle 等，数据库内部有多个强相关的组成部分，我们就可以使用一个mysql工厂来创建它的各个组成部分。

简而言之:
> A factory of factories; a factory that groups the individual but related/dependent factories together without specifying their concrete classes.

维基百科:
> 抽象工厂模式提供了一种封装一组具有共同主题的单个工厂的方法，而无需指定它们的具体类。

代码示例：
abstractfactory.h 文件
```C++
/// product
class CAbstractProductA
{
public:
    virtual ~CAbstractProductA() = 0;

protected:
    CAbstractProductA();
};

class CAbstractProductB
{
public:
    virtual ~CAbstractProductB() = 0;

protected:
    CAbstractProductB();
};

class CConcreteProductA1 : public CAbstractProductA
{
public:
    ~CConcreteProductA1();
    CConcreteProductA1();
};

class CConcreteProductA2 : public CAbstractProductA
{
public:
    ~CConcreteProductA2();
    CConcreteProductA2();
};

class CConcreteProductB1 : public CAbstractProductB
{
public:
    ~CConcreteProductB1();
    CConcreteProductB1();
};

class CConcreteProductB2 : public CAbstractProductB
{
public:
    ~CConcreteProductB2();
    CConcreteProductB2();
};


/// factory
class CAbstractFactory
{
public:
    virtual ~CAbstractFactory() = 0;
    virtual CAbstractProductA* CreateProductA() = 0;
    virtual CAbstractProductB* CreateProductB() = 0;
protected:
    CAbstractFactory();
};

class CConcreteFactory1 : public CAbstractFactory
{
public:
    ~CConcreteFactory1();
    CConcreteFactory1();
    CAbstractProductA* CreateProductA();
    CAbstractProductB* CreateProductB();
};

class CConcreteFactory2 : public CAbstractFactory
{
public:
    ~CConcreteFactory2();
    CConcreteFactory2();
    CAbstractProductA* CreateProductA();
    CAbstractProductB* CreateProductB();
};
```
abstractfactory.cpp 文件
```C++
CAbstractProductA::~CAbstractProductA()
{

}

CAbstractProductA::CAbstractProductA()
{

}

CAbstractProductB::~CAbstractProductB()
{

}

CAbstractProductB::CAbstractProductB()
{

}

CConcreteProductA1::~CConcreteProductA1()
{

}

CConcreteProductA1::CConcreteProductA1()
{
    std::cout << "Abstract factory CConcreteProductA1::ConcreteProductA1()" << std::endl;
}

CConcreteProductA2::~CConcreteProductA2()
{

}

CConcreteProductA2::CConcreteProductA2()
{
    std::cout << "Abstract factory CConcreteProductA2::CConcreteProductA2()" << std::endl;
}

CConcreteProductB1::~CConcreteProductB1()
{

}

CConcreteProductB1::CConcreteProductB1()
{
    std::cout << "Abstract factory CConcreteProductB1::CConcreteProductB1()" << std::endl;
}

CConcreteProductB2::~CConcreteProductB2()
{

}

CConcreteProductB2::CConcreteProductB2()
{
    std::cout << "Abstract factory CConcreteProductB2::CConcreteProductB2()" << std::endl;
}


CAbstractFactory::~CAbstractFactory()
{

}

CAbstractFactory::CAbstractFactory()
{

}

CAbstractProductA* CAbstractFactory::CreateProductA()
{
    return nullptr;
}

CAbstractProductB* CAbstractFactory::CreateProductB()
{
    return nullptr;
}

CConcreteFactory1::~CConcreteFactory1()
{

}

CConcreteFactory1::CConcreteFactory1()
{

}

CAbstractProductA* CConcreteFactory1::CreateProductA()
{
    return new CConcreteProductA1();
}

CAbstractProductB* CConcreteFactory1::CreateProductB()
{
    return new CConcreteProductB1();
}

CConcreteFactory2::~CConcreteFactory2()
{

}

CConcreteFactory2::CConcreteFactory2()
{

}

CAbstractProductA* CConcreteFactory2::CreateProductA()
{
    return new CConcreteProductA2();
}

CAbstractProductB* CConcreteFactory2::CreateProductB()
{
    return new CConcreteProductB2();
}
```
客户程序：
```C++
/// A and B is related or interdependent
ABSTRACT_FACTORY::CAbstractFactory* afactory = new ABSTRACT_FACTORY::CConcreteFactory1();
ABSTRACT_FACTORY::CAbstractProductA* aproductA = afactory->CreateProductA();
ABSTRACT_FACTORY::CAbstractProductB* aproductB = afactory->CreateProductB();
delete afactory;
delete aproductA;
delete aproductB;

afactory = new ABSTRACT_FACTORY::CConcreteFactory2();
aproductA = afactory->CreateProductA();
aproductB = afactory->CreateProductB();
delete afactory;
delete aproductA;
delete aproductB;
```

使用时机: 
当存在相互关联的依赖关系而不涉及简单的创建逻辑时

## 二. 结构型设计模式

## 三. 行为型设计模式
