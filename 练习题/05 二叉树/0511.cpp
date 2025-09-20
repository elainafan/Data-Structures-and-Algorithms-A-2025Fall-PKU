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
int x;
TreeNode* insert(TreeNode* root,int x){
    if(!root) return new TreeNode(x);
    if(x<root->val) root->left=insert(root->left,x);
    if(x>root->val) root->right=insert(root->right,x);
    return root;
}
int main(){
    TreeNode* root=nullptr;
    while(cin>>x) root=insert(root,x);
    queue<TreeNode*>q;
    vector<int>res;
    q.push(root);
    while(!q.empty()){
        int tem=q.size();
        for(int i=0;i<tem;i++){
            auto node=q.front();q.pop();
            res.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    for(int p:res) cout<<p<<' ';
    system("pause");
    return 0;
}