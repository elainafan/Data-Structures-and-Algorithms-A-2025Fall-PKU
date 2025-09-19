#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int n;
ll merge(vector<int>& record,vector<int>& tmp,int l,int r){
    if(l>=r) return 0;
    int mid=(l+r)/2;
    ll cnt=merge(record,tmp,l,mid)+merge(record,tmp,mid+1,r);
    int i=l,j=mid+1,tot=i;
    while(i<=mid&&j<=r){
        if(record[i]>record[j]){
            tmp[tot++]=record[j];
            j++;cnt+=mid-i+1;
        }
        else{
            tmp[tot++]=record[i];
            i++;
        }
    }
    for(int k=i;k<=mid;k++) tmp[tot++]=record[k];
    for(int k=j;k<=r;k++) tmp[tot++]=record[k];
    copy(tmp.begin()+l,tmp.begin()+r+1,record.begin()+l);
    return cnt;
}
int main(){
    while(cin>>n){
        if(n==0) break;
        vector<int>ma(n);
        for(int i=0;i<=n-1;i++) cin>>ma[i];
        vector<int>tmp(n);
        cout<<merge(ma,tmp,0,n-1)<<endl;
    }
    system("pause");
    return 0;
}