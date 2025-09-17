#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int n,k,p;
vector<int>res;
deque<int>q;
int cnt=0;
int sum=0;
int main(){
    cin>>n>>k>>p;
    for(int i=1;i<=k;i++) q.push_back(i);
    while(sum<k/n){
        cnt++;
        if(cnt%n){
            q.pop_front();
        }
        else{
            res.push_back(q.front());q.pop_front();
            sum++;
        }
        for(int i=1;i<=p;i++){
            q.push_back(q.front());q.pop_front();
        }
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    system("pause");
    return 0;
}