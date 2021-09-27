#include "cissoid.hpp"
#include <iostream>
namespace cissoid {
//Мы хотим изначально задать для объекта класса кривая x, a, (fi?)




    void menu(Cissoid &cissoid) {
        while (true) {
            std::cout << "a = " << cissoid.getA() << "; coordinates = " << cissoid.getP()
                      << "\n\tMENU:\n\t1. Change a and x, now a is = " << cissoid.getA() << "and x is ="
                      << cissoid.getX()
                      << ".\n\t2. Get y by x"
                      << "\n\t3. Get r by fi" // надо спрашивать угол
                      << "\n\t4. Get vertical asymptote"
                      << "\n\t5. Return the area of the strip between the cissoid and its asymptote"//
                      << "\n\t6. Return the volume of the body obtained by rotating the strip around the asymptote\n"
                      << ".\n\t7. Return the coefficients in the parabola equation such that the bases of the perpendiculars dropped from the vertex of the parabola to its tangents form the given cissoid."
                      << "\n\t8. Exit.\n" << std::endl;
            int choice = 0;
            bool b = false;
            Point p;
            while (true) {
                b = getNum(choice);
                if (b)
                    break;
                std::cout << "TRY AGAIN!" << std::endl;
            }
            double x, a;
            switch (choice) {
                case 1:
                    std::cout << "x = ";
                    while (true) {
                        b = getNum(x);
                        if (b)
                            break;
                        std::cout << "TRY AGAIN!" << std::endl;
                    }
                    cissoid.SetX(x);
                    std::cout << "SUCCESS!" << std::endl;
                    std::cout << "a = ";
                    while (true) {
                        b = getNum(a);
                        if (b)
                            break;
                        std::cout << "TRY AGAIN!" << std::endl;
                    }
                    cissoid.SetA(a);
                    std::cout << "SUCCESS!" << std::endl;
                    break;
                case 2:
                    std::cout << "x = ";
                    while (true) {
                        b = getNum(x);
                        if (b)
                            break;
                        std::cout << "TRY AGAIN!" << std::endl;
                    }
                    std::cout << "y(x) = " << cissoid.getybyx(x) << std::endl;
                    break;
                    /*          case 3:
                                  std::cout << "t = ";
                                  while (true) {
                                      b = getNum(t);
                                      if (b)
                                          break;
                                      std::cout << "TRY AGAIN!" << std::endl;
                                  }
                                  std::cout << "r(t) = " << astroid.getLength(t) << std::endl;
                                  break;
                              case 4:
                                  std::cout << "x = ";
                                  while (true) {
                                      b = getNum(x);
                                      if (b)
                                          break;
                                      std::cout << "TRY AGAIN!" << std::endl;
                                  }
                                  try {
                                      point = astroid.getCoordY(x);
                                      std::cout << "y(x) = " << abs(point.y) << " or y(x) = -" << abs(point.y) << std::endl;
                                      break;
                                  }
                                  catch(std::exception e) {
                                      std::cerr << "X > R!" << std::endl;
                                      break;
                                  }
                              case 5:
                                  std::cout << "t = ";
                                  while (true) {
                                      b = getNum(t);
                                      if (b)
                                          break;
                                      std::cout << "TRY AGAIN!" << std::endl;
                                  }
                                  point = astroid.getCoords(t);
                                  std::cout << "x(t) = " << point.x << ", y(t) = " << point.y << std::endl;
                                  break;
                              case 6:
                                  return;
                              default:
                                  break;
                          */}
        }
    }

    int main(int argc, char *argv[]) {
        Cissoid cissoid;
        menu(cissoid);
        //delete(cissoid);//??
    }
}