#include<bits/stdc++.h>
using namespace std;

int n;
float x;

void langrange_interpolation(float X[],float Y[]){
    float y=0;
    for(int i=0;i<n;i++){
        float curr = Y[i];
        for(int j=0;j<n;j++){
            if(i!=j){
            curr*=(x-X[j])/(X[i]-X[j]);
            }
        }
        y+=curr;
    }
    cout<<y<<endl;
}

int main(){
    cin>>n;
    float X[n];
    float Y[n];
    for(int i=0;i<n;i++){
        cin>>X[i]>>Y[i];
    }
    cin>>x;
    langrange_interpolation(X,Y);
}
