#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
priority_queue<int>q;
int t;
int n;
int op,x;
int main(){
    cin>>t;
    while(t--){
        while(!q.empty()) q.pop();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>op;
            if(op==1){
                cin>>x;
                q.push(-x);
            }
            else{
                int node=q.top();q.pop();
                cout<<-node<<endl;
            }
        }
    }
    system("pause");
    return 0;
}