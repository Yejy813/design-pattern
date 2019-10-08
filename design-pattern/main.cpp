#include "simplefactory.h"
#include "factorymethod.h"

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


    return 0;
}
