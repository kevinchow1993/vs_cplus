#include<vector>
#include<string>
#include<iostream>


/******括号生成**************
 * 给出 n 代表生成括号的对数，请你写出一个函数，
 * 使其能够生成所有可能的并且有效的括号组合。
 * 例如，给出 n = 3，生成结果为：
 * [
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
思路：只有左括号的个数大于右括号时，才能放右括号
　　　先放左括号
    左括号右括号个数相加不能超过总数


 * 对于产生所有种可能的题型，可以用递归来做
 * 对于有约束的产生可能的题,需要在递归中加入
 * 条件，约束在递归函数参数中体现
 * 如果所有结果有ｘ^n种可能，那么在递归函数种，有ｎ次递归调用，
 * 次数少的直接写出来，如这题，次数多的用循环，如ｎ皇后
 * **********************/



using namespace std;
class Solution{
public:
    vector<string> generateparent(int n){
        vector<string> result;
        generate("",n,n,result);
        return result;
    }
       void printvecotr(vector<string> v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
       }
private:
    void generate(string item,int left,int right,vector<string> &result){
        if(left+right == 0){
            result.push_back(item);
            return ;
        }
        if(left>0){
            generate(item+'(',left-1,right,result);
        }
        if(left<right){
            generate(item+')',left,right-1,result);
        }
    }
 

};


int main(int argc, char const *argv[])
{
    Solution solution;
    solution.printvecotr(solution.generateparent(2));
    cin.get();
    return 0;
}

