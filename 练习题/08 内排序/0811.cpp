#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 50005
using namespace std;
int n,k;
struct node{
    int a,b,id;
}cow[maxn];
bool cmp1(const node &x,const node &y){
    return x.a>y.a;
}
bool cmp2(const node &x,const node &y){
    return x.b>y.b;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>cow[i].a>>cow[i].b;
        cow[i].id=i;
    }
    sort(cow+1,cow+1+n,cmp1);
    sort(cow+1,cow+1+k,cmp2);
    cout<<cow[1].id<<endl;
    system("pause");
    return 0;
}