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

namespace vector1 {

class t_vector {
private:
  static const int N = 10;
  int n;
  char* array = new char[N + 1]; //для \n

public:
  // \brief стандартный конструктор, на всякий случай заполним его -1, чтобы мы
  // могли понять, если какой либо из элементов не заполниться
  t_vector();

  // \brief конструктор, записывается а, по кол-ву а в массив записывается
  // несколько подряд идущих 2, остальное заполняется -1
  t_vector(int a);
  // \brief конструктор, которому подается строка, он ее обрабатывает и загоняет
  // эту строку в массив char вектора
  t_vector(char* string);
  // \brief setters and getters
  int get_vector() const;
  char* get_vector_Array() const;
  void set_vector(char* change);
  void print_vector_Array();
  void diff_vector(t_vector vector_2);
  // \brief methods
  void output_vector() const;
  void or_vector (t_vector vector2) const;
  void and_vector (t_vector vector2) const;
  bool equal_vector(t_vector vector2) const;
  t_vector invert_vector() const;
  int analysis_vector() const;
};

} // namespace vector
#endif
