#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
int x;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr) { }
    TreeNode(int _val,TreeNode* _left,TreeNode* _right):val(_val),left(_left),right(_right) { }
};
TreeNode* insert(TreeNode* root,int val){
    if(!root) return new TreeNode(val);
    if(val<root->val) root->left=insert(root->left,val);
    if(val>root->val) root->right=insert(root->right,val);
    return root;
}
int main(){
    TreeNode* root=nullptr;
    while(cin>>x) root=insert(root,x);
    vector<int>res;
    function<void(TreeNode*)>dfs=[&](TreeNode* root){
        if(!root) return ;
        res.push_back(root->val);
        dfs(root->left);dfs(root->right);
        return ;
    };
    dfs(root);
    for(int p:res) cout<<p<<' ';
    system("pause");
    return 0;
}