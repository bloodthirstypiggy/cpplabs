#include "test.hpp"

CissoidTest::CissoidTest() {
    cissoid = new Cissoid();
}

CissoidTest::~CissoidTest() {
    delete cissoid;
}

TEST_F(CissoidTest, GettingATests)
{
    EXPECT_NO_THROW(cissoid->SetA(3));
    double a = -1;
    EXPECT_ANY_THROW(cissoid->SetA(a));
}

TEST_F(CissoidTest, ChangingATests)
{
EXPECT_EQ(1, cissoid->getA());
    cissoid->SetA(9);
EXPECT_EQ(9, cissoid->getA());
}

TEST_F(CissoidTest, getYbyX)
{
    int t_x = 1;
    EXPECT_EQ( 1, cissoid->getYbyX(t_x));
    cissoid->SetA(2);
    t_x = 2;
    EXPECT_EQ( 2, cissoid->getYbyX(t_x));
}

TEST_F(CissoidTest, getRbyFI)
{
    double t_fi = 1;
    EXPECT_NEAR( 1.25877 , cissoid->getRbyFI(t_fi), 0.001);
    //cissoid->SetA(2);
    //t_fi = 2;
    //EXPECT_EQ( 51.9830, cissoid->getRbyFI(t_fi));
}

TEST_F(CissoidTest, getSquare)
{

    cissoid->SetA(2);
    double t_x = 2;
    EXPECT_EQ( 3*M_PI*2*2, cissoid->getSquare(t_x));
}

TEST_F(CissoidTest, getVolume)
{

    cissoid->SetA(1);
    double t_x = 2;
    EXPECT_EQ(  M_PI * M_PI * 2 * t_x*t_x*t_x, cissoid->getVolume(t_x));

    //t_x = 25;
   // EXPECT_EQ(  308425, cissoid->getVolume(t_x));
}

/*int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}*/
