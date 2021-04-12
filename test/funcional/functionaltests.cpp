
#include <cassert>
#include <cmath>
#include<iostream>
#include "../../src/lib/Model.hpp"
#include "functionaltests.hpp"
using namespace std;

void functionalTest_exponential(){
	Model* model=Model::createModel("functional exponencial test");
	
	System* pop1 = model->createSystem("pop1", 100.0);
	System* pop2 = model->createSystem("pop2", 0.0);
	
	assert(pop1->get_value()==100);
	assert (pop2->get_value()==0.0);

	assert(!(pop1==pop2));
    
	Flow* exponential = model->createFlow<ExponentialFunction>("exponencial", pop1, pop2);

	model->execute(0,99,1);
	

	assert(fabs(model->getFlow("exponencial")->get_source()->get_value() - 36.6032) < 0.001f);
	
	assert(fabs(model->getFlow("exponencial")->get_target()->get_value() - 63.3968) < 0.001f);
	

	model->deleteSystem(pop2);
	model->deleteSystem(pop1);

	model->deleteFlow<ExponentialFunction>(exponential);
 	Model::deleteModel(model);
		
}

void functionalTest_Logistic(){
	 Model* model=Model::createModel("funcional Logistic test ");

	System* p1 = model->createSystem("p1", 100);
	System* p2 = model->createSystem("p2", 10);

	Flow* logistic = model->createFlow<LogisticFunction> ("logistic", p1, p2);


	model->execute(0,99,1);
	
	assert(fabs(model->getFlow("logistic")->get_source()->get_value() - 88.2167) < 0.0001f);
	
	assert(fabs(model->getFlow("logistic")->get_target()->get_value() - 21.7834) < 0.0001f);
	

    model->deleteSystem(p2);
	 model->deleteSystem(p1);
     model->deleteFlow<LogisticFunction>(logistic);
	Model::deleteModel(model);
	
	
}

void functionalTest_complete(){
Model* model=Model::createModel("functional complete test");
	
	System* Q1 = model->createSystem("Q1", 100.0);
	System* Q2 = model->createSystem("Q2", 0.0);
	System* Q3 = model->createSystem("Q3", 100.0);
	System* Q4 = model->createSystem("Q4", 0.0);
	System* Q5 = model->createSystem("Q5", 0.0);	
	
	Flow* f = model->createFlow<ExponentialFunction>("f", Q1, Q2);
	Flow* t = model->createFlow<ExponentialFunction>("t", Q2, Q3);
	Flow* u = model->createFlow<ExponentialFunction>("u", Q3, Q4);
	Flow* v = model->createFlow<ExponentialFunction>("v", Q4, Q1);
	Flow* g = model->createFlow<ExponentialFunction>("g", Q1, Q3);
	Flow* r = model->createFlow<ExponentialFunction>("r", Q2, Q5);
	
	model->execute(0,99,1);
	
	assert(fabs((Q1->get_value()) - 31.8513) < 0.0001f);
	
	assert(fabs((Q2->get_value()) - 18.4003) < 0.0001f);
	
	assert(fabs((Q3->get_value()) - 77.1143) < 0.0001f);

	assert(fabs((Q4->get_value()) - 56.1728) < 0.0001f);
	
	assert(fabs((Q5->get_value() - 16.4612)) < 0.0001f);
	
	
	

	model->deleteSystem(Q1) ;

	model->deleteSystem(Q2) ;
	
	model->deleteSystem(Q3);
	
	model->deleteSystem(Q4);

	model->deleteSystem(Q5) ;
	
	
	
	model->removeFlow("f") ;
	
	model->removeFlow("t") ; 
	
	model->removeFlow("u") ; 
	
	model->removeFlow("v");

	model->removeFlow("g");

	model->removeFlow("r");

	Model::deleteModel(model);
	
}