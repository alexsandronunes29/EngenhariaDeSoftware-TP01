#ifndef ExponencialFunction_HPP
#define ExponencialFunction_HPP

#include "Flow.hpp"
#include "FlowImpl.hpp"


class ExponentialFunction: public FlowImpl
 {
 public:
 ExponentialFunction(string,System*,System*);
 ExponentialFunction(Flow&);
 ExponentialFunction();
 virtual ~ExponentialFunction();
 virtual double function();
};
#endif // 