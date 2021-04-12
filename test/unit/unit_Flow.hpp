#ifndef UNITFLOW_HPP
#define UNITFLOW_HPP

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include "../../src/lib/Flow.hpp"
#include "../../src/lib/ExponentialFunction.hpp"
#include "../../src/lib/LogisticFunction.hpp"
#include "../../src/lib/SystemImpl.hpp"
#include "../../src/lib/System.hpp"
#include "../../src/lib/Model.hpp"
#include "../../src/lib/ModelImpl.hpp"

void run_unit_test_Flow();
void unit_Flow_constructor();
void unit_Flow_destructor();
void unit_Flow_get_name();
void unit_Flow_set_name();
void unit_Flow_get_source();
void unit_Flow_set_source();
void unit_Flow_get_target();
void unit_Flow_set_target();
void unit_Flow_operator_assignment();
void unit_Flow_execute();

#endif