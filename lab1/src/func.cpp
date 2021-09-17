#include "func.hpp"
#include <iostream>

namespace func {

int getNum(int &m) {
  std::cin >> m;
  if (!std::cin.good())
    return -1;
  return 1;
}

matrix input(matrix &mainmatrix) {
  mainmatrix.lines = nullptr; // link to the array of lines
  int m;
  const char *errormsg = "";
  do {
    std::cout << errormsg << std::endl;
    std::cout << "Enter the number of lines" << std::endl;
    errormsg = "no number of lines, repeat pls";
    if (getNum(m) < 0) // error in getnum
      break;
  } while (m < 1);
  mainmatrix.lines = new Line[m];
  mainmatrix.m = m;
  for (int i = 0; i < mainmatrix.m; i++) {
    do {
      std::cout << errormsg << std::endl;
      std::cout << "enter the number of items in line" << (i + 1) << std::endl;
      errormsg = "error number of items in line";
      if (getNum(mainmatrix.lines[i].n) < 1) {
        erasematrix(mainmatrix);
        break;
      }
    } while (mainmatrix.lines[i].n < 1);
    mainmatrix.lines.[i].a = new double[mainmatrix.lines.[i].n];
    std::cout << "enter items for line number " << (i + 1) << std::endl;
    for (int j = 0; j < mainmatrix.lines[i].n; j++) {
      if (getNum(mainmatrix.lines[i].a[j]) < 0) {
        erasematrix(mainmatrix);
        break;
      }
    }
  }
  return mainmatrix;
}

void output(matrix mainmatrix)
{
  for (int i; i < mainmatrix.m;i++){
    for(int j; j<mainmatrix.lines[i].a[j];j++){
  std::cout << "line :" << (i+1) << "numbers :" << mainmatrix.lines[i].a[j] << std::endl;
}


}}

matrix erasematrix(matrix mainmatrix)
{




}










} // namespace func
