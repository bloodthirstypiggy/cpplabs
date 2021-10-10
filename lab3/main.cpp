#include "/ternaryvector/vector.hpp"
#include <iostream>
using namespace vector;

void menu(vector vector1, vector vector2) {
  bool cont = true;
  while (cont) {
    std::cout << "\n\tMENU:1.get vector1 and vector2"
              << "\n\t2. setter"
              << "\n\t3. or of two vectors "
              << ".\n\t4. and of two vectors"
              << "\n\t5. equal of two vectors"
              << "\n\t6. invert vector"
              << "\n\t7. analysis vector"
              << "\n\t8. exit" << std::endl;
    int choice = 0;
    bool b = false;

    while (true) {
      b = getNum(choice);
      if (b)
        break;
      std::cout << "TRY AGAIN!" << std::endl;
    }

    switch (choice) {
    case 1:
      std::cout << "vector1 n is:" << vector1.getVector() << "and array is"
                << vector1.getVectorArray() << std::endl;
      std::cout << "vector2 n is:" << vector2.getVector() << "and array is"
                << vector2.getVectorArray() << std::endl;
      break;
    case 2:
      int ch;
      int cho;
      std::cout << "enter number of vector you want to set: 1 or 2"
                << std::endl;
      while (true) {
        cho = -1;
        ch = getNum(cho);
        if (cho != 1 | cho != 2 | ch != 1) //? no getnum
          break;
        std::cout << "TRY AGAIN!" << std::endl;
      }
      std::cout << "Okey, you want to set vector number" << cho
                << "now, print whole vector" << std::endl;
      std::string change = getString();
      if (cho == 1)
        vector1.setVector(change);
      else
        vector2.setVector(change);
      break;
    case 3:
      vector result;
      std::cout << "Okey, you want to or two vectors,lets go" result =
          vector1.or (vector2);
      std::cout << "your vector is" << result.output() << std::endl;

      break;
    case 4:
      vector result;
      std::cout << "Okey, you want to and two vectors,lets go" result =
          vector1.and (vector2);
      std::cout << "your vector is" << result.output() << std::endl;

      break;
    case 5:
      std::cout << "Okey, you want to equal two vectors, lets go" << std::endl;

      bool result = vector1.equal(vector2);
      std::cout << "result is:" << bool(result) << std::endl;

      break;
    case 6:
      int ch;
      int cho;
      std::cout << "enter number of vector you want to set: 1 or 2"
                << std::endl;
      while (true) {
        cho = -1;
        ch = getNum(cho);
        if (cho != 1 | cho != 2 | ch != 1) //? no getnum
          break;
        std::cout << "TRY AGAIN!" << std::endl;
      }
      std::cout << "Okey, you want to invert vector number " << cho << "lets go"
                << std::endl;
      vector result;
      if (cho == 1)
        result = vector1.invert();
      else
        result = vector2.invert();
      std::cout << "here it is" << result.output() << std::endl;
      break;
    case 7:
      bool result;
      std::cout << "okey you wanna know analysis of vector, first enter what "
                   "vector you want to analyze" std::endl;
      int ch;
      int cho;
      std::cout << "enter number of vector you want to set: 1 or 2"
                << std::endl;
      while (true) {
        cho = -1;
        ch = getNum(cho);
        if (cho != 1 | cho != 2 | ch != 1) //? no getnum
          break;
        std::cout << "TRY AGAIN!" << std::endl;
      }
      std::cout << "Okey, you want to analyze vector number " << cho
                << "lets go" << std::endl;
      if (cho == 1)
        result = vector1.analyze();
      else
        result = vector2.analyze();
      std::cout << "here it is" << result << std::endl;

      break;
    case 8:

      break;

    default:
      break;

    case 9:
      cont = false;
      break;
    }
  }
}
