#include<bits/stdc++.h>
using namespace std;

int n;
float X;

float newtons_divided_diff(float x[],float y[]){
    float dd[n][n];
    for(int i=0;i<n;i++){
        dd[i][0] = y[i];
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1])/(x[i+j]-x[i]);
        }
    }
    double res = dd[0][0];
    double curr = 1;
    for(int i=1;i<n;i++){
        curr*=(X-x[i-1]);
        res += curr*dd[0][i];
    }
    return res;
}

int main(){

    cin>>n;
    float x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    cin>>X;

    cout<<newtons_divided_diff(x,y);
}
