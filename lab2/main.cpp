#include "cissoid.hpp"
using namespace cissoid1;
//Мы хотим изначально задать для объекта класса кривая x, a, (fi?)




     void menu(Cissoid cissoid) {
         bool cont = true;
        while (cont) {
            std::cout<< "\n\tMENU:\n\t1. Change a, now a is = " << cissoid.getA()
                      << ".\n\t2. Get y by x"
                      << "\n\t3. Get r by fi" // надо спрашивать угол
                      << "\n\t4. Get vertical asymptote"
                      << "\n\t5. Return the area of the strip between the cissoid and its asymptote"//
                      << "\n\t6. Return the volume of the body obtained by rotating the strip around the asymptote\n"
                      << ".\n\t7. Return the coefficients in the parabola equation such that the bases of the perpendiculars dropped from the vertex of the parabola to its tangents form the given cissoid."
                      << "\n\t8. Exit.\n" << std::endl;
            int choice = 0;
            bool b = false;

            while (true) {
                b = getNum(choice);
                if (b)
                    break;
                std::cout << "TRY AGAIN!" << std::endl;
            }
            int x;
            double a, fi;
            switch (choice) {
                case 1:
                    std::cout << "a = ";
                    while (true) {
                        b = getDouble(a);
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

                        std::cout << "y(x) = " << cissoid.getYbyX(x) << std::endl;


                    break;
                              case 3:
                                  std::cout << "fi = ";
                                  while (true) {
                                      b = getDouble(fi);
                                      if (b)
                                          break;
                                      std::cout << "TRY AGAIN!" << std::endl;
                                  }
                                  std::cout << "r(fi) = " << cissoid.getRbyFI(fi) << std::endl;
                                  break;
                              case 4:
                                  std::cout << 2*cissoid.getA() <<std::endl;
                                      break;

                              case 5:
                                  std::cout << "x = ";
                                  while (true) {
                                      b = getNum(x);
                                      if (b)
                                          break;
                                      std::cout << "TRY AGAIN!" << std::endl;
                                  }
                                  std::cout << "S = "<< cissoid.getSquare(x) << std::endl;
                                  break;
                            /*  case 6:
                                  return;
                              default:
                                  break;
                          */
                case 8:
                    cont = false;
                    break;
            }
        }
    }

    int main() {
        Cissoid cissoid(1);
        menu(cissoid);
        //delete(cissoid);//??
        return 0;
    }
