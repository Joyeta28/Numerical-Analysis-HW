#include<bits/stdc++.h>
using namespace std;

double f(double x,double y){
    return x+y;
}

int main(){
    double x0,y0,xn,h;
    cin>>x0>>y0>>xn>>h;
    int n=(xn-x0)/h;

    double x=x0;
    double y=y0;
    cout<<fixed<<setprecision(6);
     cout << "x\t\ty\n";
    cout << x << "\t" << y << endl;
    for(int i=0;i<n;i++){
        y=y+ h*f(x,y);
        x=x+h;
         cout << x << "\t" << y << endl;
    }
    cout<<y<<endl;
}
