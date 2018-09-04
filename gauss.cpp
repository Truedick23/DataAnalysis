#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define N 10
#define ZERO 1e-6
double solve[N] = {0};

void printcoe(double coe[N][N], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + 1; j++) {
            cout << left << setw(8) << setprecision(3) << coe[i][j];
        }
        cout << endl;
    }
    cout << endl;
};

void traceback(double coe[N][N], double solve[], int n) {
    solve[n - 1] = coe[n - 1][n] / coe[n - 1][n - 1];
    for(int i = n; i >= 0; i--) {
        double sum = 0;
        for(int j = i + 1; j < n; j++) {
            sum += coe[i][j] * solve[j];
        }
        solve[i] = ((coe[i][i] == 0) ? 0 : (coe[i][n] - sum) / coe[i][i]);
    }
}

void printsolve(double solve[], int n) {
    cout << "Solve: " << endl;
    for(int i = 0; i < n; i++) {
        cout << " x" << i + 1 << " = " << solve[i] << endl;
    }
}


void gauss(double coe[N][N], int n) {
    int times[100];
    for(int k = 0; k < n; k++) {
        cout << "(" << k + 1 << ")" << endl;
        printcoe(coe, n);
        for(int i = k + 1; i < n; i++) {
            times[i] = ((coe[k][k] == 0) ? 0 : coe[i][k] / coe[k][k]);
            if(times[i] == 0)   {
                cout << "Unsolvable." << endl;
                return;
            }
        }
        for(int i = k + 1; i < n; i++) {
            for(int j = 0; j < n + 1; j++) {
                coe[i][j] -= times[i] * coe[k][j];
            }
        }
    }
    traceback(coe, solve, n);
    printsolve(solve, n);
}

void gauss_line_major(double coe[N][N], int n) {
    for(int i = 0; i < n; i++) {
        cout << "(" << i + 1 << ")" << endl;
        printcoe(coe, n);
        int maj = i;
        for(int j = i + 1; j < n; j++)
            if(fabs(coe[j][i]) > fabs(coe[maj][i]))
                maj = j;
        if(fabs(coe[maj][i]) <= ZERO){
            cout << "Unsolvable." << endl;   return;
        }
        if(maj != i) {
            for(int k = i; k < n + 1; k++) {
                double temp = coe[i][k];
                coe[i][k] = coe[maj][k];
                coe[maj][k] = temp;
            }
        }
        for(int j = i + 1; j < n; j++) {
            double times = coe[j][i] / coe[i][i];
            for(int m = i; m < n + 1; m++) {
                coe[j][m] -= times * coe[i][m];
                if(fabs(coe[j][m]) <= ZERO)    coe[j][m] = 0;
            }
        }
    }
    traceback(coe, solve, n);
    printsolve(solve, n);
}

int main() {
    int n = 4;
    double coe1[N][N] =
    //{{1, -1, 1, -4}, {-2, 2, 3, -12}, {2, 2, 1, 11}};
    //{{1, -1, 1, -4}, {-2, 2, 3, -12}, {2, -2, 1, 11}};
    {{1, 1, 1, 1, 10}, {2, 3, 1, 1, 15}, {3, -1, 2, -1, 3}, {4, 1, -3, 2, 5}};
    double coe2[N][N] =
    //{{1, -1, 1, -4}, {-2, 2, 3, -12}, {2, 2, 1, 11}};
    //{{1, -1, 1, -4}, {-2, 2, 3, -12}, {2, -2, 1, 11}};
    {{1, 1, 1, 1, 10}, {2, 3, 1, 1, 15}, {3, -1, 2, -1, 3}, {4, 1, -3, 2, 5}};
    gauss(coe1, n);
    cout << endl;
    gauss_line_major(coe2, n);
    return 0;
}

