
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    float a[n+1][n+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            cin>>a[i][j];
        }
    }

    for(int j=1;j<=n;j++){
        int mxr=j;
        for(int i=j+1;i<=n;i++){
            if(a[i][j]>a[mxr][j]) mxr=i;
        }
        if(mxr!=j){
            for(int i=1;i<=n+1;i++){
                swap(a[j][i],a[mxr][i]);
            }
        }
        float pivot=a[j][j];

        for(int i=1;i<=n;i++){
            if(i!=j){
                float rat=a[i][j]/pivot;
                for(int k=1;k<=n+1;k++){
                    a[i][k]=a[i][k]-(rat*a[j][k]);
                }
            }
        }
    }
    float x[n+1];
     for(int i=1;i<=n;i++){
       x[i]=a[i][n+1]/a[i][i];
       cout<<"X" <<i<<"   "<< x[i]<<endl;
    }
}
