#include<iostream>
#include<queue>
using namespace std;

/*
 *            5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class BFS
{

public:
void print(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        TreeNode * t = q.front();
        cout<<t->val<<" ";
        q.pop();
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);

    }
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

    TreeNode * root = &a;

    BFS bfs;
    bfs.print(root);


    cin.get();
    return 0;
}
