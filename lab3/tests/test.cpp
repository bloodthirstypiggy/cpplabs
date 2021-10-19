#include <gtest/gtest.h>
#include "../ternaryvector/vector.hpp"
#include"test.hpp"
using namespace vector1;

t_vectorTest::t_vectorTest() {

    int a =2;
  int b = 3;
  t_vector vector_1(a);
  t_vector vector_2(b);
}

t_vectorTest::~t_vectorTest() {

}

TEST_F(t_vectorTest, GettingATests)
{
    EXPECT_NO_THROW(vector_1.get_vector());
    
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}