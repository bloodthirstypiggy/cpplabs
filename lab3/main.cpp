#include "ternaryvector/vector.hpp"
#include <cstdio>
#include <iostream>
using namespace vector1;

template <class T> bool getNum(T &a) {
  std::cin >> a;
  if (!std::cin.good()) {
    std::cin.clear();
    while (std::cin.get() != '\n')
      ;
    return false;
  }
  return true;
}
int strlen(char* str)
{
  int i=0;
  while (str[i] != '\0')
  {
    i++;
  }
  return i;
}

bool strfine(char* str)
{
  int strlen1 = strlen(str);
  for(int i = 0; i< strlen1; i++)
  {
    char stroka = str[i];
    if (stroka != 0x31 & stroka != 0x30 & stroka != 'X')
      throw 6;
    //if (str[i] != 'X' | str[i] != '0x31' | str[i] != 0x30)
      //throw 6;
  }
  return 1;
}

void vectordiff( t_vector& vector1,t_vector& vector2)
{
  if (vector1.get_vector() > vector2.get_vector()) {
        vector2.diff_vector(vector1);
      } else {
        vector1.diff_vector(vector2);
      }
}

int getInt() {
  int a;
  while (true) {
    bool k = getNum(a);
    if (k)
      break;
    std::cout << "TRY AGAIN!" << std::endl;
  }
  return a;
}

char *getString(char *a) {
  std::cin >> a;
  return a;
}

void menu(t_vector vector1, t_vector vector2) {
  int choice;
  int value;
  while (true) {
    std::cout << "\n\tMENU:1.get vector1 and vector2"
              << "\n\t2. setter"
              << "\n\t3. or of two vectors "
              << ".\n\t4. and of two vectors"
              << "\n\t5. equal of two vectors"
              << "\n\t6. invert vector"
              << "\n\t7. analysis vector"
              << "\n\t8. exit" << std::endl;
    choice = getInt();

    switch (choice) {
    case 1:
      std::cout << "vector1 n is:" << vector1.get_vector() << " and array is "
                << std::endl;
      print_vector_array(vector1);
      std::cout << "vector2 n is:" << vector2.get_vector() << " and array is "
                << std::endl;
      print_vector_array(vector2);
      break;
    case 2: {

      std::cout << "print number or vector you want to set" << std::endl;
      int res_2 = 0;
      std::cin >> res_2;
      if (res_2 > 2)
        throw 4;
      char str[10];
      std::cin >> str;
      
      if (strlen(str) > 10)
        throw 5;
      strfine(str);
      if (res_2 == 1)
        vector1.set_vector(str);
      else if (res_2 == 2)
        vector2.set_vector(str); 
      break;
    }
    case 3: {
      std::cout << "Okey, you want to or two vectors,lets go" << std::endl;
      vectordiff(vector1, vector2);
      vector1 | vector2;
      break;
    }
    case 4:{
      std::cout << "Okey, you want to and two vectors,lets go" << std::endl;
      vectordiff(vector1, vector2);
      vector1 & vector2;
      break;}
    case 5: {
      std::cout << "Okey, you want to equal two vectors, lets go" << std::endl;
      vectordiff(vector1, vector2);
      bool result = vector1 == vector2;
      std::cout << result << std::endl;
    } break;
    case 6: {
      std::cout << "Okey, print vector you want to invert" << std::endl;
      int v;
      std::cin >> v;
      
      if (v == 1)
        ~vector1;
      else if (v == 2)
        ~vector2;
      break;
    }
    case 7: {
      std::cout << "Okey, print vector you want to analyze" << std::endl;
      int v;
      std::cin >> v;
      if (v == 1)
        std::cout << vector1.analysis_vector() << std::endl;
      else if (v == 2)
        std::cout << vector2.analysis_vector() << std::endl;

      break;
    }
    default:
      return;
      break;
    }
  }
}

int main(){
  try
  {
  int b = 0;
  std::cout << "print how many X you want in vector" << std::endl;
  std::cin >> b;
  t_vector vector1;
  t_vector vector2(b);
  
  
  menu(vector1, vector2);
  }

  catch(int a)
  {
    std::cout << "ext n " << a << std::endl;
  }
  return 0;
}