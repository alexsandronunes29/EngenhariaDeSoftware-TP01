/*Created By Alexsandro Nunes(17.2.5878)
API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas */

#ifndef Model_hpp
#define Model_hpp

#include <string>
#include <ostream>
#include <algorithm>
#include <vector>

#include "Flow.hpp"
#include "System.hpp"

using namespace std;

class Model{
private:
   // static Model* instance;
public:
    virtual ~Model(){};
   static Model* createModel(string); 
   static bool deleteModel(Model*);
   
    static void add(Model*);
    virtual System* createSystem(string, double)=0; 
    virtual bool deleteSystem(System*)=0;

    template <typename T_Flow>Flow* createFlow(string name,System*source,System*target){
        Flow* flow=new T_Flow(name,source,target);
        add(flow);
        return flow;
    }

    template <typename T_Flow> bool deleteFlow(Flow* delet){
       
        Flow* aux=getFlow(delet->get_name());

        if(aux!=NULL){
           delete (T_Flow*)aux;
            return true;
        }
        return false;
    }

    virtual  string get_name()  =0;
    virtual void set_name( string)=0;

    virtual void add( Flow*)=0;
    virtual  void add( System*)=0;

    virtual bool removeFlow ( string)=0;
    virtual bool removeSystem( string)=0;

    virtual  Flow* getFlow( string)=0;
    virtual  System* getSystem( string)=0;
    virtual  int get_flowSize()=0;
    virtual  int get_systemSize()=0;

    virtual void execute( double,double,double)=0;

    virtual bool operator ==( Model&)  =0;

    virtual Model& operator=( Model&) =0;
};
#endif
