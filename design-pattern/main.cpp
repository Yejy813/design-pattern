#include "simplefactory.h"

int main()
{
    /// 简单工厂模式
    CFactory factory;
    CAbstractProduct* product = factory.createProduct(PRODUCT_TYPE::PRODUCT_CONCRETE);
    product->operation();

    return 0;
}
