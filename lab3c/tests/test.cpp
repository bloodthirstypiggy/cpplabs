#include"../ternaryvector/vector.hpp"
#include "gtest/gtest.h"
using namespace vector1;

TEST(Assert, or)
{
  //Arrange
  int a =6;
  int b = 7;
  t_vector test1(a);
  t_vector test2(b);
  //Act
  t_vector result = test1 | test2;
  std::cout << result.get_vector_Array() << std::endl;
  //Assert
  EXPECT_NO_THROW(result.get_vector_Array());
  EXPECT_EQ( 6 , result.get_vector());
  EXPECT_EQ( 'X' , result.get_vector_Array()[5]);
}


TEST(Assert, and)
{
  //Arrange
  int a =6;
  int b = 7;
  t_vector test1(a);
  t_vector test2(b);
  //Act
  t_vector result = test1 & test2;
  std::cout << result.get_vector_Array() << std::endl;
  //Assert
  EXPECT_NO_THROW(result.get_vector_Array());
  EXPECT_EQ( 6 , result.get_vector());
  EXPECT_EQ( 'X' , result.get_vector_Array()[5]);
}


TEST(Assert, setter)
{


 int a =6;
  int b = 7;
 t_vector test1(a);
 t_vector test2(b);
 char* c = "111";
  test1.set_vector(c);
  EXPECT_NO_THROW(test1.get_vector_Array());
  EXPECT_EQ( '1' , test1.get_vector_Array()[1]);

}

TEST(Assert, getter)
{


 int a =6;
  int b = 7;
 t_vector test1(a);
 t_vector test2(b);
 char* c = "111";
  test1.set_vector(c);
  EXPECT_NO_THROW(test1.get_vector_Array());
  for (int i =0; i<test1.get_vector();i++){
  EXPECT_EQ( '1' , test1.get_vector_Array()[i]);
  }
}

TEST(Assert, invert)
{
  //Arrange
  int a =6;
  int b = 7;
  t_vector test1(a);
  //Act
  t_vector result = ~test1;
  std::cout << result.get_vector_Array() << std::endl;
  //Assert
  EXPECT_NO_THROW(result.get_vector_Array());
  EXPECT_EQ( 6 , result.get_vector());
  EXPECT_EQ( 'X' , result.get_vector_Array()[5]);
  char* testing = "111111";
  test1.set_vector(testing);
  result = ~test1;
  std::cout << result.get_vector_Array() << std::endl;
  EXPECT_EQ('0', result.get_vector_Array()[1]);
}

TEST(Assert, equal)
{
  //Arrange
  int a =6;
  int b = 7;
  t_vector test1(a);
  t_vector test2(b);
  //Act
  bool result = test1 == test2;
  std::cout << result << std::endl;
  //Assert
  //EXPECT_NO_THROW(result.get_vector_Array());
  EXPECT_EQ(true, result);
  //EXPECT_EQ( 'X' , result.get_vector_Array()[5]);
  char* testing = "111111";
  test1.set_vector(testing);
  result = test1 ==test2;
  //std::cout << result.get_vector_Array() << std::endl;
  EXPECT_EQ(false, result);
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
