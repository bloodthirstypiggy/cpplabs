#include "func.hpp"
#include <iostream>

namespace func {

  int getNum(int &a)
	{
		std::cin >> a;
		if (!std::cin.good())	// обнаружена ошибка ввода или конец файла
			return -1;
		return 1;
	}
  matrix* makeMatrix(){
  matrix* main = new matrix;
  main->lines = 0;
  main->nodes = nullptr;
  return main;
  }
 void getNodes(matrix* main, int N){
   int a;
   int b;
   int coordx;
   int coordy;
   int progress = 1;
   const char* errormsg = "";
  while(progress > 0)
  {
  std::cout << "print x coordinate" << std::endl;
  do{

  std::cout << errormsg << std::endl;
  a = getNum(coordx);
  errormsg = "you are wrong. Repeat pls";
  }while (a < 0);

   const char* errormsg = "";
do{
  std::cout << errormsg << std::endl;
  b = getNum(coordy);
  errormsg = "you are wrong. Repeat pls";
  while (coordy > N)
  {
  std::cout << errormsg << std::endl;
  b = getNum(coordy);
  }

}while (b < 0);

  main->nodes[coordy]->x = coordx;
  main->nodes[coordy]->next = new Node;
  main->nodes[coordy] = main->nodes[coordy]->next;

  std::cout << "print 1. to start entering coordinates or 0 to result";
  std::cin >> progress;
  }
  }

matrix* createMatrix(){
  matrix* mainmatrix = makeMatrix();
  int N;// number of lines
  const char* errormsg = "";
  std::cout << "enter number of lines" << std::endl;
  do{//получаем кол-во строк

  std::cout << errormsg << std::endl;
  errormsg = "you are wrong! Repeat please!";
  } while(getNum(N) < 1);
  Node** lines = new Node*[N];//выделили память под массив указателей. try catch ???
   mainmatrix->lines = N;
   mainmatrix->nodes = lines;//память под структуру матрицы выделена
  getNodes(mainmatrix, N); 
  }





} // namespace func
