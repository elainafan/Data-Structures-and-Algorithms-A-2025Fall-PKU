#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 105
using namespace std;
int n,m;
struct node{
    string x;
    int val;
    bool operator<(const node &other){
        return val<other.val;
    }
}q[105];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>q[i].x;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n-1;j++){
            for(int v=0;v<j;v++){
                if(q[i].x[v]>q[i].x[j]) q[i].val++;
            }
        }
    }
    sort(q+1,q+1+m);
    for(int i=1;i<=m;i++) cout<<q[i].x<<endl;
    system("pause");
    return 0;
}