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


## 行为型设计模式
