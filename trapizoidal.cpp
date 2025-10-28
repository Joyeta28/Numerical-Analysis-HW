#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 1/(1+(x*x));
}
void trapizoidal(double a,double b,int n){
    double h = (b-a)/n;
    double ans = (f(a)+f(b))/2;
    for(int i=1;i<n;i++){
        ans += f(a+(i*h));
    }
    cout<<ans*h<<endl;
}
int main(){
    double a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    trapizoidal(a,b,n);
}
