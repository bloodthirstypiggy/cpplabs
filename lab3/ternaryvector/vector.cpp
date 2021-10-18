#include "vector.hpp"
#include <iostream>
#include <cstring>

namespace vector1 {
t_vector::t_vector() {
  n=0;
  for(int i=0;i<N;i++)
  {
    array[i] ='3';
  }
};
t_vector::t_vector(int a) {
  int i = 0;
  for (i; i<a; i++)
  {
    array[i]='X';
  }
  n=a;
};

t_vector::t_vector(char* str) { //??? no working
  int j = 0;
  
  int i = 0;
  for(i; i<n;i++)
  {
    array[i] = str[i];
    if (array[i] == '\n')
      break;
  }
  array[i]='\n';
 n = i+1;
};
int t_vector::get_vector() const{
  return n;

}
char* t_vector::get_vector_Array() const{
  return array;
}

void t_vector::print_vector_Array() {
  int i = 0;
  std::cout << array << std::endl;
  i++;
}

void t_vector::set_vector(char* change){
  n = strlen(change);
  array = change;
}

void t_vector::diff_vector(t_vector vector_2)
{
  int len_v1 = strlen(array);
int  len_v2 = strlen(vector_2.array);
int len_dif = len_v1 - len_v2;
if (len_dif != 0)
{
  if (len_dif > 0)
  {
    char differ [abs(len_dif)];
    for(int i =0; i < abs(len_dif); i++)
    {
      differ[i] = 'X';
    }

    strcat(vector_2.array,differ);
    vector_2.n += abs(len_dif);
  }
  else{
    char differ [abs(len_dif)];
    for(int i =0; i < abs(len_dif); i++)
    {
      differ[i] = 'X';
    }

    strcat(array,differ);
    n = n + abs(len_dif);
  }
}
}

void t_vector::or_vector(t_vector vector_2) const
{
 char result [n];
for (int j = 0; j < n; j++){
  if (array[j] == '0')
  {
    if (vector_2.array[j] == '0')
      result[j] = '0';
    else if (vector_2.array[j] == '1')
      result[j] = '1';
    else
      result[j] = 'X';
  }
  else if (array[j] == '1')
    result[j] = '1';
  else{
    if (vector_2.array[j] == '0')
      result[j] = '0';
    else if (vector_2.array[j] == '1')
      result[j] = '1';
    else
      result[j] = 'X';
  }
}

std::cout << result << std::endl;
}

void t_vector::and_vector(t_vector vector_2) const
{
 char result [n];
for (int j = 0; j < n; j++){
  if (array[j] == '0')
  {
      result[j] = '0';
  }
  else if (array[j] == '1')
    if (vector_2.array[j] == '0')
      result[j] = '0';
    else if (vector_2.array[j] == '1')
      result[j] = '1';
    else
      result[j] = 'X';
  else{
    if (vector_2.array[j] == '0')
      result[j] = '0';
    else if (vector_2.array[j] == '1')
      result[j] = '1';
    else
      result[j] = 'X';
  }
}

std::cout << result << std::endl;
}



} // namespace vector
