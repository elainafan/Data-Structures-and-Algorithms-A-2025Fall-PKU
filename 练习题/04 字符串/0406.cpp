#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int n;
string x[55];
string pattern;
string fx[55];
unordered_set<char>s;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];fx[i]=x[i];
    }
    cin>>pattern;
    for(int i=1;i<=n;i++){
        for(int j=0;j<x[i].length();j++){
            if(x[i][j]>='A'&&x[i][j]<='Z') x[i][j]=x[i][j]-'A'+'a';
        }
    }
    for(int i=0;i<pattern.length();i++){
        if(pattern[i]>='A'&&pattern[i]<='Z') pattern[i]=pattern[i]-'A'+'a';
    }
    string pre="";
    string suf="";
    int l=pattern.length();
    for(int i=0;i<l;i++){
        if(pattern[i]=='[') break;
        pre+=pattern[i];
    }
    for(int i=l-1;i>=0;i--){
        if(pattern[i]==']') break;
        suf+=pattern[i];
    }
    reverse(suf.begin(),suf.end());
    for(int i=pre.length();i<l-suf.length();i++){
        s.insert(pattern[i]);
    }
    for(int i=1;i<=n;i++){
        if(x[i].length()!=pre.length()+suf.length()+1) continue;
        if(x[i].substr(0,pre.length())!=pre) continue;
        if(x[i].substr(x[i].length()-suf.length(),suf.length())!=suf) continue;
        if(s.find(x[i][pre.length()])==s.end()) continue;
        cout<<i<<' '<<fx[i]<<endl;
    }
    system("pause");
    return 0;
}