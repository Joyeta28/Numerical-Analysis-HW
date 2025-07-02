#include<iostream>
#include<cmath>
using namespace std;

const double TOLERANCE = 1e-4;

double f(double x) {
    if (x <= 0)
        return NAN;
    return log(3*x) - 3;
}

void regulaFalsi(double a, double b) {
    if (f(a) * f(b) >= 0 || isnan(f(a)) || isnan(f(b))) {
        cout << "Invalid interval"<<endl;
        return;
    }

    double c;
    int iterations = 0;

    do {
        c = (a * f(b) - b * f(a))/(f(b) - f(a));
        iterations++;

        if (fabs(f(c)) < TOLERANCE)
            break;

        if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;

    } while (fabs(f(c)) > TOLERANCE);

    cout << "Regula Falsi Method:\n";
    cout << "Root "<< c <<" found in " <<iterations<<" iterations."<<endl;
}

int main() {
    double a, b;
    cin>>a>>b;
    if(a<0 || b<0){
        cout<<"invalid input"<<endl;
    }
    regulaFalsi(a, b);

    return 0;
}

