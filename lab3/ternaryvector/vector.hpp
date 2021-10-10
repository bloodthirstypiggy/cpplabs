#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

/*
!
\brief Основной класс вектор.

в этом классе обозначены два состояния, макс. кол-во элементов в векторе и сам
массив этих элементов, при этом состояния ложь = 0, истина = 1, неопределенность
= 2

*/

namespace vector {

class vector {
private:
  static const int N = 10;
  int n;
  char array[N + 1]; //для \n

public:
  // \brief стандартный конструктор, на всякий случай заполним его -1, чтобы мы
  // могли понять, если какой либо из элементов не заполниться
  vector();

  // \brief конструктор, записывается а, по кол-ву а в массив записывается
  // несколько подряд идущих 2, остальное заполняется -1
  vector(int a);
  // \brief конструктор, которому подается строка, он ее обрабатывает и загоняет
  // эту строку в массив char вектора
  vector(std::string string);
  // \brief setters and getters
  int getVector() const;
  char getVectorArray() const;
  void setVector(std::string change);
  // \brief methods
  void output() const;
  vector or (vector vector2) const;
  vector and (vector vector2) const;
  bool equal(vector vector2) const;
  vector invert() const;
  int analysis() const;
}

} // namespace vector
#endif
