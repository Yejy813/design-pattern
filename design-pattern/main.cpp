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
#include "proxy.h"
#include "chainofresp.h"
#include "command.h"
#include "iterator.h"
#include "mediator.h"
#include "memento.h"
#include "observer.h"

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

    /// 13. proxy pattern
    CSubject* subject = new CConcreteSubject();
    CProxy* proxy = new CProxy(subject);
    proxy->Request();

    delete subject;
    delete proxy;


    /***
     * @brief Behavioral Design Patterns
     */


    /// 14. chain of responsibility pattern
    CAccount* bankaccount = new CBank(1000); // bank balance
    CAccount* alipayaccount = new CAliPay(2000); // alipay balance

    bankaccount->SetNextHandle(alipayaccount);
    bankaccount->Pay(1500);

    delete alipayaccount;
    delete bankaccount;

    /// 15. command pattern
    CReciever* rec = new CReciever();
    CCommand* command = new CConcreteCommand(rec);
    CInvoker invoke(command);
    invoke.Invoke();

    delete rec;
    delete command;

    /// 16. iterator pattern
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

    /// 17. mediator pattern
    CChatRoomMediator* mediator = new CChatRoom();

    CUser* userJohn = new CUserJohn("john", mediator);
    CUser* userJame = new CUserJame("jame", mediator);

    userJohn->SendMessage("Hi there!");
    userJame->SendMessage("Hey!");

    delete mediator;
    delete userJohn;
    delete userJame;

    /// 18. memento pattern
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

    /// 19. observer pattern
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
    delete subject;

    return 0;
}
