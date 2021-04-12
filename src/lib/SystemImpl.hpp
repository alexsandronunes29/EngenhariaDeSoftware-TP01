/*Created By Alexsandro Nunes(17.2.5878)
API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas */

#ifndef SystemImpl_hpp
#define SystemImpl_hpp
#include "System.hpp"
#include <string>


class SystemImpl:public System{
   protected:
    string name;
    double value;
    public:
    SystemImpl ();
    SystemImpl (string , double);
    SystemImpl (string);
    SystemImpl (double);
    SystemImpl(System&);
    virtual ~SystemImpl();

    string get_name() ;
    void set_name(string);
    double get_value();
    void set_value(double);

    bool operator==(System&);
    System& operator=(System&);
        
};

#endif

