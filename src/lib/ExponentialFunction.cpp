#include "ExponentialFunction.hpp"
#include "FlowImpl.hpp"

using namespace std;
/* ---------------------------- object ExponentialFunction ----------------------------- */

ExponentialFunction::ExponentialFunction(string name, System* source, System* target): FlowImpl(name, source, target){}
ExponentialFunction::ExponentialFunction(){
    name = "NULL";
    source = NULL;
    target = NULL;
}
ExponentialFunction::~ExponentialFunction(){}
   
ExponentialFunction::ExponentialFunction(Flow& obj){
    if(&obj == this) return;

    name = obj.get_name();
    source = obj.get_source();
    target = obj.get_target();
};

double ExponentialFunction:: function(){
	return this->get_source ()->get_value() * 0.01;
}

/* ------------------------- end of object ExponentialFunction ------------------------- */