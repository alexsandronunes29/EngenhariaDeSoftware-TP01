#include "unit_Flow.hpp"

void unit_Flow_constructor(){
    System* system1 = new SystemImpl();
    System* system2 = new SystemImpl();

    // exponential
    Flow* flowExp1 = new ExponentialFunction();
    assert(flowExp1->get_name() == "NULL");
    assert(flowExp1->get_source() == NULL);
    assert(flowExp1->get_target() == NULL);

    Flow* flowExp2 = new ExponentialFunction("teste", system1, system2);
    assert(flowExp2->get_name() == "teste");
    assert(flowExp2->get_source() == system1);
    assert(flowExp2->get_target() == system2);

    Flow* flowExp3 = new ExponentialFunction(*flowExp2);
    assert(*flowExp3 == *flowExp2);

    // logistic
    Flow* flowLogist1 = new LogisticFunction();
    assert(flowLogist1->get_name() == "NULL");
    assert(flowLogist1->get_source() == NULL);
    assert(flowLogist1->get_target() == NULL);

    Flow* flowLogist2 = new LogisticFunction("teste", system1, system2);
    assert(flowLogist2->get_name() == "teste");
    assert(flowLogist2->get_source() == system1);
    assert(flowLogist2->get_target() == system2);

    Flow* flowLogist3 = new LogisticFunction(*flowLogist2);
    assert(*flowLogist3 == *flowLogist2);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowExp2;
    delete flowExp3;
    delete flowLogist1;
    delete flowLogist2;
    delete flowLogist3;

};

void unit_Flow_destructor(){};

void unit_Flow_get_name(){
    System* system1 = new SystemImpl();
    System* system2 = new SystemImpl();

    // exponential
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    assert(flowExp1->get_name() == "teste");

    // logistic
    Flow* flowLogist1 = new LogisticFunction("teste", system1, system2);
    assert(flowLogist1->get_name() == "teste");

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;

}

void unit_Flow_set_name(){
    // exponential
    Flow* flowExp1 = new ExponentialFunction();
    flowExp1->set_name("test");
    assert(flowExp1->get_name() == "test");

    // logistic
    Flow* flowLogist1 = new LogisticFunction();
    flowLogist1->set_name("test");
    assert(flowLogist1->get_name() == "test"); 

    delete flowExp1;
    delete flowLogist1;

}

void unit_Flow_get_source(){
    System* system1 = new SystemImpl();
    System* system2 = new SystemImpl();

    // exponential
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    assert(flowExp1->get_source() == system1);

    // logistic
    Flow* flowLogist1 = new LogisticFunction("teste", system1, system2);
    assert(flowLogist1->get_source() == system1);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;

}

void unit_Flow_set_source(){
    System* system1 = new SystemImpl();
    System* system2 = new SystemImpl();
    System* system3 = new SystemImpl();

    // exponential
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    flowExp1->set_source(system3);
    assert(flowExp1->get_source() == system3);

    // logistic
    Flow* flowLogist1 = new LogisticFunction("teste", system1, system2);
    flowLogist1->set_source(system3);
    assert(flowLogist1->get_source() == system3);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;

}

void unit_Flow_get_target(){
    System* system1 = new SystemImpl();
    System* system2 = new SystemImpl();

    // exponential
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    assert(flowExp1->get_target() == system2);

    // logistic
    Flow* flowLogist1 = new LogisticFunction("teste", system1, system2);
    assert(flowLogist1->get_target() == system2);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;

}

void unit_Flow_set_target(){
    System* system1 = new SystemImpl();
    System* system2 = new SystemImpl();
    System* system3 = new SystemImpl();

    // exponential
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    flowExp1->set_target(system3);
    assert(flowExp1->get_target() == system3);

    // logistic
    Flow* flowLogist1 = new LogisticFunction("teste", system1, system2);
    flowLogist1->set_target(system3);
    assert(flowLogist1->get_target() == system3);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;

}


void unit_Flow_operator_assignment(){
    System* system1 = new SystemImpl();
    System* system2 = new SystemImpl();

     // exponential
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    Flow* flowExp2 = new ExponentialFunction();
    *flowExp2 = *flowExp1;
    assert(*flowExp1 == *flowExp2);

    // logistic
    Flow* flowLogist1 = new LogisticFunction("teste", system1, system2);
    Flow* flowLogist2 = new LogisticFunction();
    *flowLogist2 = *flowLogist1;
    assert(*flowLogist1 == *flowLogist2);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowExp2;
    delete flowLogist1;
    delete flowLogist2;

}

void unit_Flow_execute(){
    System* system1 = new SystemImpl(100.0);
    System* system2 = new SystemImpl(0.0);
    Model* model = new ModelImpl();

    // exponential
    Flow* flowExp1 = new ExponentialFunction("teste", system1, system2);
    model->add(system1);
    model->add(system2);
    model->add(flowExp1);

    /*model->execute(100);

    assert(abs(system1->get_value() - 36.6032) <  0.0001f);
    assert(abs(system2->get_value() - 63.3968) <  0.0001f);*/

    // logistic
    system1->set_value(100.0);
    system2->set_value(10.0);
    Flow* flowLogist1 = new LogisticFunction("teste", system1, system2);
    model->add(system1);
    model->add(system2);
    model->add(flowLogist1);

    /*model->execute(100);

    assert(abs(system1->get_value() - 88.2167) <  0.0001f);
    assert(abs(system2->get_value() - 21.7834) <  0.0001f);*/

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
    delete model;

}

void run_unit_test_Flow(){
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_get_name();
    unit_Flow_set_name();
    unit_Flow_get_source();
    unit_Flow_set_source();
    unit_Flow_get_target();
    unit_Flow_set_target();
    unit_Flow_operator_assignment();
    unit_Flow_execute();
}

