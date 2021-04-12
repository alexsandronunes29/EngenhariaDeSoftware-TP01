/*Created By Alexsandro Nunes(17.2.5878)
API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas */

#ifndef System_hpp
#define System_hpp

#include <string>
#include <ostream>

using namespace std;


class System{
    public:
    virtual ~System(){}
    virtual string get_name()=0 ;
    virtual void set_name( string)=0;
    virtual double get_value()=0;
    virtual void set_value( double)=0;

    virtual bool operator==( System&)=0;
    virtual System& operator=( System&)=0;
        
};

#endif

