#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int m,n,t;
int main(){
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++) dp[0][i]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i>=j){
                    dp[i][j]=dp[i-j][j]+dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i][i];
                }
            }
        }
        cout<<dp[m][n]<<endl;
    }
    system("pause");
    return 0;
}