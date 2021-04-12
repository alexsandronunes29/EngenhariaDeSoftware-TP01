#include "unit_Model.hpp"
using namespace std;
void unit_Model_constructor(){
    Model* model1 = new ModelImpl();
    assert(model1->get_name() == "NULL");
    assert(model1->get_flowSize() == 0);
    assert(model1->get_systemSize() == 0);

    vector<Flow*> vectorFlow;
    Flow* flowExp1 = new ExponentialFunction();
    vectorFlow.push_back(flowExp1);

    vector<System*> vectorSystem;
    System* system1 = new SystemImpl();
    vectorSystem.push_back(system1);

    Model* model2 = new ModelImpl("teste", vectorFlow, vectorSystem);
    assert(model2->get_name() == "teste");
    assert(model2->get_flowSize() == 1);
    assert(model2->get_systemSize() == 1);

    delete model1;
    delete model2;
    delete flowExp1;
    delete system1;
    vectorFlow.clear();
    vectorSystem.clear();

};

void unit_Model_destructor(){};

void unit_Model_get_name(){
    Model* model1 = new ModelImpl();
    assert(model1->get_name() == "NULL");

    delete model1;

}

void unit_Model_set_name(){
    Model* model1 = new ModelImpl();
    model1->set_name("test");
    assert(model1->get_name() == "test");

    delete model1;

}

void unit_Model_add(){
    Model* model1 = new ModelImpl();
    System* system1 = new SystemImpl("system1");
    System* system2 = new SystemImpl("system2");    
    Flow* flowExp1 = new ExponentialFunction("flowExp", system1, system2);
    
    model1->add(system1);
    
    assert(model1->get_systemSize() == 1);
    

    assert(model1->getSystem("system1") == system1);

   model1->add(flowExp1);

   assert(model1->get_flowSize() == 1);
 

   assert(model1->getFlow("flowExp") == flowExp1);
   

    delete model1;
    delete system1;
    delete system2;
    delete flowExp1;
    

}

void unit_Model_remove(){
    
    Model* model1 = new ModelImpl();
    System* system1 = new SystemImpl("system1");

    model1->add(system1);
     

    assert(model1->get_systemSize() == 1);
   

    model1->removeSystem("system1");
     

    assert(model1->getSystem("system1") != system1);
     
    assert(model1->get_systemSize() == 0);  
    

    delete model1;
    delete system1;
     

}

void unit_Model_execute(){
   
    System* system1 = new SystemImpl(100.0);
    System* system2 = new SystemImpl(0.0);
    Model* model = new ModelImpl();

    // exponential
    
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    model->add(system1);
    model->add(system2);
    model->add(flowExp1);
     

   model->execute(0,99,1);
     

   assert(abs(system1->get_value() - 36.6032) <  0.0001);
    
    assert(abs(system2->get_value() - 63.3968) <  0.0001);
     

    delete system1;
    delete system2;
    delete flowExp1;
    delete model;
     
}

void run_unit_test_Model(){
    
    unit_Model_constructor();
    
    unit_Model_destructor();
    
    unit_Model_get_name();
    
    unit_Model_set_name();
    
    unit_Model_add();
    
    unit_Model_remove();
    
    unit_Model_execute();
    
}