#include "ternaryvector/vector.hpp"
#include <iostream>
#include <cstdio>
using namespace vector1;



template <class T>
 bool getNum(T& a) {
	std::cin >> a;
	if (!std::cin.good()) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		return false;
	}
	return true;
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

char* getString(char* a)
{
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
      std::cout << "vector1 n is:" << vector1.get_vector() << " and array is " << std::endl;
      vector1.print_vector_Array();
      std::cout << "vector2 n is:" << vector2.get_vector() << " and array is " << std::endl;
      vector2.print_vector_Array();
      break;
    case 2:{
    
    std::cout << "print number or vector you want to set" << std::endl;
      int res_2 = 0;
      std::cin >> res_2;
      char str[10];
      std::cin >> str;

      
      if (res_2 == 1)
        vector1.set_vector(str);
      else if (res_2 == 2)
        vector2.set_vector(str);//добавить обработку ошибок
      break;}
    case 3:{
      std::cout << "Okey, you want to or two vectors,lets go" << std::endl;
      if (vector1.get_vector() > vector2.get_vector())
        {vector2.diff_vector(vector1);}
      else
        {vector1.diff_vector(vector2);}
      vector1.or_vector(vector2);


      break;}
    case 4:
      std::cout << "Okey, you want to and two vectors,lets go" << std::endl;
      if (vector1.get_vector() > vector2.get_vector())
        {vector2.diff_vector(vector1);}
      else
        {vector1.diff_vector(vector2);}
      vector1.and_vector(vector2);

      break;
    case 5:{
      std::cout << "Okey, you want to equal two vectors, lets go" << std::endl;
      if (vector1.get_vector() > vector2.get_vector())
        {vector2.diff_vector(vector1);}
      else
        {vector1.diff_vector(vector2);}
      bool result = vector1.equal_vector(vector2);
      std::cout << "result is:" << bool(result) << std::endl;
    }
      break;
    case 6:
    {
      std::cout << "Okey, print vector you want to invert" << std::endl;
      int v;
      std::cin >> v;
      if (v == 1)
        vector1.invert_vector();
      else if (v == 2)
        vector2.invert_vector();
        break;}
    case 7:
      {
          std::cout << "Okey, print vector you want to analyze" << std::endl;
      int v;
      std::cin >> v;
      if (v == 1)
        std::cout << vector1.analysis_vector() << std::endl;
      else if (v == 2)
        std::cout << vector2.analysis_vector() << std::endl;
      
      break;}
    case 8:
    if (vector1.get_vector() > vector2.get_vector())
      vector2.diff_vector(vector1);
    else
      vector1.diff_vector(vector2);
      break;

      case 9:
    vector1.test();
      break;

    default:
    return;
    break;
    }
  
  }





}




/*int main(){
  int a =2;
  int b = 3;
  t_vector vector1(a);
  t_vector vector2(b);
  menu(vector1, vector2);
  return 0;
}*/
