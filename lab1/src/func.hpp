#include <iostream>

namespace func{
    struct Line{
        int n; // lenght
        double* a;
    };
    struct matrix{
        int m; // number of lines
        Line* lines; // array of lines
    };

};
