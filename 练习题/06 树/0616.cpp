#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 50005
using namespace std;
int n,k;
int fa[3*maxn];//+n表示是eat，+2*n表示是enemy
int d,x,y;
int ans;
int get(int x){
    if(fa[x]==x) return fa[x];
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)]=get(y);
    return ;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=3*n;i++) fa[i]=i;
    for(int i=1;i<=k;i++){
        cin>>d>>x>>y;
        int x_self=x,x_eat=x+n,x_enemy=x+2*n;
        int y_self=y,y_eat=y+n,y_enemy=y+2*n;
        if((d==2&&x==y)||x>n||y>n){
            ans++;continue;
        }
        if(d==1){
            if(get(x_eat)==get(y_self)||get(x_enemy)==get(y_self)){
                ans++;continue;
            }
            merge(x_eat,y_eat);
            merge(x_self,y_self);
            merge(x_enemy,y_enemy);
        }
        else{
            if(get(x_self)==get(y_eat)||get(x_self)==get(y_self)){
                ans++;continue;
            }
            merge(x_eat,y_self);
            merge(x_self,y_enemy);
            merge(x_enemy,y_eat);
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}