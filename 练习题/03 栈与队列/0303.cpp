#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
queue<string>q[10];
queue<string>fq[4];
int n;
string x;
vector<string>res;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        q[x[1]-'0'].push(x);
    }
    for(int i=1;i<=9;i++){
        cout<<"Queue"<<i<<":";
        while(!q[i].empty()){
            auto node=q[i].front();q[i].pop();
            cout<<node<<' ';
            res.push_back(node);
        }
        cout<<endl;
    }
    for(auto p:res) fq[p[0]-'A'].push(p);
    res.clear();
    for(int i=0;i<=3;i++){
        cout<<"Queue"<<(char)('A'+i)<<':';
        while(!fq[i].empty()){
            auto node=fq[i].front();fq[i].pop();
            cout<<node<<' ';
            res.push_back(node);
        }
        cout<<endl;
    }
    for(auto p:res) cout<<p<<' ';
    system("pause");
    return 0;
}