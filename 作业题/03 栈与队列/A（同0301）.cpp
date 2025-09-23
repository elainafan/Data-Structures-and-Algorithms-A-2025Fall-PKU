#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 1000005
using namespace std;
int ma[maxn];
int mixx[maxn];
int maxx[maxn];
int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>ma[i];
    deque<int>q;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&ma[q.back()]>=ma[i]) q.pop_back();
        q.push_back(i);
        while(!q.empty()&&q.front()<i-k+1) q.pop_front();
        if(i>=k) mixx[i]=ma[q.front()];
    }
    for(int i=k;i<=n;i++) cout<<mixx[i]<<' ';
    q.clear();cout<<endl;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&ma[q.back()]<=ma[i]) q.pop_back();
        q.push_back(i);
        while(!q.empty()&&q.front()<i-k+1) q.pop_front();
        if(i>=k) maxx[i]=ma[q.front()];
    }
    for(int i=k;i<=n;i++) cout<<maxx[i]<<' ';
    system("pause");
    return 0;
}