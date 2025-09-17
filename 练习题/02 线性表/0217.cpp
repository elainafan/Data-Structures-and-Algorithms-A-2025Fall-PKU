#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) x&(-x)
#define maxn 25
using namespace std;
int n;
int dx,dy;
int ma[2*maxn+1][2*maxn+1];
int main(){
    cin>>n;
    dx=1,dy=n;
    for(int i=1;i<=(2*n-1)*(2*n-1);i++){
        ma[dx][dy]=i;
        if(dx==1&&dy==2*n-1){
            dx++;continue;
        }
        if(dx-1>=1&&dx-1<=2*n-1&&dy+1>=1&&dy+1<=2*n-1&&ma[dx-1][dy+1]!=0){
            dx++;continue;
        }
        if(dx==1){
            dx=2*n-1;dy++;continue;
        }
        if(dy==2*n-1){
            dx--;dy=1;continue;
        }
        dx--;dy++;
    }
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            cout<<ma[i][j]<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}