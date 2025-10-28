#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 1/(1+(x*x));
}
void simphson_one_third(double a,double b,int n){
    double h=(b-a)/n;
    double ans = f(a)+f(b);
    for(int i=1;i<n;i++){
        if(i%2==0){
            ans += 2*(f(a+i*h));
        }
        else{
            ans+= 4*(f(a+i*h));
        }
    }
    ans= ans*h/3;
    cout<<ans<<endl;
}

void simphson_eight_third(double a,double b,int n){
    double h = (b-a)/n;
    double ans = f(a)+f(b);
    for(int i=1;i<n;i++){
        if(i%3==0){
            ans+=2*(f(a+i*h));
        }
        else{
            ans+=3*f(a+i*h);
        }
    }
    ans = (3*h*ans)/8;
    cout<<ans<<endl;
}

int main(){
    double a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    simphson_one_third(a,b,n);
    simphson_eight_third(a,b,n);
}
