#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x) //º¯Êýf(x)
{
   return pow(x, 1.0/3);
}
int main()
{
    double a = 0, b = 0, epsilon = 0;
    cout << "input a, b, epsilon" << endl;
    cin >> a >> b >> epsilon;
    int m = 1, k = 1;
    double h = (b - a) / 2.0;
    double T0 = h * (f(a) + f(b)), T = 3;
    double F = 0;
    while(fabs(T - T0) >= 3 * epsilon)
    {
       if(m != 1)
            T0 = T;
        F = 0;
        k = pow(2, m - 1);
       for(int i = 1; i <= k ; i++)
        {
            F += f(a + (2 * i - 1) * h);
        }
        T = T0 / 2.0 + h * F;
        m += 1;
        h /= 2.0;
        cout << setprecision(16) << "m = " << m << " T = " << T << endl;
    }
    return 0;
}
