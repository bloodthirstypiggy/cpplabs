#ifndef ADD_H
#define ADD_H
#include <iostream>
    struct Node {
        int x;
        Node *next;
        int value;
    };

    struct matrix {
        int lines;
        Node **nodes;
    };

    inline Node *newNode(int x, int value) {
        Node *node = new Node;
        node->x = x;
        node->value = value;
        node->next = nullptr;
        return node;
    }

    int getNum(int &N);

    void getNodes(matrix *main, int N);

    matrix *makeMatrix(int n);

    int inputMatrix(matrix main);

    double *getResult(matrix &main);

    void printMatrix(matrix &main);

    void erase(matrix main);

#endif
