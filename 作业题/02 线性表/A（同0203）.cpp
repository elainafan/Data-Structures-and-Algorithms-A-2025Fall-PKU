#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
string x,y;
int main(){
    while(cin>>x>>y){
        int temp=0;
        int tem=0;
        for(int i=0;i<x.length();i++){
            if(x[i]-'a'+97>temp){
                temp=x[i]-'a'+97;
                tem=i;
            }
        }
        string ans=x.substr(0,tem+1);
        ans+=y;
        ans+=x.substr(tem+1);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}