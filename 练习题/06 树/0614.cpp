#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 50005
using namespace std;
int n,m;
int x,y;
int fa[maxn];
int cnt=0;
int get(int x){
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)]=get(y);
    return ;
}
int main(){
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            merge(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(fa[i]==i) ans++;
        }
        cnt++;
        cout<<"Case "<<cnt<<": ";
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}