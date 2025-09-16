#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 35
using namespace std;
int n,m;
int ma[maxn][maxn];
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
int tempx=1,tempy=1;
int cnt=0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*n;i++){
        ma[tempx][tempy]=i;
        if(tempx+dx[cnt]>n||tempx+dx[cnt]<=0||tempy+dy[cnt]>n||tempy+dy[cnt]<=0||ma[tempx+dx[cnt]][tempy+dy[cnt]]!=0) cnt=(cnt+1)%4;
        tempx+=dx[cnt],tempy+=dy[cnt];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ma[i][j]==m) cout<<i<<' '<<j<<endl;
        }
    }
    system("pause");
    return 0;
} 