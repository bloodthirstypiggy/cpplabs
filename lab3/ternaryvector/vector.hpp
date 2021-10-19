#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

/*
!
\brief Основной класс вектор.

в этом классе обозначены два состояния, макс. кол-во элементов в векторе и сам
массив этих элементов, при этом состояния ложь = 0, истина = 1, неопределенность
= X

*/

namespace vector1 {

class t_vector {
private:
  static const int N = 10;
  int n;
  char array[N+1];

public:
  // \brief стандартный конструктор
  t_vector();

  // \brief конструктор, записывается а, по кол-ву а в массив записывается
  // несколько подряд идущих 2
  t_vector(int a);
  // \brief конструктор, которому подается строка, он ее обрабатывает и загоняет
  // эту строку в массив char вектора
  t_vector(char* string);
  // \brief setters and getters
  int get_vector() const;
  const char* get_vector_Array() const;

  // \brief копирует строку, которая подается в массив класса
  void set_vector(char* change);
  void print_vector_Array();
  // \brief дополняет иксами один из векторов чтобы было одинаковое кол-во
  void diff_vector(t_vector vector_2);
  void invert_vector();
  // \brief methods
  void or_vector (t_vector vector2) const;
  void and_vector (t_vector vector2) const;
  bool equal_vector(t_vector vector2) const;
  // \brief возвращает тру если в векторе нет Х
  bool analysis_vector() const;
};

} // namespace vector
#endif
