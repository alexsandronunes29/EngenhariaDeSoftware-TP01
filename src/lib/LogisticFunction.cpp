#include "LogisticFunction.hpp"
#include "Flow.hpp"
#include "FlowImpl.hpp"

using namespace std;


/* ------------------------------ object LogisticFunction ------------------------------ */

LogisticFunction::LogisticFunction(string name, System* source, System* target):FlowImpl(name, source, target){}
LogisticFunction::LogisticFunction(){
     name = "NULL";
    source = NULL;
    target = NULL;
}
LogisticFunction::~LogisticFunction(){}
LogisticFunction::LogisticFunction(Flow& obj){
    if(&obj == this) return;

    name = obj.get_name();
    source = obj.get_source();
    target = obj.get_target();
};

double LogisticFunction::function(){
	double p2 = this->get_target()->get_value();
	return 0.01*p2*(1-p2/70);
}

/* -------------------------- end of object LogisticFunction -------------------------- */