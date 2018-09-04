#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double e = 0.0001;

double F(double x) {
    return x * x - 101 * x + 100;
}

double f(double x) {
    return 2 * x - 101;
}

void divide(double x1, double x2) {
    double y1, y2, m, result;
    cout << "Division: " << endl;
    int times = 0;
    y1 = F(x1);
    y2 = F(x2);
    if(y1 * y2 > 0) {
        cout << "Unable to solve." << endl;
        return;
    }
    while(1) {
        cout << ++times << " solve times: " << m << endl;
        m = (x1 + x2) / 2;
        result = F(m);
        if(fabs(x1 - m) <= e)  break;
        if(y1 * result < 0)
            x2 = m;
        else if(result * y2 < 0)
            x1 = m;
        else continue;
    }
    cout << endl << "Result: " << endl << "Times: " << times << endl << "Solve: " << setprecision (8) << m << endl;
}

double newtonFunc(double x) {
    return x - F(x) / f(x);
}

void newton(double x) {
    cout << endl << "Newton: " << endl;
    int times = 0;
    double y = newtonFunc(x);
    while(1){
        if(fabs(y - x) <= e) break;
        x = y;
        y = newtonFunc(x);
        cout << ++times << " Times: " << setprecision (7) << x << endl;
    }
    cout << endl << "Result: " << endl << "Times: " << times << endl << "Solve: " << setprecision (7) << x << endl;
}

int main() {
    double x1, x2, x;
    int i = 1;
    cout.precision(7);
    cout << "Function: x^2 - 101 * x + 100" << endl << endl;
    cout << "Input x1, x2 for division: " << endl;
    cin >> x1 >> x2;
    cout << "Input x for newton: " << endl;
    cin >> x;
    divide(x1, x2);
    newton(x);
}
