#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 2005
using namespace std;
int t;
int n,m;
int fa[2*maxn];
int x,y;
int get(int x){
    if(fa[x]==x) return fa[x];
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)]=get(y);
    return ;
}
int main(){
    cin>>t;
    for(int vv=1;vv<=t;vv++){
        cout<<"Scenario #"<<vv<<":"<<endl;
        cin>>n>>m;
        int flag=0;
        for(int i=1;i<=2*n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            int x_self=x,y_self=y;
            int x_another=x+n,y_another=y+n;
            if(get(x_self)==get(y_self)||get(x_another)==get(y_another)){
                flag=1;
            }
            merge(x_self,y_another);
            merge(y_self,x_another);
        }
        if(!flag) cout<<"No suspicious bugs found!"<<endl;
        else cout<<"Suspicious bugs found!"<<endl;
        cout<<endl;
    }
    system("pause");
    return 0;
}