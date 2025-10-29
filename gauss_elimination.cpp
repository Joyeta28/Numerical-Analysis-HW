#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    float a[n+1][n+1],x[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            cin>>a[i][j];
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(i!=j){
                float ratio = a[i][j]/a[j][j];
                for(int k=1;k<=n+1;k++){
                    a[i][k] = a[i][k] - ratio*a[j][k];
                }
            }
        }
    }
   for(int i=1;i<=n;i++){
       x[i] = a[i][n+1]/a[i][i];
       cout<<"X"<<i<<" "<<x[i]<<endl;
   }
}
