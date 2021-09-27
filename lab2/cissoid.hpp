//
// Created by piggy on 27.09.2021.
//

#ifndef LAB2_CISOID_HPP
#define LAB2_CISOID_HPP
#include<iostream>
#include <cmath>
#include <stdio.h>
#include<strstream>
#include <string.h>
namespace cissoid1 {

    class Cissoid {
    private:
        double a;//точка на которой окружность будет строиться
    public:
        Cissoid(double a = 1);

        ~Cissoid();

        double getA() const;

        void SetA(double a);

        double getYbyX(double x) const;

        double getRbyFI(double fi) const;

        double getSquare(double x) const;



    };

    inline int getNum(int& a)
    {
        std::cin >> a;
        if (!std::cin.good()) // обнаружена ошибка ввода или конец файла
            return 0;
        return 1;
    }

    inline int getDouble(double & a)
    {
        std::cin >> a;
        if (!std::cin.good()) // обнаружена ошибка ввода или конец файла
            return 0;
        return 1;
    }

}
#endif //LAB2_CISOID_HPP
