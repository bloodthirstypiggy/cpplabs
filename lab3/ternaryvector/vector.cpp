#include "vector.hpp"
#include <iostream>
#include <cstring>

namespace vector1 {
t_vector::t_vector() {
  n=0;
};
t_vector::t_vector(int a) {
  int i = 0;
  for (i; i<a; i++)
  {
    array[i]='X';
  }
  n=a;
};

t_vector::t_vector(char* str) {
  
};
int t_vector::get_vector() const{
  return n;

}


const char* t_vector::get_vector_Array() const{
  return array;
}

/*void t_vector::print_vector_Array() {//френд функцию?
  std::cout << array << std::endl;
}*/

void print_vector_array(t_vector & vector){
  std::cout << vector.array << std::endl;
}


void t_vector::set_vector(char* change){
  
  n = strlen(change);
  int i = 0;
  for(i; i<n;i++)
  {
    array[i] = change[i];
  }
  array[i] = '\0';

}

void t_vector::diff_vector(t_vector other_vector)
{
  int len_v1 = n;
int  len_v2 = other_vector.n;
int len_dif = len_v1 - len_v2;
int i = 0;
int j = 0;
if (len_dif != 0)
{
  if (len_dif <0){
    for(j; j<abs(len_dif); j++)
    {
      array[n] = 'X';
      n +=1;
    }
    array[n] = '\0';
  }
}
}

void t_vector::or_vector(t_vector vector_2, char* result) const
{
 for (int k = 0; k<n;k++)
  result[k] = 'X';
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

}

void t_vector::and_vector(t_vector vector_2, char* result) const
{
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


}

bool t_vector::equal_vector(t_vector vector2) const{
  for (int i = 0; i<n;i++)
  {
    if (array[i] != vector2.array[i])
      return false;
  }
  return true;
}

void t_vector::invert_vector(){
  for(int i = 0; i < n; i++)
  {
    if (array[i] == '0')
      array[i] = '1';
    else if (array[i] == '1')
      array[i] = '0';
  }
}

bool t_vector::analysis_vector() const{
  for (int i = 0; i<n; i++)
  {
    if (array[i] == 'X')
      return false;
    
  }
return true;

}

void operator | (t_vector vector1, t_vector vector2)
{
      int forres = vector1.get_vector();
      forres+=1;
      char result [forres];
      result[forres-1] = '\0';
      vector1.or_vector(vector2,result);
      std::cout << result << std::endl;
}

void operator & (t_vector vector1, t_vector vector2)
{
      int forres = vector1.get_vector();
      forres+=1;
      char result [forres];
      result[forres-1] = '\0';
      vector1.and_vector(vector2,result);
      std::cout << result << std::endl;
}

bool operator == (t_vector vector1, t_vector vector2)
{
      
      bool result;
      result = vector1.equal_vector(vector2);
      return result;
}

void operator ~ (t_vector vector)
{
      vector.invert_vector();
}




} // namespace vector | & == ~ 
