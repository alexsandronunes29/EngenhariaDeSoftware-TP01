/*Created By Alexsandro Nunes(17.2.5878)
API-Disciplina Engengaria de Software I-UFOP*- fabrica e componetização*/

#include "Model.hpp"
#include "ModelImpl.hpp"
#include "FlowImpl.hpp"
#include "SystemImpl.hpp"
#include "Flow.hpp"
#include "ExponentialFunction.hpp"
#include "LogisticFunction.hpp"
#include "System.hpp"


using  namespace std;

ModelImpl:: ModelImpl(){
	name = "NULL";
    flows.clear();
    systems.clear();
}

ModelImpl::ModelImpl(string name): name(name){}

ModelImpl::ModelImpl(const string name, vector<Flow*> &flows, vector<System*> &systems) : name(name), flows(flows), systems(systems) {}

ModelImpl::ModelImpl(Model& copy){
	if(this != &copy){
		name = ((ModelImpl)copy).get_name();
		if(	flows == ((ModelImpl)copy).flows){}
		else{
			vector<int>auxiliar;
				for(auto it:flows)
					if(it!=NULL)
						delete (FlowImpl*)it;

				ExponentialFunction* exp;
				LogisticFunction* log;
				for (auto it :((ModelImpl)copy).flows){
					if((exp= dynamic_cast<ExponentialFunction*>(it))!=NULL)
						add(new ExponentialFunction(exp->get_name(),exp->get_source(),exp->get_target()));

						else if((log=dynamic_cast<LogisticFunction*>(it))!=NULL)
						add(new LogisticFunction(log->get_name(),log->get_source(),log->get_target()));
				}	
		}
		if(systems == ((ModelImpl)copy).systems){}
		else{
				for(auto it: systems){
					SystemImpl* del=dynamic_cast<SystemImpl*>(it);

					if(del=NULL)
						delete del;

				}
				for (auto it: ((ModelImpl)copy).systems)
				add(new SystemImpl(it->get_name(),it->get_value()));

		}
	}
}

ModelImpl::~ModelImpl(){}

string ModelImpl::get_name(){
	return name;
}


System* ModelImpl::createSystem(string id, double qtd){
	System* sys=new SystemImpl(id,qtd);
	add(sys);
	return sys;
}

ModelImpl* ModelImpl::instance=NULL;

//Model* Model::instance=NULL;


bool ModelImpl::deleteSystem(System *del){

	System* aux=getSystem(del->get_name());
		if (aux!=NULL){
			removeSystem(del->get_name());
			delete(SystemImpl*)aux;
			return true;
		}
		return false;
}

Model* Model::createModel(string id){
	
	return ModelImpl::createModel(id); 

}

/*Model* ModelImpl::createModel(string id){
	if (instance==NULL){
		Model* m= new ModelImpl(id);
		add(m);
		return m; 
	}
	else{
		return instance;
	}
}*/
Model* ModelImpl::createModel(string id){
	if(instance==NULL){
		instance=new ModelImpl(id);
	}
	else (instance =NULL);
		instance=new ModelImpl(id);
return instance;

}
bool Model::deleteModel(Model*model ){
	return ModelImpl::deleteModel(model); 

}

bool ModelImpl::deleteModel(Model*model){
	if(model!=NULL){
		delete(ModelImpl*)model;
		return true;
	}
	return false;
}

void ModelImpl::set_name(string name){
	this->name = name;
}


void ModelImpl::add(Flow* flow){
	flows.push_back(flow);
}

void ModelImpl::add(System* system){
	systems.push_back(system);
}




bool ModelImpl::removeFlow(string name){
	for(unsigned int i=0; i<flows.size(); i++)
		if(flows[i]->get_name() == name){
			flows.erase(flows.begin()+i);
			return true;
		}

	return false;
}

bool ModelImpl::removeSystem(string name){
	for(unsigned int i=0; i<systems.size(); i++)
		if(systems[i]->get_name() == name){
			systems.erase(systems.begin()+i);
			return true;
		}

	return false;
}

