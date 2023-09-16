#include <stdio.h>

static double F(double x) {
    return x * x;
}

static double f(double x) {
    double diff = 0.000000001;
    return (F(x+diff) - F(x)) / diff;
}

int main() {
    double points[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000 };
    int pointsCount = sizeof(points) / sizeof(double);
    for (size_t i = 0; i < pointsCount; i++) {
        printf("Derivative of x^2 at %f = %f\n", points[i], f(points[i]));
    }
}