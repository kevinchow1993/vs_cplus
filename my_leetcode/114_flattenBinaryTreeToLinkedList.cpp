#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};





//递归的方法
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        //备份右节点

        root->right = root->left;
        
        root->left = NULL;
        while (root->right) root = root->right;//往下找到左节点的叶节点 如果链表很长的话会浪费时间
        root->right = tmp;
    }
};


int main(int argc, char const *argv[])
{
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    c.left =&e;
    c.right = &f;
    b.left = &d;
    d.left = &g;
    d.right =  &h;
    f.left = &x;
    f.right = &y;
    Solution solution;
    TreeNode * root = &a;

    solution.flatten(root);
    while(root){
        cout<<root->val<<endl;
        root=root->right;
    }
    cin.get();
    return 0;
}
