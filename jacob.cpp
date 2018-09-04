#include<iostream>
#include<cmath>

#define N 10
#define INF 20
#define ZERO 0.000005

using namespace std;

double jacob[3], gauss[3];

void acquireVal(double co[N][N], double val[N][N], int n) {
    for(int i = 0; i < n; i++) {
        int d = co[i][i];
        val[i][i] = 1;
        for(int j = 0; j < n; j++) {
            if(j != i)
                val[i][j] = -co[i][j] / d;
        }
        val[i][n] = co[i][n] / d;
    }
}

void jacobMethod(double val[N][N], int n) {
    double x0[N], x[N];
    for(int i = 0; i < n; i++) {
        x[i] = 0;
        x0[i] = 0;
    }
    cout << "Jacob: " << endl;
    for(int times = 0; times < 14; times++) {
        for(int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << x[i] << "   ";
        }
        for(int i = 0; i < n; i++) {
            x[i] = val[i][n];
            for(int j = 0; j < n; j++) {
                if(j != i) {
                    x[i] += x0[j] * val[i][j];
                }
            }
        }
        //if(fabs(x0[0] - x[0]) < ZERO)   break;
        for(int i = 0; i < n; i++) {
            x0[i] = x[i];
        }
        cout << endl;
    }
    cout << endl;
}

void gaussMethod(double val[N][N], int n) {
    double x[N], x0[N];
    for(int i = 0; i < n; i++) {
        x[i] = 0;
        x0[i] = INF;
    }
    cout << "Gauss-Seidel: " << endl;
    for(int times = 0; times < 10; times++) {
        int mark = 1;
        for(int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << x[i] << "   ";
        }
        for(int i = 0; i < n; i++) {
            x[i] = val[i][n];
            for(int j = 0; j < n; j++) {
                if(j != i) {
                    x[i] += x[j] * val[i][j];;
                }
            }
        }
        //if(fabs(x0[0] - x[0]) < ZERO)   break;
        cout << endl;
    }
}

int main() {
    double x[N], val[N][N] = {0};
    double coe1[N][N] = {{10, -1, -2, 7.2}, {-1, 10, -2, 8.3}, {-1, -1, 5, 4.2}};
    double coe2[N][N] = {{10, -2, -1, 7.2}, {-1, -2, 10, 8.3}, {-1, 5, -1, 4.2}};
    //val[N][N] = {{0.1, 0.2, 0.72}, {0.1, 0.2, 0.83}, {0.2, 0.2, 0.84}};
    //{{}{}{}{}
    acquireVal(coe1, val, 3);
    /*cout << "Function set: " << endl;
    cout << " 10 * x1 - x2 - x3 = 7.2" << endl
         << " - x1 + 10 * x2 - 2 * x3 = 8.3" << endl
         << " - x1 - x2 + 5 * x3 = 4.2" << endl << endl;*/

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++)
            cout << coe2[i][j] << "  ";
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++)
            cout << val[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
    jacobMethod(val, 3);
    gaussMethod(val, 3);
    return 0;
}
