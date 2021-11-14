#ifndef LAB2_TEST_HPP
#define LAB2_TEST_HPP

#include <gtest/gtest.h>
#include "../ternaryvector/vector.hpp"

using namespace vector1;

struct t_vectorTest : testing::Test
{
    t_vector vector_1;
    t_vector vector_2;

    t_vectorTest();

    ~t_vectorTest();
};

#endif //LAB2_TEST_HPP