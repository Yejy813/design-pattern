#include "simplefactory.h"

int main()
{
    /// simple factory pattern
    CFactory factory;
    CAbstractProduct* product = factory.createProduct(PRODUCT_TYPE::PRODUCT_CONCRETE);
    product->operation();

    /// factory method pattern


    return 0;
}
