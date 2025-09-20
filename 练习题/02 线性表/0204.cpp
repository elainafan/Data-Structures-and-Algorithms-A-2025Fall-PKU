#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int n;
string x;
int tot=0;
int main(){
    while(cin>>n){
        if(n==0) break;
        cin>>x;
        tot++;
        cout<<"Test case #"<<tot<<endl;
        int cnt=0;
        vector<int>pi(n);
        for(int i=1;i<n;i++){
            char b=x[i];
            while(cnt&&x[cnt]!=b) cnt=pi[cnt-1];
            if(x[cnt]==b) cnt++;
            pi[i]=cnt;
        }
        for(int i=1;i<n;i++){
            int len=i+1;
            int lps=pi[i];
            if(len%(len-lps)==0&&lps>0){
                cout<<len<<' '<<len/(len-lps)<<endl;
            }
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}