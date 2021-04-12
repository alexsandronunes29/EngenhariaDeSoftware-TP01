
/*Created By Alexsandro Nunes(17.2.5878)
API-Disciplina Engengaria de Software I-UFOP*- Classes canonicas */

#include "FlowImpl.hpp"
#include <string>

using namespace std;

FlowImpl::FlowImpl():name(""), source(NULL),target (NULL){}

FlowImpl::FlowImpl(string name, System* source, System* target): name(name), source(source), target(target){}

FlowImpl::FlowImpl(Flow& copy){
	if(this == &copy){}

	else{
		set_name(copy.get_name());
		insert(copy.get_source(), copy.get_target());
	}
}

FlowImpl::~FlowImpl(){}

string FlowImpl::get_name(){
	return name;
}

void FlowImpl::set_name(string name){
	this->name = name;
}

void FlowImpl::insert(System* source, System* target){
	this->source  = source;
	this->target = target;
}

System* FlowImpl::get_source(){
	return source;
}

void FlowImpl::set_source(System* source){
	this->source = source;
}

System* FlowImpl::get_target(){
	return target;
}

void FlowImpl::set_target(System* target){
	this->target = target;
}

bool FlowImpl::operator==(Flow& object){
	return (this->name == object.get_name() && this->source == object.get_source() && this->target == object.get_target());
}

Flow& FlowImpl::operator= (Flow& copy){
	if(this == &copy)
		return *this;

	set_name(copy.get_name());
	insert(copy.get_source (), copy.get_target());

	return *this;
}

