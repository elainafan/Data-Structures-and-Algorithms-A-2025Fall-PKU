#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 100005
using namespace std;
int n,m;
int ma[maxn];
int d;
char op;
const int INF=65536;
void add(int x){
    for(int i=1;i<=n;i++) ma[i]=(ma[i]+x)%INF;
    return ;
}
int query(int x){
    int ans=0;
    for(int i=1;i<=n;i++){
        if((ma[i]>>x)&1) ans++;
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>ma[i];
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=='C'){
            cin>>d;
            add(d);
        }
        else{
            cin>>d;
            cout<<query(d)<<endl;
        }
    }
    system("pause");
    return 0;
}