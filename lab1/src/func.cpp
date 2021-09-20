#include "func.hpp"
#include <iostream>

int getNum(int& a)
{
    std::cin >> a;
    if (!std::cin.good()) // обнаружена ошибка ввода или конец файла
        return -1;
    return 1;
}
matrix* makeMatrix(int n)
{
    matrix* main = new matrix;
    main->lines = n;
    main->nodes = new Node*[n];
    for (int i = 0; i < n; i++) {
        main->nodes[i] = nullptr;
    }
    return main;
}
void getNodes(matrix* main, int N)
{
    int a;
    int b;
    int coordx;
    int coordy;
    int progress = 1;
    const char* errormsg = "";
    while (progress > 0) {
        std::cout << "print x coordinate" << std::endl;
        do {

            std::cout << errormsg << std::endl;
            a = getNum(coordx);
            errormsg = "you are wrong. Repeat pls";
        } while (a < 0);

        const char* errormsg = "";

        std::cout << "print y coordinate" << std::endl;
        do {
            std::cout << errormsg << std::endl;
            b = getNum(coordy);
            errormsg = "you are wrong. Repeat pls";
            while (coordy > N) {
                std::cout << errormsg << std::endl;
                b = getNum(coordy);
            }

        } while (b < 0);

        int value;
        std::cout << "print y coordinate" << std::endl;
        getNum(value);

        if (main->nodes[coordy] == nullptr) {
            main->nodes[coordy] = newNode(coordx, value);
        } else {
            Node* curNode = main->nodes[coordy];
            Node* prevNode = main->nodes[coordy];
            while (curNode != nullptr) {
                if (coordx < curNode->x) {
                    Node* newnode = newNode(coordx, value);
                    if (prevNode == curNode) {
                        newnode->next = curNode;
                        main->nodes[coordy] = newnode;
                    } else {
                        prevNode->next = newnode;
                        newnode->next = curNode;
                    }
                    break;
                }
                if (coordx == curNode->x) {
                    curNode->value = value;
                    break;
                }
                prevNode = curNode;
                curNode = curNode->next;
                if (curNode == nullptr)
                    prevNode->next = newNode(coordx, value);
            }
        }
        std::cout << "print 1. to start entering coordinates or 0 to result";
        std::cin >> progress;
    }
}

void printMatrix(matrix& main)
{
    for (int i = 0; i < main.lines; i++) {
        Node* curNode = main.nodes[i];
        for (int j = 0; j < main.lines; j++) {
            if (curNode == nullptr) {
                std::cout << 0 << "\t";
            } else {
                if (curNode->x != j)
                    std::cout << 0 << "\t";
                else {
                    std::cout << curNode->value << "\t";
                    curNode = curNode->next;
                }
            }
        }
        std::cout << std::endl;
    }
}

int max(matrix main, int j)
{
    int max = 0;
    Node* node = main.nodes[j];
    while (node != nullptr) {
        if (node->value > max)
            max = node->value;
        node = node->next;
    }
    return max;
}

int getByCoord(matrix main, int i, int j)
{
    Node* node = main.nodes[i];
    while (node != nullptr) {
        if (j == node->x)
            return node->value;
        else {
            if (j > node->x)
                return 0;
            node = node->next;
        }
    }
    return 0;
}

double* getResult(matrix& main)
{
    double* b = new double[main.lines];
    for (int i = 0; i < main.lines; i++) {
        for (int j = 0; j < main.lines; j++) {
            b[i] = max(main, j) * getByCoord(main, i, j);
        }
    }
    return b;
}
// namespace func
