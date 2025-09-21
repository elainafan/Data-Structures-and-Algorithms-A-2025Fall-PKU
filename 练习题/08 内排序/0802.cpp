#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int n;
string x;
map<string,int>ma;
char change(int x){
    if(x=='A'||x=='B'||x=='C') return '2';
    if(x=='D'||x=='E'||x=='F') return '3';
    if(x=='G'||x=='H'||x=='I') return '4';
    if(x=='J'||x=='K'||x=='L') return '5';
    if(x=='M'||x=='N'||x=='O') return '6';
    if(x=='P'||x=='R'||x=='S') return '7';
    if(x=='T'||x=='U'||x=='V') return '8';
    if(x=='W'||x=='X'||x=='Y') return '9';
    return 'd';
}
int main(){
    int maxx=-1;
    cin>>n;
    while(n--){
        cin>>x;
        char c[7];
        int cnt=0;
        for(int i=0;i<x.length();i++){
            if(cnt==8) break;
            if(x[i]=='-') continue;
            if(x[i]>='0'&&x[i]<='9'){
                c[cnt++]=x[i];continue;
            }
            c[cnt++]=change(x[i]);
        }
        string temp="";
        for(int i=0;i<=6;i++){
            temp+=c[i];
            if(i==2) temp+='-';
        }
        ma[temp]++;
        maxx=max(maxx,ma[temp]);
    }
    if(maxx==1){
        cout<<"No duplicates."<<endl;
        system("pause");
        return 0;
    }
    for(auto it=ma.begin();it!=ma.end();it++){
        if(it->second>=2) cout<<it->first<<' '<<it->second<<endl;
    }
    system("pause");
    return 0;
}