#include <iostream>
#include <cmath>
using namespace std;

double TOLERANCE = 0.0001;
double f(double x) {
    return 4*x*x + 3*x -3;
}

void bisection(double a, double b){
    double c;
    if(f(b)*f(a) >= 0) return;
    int it=1;
    double error = abs(b-a);
    while(error >= tolerance){
        c = (a+b)/2;
        error = abs(a-b);
        cout<<"iteration : "<<it<<endl<<" a "<<a<<" b "<<b<<" c "<<c<<" f(c) "<<f(c)<<" error "<<error<<endl;
            it++;
        if(f(c)*f(a) < 0){
            b=c;
        }
        else{
            a=c;
        }

    }

}

bool betterRange(double &a, double &b) {
    double step = 0.1;
    for (double x = -100; x < 100; x += step) {
        if (f(x) * f(x + step) < 0) {
            a = x;
            b = x + step;
            return true;
        }
    }
    return false;
}

void bisectionBetter(double a,double b) {

    if (!betterRange(a, b)) {
        cout << "No sign change found in range [-100, 100]."<<endl;
        return;
    }


    int iteration = 0;
    double c;

    while (abs(b - a) >= TOLERANCE) {
        c = (a + b) / 2;
        iteration++;

        if (f(c) == 0) break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Better Method:"<<endl;
    cout << "Root = " << c << " in " << iteration << " iterations."<<endl;
}

int main() {
    double a,b;
    cin>>a>>b;
    bisectionTraditional(a,b);

    bisectionBetter(a,b);

    return 0;
}
