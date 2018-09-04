#include <iostream>
#include <stdio.h>
using namespace std;

double func(double x) {
    return 5 * x + 4;
}

double calculate(int n, double x[], double y[]) {
    double x1[100] = {0}, x2[100] = {0}, result = 0;
    if(n == 2)
        return (y[1] - y[0]) / (x[1] - x[0]);
    for(int i = 1; i < n; i++)
        x1[i - 1] = x[i];
    for(int i = 0; i < n - 1; i++)
        x2[i] = x[i];
    return ((calculate(n - 1, x1, y) - calculate(n - 1, x2, y)) / (x[n] - x[0]));
}

void calculateMargin(int n, double y[]) {
    cout << endl;
    double marg[100];
    if(n == 1) {
        printf("ждY:   ");
        printf("%10.3f\n", y[0]);
        return;
    }
    printf("жд%dY: ", n);
    for(int i = 0; i < n; i++)
        printf("%10.2f", y[i]);
    for(int i = 0; i < n - 1; i++)
        marg[i] = y[i + 1] - y[i];
    for(int i = 0; i < n - 1; i++) {
        y[i] = marg[i];
    }
    cout << endl;
    calculateMargin(n - 1, y);
    return;
}

double fn(int n, double a[]) {
    double result = 0;
    for(int i = 0; i <= n; i++) {
        double mult = 1;
        for(int j = 0; j <= n; j++) {
            if(i != j)
                mult *= (a[i] - a[j]);
        }
        result += func(a[i]) / mult;
    }
    return result;
}

double newton(int n, double a[], double x) {
    double result = func(a[0]);
    a[n] = x;
    for(int i = 0; i <= n; i++) {
        double b = 1;
        for(int j = 0; j < i; j++) {
            b *= (x - a[j]);
        }
        result += fn(i, a) * b;
    }
    return result;
}

int main() {
    int n;
    double xn[100] = {0}, y[100] = {0}, result = 0, x;
    cout << "Please type x:" << endl;
    cin >> x;
    cout << "Please type n:" << endl;
    cin >> n;
    cout << "Please type " << n << " numbers: " << endl;
    for(int i = 0; i < n; i++)
        cin >> xn[i];
    for(int i = 0; i < n; i++)
        y[i] = func(xn[i]);
    calculateMargin(n, xn);
    cout << endl << "Newton Result is: " << newton(n, xn, x) << endl;
}
