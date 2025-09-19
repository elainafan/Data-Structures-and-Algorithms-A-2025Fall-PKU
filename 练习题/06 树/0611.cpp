#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 200005
using namespace std;
struct SegmentTree{
    int l,r;
    ll add,sum;
}tree[4*maxn];
int n,q;
int ma[maxn];
char op;
int x,y,d;
void build(int x,int l,int r){
    tree[x].l=l;tree[x].r=r;
    if(tree[x].l==tree[x].r){
        tree[x].sum=ma[l];
        tree[x].add=0;
        return ;
    }
    int mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
    return ;
}
void pushdown(int x){
    if(tree[x].add){
        tree[x*2].add+=tree[x].add;
        tree[x*2+1].add+=tree[x].add;
        tree[x*2].sum+=tree[x].add*(tree[x*2].r-tree[x*2].l+1);
        tree[x*2+1].sum+=tree[x].add*(tree[x*2+1].r-tree[x*2+1].l+1);
        tree[x].add=0;
    }
    return ;
}
void change(int x,int l,int r,int d){
    if(l<=tree[x].l&&tree[x].r<=r){
        tree[x].sum+=(tree[x].r-tree[x].l+1)*d;
        tree[x].add+=d;
        return ;
    }
    int mid=(tree[x].l+tree[x].r)/2;
    pushdown(x);
    if(l<=mid) change(x*2,l,r,d);
    if(r>mid) change(x*2+1,l,r,d);
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
    return ;
}
ll query(int x,int l,int r){
    if(l<=tree[x].l&&tree[x].r<=r) return tree[x].sum;
    pushdown(x);
    ll ans=0;
    int mid=(tree[x].l+tree[x].r)/2;
    if(l<=mid) ans+=query(x*2,l,r);
    if(r>mid) ans+=query(x*2+1,l,r);
    return ans;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>ma[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op=='Q'){
            cin>>x>>y;
            ll ans=query(1,x,y);
            cout<<ans<<endl;
        }
        else{
            cin>>x>>y>>d;
            change(1,x,y,d);
        }
    }
    system("pause");
    return 0;
}