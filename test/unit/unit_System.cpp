#include "unit_System.hpp"


void unit_System_constructor(){
    System* system1 = new SystemImpl();    
    assert(system1->get_name() == "NULL");
    assert(system1->get_value() == 0);

    System* system2 = new SystemImpl("test", 1);
    assert(system2->get_name() == "test");
    assert(system2->get_value() == 1);

    System* system3 = new SystemImpl(*system2);
    assert(*system3 == *system2);

    delete system1;
    delete system2;
    delete system3;
};

void unit_System_destructor(){};

void unit_System_get_value( void){
    System* system1 = new SystemImpl(10);
    assert(system1->get_value() == 10);

    delete system1;
}

void unit_System_set_value( void ) {
    System* system1 = new SystemImpl();
    system1->set_value(10);
    assert(system1->get_value() == 10);

    delete system1;
}

void unit_System_get_name(){
    System* system1 = new SystemImpl("test");
    assert(system1->get_name() == "test");

    delete system1;
}

void unit_System_set_name(){
    System* system1 = new SystemImpl();
    system1->set_name("test");
    assert(system1->get_name() == "test");

    delete system1;    
}

void unit_System_operator_assignment(){
    System* system1 = new SystemImpl("test", 1);
    System* system2 = new SystemImpl();
    *system2 = *system1;
    assert(*system2 == *system1);

    delete system1;
    delete system2;
}


void run_unit_test_System(){
    unit_System_constructor();
    unit_System_destructor();
    unit_System_get_value();
    unit_System_set_value();
    unit_System_get_name();
    unit_System_set_name();
    unit_System_operator_assignment();
}