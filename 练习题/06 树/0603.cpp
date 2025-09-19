#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 100005
using namespace std;
int n,m;
int t;
char op;
int x,y;
int fa[2*maxn];
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
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=2*n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            cin>>op>>x>>y;
            int x_self=x,y_self=y;
            int x_another=x+n,y_another=y+n;
            if(op=='A'){
                if(get(x_self)==get(y_self)&&get(x_another)==get(y_another)){
                    cout<<"In the same gang."<<endl;
                }
                else if(get(x_self)==get(y_another)&&get(x_another)==get(y_self)){
                    cout<<"In different gangs."<<endl;
                }
                else cout<<"Not sure yet."<<endl;
            }
            else{
                merge(x_another,y_self);
                merge(x_self,y_another);
            }
        }
    }
    system("pause");
    return 0;
}