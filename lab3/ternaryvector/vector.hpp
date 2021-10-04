#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

/*
!
\brief Основной класс вектор.

в этом классе обозначены два состояния, макс. кол-во элементов в векторе и сам массив этих элементов, при этом состояния ложь = 0, истина = 1, неопределенность = 2

*/


class vector{
private:
  static const int N = 10;
  int n
  char array[N];
public:
  // \brief стандартный конструктор, на всякий случай заполним его -1, чтобы мы могли понять, если какой либо из элементов не заполниться
  vector(){
    n = 0;
    for(int i=0; i<n; i++)
    {
      array[i] = -1;
    }
  };
  int uncertainvector


}
#endif
