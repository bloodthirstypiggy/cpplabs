#include <gtest/gtest.h>
#include "../ternaryvector/vector.hpp"
#include"test.hpp"
using namespace vector1;

t_vectorTest::t_vectorTest() {


}

t_vectorTest::~t_vectorTest() {

}

TEST_F(t_vectorTest, SettingTests)
{

    char text[2] = {1,1};
    EXPECT_NO_THROW(vector_1.set_vector(text));
    

}

TEST_F(t_vectorTest, GettingTests)
{

    char text1[4] = {1,1,1,1};
    vector_1.set_vector(text1);                                                                                                                                                                                   
    EXPECT_EQ(vector_1.get_vector(), 4);
    EXPECT_NO_THROW(vector_1.print_vector_Array());

}

TEST_F(t_vectorTest, ORTests)
{

    char text1[5] = {1,1,1,1};
    vector_1.set_vector(text1);
    char text2[5] = {0,0,0,0};
    vector_2.set_vector(text2);
    if (vector_1.get_vector() > vector_2.get_vector()) {
        vector_2.diff_vector(vector_1);
      } else {
        vector_1.diff_vector(vector_2);
      }
    EXPECT_NO_THROW(vector_2.or_vector(vector_1));
    
}

TEST_F(t_vectorTest, ANDTests)
{

    char text1[5] = {1,1,1,1};
    vector_1.set_vector(text1);
    char text2[5] = {0,0,0,0};
    vector_2.set_vector(text2);
    if (vector_1.get_vector() > vector_2.get_vector()) {
        vector_2.diff_vector(vector_1);
      } else {
        vector_1.diff_vector(vector_2);
      }
    EXPECT_NO_THROW(vector_2.and_vector(vector_1));
    
}

TEST_F(t_vectorTest, EqualTests)
{

    char text1[5] = {1,1,1,1};
    vector_1.set_vector(text1);
    char text2[5] = {0,0,0,0};
    vector_2.set_vector(text2);
    if (vector_1.get_vector() > vector_2.get_vector()) {
        vector_2.diff_vector(vector_1);
      } else {
        vector_1.diff_vector(vector_2);
      }
    EXPECT_EQ(vector_1.equal_vector(vector_2), false);
    EXPECT_NO_THROW(vector_1.equal_vector(vector_2));

}

TEST_F(t_vectorTest, AnalysisTests)
{

    char text[10] = {1,1,1,1};
    vector_1.set_vector(text);
    EXPECT_EQ(vector_1.analysis_vector(), false);
    EXPECT_NO_THROW(vector_1.print_vector_Array());

}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}