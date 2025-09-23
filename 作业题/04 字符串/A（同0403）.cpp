#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
string x,y;
int main(){
    while(cin>>x>>y){
        int i=0;
        int m=x.length(),n=y.length();
        for(int j=0;j<n;j++){
            if(x[i]==y[j]) i++;
            if(i==m) break; 
        }
        if(i==m) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    system("pause");
    return 0;
}