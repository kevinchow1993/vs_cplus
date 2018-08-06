#include<vector>
#include<iostream>

using namespace std;

/*********路径之和****************
 * 给定一个二叉树和一个目标和，找到所有从
 * 根节点到叶子节点路径总和等于给定目标和的路径。
 * 给定如下二叉树，以及目标和 sum = 22，
 *            5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
        返回　
 [ [5,4,11,2],[5,8,4,5]]
 * 
 * 
 *******************************8*/

/*********思路******************
 * 使用递归的方法，前序遍历所有节点，使用一个堆栈
 * 记录路径
 * 在遍历路径等操作时，要在后序需要弹栈
 * 在每次递归时都要更新的值需要作为参数传入，不能作为局部变量
 * 
 * */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
      val(x),left(NULL),right(NULL){}
};


class Solution
{
private:
    void preorder(TreeNode *Tn,int sum,vector<int> &path,int path_val,vector<vector<int> > &result){
        //如果空节点返回
        if(!Tn){
            return;
        }
        //累加路径值
        path_val += Tn->val;
        path.push_back(Tn->val);
        //如果到达叶节点，且路径和　为想查找的那个数
        if(!Tn->left&&!Tn->right&&path_val == sum){
            result.push_back(path);
        }
        preorder(Tn->left,sum,path,path_val,result);
        preorder(Tn->right,sum,path,path_val,result);
        //后序弹栈
        path.pop_back();
        path_val -=Tn->val;

 

        
    }
public:
    
    vector<vector<int> > search_path_sum(TreeNode &TN,int sum){
        vector<vector<int> > result;
        vector<int> path;
        int path_val=0;
        preorder(&TN,sum,path,path_val,result);
        return result;

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
    Solution Solution;
    TreeNode * root = &a;

    vector<vector<int> > result = Solution.search_path_sum(a,22);
    
    for(size_t i = 0; i < result.size(); i++)
    {
        
        for(size_t j = 0; j< result[i].size(); j++)
        {
            cout<<result[i][j]<<endl;
        }
        
    }
    cin.get();
    
}
