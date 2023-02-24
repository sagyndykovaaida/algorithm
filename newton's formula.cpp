#include <iostream>

double sqrt(double x) {
    double y = x;
    double eps = 1e-6; 
    while (y * y - x > eps) {
        y = (y + x / y) / 2;
    }
    return y;
}

int main() {
    double x = 2;
    double sqrt_x = sqrt(x);

    std::cout << sqrt_x ;

    return 0;
}
