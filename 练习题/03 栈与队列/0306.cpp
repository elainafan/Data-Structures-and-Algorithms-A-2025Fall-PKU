#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 200005
using namespace std;
int n;
int x;
stack<int>s;
int cnt=1;
vector<string>temp;
int ma[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ma[i];
    for(int i=1;i<=n;i++){
        s.push(i);
        temp.push_back("PUSH "+to_string(i));
        while(!s.empty()&&s.top()==ma[cnt]){
            temp.push_back("POP "+to_string(ma[cnt]));
            cnt++;s.pop();
        }
    }
    while(!s.empty()){
        auto node=s.top();s.pop();
        if(node==ma[cnt]){
            temp.push_back("POP "+to_string(ma[cnt]));
            cnt++;
        } 
        else break;
    }
    if(cnt!=n+1) cout<<"NO"<<endl;
    else{
        for(auto p:temp) cout<<p<<endl;
    }
    system("pause");
    return 0;
}