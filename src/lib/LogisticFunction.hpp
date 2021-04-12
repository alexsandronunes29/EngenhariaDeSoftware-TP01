#ifndef LogisticFunction_HPP
#define LogisticFunction_HPP

#include "Flow.hpp"
#include "FlowImpl.hpp"

using namespace std;

class LogisticFunction : public FlowImpl{
public:
LogisticFunction (string,System*,System*);
LogisticFunction(Flow&);
LogisticFunction();
virtual ~LogisticFunction();
double function();
};

#endif // !LogisticFunction_HPP
