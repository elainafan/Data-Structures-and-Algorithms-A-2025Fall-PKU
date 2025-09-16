#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 25
using namespace std;
int r,c;
int ans=0;
bool vis[26];
char ma[maxn][maxn];
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
void dfs(int x,int y,int temp){
    ans=max(ans,temp);
    vis[ma[x][y]-'A']=true;
    for(int i=1;i<=4;i++){
        int ax=x+dx[i],ay=y+dy[i];
        if(ax>=1&&ax<=r&&ay>=1&&ay<=c&&!vis[ma[ax][ay]-'A']) dfs(ax,ay,temp+1);
    }
    vis[ma[x][y]-'A']=false;
    return ;
}
int main(){
    cin>>r>>c;
    for(int i=0;i<=25;i++) vis[i]=false;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>ma[i][j];
        }
    }
    dfs(1,1,1);
    cout<<ans<<endl;
    system("pause");
    return 0;
}