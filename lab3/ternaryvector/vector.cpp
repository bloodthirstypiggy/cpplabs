#include "vector.cpp"
#include <iostream>

namespace vector1 {
vector() {
  n = 0;
  for (int i = 0; i < N; i++) {
    array[i] = '-1';
  }
  array[0] = '\n';
};
vector(int a) {
  n = a;
  for (int i = 0; i < a; i++) {
    arrray[i] = '2';
  }
  for (int j = a; j < N; j++) {
    array[j] = '-1';
  }
  array[n] = '\n';
};

vector(std::string string) {
  n = 0;
  i = 0;
  while (string[i] != '\n') {
    array[i] = string[i];
    i++;
    n++;
  }
  array[n] = '\n';
};
int getVector() const{
  return n;
}
char getVectorArray() const{
  return array;//????
}
// \brief нам дали никак не обработанную строку, мы должны проверить чтобы символов было не больше N, если их больше выбросить исключение

void setVector(std::string change){
  int i = 0;
  while (string[i] != '\n')
  {
    i++;
  }
}



} // namespace vector
