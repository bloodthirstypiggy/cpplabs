//
// Created by piggy on 27.09.2021.
//

#ifndef LAB2_CISOID_HPP
#define LAB2_CISOID_HPP
namespace cissoid {
    struct Point {
        double x, y;
    };

    class Cissoid {
    private:
        Point p;
        double a;//точка на которой окружность будет строиться
    public:
        Cissoid(double a = 1);

        ~Cissoid();

        Cissoid getP() const;

        Cissoid getA() const;

        void SetA(double a);

        void SetX(double x);

        Point getX() const;

        Point gety() const;

        double getYbyX(double x) const;

    };

}
#endif //LAB2_CISOID_HPP
