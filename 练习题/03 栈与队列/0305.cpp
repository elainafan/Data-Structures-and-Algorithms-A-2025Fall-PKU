#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int n;
int cnt[5]={1,10,100,1000,10000};
int x;
vector<int>res;
queue<int>q[10];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        q[x%10].push(x);
    }  
    for(int i=1;i<=4;i++){
        cout<<"Step"<<i<<'.'<<endl;
        for(int j=0;j<=9;j++){
            cout<<"Queue"<<j<<':';
            while(!q[j].empty()){
                auto node=q[j].front();q[j].pop();
                res.push_back(node);
                cout<<node<<' ';
            }
            cout<<endl;
        }
        int flag=0;
        for(int p:res){
            if(p>=cnt[i]){
                flag=1;break;
            }
        }
        if(i==4||!flag) break;
        for(int j=0;j<res.size();j++){
            int temp=res[j]%cnt[i+1];
            temp/=cnt[i];
            q[temp].push(res[j]);
        }
        res.clear();
    }
    for(int p:res) cout<<p<<' ';
    system("pause");
    return 0;
}