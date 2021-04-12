/*Created By Alexsandro Nunes(17.2.5878)
API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas */

#ifndef ModelImpl_hpp
#define ModelImpl_hpp

#include <string>
#include <vector>
#include "Flow.hpp"
#include "System.hpp"
#include "Model.hpp"

using namespace std;

class ModelImpl:public Model{
private:
static ModelImpl* instance;
protected:    
    string name;
    vector <Flow*> flows;
    vector <System*> systems;
    static vector<Model*> models;
    
    
   
    private:
     Model& operator=(Model&); 
     bool operator ==(Model&);
    void add(Flow*);
    void add(System*);
   static  void add(Model*);

   

public:
    ModelImpl(string);
    ModelImpl(const string name, vector<Flow*> &flows, vector<System*> &systems);
    ModelImpl();
    ModelImpl(Model&);
   virtual ~ModelImpl();

    static Model* createModel(string);
    static bool deleteModel(Model*);

    System* createSystem(string,double);
    bool deleteSystem(System*);

    string get_name();
    void set_name(string);

    bool removeFlow (string);
    bool removeSystem(string);

    Flow* getFlow(string);
    System* getSystem(string);
    int get_flowSize();
    int get_systemSize();

    void execute(double,double,double);
   
  
};
#endif
