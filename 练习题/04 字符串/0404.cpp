#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
string x;
int main(){
    while(cin>>x){
        if(x==".") break;
        int cnt=0;
        int m=x.length();
        vector<int>pi(m);
        for(int i=1;i<m;i++){
            char b=x[i];
            while(cnt&&x[cnt]!=b) cnt=pi[cnt-1];
            if(x[cnt]==b) cnt++;
            pi[i]=cnt;
        }
        int len=m;
        int lps=pi[m-1];
        if(lps>0&&len%(len-lps)==0) cout<<len/(len-lps)<<endl;
        else cout<<1<<endl;
    }
    system("pause");
    return 0;
}