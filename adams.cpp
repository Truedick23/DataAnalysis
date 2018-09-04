#include<iostream>
#include<iomanip>
using namespace std;

const int N = 1000;

double Func(double x) {
    return (5.0 * x * x + 6.0 * x - 4.0 / x);
}

double func(double x) {
    return (10.0 * x + 6.0 + 8 / (x * x));
}

void adamsTwoExp(double ade[N], int n, double f[], double F[], double h) {
    ade[0] = F[0];
    ade[1] = F[1];
    for(int i = 1; i < n - 1; i++) {
        ade[i + 1] = ade[i] + h / 2.0 * (3.0 * f[i] - f[i - 1]);
    }
}

void adamsThreeExp(double ate[N], int n, double f[], double F[], double h) {
    ate[0] = F[0];
    ate[1] = F[1];
    ate[2] = F[2];
    for(int i = 2; i < n - 1; i++) {
        ate[i + 1] = ate[i] + h / 12.0 * (23.0 * f[i] - 16.0 * f[i - 1] + 5.0 * f[i - 2]);
    }
}

void adamsFourExp(double aqe[N], int n, double f[], double F[], double h) {
    aqe[0] = F[0];
    aqe[1] = F[1];
    aqe[2] = F[2];
    aqe[3] = F[3];
    for(int i = 3; i < n - 1; i++) {
        aqe[i + 1] = aqe[i] + h / 24.0 * (55.0 * f[i] - 59.0 * f[i - 1] + 37.0 * f[i - 2] - 9.0 * f[i - 3]);
    }
}

void adamsTwoImp(double adi[N], int n, double f[], double F[], double h) {
    adi[0] = F[0];
    for(int i = 0; i < n - 1; i++) {
        adi[i + 1] = adi[i] + h / 2.0 * (f[i + 1] + f[i]);
    }
}

void adamsThreeImp(double ati[N], int n, double f[], double F[], double h) {
    ati[0] = F[0];
    ati[1] = F[1];
    for(int i = 1; i < n - 1; i++) {
        ati[i + 1] = ati[i] + h / 12.0 * (5.0 * f[i + 1] + 8.0 * f[i] - f[i - 1]);
    }
}

void adamsFourImp(double aqi[N], int n, double f[], double F[], double h) {
    aqi[0] = F[0];
    aqi[1] = F[1];
    aqi[2] = F[2];
    for(int i = 2; i < n - 1; i++) {
        aqi[i + 1] = aqi[i] + h / 24.0 * (9.0 * f[i + 1] + 19.0 * f[i] - 5.0 * f[i - 1] + f[i - 2]);
    }
}

void RungeKuttaFirst(double LK1[N], int n, double f[], double F[], double h) {
    LK1[0] = f[0];
    LK1[n - 1] = f[n - 1];
    for(int i = 0; i < n - 1; i++) {
        LK1[i + 1] = LK1[i] + h / 2 * (f[i] + f[i + 1]);
    }
}

int main() {
    double xa, xb, h, f[N], F[N], n, choice;
    double ade[N], ate[N], aqe[N], adi[N], ati[N], aqi[N], LK1[N], LK2[N], LK3[N];
    cout << "Function: 5 * x * x + 6 * x - 4 / x" << endl << endl;
    cout << "input a & b: " << endl;
    cin >> xa >> xb;
    cout << "input n: " << endl;
    cin >> n;
    cout << "input your desired result: " << endl;
    cin >> choice;
    h = (xb - xa) / n;
    for(int i = 0; i < n; i++) {
        *(f + i) = func(xa + i * h);
        *(F + i) = Func(xa + i * h);
    }
    F[0] = LK1[0];
    F[1] = LK2[1];
    F[2] = LK3[2];
    adamsTwoExp(ade, n, f, F, h);
    adamsThreeExp(ate, n, f, F, h);
    adamsFourExp(aqe, n, f, F, h);
    adamsTwoImp(adi, n, f, F, h);
    adamsThreeImp(ati, n, f, F, h);
    adamsFourImp(aqi, n, f, F, h);
    /*for(int i = 0; i < n; i++) {
        cout << i + 1 << ":  " << F[i] << "  " << ade[i] << "  " << ate[i] << "  " << aqe[i] << "  " << adi[i] << "  " << ati[i] << "  " << aqi[i] << endl;
    }*/
    int i = choice;
    cout << "No. " << i << endl
        << "Exact: " << setprecision(15) << F[i] << endl << endl
        << "Second: " << endl
        << "Explicit: " << setprecision(15) << ade[i] << "  Implicit: " << setprecision(15) << adi[i] << endl
        << "Third: " << endl
        << "Explicit: " << setprecision(15) << ate[i] << "  Implicit: " << setprecision(15) << ati[i] << endl
        << "Fourth: " << endl
        << "Explicit: " << setprecision(15) << aqe[i] << "  Implicit: " << setprecision(15) << aqi[i] << endl;
}

