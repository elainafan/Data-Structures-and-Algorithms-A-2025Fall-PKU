#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr) { }
    TreeNode(int _val,TreeNode* _left,TreeNode* _right):val(_val),left(_left),right(_right) { }
};
auto cmp=[](TreeNode* x,TreeNode* y){
    return x->val>y->val;
};
priority_queue<TreeNode*,vector<TreeNode*>,decltype(cmp)>q(cmp);
int t;
int x;
int n;
int main(){
    cin>>t;
    while(t--){
        while(!q.empty()) q.pop();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x;
            TreeNode* temp=new TreeNode(x);
            q.push(temp);
        }
        TreeNode* root=nullptr;
        while(!q.empty()){
            auto node1=q.top();q.pop();
            if(q.empty()){
                root=node1;break;
            }
            auto node2=q.top();q.pop();
            TreeNode* temp=new TreeNode(node1->val+node2->val,node1,node2);
            q.push(temp);
        }
        int ans=0;
        function<void(TreeNode*,int)>dfs=[&](TreeNode* root,int depth){
            if(!root) return ;
            if(!root->left&&!root->right){
                ans+=depth*root->val;
                return ;
            }
            dfs(root->left,depth+1);
            dfs(root->right,depth+1);
        };
        dfs(root,0);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}