#include "simplefactory.h"
#include "factorymethod.h"
#include "abstractfactory.h"

int main()
{
    /// 1. simple factory pattern
    SIMPLE_FACTORY::CFactory factory;
    SIMPLE_FACTORY::CAbstractProduct* product = factory.createProduct(SIMPLE_FACTORY::PRODUCT_TYPE::PRODUCT_CONCRETE);
    product->operation();

    /// 2. factory method pattern
    FACTORY_METHOD::CAbstractFactory* mfactory = new FACTORY_METHOD::CConcreteFactory();
    FACTORY_METHOD::CAbstractProduct* mproduct = nullptr;
    /// No need to change
    mproduct = mfactory->CreateProduct();
    delete mfactory;
    delete mproduct;

    /// 3. abstract factory pattern
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

    /// 4. builder

    return 0;
}
