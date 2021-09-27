#include "cissoid.hpp"



namespace cissoid1{
    Cissoid::Cissoid(double a) { this->a = a;}
    Cissoid::~Cissoid() {}
    double Cissoid::getA() const {
        return a;
    }
    void Cissoid::SetA(double _a) {
    a = _a;
    }
    double Cissoid::getYbyX(double x) const {
        if (2*a - x == 0)
            throw std::overflow_error("Divide by zero exception");
        if (double(pow(x, 3)/double((2*a-x)) < 0))
            throw std::overflow_error("Divide by zero exception");
        double y = sqrt(pow(x, 3) / (2*a - x));
        return y;
    }

    double to_degrees(double rad)
    {
        return rad * 180.0 / M_PI;
    }

    double to_radians(double deg)
    {
        return deg * M_PI / 180.0;
    }

    double sec(double z_r)
    {
        return 1.0 / cos(z_r);
    }

    double Cissoid::getRbyFI(double fi) const {
        double fi_rad = to_degrees(fi);
        double r = 2*a*(sec(fi_rad) - cos(fi_rad));
        return r;
    }

    double Cissoid::getSquare(double x) const {
        double s = 3*M_PI*x*x;
        return s;
    }















}

