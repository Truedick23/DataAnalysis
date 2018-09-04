#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int N = 1000;

double Func(double x, double y) {
    return y  - 2 * x / y;
}

double Solve(double x) {
    return sqrt(1 + 2 * x);
}

int main() {
    double x0, y0, K1, K2, K3, K4, h, yp, Yp;
    double x[N], y[N], Y[N];
    int N, n = 4;
    cout << "Function: y' = y - 2 * x / y" << endl
         << "Exact solve: y = sqrt(1 + 2 * x)" << endl << endl;
    cout << "x0 = ";
    cin >> x0;
    cout << "y0 = ";
    cin >> y0;
    cout << "h = ";
    cin >> h;
    cout << "N = ";
    cin >> N;
    for(int n = 0; n <= 3; n++) {
        x[n] = x0 + h;
        K1 = Func(x0, y0);
        K2 = Func(x0 + h / 2, y0 + h * K1 / 2);
        K3 = Func(x0 + h / 2, y0 + h * K2 / 2);
        K4 = Func(x[n], y0 + h * K3);
        y[n] = y0 + h * (K1 + 2 * K2 + 2 * K3 + K4) / 6;
        Y[n] = Func(x[n], y[n]);
        x0 = x[n];
        y0 = y[n];
        cout << "x" << left << setw(2) << n << " = " << left << setw(12) << x[n] <<
                "                   " <<
                "y" << left << setw(2) << n << " = " << left << setw(12) << y[n] <<
                "y(x" << left << setw(1) << n << ") = " << left << setw(12) << Solve(x[n]) << endl;
    }
    for(int n = 4; n <= N; n++) {
        x[4] = x[3] + h;
        yp = y[3] + h * (55 * Y[3] - 59 * Y[2] + 37 * Y[1] - 9 * Y[0]) / 24;
        Yp = Func(x[4], yp);
        y[4] = y[3] + h * (9 * Yp + 19 * Y[3] - 5 * Y[2] + Y[1]) / 24;
        Y[4] = Func(x[4], y[4]);
        cout << "x" << left << setw(2) << n << " = " << left << setw(12) << x[4] <<
                "y*" << left << setw(2) << n << " = " << left << setw(12) << yp <<
                "y" << left << setw(2) << n << " = " << left << setw(12) << y[4] <<
                "y(x" << left << setw(1) << n << ") = " << left << setw(12) << Solve(x[4]) << endl;
        x[3] = x[4];
        y[3] = y[4];
        for(int i = 0; i < 4; i++) {
            Y[i] = Y[i + 1];
        }
    }
    return 0;
}
