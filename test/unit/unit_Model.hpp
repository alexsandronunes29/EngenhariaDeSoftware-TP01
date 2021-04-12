#ifndef UNITMODEL_HPP
#define UNITMODEL_HPP

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include "../../src/lib/ExponentialFunction.hpp"
#include "../../src/lib/LogisticFunction.hpp"
#include "../../src/lib/SystemImpl.hpp"
#include "../../src/lib/System.hpp"
#include "../../src/lib/Model.hpp"
#include "../../src/lib/ModelImpl.hpp"

void run_unit_test_Model();
void unit_Model_constructor();
void unit_Model_destructor();
void unit_Model_get_name();
void unit_Model_set_name();
void unit_Model_add();
void unit_Model_remove();
void unit_Model_execute();

#endif