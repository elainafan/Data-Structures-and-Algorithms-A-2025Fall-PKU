#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 10005
using namespace std;
string ma[maxn];
int n;
string x;
unordered_map<string,int>if_in;
int cnt[maxn][26];
int dp[16][16];
const int INF=1e9+7;
bool check(int idx,string x){
    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=ma[idx].length();i++) dp[i][0]=i;
    for(int i=1;i<=x.length();i++) dp[0][i]=i;
    for(int i=1;i<=ma[idx].length();i++){
        for(int j=1;j<=x.length();j++){
            if(ma[idx][i-1]==x[j-1]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i][j-1])+1);
                continue;
            }
            dp[i][j]=min(dp[i][j],min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1);
        }
    }
    return dp[ma[idx].length()][x.length()]==1;
}
int main(){
    while(cin>>ma[++n]){
        if(ma[n]=="#") break;
        if_in[ma[n]]++;
    }
    n--;
    while(cin>>x){
        if(x=="#") break;
        if(if_in.count(x)){
            cout<<x<<" is correct"<<endl;
            continue;
        }
        cout<<x<<": ";
        for(int i=1;i<=n;i++){
            if(check(i,x)) cout<<ma[i]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}