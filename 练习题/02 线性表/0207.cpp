#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
char ma[4][4];
char fa[4][4];
int ans=1e9+7;
int cnt=0;
char change(char x){
    return x=='b'?'w':'b';
}
void dfs(char c,int t){
    if(t==4){
        int flag=0;
        for(int i=0;i<=3;i++){
            if(ma[3][i]!=c) flag=1;
        }
        if(!flag) ans=min(ans,cnt);
        return ;
    }
    for(int i=0;i<=3;i++){
        if(ma[t-1][i]!=c){
            cnt++;
            for(int j=0;j<=4;j++){
                int ax=t+dx[j],ay=i+dy[j];
                if(ax>=0&&ax<=3&&ay>=0&&ay<=3){
                    ma[ax][ay]=change(ma[ax][ay]);
                }
            }
        }
    }
    dfs(c,t+1);
    return ;
}
int main(){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            cin>>ma[i][j];fa[i][j]=ma[i][j];
        }
    }
    for(int i=0;i<=15;i++){
        for(int j=0;j<=3;j++){
            if((i>>j)&1){
                cnt++;
                for(int v=0;v<=4;v++){
                    int ax=dx[v],ay=j+dy[v];
                    if(ax>=0&&ax<=3&&ay>=0&&ay<=3) ma[ax][ay]=change(ma[ax][ay]);
                }
            }
        }
        dfs('b',1);
        cnt=0;
        for(int j=0;j<=3;j++){
            for(int v=0;v<=3;v++){
                ma[j][v]=fa[j][v];
            }
        }
        for(int j=0;j<=3;j++){
            if((i>>j)&1){
                cnt++;
                for(int v=0;v<=4;v++){
                    int ax=dx[v],ay=j+dy[v];
                    if(ax>=0&&ax<=3&&ay>=0&&ay<=3) ma[ax][ay]=change(ma[ax][ay]);
                }
            }
        }
        dfs('w',1);
        for(int j=0;j<=3;j++){
            for(int v=0;v<=3;v++){
                ma[j][v]=fa[j][v];
            }
        }
        cnt=0;
    }
    if(ans==1e9+7) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    system("pause");
    return 0;
}