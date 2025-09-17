#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 35
using namespace std;
int dx[9]={0,2,2,1,1,-1,-1,-2,-2},dy[9]={0,1,-1,2,-2,2,-2,1,-1};
int fdx[9]={0,1,1,0,0,0,0,-1,-1},fdy[9]={0,0,0,1,-1,1,-1,0,0};
int sx,sy,fx,fy;
int ma[maxn][maxn];
int m;
int tx,ty;
int fin=1e9+7;
queue<pair<int,int>>q;
string ans[11][11];
int dis[11][11];
int cnt[11][11];
int main(){
    cin>>sx>>sy>>fx>>fy;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>tx>>ty;
        ma[tx][ty]=1;
    }
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            dis[i][j]=1e9+7;
        }
    }
    q.push(make_pair(sx,sy));
    dis[sx][sy]=0;cnt[sx][sy]=1;
    ans[sx][sy]='('+to_string(sx)+','+to_string(sy)+')';
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int i=1;i<=8;i++){
            int ax=x+dx[i],ay=y+dy[i];
            int tx=x+fdx[i],ty=y+fdy[i];
            if(ax<0||ax>10||ay<0||ay>10||ma[ax][ay]==1||ma[tx][ty]==1) continue;
            if(dis[ax][ay]==dis[x][y]+1){
                cnt[ax][ay]+=cnt[x][y];continue;
            }
            if(dis[ax][ay]<dis[x][y]+1) continue;
            dis[ax][ay]=dis[x][y]+1;
            cnt[ax][ay]=cnt[x][y];
            ans[ax][ay]=ans[x][y]+"-("+to_string(ax)+','+to_string(ay)+')';
            q.push(pair(ax,ay));
        }
    }
    if(cnt[fx][fy]==1) cout<<ans[fx][fy]<<endl;
    else cout<<cnt[fx][fy]<<endl;
    system("pause");
    return 0;
}