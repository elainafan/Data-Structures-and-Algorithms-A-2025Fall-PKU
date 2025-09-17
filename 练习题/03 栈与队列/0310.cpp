#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 105
using namespace std;
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
int ma[maxn][maxn];
bool vis[maxn][maxn][2];
int m,n;
int sx,sy;
int fx,fy;
int kx,ky;
char c;
int ans=1e9+7;
vector<pair<int,int>>res;
vector<pair<int,int>>res_2;
void dfs(int x,int y,int cnt,int st){
    if(x==fx&&y==fy&&st==1){
        if(cnt<ans){
            res_2=res;
            ans=cnt;
        }
        return ;
    }
    res.push_back(pair(x,y));
    vis[x][y][st]=true;
    for(int i=1;i<=4;i++){
        int ax=x+dx[i],ay=y+dy[i];
        if(ax>=1&&ax<=m&&ay>=1&&ay<=n&&ma[ax][ay]==0){
            if(ax==kx&&ay==ky){
                if(!vis[ax][ay][1]) dfs(ax,ay,cnt+1,1);
            }
            else{
                if(!vis[ax][ay][st]) dfs(ax,ay,cnt+1,st);
            }
        }
    }
    vis[x][y][st]=false;
    res.pop_back();
    return ;
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='0') ma[i][j]=0;
            else if(c=='1') ma[i][j]=1;
            else if(c=='R'){
                ma[i][j]=0;sx=i;sy=j;
            }
            else if(c=='C'){
                ma[i][j]=0;fx=i;fy=j;
            }
            else if(c=='Y'){
                ma[i][j]=0;kx=i;ky=j;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            vis[i][j][0]=false;vis[i][j][1]=false;
        }
    }
    dfs(sx,sy,0,0);
    res_2.push_back(pair(fx,fy));
    for(auto p:res_2) cout<<p.first<<' '<<p.second<<endl;
    system("pause");
    return 0;
}