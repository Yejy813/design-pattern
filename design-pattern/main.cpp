#include "simplefactory.h"

int main()
{
    /// �򵥹���ģʽ
    CFactory factory;
    CAbstractProduct* product = factory.createProduct(PRODUCT_TYPE::PRODUCT_CONCRETE);
    product->operation();

    return 0;
}
