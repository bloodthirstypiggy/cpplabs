#ifndef ADD_H
#define ADD_H


  struct Node {
    int x;
    Node* next;
    };


    struct matrix {
    int lines;
    Node** nodes;
    };
  
int getNum(int &N);
matrix* createMatrix();
void getNodes(matrix* main, int N);
matrix* makeMatrix();
int inputMatrix(matrix main);
double* getResult(matrix main);
void printMatrix(double& result);
void erase(matrix main);
#endif
