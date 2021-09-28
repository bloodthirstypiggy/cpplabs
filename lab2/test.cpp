#include "test.hpp"

CissoidTest::CissoidTest() {
    cissoid = new Cissoid();
}

CissoidTest::~CissoidTest() {
    delete cissoid;
}

TEST_F(CissoidTest, ChangingATests)
{
EXPECT_EQ(1, cissoid->getA());
cissoid->SetA(9);
EXPECT_EQ(9, cissoid->getA());
cissoid->SetA(-3);
EXPECT_EQ(-3, cissoid->getA());
}

TEST_F(CissoidTest, getYbyX)
{
    int t_x = 1;
    EXPECT_EQ( 1, cissoid->getYbyX(t_x));
    cissoid->SetA(2);
    t_x = 2;
    EXPECT_EQ( 2, cissoid->getYbyX(t_x));
}

/*TEST_F(CissoidTest, getRbyFI)
{
    double t_fi = 1;
    EXPECT_EQ( 1.2587700000000 , cissoid->getRbyFI(t_fi));
    cissoid->SetA(2);
    t_fi = 2;
    EXPECT_EQ( 51.9830, cissoid->getRbyFI(t_fi));
}*/

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

/*
TEST_F(AstroidTest, LengthTests)
{
double t = 0;
EXPECT_EQ(0, cissoid->getLength());
cissoid->setRadius(9);
EXPECT_EQ(54, cissoid->getLength());
EXPECT_EQ(0, cissoid->getLength(t));
t = 90;
EXPECT_EQ(3.0 * 9.0 / 2.0, cissoid->getLength(t));
cissoid->setRadius(3);
EXPECT_EQ(18, cissoid->getLength());
t = 180;
EXPECT_EQ(3.0 * 6.0 / 2.0, cissoid->getLength(t));
t = 720;
EXPECT_EQ(-1, cissoid->getLength(t));
}

TEST_F(AstroidTest, SquareTests)
{
EXPECT_EQ(0, cissoid->getSquare());
cissoid->setRadius(9);
EXPECT_EQ(3.0 * PI * 81.0 / 8.0, cissoid->getSquare());
cissoid->setRadius(3);
EXPECT_EQ(3.0 * PI * 9.0 / 8.0, cissoid->getSquare());
}

TEST_F(AstroidTest, CoordsTests)
{
double t;
t = 0;
Point point;
point = cissoid->getCoords(t);
EXPECT_EQ(0, point.x);
EXPECT_EQ(0, point.y);
cissoid->setRadius(9);
point = cissoid->getCoords(t);
EXPECT_EQ(9, point.x);
EXPECT_EQ(0, point.y);
t = 90;
point = cissoid->getCoords(t);
EXPECT_EQ(0, (int) point.x);
EXPECT_EQ(9, point.y);
t = 45;
point = cissoid->getCoords(t);
EXPECT_EQ(round(point.x), round(point.y));

double x = 0;
point = cissoid->getCoordY(x);
EXPECT_EQ(9, round(point.y));
x = 9;
point = cissoid->getCoordY(x);
EXPECT_EQ(0, point.y);
x = 3;
point = cissoid->getCoordY(x);
EXPECT_EQ(3.3675, point.y);
}

TEST_F(AstroidTest, CurvativeRadiusTests)
{
double t;
t = 0;
cissoid->setRadius(9);
EXPECT_EQ(0, cissoid->getCurvativeRadius(t));
t = 90;
EXPECT_EQ(0, round(astroid->getCurvativeRadius(t)));
t = 45;
EXPECT_EQ(3.0 * 9.0 / 2.0, astroid->getCurvativeRadius(t));
}*/

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
