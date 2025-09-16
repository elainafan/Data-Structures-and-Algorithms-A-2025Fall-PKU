#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int t;
int x,y;
int main(){
    cin>>t;
    while(t--){
        map<int,int>ma;
        while(cin>>x>>y){
            if(y<0) break;
            ma[-y]+=x;
        }
        while(cin>>x>>y){
            if(y<0) break;
            ma[-y]+=x;
        }
        for(auto it=ma.begin();it!=ma.end();it++){
            if(it->second==0) continue;
            cout<<"[ "<<it->second<<' '<<-it->first<<" ] ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}