Flow* ModelImpl::getFlow(string name){
	for(unsigned int i=0; i<flows.size(); i++)
		if(flows[i]->get_name() == name){
			return flows[i];
		}

	return NULL;
}

System* ModelImpl::getSystem(string name){
	for(unsigned int i=0; i<systems.size(); i++)
		if(systems[i]->get_name() == name){
			return systems[i];
		}

	return NULL;
}

int ModelImpl::get_flowSize(){
	return flows.size();
}

int ModelImpl::get_systemSize(){
	return systems.size();
}

void ModelImpl::execute(double start, double finish, double increment){

    vector<Flow*>::iterator Itflow;

    System* source;
    System* target;

    vector<double> results;

    int i = 0;
    int j = 0;
    double initial = 0.0;

    for (int i = 0; i < flows.size(); i++){
        results.push_back(initial);
    }

    for(int index = start; index <= finish; index+=increment){
        i = 0;
        Itflow = flows.begin();
        while (i != flows.size()){
            results[i] = (*Itflow)->function();
            Itflow++;
            i++;
        }
        j = 0;
        while (j != flows.size()){
            source = flows[j]->get_source();
            source->set_value(source->get_value() - results[j]);

            target= flows[j]->get_target();
            target->set_value(target->get_value() + results[j]);
            j++;
        }
    }
    
}


/*void ModelImpl::execute(int time){
	 int count = 0;
	cout<<"voltou ao inicio"<<endl;
	for(int i = 0; i < time; i++){
		vector<double> results;
		cout<<"test"<<endl;
		for(vector<Flow*>::iterator flow = flows.begin(); flow != flows.end(); ++flow){
			results.push_back((*flow)->function());
			cout<<" "<< endl;
			
		}

			cout<<"vai entrar no for"<<endl;
		for(vector<Flow*>::iterator flow = flows.begin(); flow != flows.end(); ++flow){

			
			(*flow)->get_target()->set_value((*flow)->get_target()->get_value() + results[count]);
			    cout<<"aqui chega"<<endl;
				//(*flow)->get_source()->set_value((*flow)->get_source()->get_value() - results[count]);
					cout<<"agora saiu"<<endl;
								count++;
		}

		for(vector<System*>::iterator system = systems.begin(); system != systems.end(); ++system){
			cout<<"entrou no vetor de system"<<endl;
			//(*system)->set_value((*system)->get_value());
			cout<<"saiu do vetor de system"<<endl;
		}
		cout<<"limpando"<<endl;
		cout<<count<<endl;
		results.clear();
		count = 0;
		cout<<count<<endl;
	}
	cout<<"saiu"<<endl;
}*/

bool ModelImpl::operator==(Model& object){
	if(name!=(object).get_name())
		return false;

	int count = 0;

	for(auto it :flows){
		if(it ==((ModelImpl) object).flows[count]){}

		else
			return false;
		count++;
	}

	count = 0;

	for(auto it :systems){
		if(it == ((ModelImpl)object).systems[count]){}
		
		else
			return false;
		
		count++;
	}

	return true;
}	

Model& ModelImpl::operator=(Model& copy){
	if(this == &copy)
		return *this;

	name = ((ModelImpl)copy).get_name();

	if (flows == ((ModelImpl)copy).flows){}
	else{
		vector<int>auxiliar;
		
		for(auto it :flows)
			if(it!=NULL)
				delete it;
				flows.clear();
				ExponentialFunction* exp;
				LogisticFunction* log;

				for(auto it: ((ModelImpl)copy).flows){
					if((exp=dynamic_cast<ExponentialFunction*>(it))!=NULL)
						add( new ExponentialFunction(*exp));
					
					else if((log= dynamic_cast<LogisticFunction*>(it))!=NULL)
						add(new LogisticFunction(*log));
				}

	}

	if(systems ==((ModelImpl)copy).systems){}
	else{
		for(auto del : systems)
			if(del!=NULL)
			delete del;
		systems.clear();	

		for(auto it: ((ModelImpl)copy).systems)
			add(new SystemImpl(*it));

	}

	
	return *this;
}