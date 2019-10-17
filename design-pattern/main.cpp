#include "simplefactory.h"
#include "factorymethod.h"
#include "abstractfactory.h"
#include "builder.h"
#include "prototype.h"
#include "singleton.h"
#include "adapter.h"
#include "bridge.h"
#include "composite.h"
#include "decorator.h"
#include "facade.h"
#include "flyweight.h"

int main()
{
    /***
     * @brief Creative Design Patterns
     */

    /// 1. simple factory pattern
    SIMPLE_FACTORY::CFactory factory;
    SIMPLE_FACTORY::CAbstractProduct* product = factory.createProduct(SIMPLE_FACTORY::PRODUCT_TYPE::PRODUCT_CONCRETE);
    product->operation();

    /// 2. factory method pattern
    FACTORY_METHOD::CAbstractFactory* mfactory = new FACTORY_METHOD::CConcreteFactory();
    FACTORY_METHOD::CAbstractProduct* mproduct = nullptr;
    // No need to change
    mproduct = mfactory->CreateProduct();
    delete mfactory;
    delete mproduct;

    /// 3. abstract factory pattern
    // A and B is related or interdependent
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

    /// 4. singleton pattern
    CSingleton& singletonA = g_refSingleton;
    CSingleton& singletonB = g_refSingleton;

    /// 5. prototype pattern
    CAbstractPrototype* prototypeA = new CConcretePrototypeA();
    prototypeA->SetStatus(77);
    CAbstractPrototype* prototypeB = prototypeA->clone();
    prototypeB->PrintStatus();

    /// 6. builder pattern
    CAbstractBuild* build = new CConcreteBuild();
    // No need to change
    CDirector director;
    director.SetBuild(build);
    CProduct* bproduct = director.Construct(); // construct step and create object
    bproduct->show();

    delete bproduct;
    delete build;


    /***
     * @brief Structural Design Patterns
     */

    /// 7. adapter pattern
    CAdaptee* adaptee = new CAdaptee();
    CTarget* target = new CAdapter(adaptee);
    target->Request();

    delete adaptee;
    delete target;

    /// 8. bridge pattern
    CImplementor* imp = new CConcreteImplementorB();
    CAbstraction* abs = new CRefinedAbstraction(imp);
    abs->operation();

    delete imp;
    delete abs;

    /// 9. composite pattern
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

    /// 10. decorator pattern
    CComponent* component = new CConcreteComponent();
    CDecorator* decorator = new CConcreteDecorator(component);
    decorator->Operation();

    delete component;
    delete decorator;

    /// 11. facade pattern
    CFacade* facade = new CFacade();
    facade->OperationWrapper();

    delete facade;

    /// 12. flyweight pattern
    CFlyWeightFactory* fwFactory = new CFlyWeightFactory();
    CFlyWeight* fw1 = fwFactory->GetFlyWeight("nihao");
    fw1->Operation("qian");

    CFlyWeight* fw2 = fwFactory->GetFlyWeight("zaijian");
    fw2->Operation("qian");

    CFlyWeight* fw3 = fwFactory->GetFlyWeight("nihao");
    fw3->Operation("qian");

    delete fwFactory;

    /***
     * @brief Behavioral Design Patterns
     */

    return 0;
}
