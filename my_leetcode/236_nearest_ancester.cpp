#include<iostream>
#include<vector>
using namespace std;

/******************题目******************
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
（一个节点也可以是它自己的祖先）。” 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
************************************/

/**********思路********************
 * 
 * 首先使用前序遍历存储从root到p 和q 的路径；
 * 当 找到p时return，
 * 使用finish 标志 找到
 * 找到后保存当前的路径
 * 因为还会往下递归
 * 
 * 然后循环更新两个路径的相同节点
 * 
*/


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}

};
class Soulution
{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        vector<TreeNode*> path_temp;
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        bool finish =0;
        TreeNode* result=NULL;
        findpath(root,p,path1,path_temp,finish);
        path_temp.clear();
        finish = 0;
        findpath(root,q,path2,path_temp,finish);
        int count =(path1.size()<path2.size())?path1.size():path2.size();
        
        for(size_t i = 0; i < count; i++)
        {
            if(path1[i]==path2[i]){
                result = path1[i];
            }
        }
        return result;


    }
private:

    void findpath(TreeNode *N,TreeNode *n1,vector<TreeNode*> &path,vector<TreeNode*> &path_temp,bool &finish){
            
            
            if(!N||finish){
                return;
            }
            path_temp.push_back(N);
            if(N==n1){
                finish =1;
                path = path_temp;
                
            }
            
            findpath(N->left,n1,path,path_temp,finish);
            findpath(N->right,n1,path,path_temp,finish);
            path_temp.pop_back();
            
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
    Soulution sou;
    TreeNode* result;
    result = sou.lowestCommonAncestor(&a,&e,&f);
    cout<<result->val<<endl;
    cin.get();




    return 0;
}
