
//Created By Alexsandro Nunes(17.2.5878)
//API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas 


#ifndef Flow_hpp
#define Flow_hpp
#include "System.hpp"


using namespace std;

class Flow{
       
public:
        
        virtual string get_name()  =0;
        virtual void set_name(string)=0;

        virtual void insert( System*,  System*)=0;
        virtual System* get_source()= 0;
        virtual void set_source(System*)= 0;
        virtual System* get_target()= 0;
        virtual void set_target(System*)= 0;
        virtual double function()=0;

        virtual bool operator==( Flow&)= 0;
        virtual Flow& operator=(Flow&)=0;

};

#endif
