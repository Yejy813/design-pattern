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

## 设计模式类型
- [创建型设计模式](#创建型设计模式)
- [结构型设计模式](#结构型设计模式)
- [行为型设计模式](#行为型设计模式)

## 创建型设计模式
简而言之：
> 创建模式的重点是如何实例化一个对象或一组相关对象。

维基百科:
> 在软件工程中，创造性设计模式是处理对象创建机制的设计模式，试图以适合情况的方式创建对象。对象创建的基本形式可能会导致设计问题或增加设计的复杂性。创造性的设计模式通过某种方式控制对象的创建来解决这个问题。

- [简单工厂](#简单工厂)
- [工厂方法](#工厂方法)
- [抽象工厂](#抽象工厂)
- [单例模式](#单例模式)
- [原型模式](#原型模式)
- [建造者模式](#建造者模式)

### 简单工厂
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

### 工厂方法
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

### 抽象工厂
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

### 单例模式
现实世界的例子
> 一个国家一次只能有一位总统。只要有责任，就必须让同一位总统采取行动。总统是singleton。

简而言之:
> 确保只创建特定类的一个对象。

维基百科:
>在软件工程中，单例模式是一种软件设计模式，它将类的实例化限制在一个对象上。当需要一个对象来协调整个系统中的操作时，这非常有用。

单例模式实际上被认为是一种反模式，应该避免过度使用它。它不一定是坏的，可能有一些有效的用例，但是应该谨慎使用，因为它在应用程序中引入了全局状态，在一个地方对其进行更改可能会影响到其他区域，并且可能变得很难调试。另一个不好的地方是，这会使代码紧密耦合，并且很难模拟单例。

`注`: (C++11, GCC > 4.3, VS2015) support Thread-safe Local Static Variables [链接](https://stackoverflow.com/questions/449436/singleton-instance-declared-as-static-variable-of-getinstance-method-is-it-thre/449823#449823)

代码示例：
```C++
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
```

### 原型模式
现实世界的例子
> 还记得多莉吗？克隆的羊！我们先不谈细节，但这里的关键是，一切都是关于克隆的

简而言之
> 通过克隆来创建基于现有对象的对象。

维基百科:
> 原型模式是软件开发中一种创造性的设计模式。当要创建的对象类型由一个原型实例确定时，使用该实例，该实例被克隆以生成新对象。

简而言之，它允许您创建现有对象的副本并将其修改为您的需要，而不是从头开始创建对象并设置它的麻烦。

代码示例：

prototype.h文件
```C++
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
```

prototype.cpp文件
```C++
CAbstractPrototype::CAbstractPrototype()
{

}

CAbstractPrototype::~CAbstractPrototype()
{

}


CAbstractPrototype* CAbstractPrototype::clone()
{
    return nullptr;
}

void CAbstractPrototype::PrintStatus()
{
    std::cout << "prototype pattern, my status: " << m_iStatus << std::endl;
}


CConcretePrototypeA::CConcretePrototypeA()
{

}

CConcretePrototypeA::~CConcretePrototypeA()
{

}

CAbstractPrototype* CConcretePrototypeA::clone()
{
    return new CConcretePrototypeA(*this);
}

CConcretePrototypeB::CConcretePrototypeB()
{

}

CConcretePrototypeB::~CConcretePrototypeB()
{

}

CAbstractPrototype* CConcretePrototypeB::clone()
{
    return new CConcretePrototypeB(*this);
}
```

客户程序：
```C++
CAbstractPrototype* prototypeA = new CConcretePrototypeA();
prototypeA->SetStatus(77);
CAbstractPrototype* prototypeB = prototypeA->clone();
prototypeB->PrintStatus();
```

使用时机: 
当需要一个对象时，该对象与现有对象相似，或者当创建与克隆相比昂贵时。

### 建造者模式
现实世界的例子
> 假设您在Hardee's，并订购了一笔特定的交易，比如说“ Big Hardee”，他们会毫无疑问地将其交给您, 这是简单工厂的例子。但是在某些情况下，创建逻辑可能涉及更多步骤。例如，您想要定制的Subway交易，您在汉堡的制作方式上有多种选择，例如，您想要哪种面包？ 您想要哪种调味料？ 您要什么奶酪？ 等等。在这种情况下，构建者模式可以解决。

简而言之
> 使您可以创建对象的不同样式，同时避免构造函数污染。当一个物体可能有多种口味时很有用。或者在创建对象时涉及很多步骤。

维基百科：
> builder模式是一种对象创建型软件设计模式，旨在找到伸缩构造函数反模式的解决方案。


说到这里，让我补充一下伸缩构造函数反模式是什么。在某种程度上，我们都看到了一个构造函数，如下所示：

```C++
__construct($size, $cheese = true, $pepperoni = true, $tomato = false, $lettuce = true)
{
}
```

如您所见，构造函数参数的数量可能很快失控，并且可能会变得难以理解参数的排列。另外，如果您将来想添加更多选项，这个参数列表可能会继续增长。这叫做伸缩构造器反模式。

代码示例：

builder.h
```C++
class CProduct
{
public:
    CProduct();
    ~CProduct();

    void SetType(int iType)
    {
        m_iType = iType;
    }

    void SetStatus(int iStatus)
    {
        m_iStatus = iStatus;
    }

    void SetStyle(int iStyle)
    {
        m_iStyle = iStyle;
    }

    void show();

private:
    int m_iType;
    int m_iStatus;
    int m_iStyle;
};

class CAbstractBuild
{
public:
    virtual ~CAbstractBuild() = 0;
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual void BuildPartC() = 0;
    CProduct* GetProduct();

protected:
    CAbstractBuild();

protected:
    CProduct* m_pProduct;
};

class CConcreteBuild : public CAbstractBuild
{
public:
    ~CConcreteBuild();
    CConcreteBuild();
    void BuildPartA();
    void BuildPartB();
    void BuildPartC();
};

class CDirector
{
public:
    CDirector();
    ~CDirector();

    void SetBuild(CAbstractBuild* pBuild);
    CProduct* Construct();
private:
    CAbstractBuild* m_pBuild;
};
```

客户程序：
```C++
CAbstractBuild* build = new CConcreteBuild();
// No need to change
CDirector director;
director.SetBuild(build);
CProduct* bproduct = director.Construct(); // construct step and create object
bproduct->show();

delete bproduct;
delete build;
```

使用时机: 
当一个对象可能有几种类型时，为了避免构造器伸缩。与工厂模式的关键区别在于：工厂模式在创建是一步流程时使用，而构建器模式在创建是多步流程时使用。

## 结构型设计模式
简而言之：
> 结构模式主要关注对象组合，或者换句话说，实体如何相互使用。或者另一种解释是，它们有助于回答“如何构建软件组件？”

维基百科
> 在软件工程中，结构设计模式是通过识别实现实体之间关系的简单方法来简化设计的设计模式。

- [适配器](#适配器模式)
- [桥模式](#桥模式)
- [组合模式](#组合模式)
- [装饰者模式](#装饰者模式)
- [门面模式](#门面模式)
- [享元模式](#享元模式)
- [代理模式](#代理模式)

### 适配器模式
现实世界的例子：
> 考虑到你的存储卡中有一些图片，你需要将它们传送到你的计算机上。为了传输它们，您需要某种与计算机端口兼容的适配器，以便可以将存储卡连接到计算机。在这种情况下，读卡器是一个适配器。另一个例子是著名的电源适配器；三脚插头不能连接到双脚插座，它需要使用电源适配器，使其与双脚插座兼容。另一个例子是翻译人员把一个人说的话翻译成另一个人说的话。

简而言之：
> 适配器模式允许您将不兼容的对象包装到适配器中，使其与其他类兼容。

维基百科:
> 在软件工程中，适配器模式是一种软件设计模式，它允许现有类的接口用作另一个接口。它通常用于使现有类与其他类协同工作而不修改源代码。

代码示例：

adapter.h
```C++
/// client will call it
class CTarget
{
public:
    virtual ~CTarget() = 0;
    virtual void Request() = 0;

protected:
    CTarget();
};


class CAdaptee;
// adapter 组合与继承完成适配
class CAdapter : public CTarget
{
public:
    ~CAdapter();
    CAdapter(CAdaptee* adaptee);
    void Request(); // adapter request

private:
    CAdaptee* m_pAdaptee;
};

class CAdaptee
{
public:
    ~CAdaptee();
     CAdaptee();
     void specificRequest(); // real request
};
```
客户程序
```C++
CAdaptee* adaptee = new CAdaptee();
CTarget* target = new CAdapter(adaptee);
target->Request();

delete adaptee;
delete target;
```
### 桥模式
现实世界的例子:
>考虑您拥有一个包含不同页面的网站，并且应该允许用户更改主题。 你会怎么做？ 为每个主题创建每个页面的多个副本，还是只是创建单独的主题并根据用户的喜好加载它们？ 桥接模式允许您执行第二个操作。

简而言之:
>桥模式是关于更喜欢组合而不是继承。实现细节从一个层次结构推送到另一个具有单独层次结构的对象。

维基百科：
>桥接模式是软件工程中使用的一种设计模式，其目的是“将抽象与其实现分离，以便两者可以独立变化”

`Favor Compsition Over Inheritance`， 组合优于继承，无论是 C++ STL库，还是一般设计中，都会有这种思想，handle/body 就是这种思想，抽象与实现分离。

代码示例：

```C++
class CAbstraction
{
public:
    virtual ~CAbstraction();
    virtual void operation() = 0;

protected:
    CAbstraction();
};

class CImplementor;
class CRefinedAbstraction : public CAbstraction
{
public:
    ~CRefinedAbstraction();
    CRefinedAbstraction(CImplementor* imp);
    void operation();

private:
    CImplementor* m_imp;
};

class CImplementor
{
public:
    virtual ~CImplementor();
    virtual void operationimp() = 0;

protected:
    CImplementor();
};

class CConcreteImplementorA : public CImplementor
{
public:
    ~CConcreteImplementorA();
    CConcreteImplementorA();
    void operationimp();
};

class CConcreteImplementorB : public CImplementor
{
public:
    ~CConcreteImplementorB();
    CConcreteImplementorB();
    void operationimp();
};
```
客户程序：
```C++
CImplementor* imp = new CConcreteImplementorB();
CAbstraction* abs = new CRefinedAbstraction(imp);
abs->operation();

delete imp;
delete abs;
```
### 组合模式
现实世界的例子：
> 每个组织都是由雇员组成的。每个雇员都有相同的特点，即有工资，有一些责任，可能向某人汇报，也可能不向某人汇报，可能有或可能没有下属等。

简而言之：
> 复合模式允许客户机以统一的方式处理各个对象。

维基百科：
> 在软件工程中，组合模式是一种分区设计模式。 组合模式描述了要以与对象的单个实例相同的方式对待一组对象。 组合的目的是将对象“组成”树状结构以表示部分整体层次结构。 实施组合模式可使客户统一对待单个对象和构图。

示例代码：
以我们的员工为例，这里我们有不同的员工类型。
composite.h文件
```C++
#include <vector>

class CEmployee
{
public:
    virtual ~CEmployee();
    virtual void SetSalary(int iSalary) = 0;
    virtual int GetSalary() = 0;
protected:
    CEmployee(int iSalary);

public:
    int m_iSalary;
};

class CDeveloper : public CEmployee
{
public:
    ~CDeveloper();
    CDeveloper(int iSalary);
    void SetSalary(int iSalary);
    int GetSalary();
};

class CDesign : public CEmployee
{
public:
    ~CDesign();
    CDesign(int iSalary);
    void SetSalary(int iSalary);
    int GetSalary();
};

class COrganization
{
public:
    ~COrganization();
    COrganization();
    void AddEmployee(CEmployee* pEmployee);
    void DelEmployee(CEmployee* pEmployee);
    int GetNetSalaries();

private:
    std::vector<CEmployee*> m_vecEmployee;
};
```

客户程序：
```C++
CEmployee* design = new CDesign(8000);
CEmployee* develop = new CDeveloper(12000);

COrganization organization;
organization.AddEmployee(design);
organization.AddEmployee(develop);

std::cout << "organization net salary : " << organization.GetNetSalaries() << std::endl;
organization.DelEmployee(design);
std::cout << "organization net salary : " << organization.GetNetSalaries() << std::endl;

delete design;
delete develop;
```

### 装饰者模式
现实世界的例子:
> 想象一下，您经营一家提供多种服务的汽车维修店。现在，您如何计算要收取的帐单？您选择一项服务，并动态地不断向其添加所提供服务的价格，直到获得最终成本为止。在这里，每种服务都是装饰器。

简而言之:
> 装饰器模式使您可以将对象包装在装饰器类的对象中，从而在运行时动态更改对象的行为。

维基百科:
> 在面向对象的编程中，装饰器模式是一种设计模式，它允许将行为静态或动态地添加到单个对象中，而不会影响同一类中其他对象的行为。装饰器模式通常可用于遵守“单一职责原则”，因为它允许功能在具有唯一关注区域的类之间进行划分。

示例代码：
decorato.h
```C++
 // abstract class
class CComponent
{
public:
    virtual ~CComponent();
    virtual void Operation() = 0;
protected:
    CComponent();
};


class CConcreteComponent : public CComponent
{
public:
    ~CConcreteComponent();
    CConcreteComponent();
    void Operation();
};

// abstract decorator
class CDecorator : public CComponent
{
public:
    ~CDecorator();
    CDecorator(CComponent* comp);
    virtual void Operation();

public:
    CComponent* m_Comp;
};

// decorator add behavior
class CConcreteDecorator : public CDecorator
{
public:
    ~CConcreteDecorator();
    CConcreteDecorator(CComponent* comp);
    void Operation();
    void AddBehavior();
};
```
客户程序：
```C++
CComponent* component = new CConcreteComponent();
CDecorator* decorator = new CConcreteDecorator(component);
decorator->Operation();

delete component;
delete decorator;
```
### 门面模式
现实世界的例子:
> 您如何打开计算机？ 你说“打电源按钮”！ 这就是您所相信的，因为您使用的是计算机在外部提供的简单界面，在内部它必须做很多事情才能实现。 与复杂子系统的这种简单接口是一个外观。

简而言之:
> 外观模式提供了到复杂子系统的简化接口。

维基百科:
> 外观是为大型代码（例如类库）提供简化接口的对象。

Fcade 模式在高层组合封装了子系统的接口，解耦了系统。隐藏了子系统的复杂性，使其更易使用。

代码示例：

facade.h
```C++
class CSubSystemA
{
public:
    ~CSubSystemA();
    CSubSystemA();
    void Operation();
};

class CSubSystemB
{
public:
    ~CSubSystemB();
    CSubSystemB();
    void Operation();
};

class CFacade
{
public:
    ~CFacade();
    CFacade();
    void OperationWrapper();

private:
    CSubSystemA* m_pSubSystemA;
    CSubSystemB* m_pSubSystemB;
};
```

客户程序：
```C++
CFacade* facade = new CFacade();
facade->OperationWrapper();

delete facade;
```
### 享元模式
现实世界的例子：
> 举个最简单的例子，网络联机下棋的时候，一台服务器连接了多个客户端（玩家），如果我们每个棋子都要创建对象，那一盘棋可能就有上百个对象产生，玩家多点的话，因为内存空间有限，一台服务器就难以支持了，所以这里要使用享元模式，将棋子对象减少到几个实例。下面给出享元模式的定义: 运用共享技术有效地支持大量细粒度的对象。


简而言之：
> 它用于通过与相似对象尽可能多地共享来最大程度地减少内存使用或计算开销。

维基百科：
> 在计算机编程中，flyweight是一种软件设计模式。 flyweight是通过与其他类似对象共享尽可能多的数据来最大程度减少内存使用的对象。当简单的重复表示使用不可接受的内存量时，这是大量使用对象的方法。

说到享元模式，第一个想到的应该就是池技术了，String常量池、数据库连接池、缓冲池等等都是享元模式的应用，所以说享元模式是池技术的重要实现方式。

代码示例：
flyweight.h
```C++
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

```
客户程序：
```C++
CFlyWeightFactory* fwFactory = new CFlyWeightFactory();
CFlyWeight* fw1 = fwFactory->GetFlyWeight("nihao");
fw1->Operation("qian");

CFlyWeight* fw2 = fwFactory->GetFlyWeight("zaijian");
fw2->Operation("qian");

CFlyWeight* fw3 = fwFactory->GetFlyWeight("nihao");
fw3->Operation("qian");

delete fwFactory;
```
### 代理模式
现实世界的例子：
> 您是否曾经使用过门禁卡穿过一扇门？可以通过多种方式打开该门，即可以使用门禁卡或按绕过安全保护的按钮将其打开。门的主要功能是打开，但是在其顶部添加了代理以添加一些功能。让我使用下面的代码示例更好地解释它。

简而言之:
> 使用代理模式，一个类表示另一个类的功能。

维基百科:
> 在最一般的形式上，代理是一个类，它充当与其他对象的接口。代理是客户端正在调用的包装器或代理对象，以访问幕后的真实服务对象。代理的使用可以简单地转发到真实对象，也可以提供其他逻辑。在代理中，可以提供额外的功能，例如在对实际对象的操作占用大量资源时进行缓存，或者在对实际对象的操作被调用之前检查先决条件。

Proxy Pattern最大的好处就是实现了逻辑和实现的彻底解耦。

代码示例：
proxy.h
```C++
class CSubject
{
public:
    virtual ~CSubject();
    virtual void Request() = 0;
protected:
    CSubject();
};

class CConcreteSubject : public CSubject
{
public:
    ~CConcreteSubject();
    CConcreteSubject();
    void Request();
};

class CProxy : public CSubject
{
public:
    ~CProxy();
    CProxy(CSubject* subject);
    void Request();

private:
    CSubject* m_pSubject;
};
```
客户程序：
```C++
CSubject* subject = new CConcreteSubject();
CProxy* proxy = new CProxy(subject);
proxy->Request();

delete subject;
delete proxy;
```

另一个示例是某种数据映射器实现。 例如，最近我使用这种模式为 `MongoDB` 制作了`ODM`（对象数据映射器），其中我在使用魔术方法 `__call（）` 时围绕 `mongo` 类编写了一个代理。 所有方法调用都被代理到原始`mongo`类，并且按原样返回检索到的结果，但是在`find`或`findOne`数据被映射到所需的类对象的情况下，将返回该对象而不是`Cursor`。

## 行为型设计模式
简而言之：
> 它与对象之间的职责分配有关。 它们与结构模式的不同之处在于它们不仅指定结构，而且还概述了它们之间消息传递/通信的模式。 换句话说，它们有助于回答“如何在软件组件中运行行为？”。

维基百科:
> 在软件工程中，行为设计模式是一种设计模式，用于标识对象之间的通用通信模式并实现这些模式。 通过这样做，这些模式增加了执行此通信的灵活性。

- [责任链模式](#责任链模式)
- [命令模式](#命令模式)
- [迭代器模式](#迭代器模式)
- [中介者模式](#中介者模式)
- [备忘录模式](#备忘录模式)
- [观察者模式](#观察者模式)
- [访问者模式](#访问者模式)
- [策略模式](#策略模式)
- [状态模式](#状态模式)
- [模板方法模式](#模板方法模式)

### 责任链模式
现实世界的例子：
> 例如，您的帐户中设置了三种付款方式（A，B和C）。 每个都有不同的数量。 A拥有100美元，B拥有300美元，C拥有1000美元，并且选择付款的先后顺序为A，然后B，然后C。您尝试购买价值210美元的商品。 使用责任链，首先将检查帐户A是否可以进行购买，如果可以，则进行购买并且该链将被破坏。 如果不是，则请求将前进到帐户B，如果是的链将被打破，则检查金额，否则请求将继续转发，直到找到合适的处理程序为止。 这里的A，B和C是链条的链接，整个现象就是责任链。

简而言之：
> 它有助于构建对象链。请求从一端进入，并不断地从一个对象移到另一个对象，直到找到合适的处理程序为止。

维基百科：
> 在面向对象的设计中，责任链模式是一种由命令对象的源和一系列处理对象组成的设计模式。每个处理对象都包含定义其可以处理的命令对象类型的逻辑。其余的将传递到链中的下一个处理对象。

代码示例：
翻译上面的帐户示例。 首先，我们有一个基本帐户，该帐户具有将帐户和某些帐户链接在一起的逻辑。

chainofresp.h 文件
```C++
#include <string>

class CAccount
{
public:
    virtual ~CAccount();
    virtual std::string GetAccountName() = 0;
    void SetNextHandle(CAccount* pHandle);
    void Pay(int iAmountToPay);
    bool CanPay(int iAmountToPay);

protected:
    CAccount(int iBalance);

private:
    int m_iBalance;
    CAccount* m_pHandle;
};

class CBank : public CAccount
{
public:
    CBank(int iBalance);
    ~CBank();
    std::string GetAccountName();
};

class CAliPay : public CAccount
{
public:
    CAliPay(int iBalance);
    ~CAliPay();
    std::string GetAccountName();
};
```

客户程序：
```C++
CAccount* bankaccount = new CBank(1000); // bank balance
CAccount* alipayaccount = new CAliPay(2000); // alipay balance

bankaccount->SetNextHandle(alipayaccount);
bankaccount->Pay(1500);

delete alipayaccount;
delete bankaccount;
```

输出:
> CBank Account can not pay it! use next account. 
> CAliPay Account can pay it! pay 1500 dollors

### 命令模式
现实世界的例子:
> 一个通用的示例是您在餐厅订购食物。您（即客户）要求服务员（例如，祈求者）带来一些食物（即命令），服务员将请求简单地转发给知道如何烹饪的厨师（即接收者）。另一个示例是您（即客户端）使用遥控器（“调用者”）打开（即命令）电视（即接收器）。

简而言之:
> 允许您将动作封装在对象中。该模式背后的关键思想是提供使客户端与接收器解耦的方法。

维基百科:
> 在面向对象的编程中，命令模式是一种行为设计模式，其中的对象用于封装以后执行动作或触发事件所需的所有信息。该信息包括方法名称，拥有方法的对象和方法参数的值。

代码示例：
command.h
```C++
class CReciever
{
public:
    ~CReciever();
    CReciever();

    void Action();
};

class CCommand
{
public:
    ~CCommand();
    virtual void Excute() = 0;
protected:
    CCommand();
};

class CConcreteCommand : public CCommand
{
public:
    ~CConcreteCommand();
    CConcreteCommand(CReciever* pRec);
    void Excute();

private:
    CReciever* m_pRec;
};

class CInvoker
{
public:
    ~CInvoker();
    CInvoker(CCommand* pCommand);

    void Invoke();
private:
    CCommand* m_pCommand;
};
```

客户程序:
```C++
CReciever* rec = new CReciever();
CCommand* command = new CConcreteCommand(rec);
CInvoker invoke(command);
invoke.Invoke();

delete rec;
delete command;
```

输出：
> CConcreteCommand::Excute() . CReciever::Action(). truely action

### 迭代器模式
现实世界的例子:
> 旧的收音机是迭代器的一个很好的例子，用户可以从某个频道开始，然后使用next或previous按钮遍历各个频道。或者以mp3播放器或电视机为例，您可以按next和previous按钮来浏览连续的频道，或者换句话说，它们都提供了一个界面来遍历各个频道、歌曲或广播电台。

简而言之：
> 它提供了一种访问对象元素而不公开底层表示的方法。

维基百科:
> 在面向对象编程中，迭代器模式是一种设计模式，其中迭代器用于遍历容器并访问容器的元素。迭代器模式将算法与容器分离；在某些情况下，算法必须特定于容器，因此无法分离。

代码示例:
iterator.h
```C++
#include <vector>
#include <string>
#include <iostream>

template<class Item>
class CIterator;

template<class Item>
class CAggregate
{
public:
    virtual ~CAggregate(){}
    virtual CIterator<Item>* CreateIterator() = 0;
    virtual void Pop() = 0;
    virtual void Push(const Item& value) = 0;
    virtual int Size() = 0;
    virtual Item& operator[](int iIndex) = 0;
};

template<class Item>
class CConcreteIterator;

template<class Item>
class CConcreteAggregate : public CAggregate<Item>
{
public:
    ~CConcreteAggregate()
    {

    }

    CConcreteAggregate()
    {

    }

    CIterator<Item>* CreateIterator()
    {
        return new CConcreteIterator<Item>(this);
    }

    void Pop()
    {
        m_vecItem.pop_back();
    }

    void Push(const Item& value)
    {
        m_vecItem.push_back(value);
    }

    int Size()
    {
        return m_vecItem.size();
    }

    Item& operator[](int iIndex)
    {
        return m_vecItem[iIndex];
    }

private:
    std::vector<Item> m_vecItem;
};

template<class Item>
class CIterator
{
public:
    virtual ~CIterator(){}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Item CurrentItem() = 0;
};

template<class Item>
class CConcreteIterator : public CIterator<Item>
{
public:
    ~CConcreteIterator(){}
    CConcreteIterator(CAggregate<Item>* aggregate) : m_Aggregate(aggregate), m_iCurIndex(0){}
    void First()
    {
        m_iCurIndex = 0;
    }

    void Next()
    {
        if(m_iCurIndex < m_Aggregate->Size())
        {
            ++m_iCurIndex;
        }
    }

    bool IsDone()
    {
        if(m_iCurIndex == m_Aggregate->Size())
        {
            return true;
        }

        return false;
    }

    Item CurrentItem()
    {
        return (*m_Aggregate)[m_iCurIndex];
    }

private:
    int m_iCurIndex;
    CAggregate<Item>* m_Aggregate;
};
```

客户程序：
```C++
CAggregate<std::string>* aggregate = new CConcreteAggregate<std::string>();
aggregate->Push("11");
aggregate->Push("22");
aggregate->Push("33");
aggregate->Push("44");
aggregate->Push("55");
aggregate->Push("66");

std::cout << "aggregate size: " << aggregate->Size() << std::endl;
std::cout << "aggregate element: ";
CIterator<std::string>* iter = aggregate->CreateIterator();

for(iter->First(); !iter->IsDone(); iter->Next())
{
    std::cout << iter->CurrentItem() << " ";
}

std::cout << std::endl;

delete iter;
delete aggregate;
```
整体类关系，容器类依赖迭代器类，对于迭代器来说，两者关系又是聚合关系。

### 中介者模式
现实世界的例子:
> 一个普遍的例子是，当你用手机和某人交谈时，你和他们之间有一个网络提供商，你的对话通过它而不是直接发送。在这种情况下，网络提供者是中介者。

简而言之:
> 中介模式添加一个第三方对象（称为中介）来控制两个对象（称为同事）之间的交互它有助于减少相互通信的类之间的耦合。因为现在他们不需要知道对方的实现。

维基百科:
> 在软件工程中，中介模式定义了一个对象，该对象封装了一组对象如何交互。这种模式被认为是一种行为模式，因为它可以改变程序的运行行为。

程序示例:
mediator.h
```C++
#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__

/***
 * This is mediator pattern
 * @brief mediator (encapsulates how a set of objects interact)
 * @time 2019/10/31
 * @authr yejy
 */

#include <string>

class CUser;
class CChatRoomMediator
{
public:
    virtual ~CChatRoomMediator();
    virtual void ShowMessage(CUser* user, std::string strMessge) = 0;

protected:
    CChatRoomMediator();
};

class CChatRoom : public CChatRoomMediator
{
public:
    ~CChatRoom();
    CChatRoom();
    void ShowMessage(CUser* user, std::string strMessge);
};


class CUser
{
public:
    virtual ~CUser();
    virtual void SendMessage(std::string strMessge) = 0;
    virtual std::string GetName() = 0;

protected:
    CUser(std::string strName, CChatRoomMediator* pChat);

public:
    std::string m_strName;
    CChatRoomMediator* m_pChat;
};

class CUserJohn : public CUser
{
public:
    ~CUserJohn();
    CUserJohn(std::string strName, CChatRoomMediator* pChat);
    void SendMessage(std::string strMessge);
    std::string GetName();
};

class CUserJame : public CUser
{
public:
    ~CUserJame();
    CUserJame(std::string strName, CChatRoomMediator* pChat);
    void SendMessage(std::string strMessge);
    std::string GetName();
};

#endif // __MEDIATOR_H__
```

客户程序：
```C++
CChatRoomMediator* mediator = new CChatRoom();

CUser* userJohn = new CUserJohn("john", mediator);
CUser* userJame = new CUserJame("jame", mediator);

userJohn->SendMessage("Hi there!");
userJame->SendMessage("Hey!");

delete mediator;
delete userJohn;
delete userJame;
```

打印:
```c++
[john]: Hi there!
[jame]: Hey!
```

### 备忘录模式
现实世界的例子：
> 以计算器（即发起者）为例，当您执行某个计算时，最后一个计算将保存在内存（即纪念品）中，这样您就可以返回它，并可能使用一些操作按钮（即管理员）恢复它。

简而言之：
> 备忘录模式是一种捕捉和存储对象当前状态的方式，它可以在以后以一种平滑的方式恢复。

维基百科:
> memento模式是一种软件设计模式，它提供了将对象还原到其先前状态（通过回滚撤消）的能力。

通常在需要提供某种撤消功能时很有用。

代码示例：
memento.h
```C++
#include <string>

class CEditMemento
{
public:
    CEditMemento(std::string strStatus);
    ~CEditMemento();

    std::string GetStatus();

private:
    std::string m_strStatus;
};

class CEdit
{
public:
    CEdit(std::string strStatus);
    ~CEdit();

    CEditMemento* CreateMemento();
    void restore(CEditMemento* pMemento);

    void PrintStatus();
    void SetStatus(std::string strStatus);

private:
    std::string m_strStatus;
};
```

客户程序：
```C++
CEdit* edit = new CEdit("past!");
edit->PrintStatus();

CEditMemento* memento = edit->CreateMemento();

edit->SetStatus("now!");
edit->PrintStatus();

edit->restore(memento);
std::cout << "restore:" << std::endl;
edit->PrintStatus();

delete memento;
delete edit;
```
代码输出：
```C++
edit status: past!
edit status: now!
restore:
edit status: past!
```

### 观察者模式

现实世界的例子：
> 一个很好的例子就是求职者订阅了一些招聘网站，只要有匹配的工作机会，他们就会收到通知。

简而言之:
> 定义对象之间的依赖关系，以便在对象更改其状态时通知其所有依赖项。

维基百科:
> 观察者模式是一种软件设计模式，在这种模式中，一个名为subject的对象维护其从属对象（称为观察者）的列表，并自动通知它们任何状态更改，通常是通过调用它们的一个方法。

程序示例：
observer.h
```C++
class CObserver;
class CObserverSubject
{
public:
    virtual ~CObserverSubject();
    virtual void Attach(CObserver* observer);
    virtual void Detach(CObserver* observer);
    virtual void Notify();
    virtual void SetStatus(std::string strStatus) = 0;
    virtual std::string GetStatus() = 0;

protected:
    CObserverSubject();

private:
    std::vector<CObserver*> m_vecObserver;
};

class CConcreteObserverSubject : public CObserverSubject
{
public:
    CConcreteObserverSubject();
    ~CConcreteObserverSubject();

    void SetStatus(std::string strStatus);
    std::string GetStatus();

private:
    std::string m_strStatus;
};


class CObserver
{
public:
    virtual ~CObserver();
    virtual void Update() = 0;
    std::string GetStatus();

protected:
    CObserver(std::string strStatus);

public:
    std::string m_strStatus;
};

class CConcreteObserverA : public CObserver
{
public:
    CConcreteObserverA(std::string strStatus);
    ~CConcreteObserverA();

    void Update();
};

class CConcreteObserverB : public CObserver
{
public:
    CConcreteObserverB(std::string strStatus);
    ~CConcreteObserverB();

    void Update();
};
```

客户程序:
```C++
CObserver* observerA = new CConcreteObserverA("excited");
CObserver* observerB = new CConcreteObserverB("sad");

CObserverSubject* observerSubject = new CConcreteObserverSubject();

observerSubject->Attach(observerA);
observerSubject->Attach(observerB);

observerSubject->SetStatus("sad");
observerSubject->Notify();

observerSubject->SetStatus("excited");
observerSubject->Notify();

observerSubject->Detach(observerA);
observerSubject->Notify();

delete observerB;
delete observerA;
delete observerSubject;
```

程序输出：
```C++
CConcreteObserverB Update() status: sad
CConcreteObserverA Update() status: excited
no observer match
```

### 访问者模式
现实世界的例子:
> 想想有人去迪拜。他们只需要一种方式（即签证）就可以进入迪拜。抵达后，他们可以自己来迪拜的任何地方参观，而无需申请许可或做一些腿部工作，以便参观这里的任何地方；只要让他们知道一个地方，他们就可以参观，访问者模式允许您这样做，它可以帮助您添加要访问的地方，以便他们可以访问尽可能多的，而不必做任何遗留工作。

简而言之:
> visitor 模式允许您向对象添加进一步的操作，而无需修改它们。

维基百科：
> 在面向对象编程和软件工程中，访问者设计模式是一种将算法与其操作的对象结构分离的方法。这种分离的实际结果是在不修改这些结构的情况下向现有对象结构添加新操作的能力。这是遵循开/闭原则的一种方法。


程序示例:
让我们举一个动物园模拟的例子，我们有几种不同的动物，我们必须让它们听起来像。让我们使用visitor模式来翻译这个。

visitor.h
```C++
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
```

客户程序：
```C++
CAniaml* monkey = new CMonkey();
CAniaml* Lion = new CLion();

CAniamlOperation* speak = new CSpeakOperation();
CAniamlOperation* jump = new CJumpOperation();

monkey->Accept(speak);
monkey->Accept(jump);

Lion->Accept(speak);
Lion->Accept(jump);

delete monkey;
delete Lion;
delete speak;
delete jump;
```

程序输出：
```C++
Ooh oo aa aa!
Jumped 20 feet high! on to the tree!
Roaaar!
Jumped 7 feet! Back on the ground!
```
### 策略模式
现实世界的例子：
> 以排序为例，我们实现了bubble sort，但是数据开始增长，bubble sort开始变得非常缓慢。为了解决这个问题，我们实现了快速排序。但现在，尽管快速排序算法在处理大型数据集方面做得更好，但在处理较小的数据集方面却很慢。为了处理这个问题，我们实现了一种策略，对于小数据集，将使用气泡排序，对于较大的，快速排序。

简而言之：
> 策略模式允许您根据情况切换算法或策略。

维基百科：
> 在计算机程序设计中，策略模式（也称为策略模式）是一种行为软件设计模式，它允许在运行时选择算法的行为。

程序示例：
strategy.h
```C++
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
```

客户程序：
```C++
CStrategy* strategyA = new CConcreteStrategyA();
CContext* context = new CContext(strategyA);
context->DoAction();

delete strategyA;
delete context;
```
程序输出:
```C++
Algorithm A
```

### 状态模式

### 模板方法模式