#include <iostream>  
#include <math.h>    
#include <stdio.h>   

# define f(x) x*cos(x)  //deifinicao da função

using namespace std;


class Calc
{
    
    static const int m = 20;  //numero de divisões

    
    double h;         
    double x;         
    double f_o, f_e;  
    double s;         
    int k;            

public:
    
    void calcIntegral(double a, double b);
};


void Calc::calcIntegral(double a, double b)
{
    
    h = (b - a) / (2 * m);

    
    x = a;    
    f_o = 0;  
    f_e = 0;  
    s = 0;    

    
    for (k = 1; k <= 2 * m - 2; k++) {
        x = x + h;
        if (k % 2 == 1) {
            f_o = f_o + f(x);
        }
        else {
            f_e = f_e + f(x);
        }
    }
    
    s = f(a) + f(b);
    s += 4 * (f_o + f(b - h)) + 2 * f_e;
    s *= h / 3;

    
    printf("  /%f\n", b);
    printf("  | O valor aproximado para a integral eh  = %f\n", s);
    printf("  /%f\n", a);
}


int main()
{
    
    double a, b;

    try
    {
        
        cout << "Digite o limite superior pressione enter e digite o limite inferior A, B :\n";
        scanf_s("%lf \n %lf", &a, &b);

        
        Calc objCalc;

        
        objCalc.calcIntegral(a, b);
    }
    catch (...) {
        cout << "O valor aproximado da integral eh" << endl;
        return -1;
    }

    
    return 0;
}