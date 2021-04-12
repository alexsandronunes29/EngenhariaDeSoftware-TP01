/*Created By Alexsandro Nunes(17.2.5878)
API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas */

#include "SystemImpl.hpp"
#include <string>
using namespace std;


SystemImpl ::SystemImpl(){name="NULL"; value=0.0;};
SystemImpl ::SystemImpl (string name, double value):name(name), value(value){};//construtor padrão
SystemImpl ::SystemImpl (string name):name(name){};
SystemImpl ::SystemImpl (double value):value(value){};

SystemImpl ::SystemImpl (System& copy){  
      if (this!=&copy){
     
      set_name(copy.get_name());
      set_value(copy.get_value());
  } 
}
SystemImpl ::~SystemImpl (){}

string SystemImpl::get_name(){
    return name;
}
void SystemImpl ::set_name(string name){
    this->name=name;
}

double SystemImpl::get_value(){
    return value;
}

void SystemImpl ::set_value(double value){
    this->value=value;
}

bool SystemImpl::operator ==(System & obj){
    return (this->name==obj.get_name() && this-> value==obj.get_value());
} 

System& SystemImpl ::operator=(System & copy){
    if (this==&copy)
        return *this;
    set_name(copy.get_name());
    set_value(copy.get_value()) ;
    return *this   ;

}