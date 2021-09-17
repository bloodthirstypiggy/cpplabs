#include "func.hpp"

namespace func{

int main(){
  matrix* main = createMatrix();
  inputMatrix(main);
  double * result = getResult(main);
  printMatrix(result);
  erase(main);
    return 0;
}
}
