#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define maxn 10005
using namespace std;
string x;
string s[maxn];
set<string>if_in;
int tot=0;
const int INF=1e9+7;
int dp[16][16];
bool check(string x,string y){
    int m=x.length();
    int n=y.length();
    memset(dp,INF,sizeof(dp));
    for(int i=0;i<=m;i++) dp[i][0]=i;
    for(int i=0;i<=n;i++) dp[0][i]=i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i][j-1])+1);
                continue;
            }
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }
    return dp[m][n]==1;
}
int main(){
    while(cin>>x){
        if(x=="#") break;
        s[++tot]=x;
        if_in.insert(x);
    }
    while(cin>>x){
        if(x=="#") break;
        if(if_in.find(x)!=if_in.end()){
            cout<<x<<" is correct"<<endl;continue;
        }
        cout<<x<<": ";
        for(int i=1;i<=tot;i++){
            auto temp=s[i];
            if(check(temp,x)) cout<<temp<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}