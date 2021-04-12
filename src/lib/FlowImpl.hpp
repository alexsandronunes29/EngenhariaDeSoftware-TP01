//Created By Alexsandro Nunes(17.2.5878)
//API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas 


#ifndef FlowImpl_hpp
#define FlowImpl_hpp
#include "Flow.hpp"
#include "System.hpp"


using namespace std;

class FlowImpl:public Flow{
        protected:
        string name;
        System*  source;
        System* target;

public:
        FlowImpl();
        FlowImpl(string,System*,System *);
        FlowImpl(Flow&);

        virtual ~FlowImpl();

        string get_name();
        void set_name(string);

        void insert(System*,System*);
        System* get_source();
        void set_source(System*);
        
        System* get_target();
        void set_target(System*);

        virtual double function()=0;

        bool operator==(Flow&);
        Flow& operator=(Flow&);


};

#endif
