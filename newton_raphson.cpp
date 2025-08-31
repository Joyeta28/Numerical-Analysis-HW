#include<bits/stdc++.h>
using namespace std;
const double TOLERANCE = 1e-3;
double f(double x){
    return (x*x*x*x*x) - 3*x + 5;
}

double f_slope(double x){
    return 5*(x*x*x*x) - 3;
}
void newton_raphson(double a){
    int iteration = 0;
    double error;

    do{
        double prev = a;
        a = prev - f(prev)/f_slope(prev);
        error = fabs((a - prev)/a);
        iteration++;
        cout<<" iteration "<<iteration<<" x : "<<a<<" relative error "<<error<<endl;
    }while(error>TOLERANCE);
    cout<<"Root "<<a<<endl;
}
int main(){
    double a;
    cin>>a;
    newton_raphson(a);
}
