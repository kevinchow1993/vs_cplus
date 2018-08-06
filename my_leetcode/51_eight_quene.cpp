//回溯算法
#include<vector>
#include<string>
#include<iostream>
using namespace std;

/****************************
 * n 皇后问题研究的是如何将 n 个皇后放置
 * 在 n×n 的棋盘上，并且使皇后彼此之间不
 * 能相互攻击。
 * 
 * 
 * 输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 * ************************/

class Solution
{
private:

//把某个点的八个方向全部占据
void put_the_quene(int x, int y, vector<vector<int> > &mark){
    //方向数组
    static const int dx[] = {-1,1,0,0,-1,-1,1,1};
    static const int dy[] = {0,0,-1,1,-1,1,-1,1};
    mark[x][y]=1;
    
    for(size_t i = 0; i < mark.size(); i++)
    {
        
      
      for(size_t j = 0; j < 8; j++)
      {
          int new_x = x+i*dx[j];
          int new_y = y+i*dy[j];
          if (new_x>=0&&new_x<mark.size()&&new_y>=0&&new_y<mark.size()) {
              mark[new_x][new_y] = 1;
          } 
      }
    } 
} 

void generate(int row, int i, vector<vector<int> > &mark, vector<string> &location,vector<vector<string> > &result){

    //i个皇后
    if(row == i){
        result.push_back(location);
        return;
    }
    
    for(size_t j = 0; j < i; j++)
    {
        
        if (mark[row][j]==0) {

            //回溯的操作，用临时变量记录当前的地图，当返回时再载入当时的地图
            vector<vector<int> > temp_mark = mark;
            put_the_quene(row,j,mark);
            location[row][j]= 'Q';
            generate(row+1,i,mark,location, result);
            //载入递归前的地图
            mark = temp_mark;
            //重置皇后放置点
            location[row][j] = '.';


        }
        
    }
    
}


public:
    vector<vector<string> > solveNquene(int n){
        vector<vector<string> > result;
        //初始化二维数组
        vector<string> location(n,"");
        vector<vector<int> > mark(n,vector<int>(n,0));

        
        for(size_t i = 0; i < n; i++)
        {
            location[i].append(n,'.');
           
        }
        generate(0,n,mark,location,result);//从第零行开始递归
        return result;
        



    }
};


int main(int argc, char const *argv[])
{
    Solution solution;
    int num = 8;
    vector<vector<string> > result;
    result  = solution.solveNquene(num);
    if(result.size() == 0){
        cout<<"not find!"<<endl;
    }
    for(size_t i = 0; i < result.size(); i++)
    {
        cout<< "i = "<<i<<endl;
        
        for(size_t j = 0; j < num;j++)
        {
            cout<<result[i][j]<<endl;
        }
        
    }
    cin.get();

    return 0;
}
