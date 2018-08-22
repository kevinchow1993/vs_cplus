#include<string>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#include<set>


using namespace std;


/**
 * @brief 200.搜索独立小岛
 * 
 */
class island
{
private:
   void DFS(vector<vector<int> > &grid,vector<vector<int> > &mark,int i,int j){

    mark[i][j]=1;
    static const int dx[] = {0,1,0,-1};
    static const int dy[] = {1,0,-1,0};

    for(size_t k = 0; k < 4; k++)
    {
        int newx = i+dx[k];
        int newy = j+dy[k];
        if(newx<0||newx>=grid.size()||newy<0||newy>=grid[0].size()){
            continue;
        }
        if(grid[newx][newy]&&!mark[newx][newy]){
            DFS(grid,mark,newx,newy);
        }
    }
    }

    void BFS(vector<vector<int> > &grid,vector<vector<int> >&mark,int i,int j){
        mark[i][j]=1;
        static const int dx[] = {0,1,0,-1};
        static const int dy[] = {1,0,-1,0};
        queue<pair<int,int> > q;
        q.push(make_pair(i,j));
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(size_t k = 0; k < 4; k++)
            {
                int newx = i+dx[k];
                int newy = j+dy[k];
                if(newx<0||newx>=grid.size()||newy<0||newy>=grid[0].size()){
                    continue;
                }
                if(grid[newx][newy]&&!mark[newx][newy]){
                    q.push(make_pair(newx,newy));
                    mark[newx][newy]=1;
                }
            }
            
        }

    }

public:
    int numIslands(vector<vector<int> > &grid){

        vector<vector<int> > mark(grid.size(),vector<int>(grid[0].size(),0));
        int nums = 0;

        for(size_t i = 0; i < grid.size(); i++)
        {
            
            for(size_t j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]&&!mark[i][j]){
                    DFS(grid,mark,i,j);
                    nums++;
                }


            }
            
        }
        return nums;
    }
};

/**
 * @brief 127 词语阶梯 已知两个单词(分别是起始单词与结束单词)，一个 单词词典 ，根据 转换规则 计算从起
    始单词到结束单词的 最短转换步数 。
    转换规则如下:
    1.在转换时，只能转换单词中的 1 个字符 。
    2.转换得到的 新单词 ，必须在单词词典中。
    例如: beginWord = “hit”；endWord = “cog”；wordList = ["hot","dot","dog","lot","log","cog"]
    最短转换方式: "hit" -> "hot" -> "dot" -> "dog" -> "cog", 结果为5
 * 
 * @param beginword 
 * @param endword 
 * @param wordlist 
 * @return int 
 */
int ladderLength(string beginword,string endword,vector<string> &wordlist){

    map<string, vector<string> > graph;
    construct_graph(beginword,wordlist,graph);
    set<string> visited;
    queue<pair<string,int> > q;
    q.push(make_pair(beginword,1));
    visited.insert(beginword);
    while(!q.empty()){
        int step = q.front().second;
        string s = q.front().first;
        q.pop();
        if(endword == s){
            return step;
        }
       for(auto i:graph[s]){
           if(visited.find(i)==visited.end()){
                q.push(make_pair(i,step+1));
                visited.insert(i);
           }
           

       }
        


        
    }


}
bool connect(string &word1,string &word2){
    int cnt;
    
    for(size_t i = 0; i < word1.size(); i++)
    {
        if(word1[i]==word2[i]){
            cnt++;
        }
    }
    return cnt == 1;
    
}
void construct_graph(string &beginword,vector<string> &wordlist,map<string,vector<string> >&graph){
    wordlist.push_back(beginword);
    
    for(auto i:wordlist)
    {
        graph[i] = vector<string>();
    }
    
    for(size_t i = 0;i<wordlist.size();i++)
    {
        for(size_t j=i+1;j<wordlist.size();j++){
            
            if (connect(wordlist[i],wordlist[j])) {
                graph[wordlist[i]].push_back(wordlist[j]);
                graph[wordlist[j]].push_back(wordlist[i]);
            }
            
        }
    }
    
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
