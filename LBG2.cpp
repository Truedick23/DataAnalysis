#include<iostream>
#include<cmath>
using namespace std;

double f(double x) {
    return 3 * x * x  + 2 * x;
}

double F(double x) {
    return pow(x, 3) + pow(x, 2);
}

double Tn(double a, double b, int n) {
    double h = (b - a) / n, result = 0;
    if(n == 1) {
        result = h / 2.0 * (f(a) + f(b));
        return result;
    }
    result = Tn(a, b, n / 2.0) / 2.0;
    for(int i = 0; i < n; i++) {
        double x = h / 2.0 * f(a + (i + 1 / 2.0) * h);
        result += x;
    }
    return result;
}

double Sn(double a, double b, int n, int p) {
    double result;
    if(p == 1)
        result = 4 / 3.0 * Tn(a, b, 2 * n) - 1 / 3.0 * Tn(a, b, n);
    else
        result = pow(4, p) * Sn(a, b, 2 * n, p - 1) / (pow(4, p) - 1) -
                 1 * Sn(a, b, n, p - 1) / (pow(4, p) - 1);
    return result;
}

int main() {
    double a, b;
    double R1, R2, R3, R;
    cout << "Input a & b: " << endl;
    cin >> a >> b;
    R1 = Sn(a, b, 20, 3);       //龙贝格算法
    R2 = Tn(a, b, 20);          //复化梯算法
   // R3 = Sn(a, b, 20, 6);       更高阶的算法
    R = F(b) - F(a);            //准确值
    cout << endl << "Results are: " << endl << endl;
    cout << "Trapezium: " << R2 << endl << "Lebesgue: " << R1 << endl << "Exact Value: " << R << endl;
    return 0;
}
