#include<bits/stdc++.h>
using namespace std;

double f_slope(double x,double y){
    return x+y;
}

int main(){
    double x0,y0,xn,h;
    cout<<"enter initial value of x and y"<<endl;
    cin>>x0>>y0;
    cout<<"enter the value of x"<<endl;
    cin>>xn;
    cout<<"enter step size";
    cin>>h;
    int n = (xn-x0)/h;//number of step

    double x = x0;
    double y = y0;
    cout << fixed << setprecision(6);
    cout<<"step by step values "<<endl;
    cout<<"x\t\ty"<<endl;
    cout<<x<<"\t"<<y<<endl;

    for(int i=0;i<n;i++){
        double k1 = f_slope(x,y);
        double k2 = f_slope(x+(h/2),y+(k1*h/2));
        double k3 = f_slope(x+(h/2),y+(k2*h/2));
        double k4 = f_slope(x+h,y+(k3*h));

        y = y+((k1+(2*k2)+(2*k3)+k4)*h)/6;
        x = x+h;
        cout<<x<<" \t"<<y<<endl;
    }
    cout<< "solution of x at x = "<<xn<<"is "<<y<<endl;

}
