#include "func.hpp"
#include<iostream>

int main()
{
    int n;
    std::cout << "print n" << "\n";
    getNum(n);

    matrix* main = makeMatrix(n);
    getNodes(main, n);
    double* result = getResult(*main);
    printMatrix(*main);
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " "
                  << "\t";
    }
    //erase(main);
    delete[] result;
    return 0;
}

