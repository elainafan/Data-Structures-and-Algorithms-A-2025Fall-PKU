#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int x;
vector<int>ori;
int main(){
    while(cin>>x){
        ori.push_back(x);
    }
    int temp=ori.size()/2;
    vector<int>inorder(ori.begin(),ori.begin()+temp);
    vector<int>postorder(ori.begin()+temp,ori.end());
    vector<int>preorder;
    function<void(vector<int>,vector<int>)>dfs=[&](vector<int>inorder,vector<int>postorder){
        if(inorder.size()==0) return ;
        if(inorder.size()==1){
            preorder.push_back(inorder[0]);return ;
        }
        int ans=-1;
        for(int i=0;i<=inorder.size()-1;i++){
            if(inorder[i]==postorder[postorder.size()-1]){
                ans=i;break;
            }
        }
        preorder.push_back(postorder[postorder.size()-1]);
        vector<int>inorder_1(inorder.begin(),inorder.begin()+ans);
        vector<int>inorder_2(inorder.begin()+ans+1,inorder.end());
        vector<int>postorder_1(postorder.begin(),postorder.begin()+ans);
        vector<int>postorder_2(postorder.begin()+ans,postorder.end()-1);
        dfs(inorder_1,postorder_1);
        dfs(inorder_2,postorder_2);
        return ;
    };
    dfs(inorder,postorder);
    for(int p:preorder) cout<<p<<' ';
    system("pause");
    return 0;
}