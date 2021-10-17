#include "vector.hpp"
#include <iostream>


namespace vector1 {
t_vector::t_vector() {

};
t_vector::t_vector(int a) {
  for (int i; i<a; i++)
  {
    array[i]=2;
  }

};

t_vector::t_vector(char* str) {
  n=0;
  for(int i = 0; i<n;i++)
  {
    array[i] = str[i];
  }
};
int t_vector::get_vector() const{

}
char* t_vector::get_vector_Array() const{
  return array;
}

void t_vector::set_vector(std::string change){

}



} // namespace vector
