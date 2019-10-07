## 概要
本仓库会将 [`design-patterns-for-humans`](https://github.com/kamranahmedse/design-patterns-for-humans)  内容翻译一遍，并且将里面涉及到的设计模式使用 `C++` 实现。

## 介绍
设计模式是对反复出现的问题的解决方案。有关如何解决某些问题的指南。它们不是您可以插入应用程序并等待魔法发生的类，包或库。它们是在某些情况下如何解决某些问题的指南。

> Design patterns are solutions to recurring problems; guidelines on how to tackle certain problems

维基百科将其描述为
>在软件工程中，软件设计模式是在软件设计中给定上下文中对常见问题的通用可重用解决方案。 它不是可以直接转换为源代码或机器代码的最终设计。它是关于如何解决可以在许多不同情况下使用的问题的描述或模板。

## **Be Careful**
1. 设计模式并不是解决所有问题的灵丹妙药。
2. 不要试图强制使用他们。如果这样做，应该会发生坏事。
3. 请记住，设计模式是解决问题的方法，而不是发现问题的解决方案；所以不要想太多。
4. 如果在正确的地方以正确的方式使用它们，它们可以证明是救星；否则会导致代码混乱。

## 设计模式的类型
创建型、结构型、行为型

## 创建型设计模式
### Simple Factory
现实世界的例子：
考虑一下，您正在盖房子，需要门。 您可以穿上木匠的衣服，带些木头，胶水，钉子和所有用来建造门的工具，然后开始在您家中建造它，也可以直接致电工厂并把建造好的门交付给您，以便您不需要学习任何有关门的制作或处理门所带来的混乱的知识。

简而言之：
简单工厂只需为客户端生成一个实例，而无需向客户端公开任何实例化逻辑。

维基百科：
在面向对象编程（OOP）中，工厂是用于创建其他对象的对象；形式上，工厂是一种函数或方法，该函数或方法从某个方法调用（假定为“新”）返回不同原型或类的对象。

代码示例：
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

```
    /// 简单工厂模式
    CFactory factory;
    CAbstractProduct* product = factory.createProduct(PRODUCT_TYPE::PRODUCT_CONCRETE);
    product->operation();
```

使用时机：当创建一个对象时，不仅仅是分配一些任务，而且涉及一些逻辑，将它放在专用工厂中而不是在各处重复相同的代码是有意义的。

## 结构型设计模式

## 行为型设计模式
