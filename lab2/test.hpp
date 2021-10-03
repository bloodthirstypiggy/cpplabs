//
// Created by piggy on 27.09.2021.
//

#ifndef LAB2_TEST_HPP
#define LAB2_TEST_HPP

#include <gtest/gtest.h>
#include "classcissoid/cissoid.hpp"

using namespace cissoid1;

struct CissoidTest : testing::Test
{
    Cissoid* cissoid;

    CissoidTest();

    ~CissoidTest();
};

#endif //LAB2_TEST_HPP
