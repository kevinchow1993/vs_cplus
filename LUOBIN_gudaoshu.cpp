#include<vector>
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

void DFS(vector<vector<int> > &mark,vector<vector<int> > &grid,int x,int y,int &nums){
    mark[x][y]=1;
    static const int dx[]={-1,0,1,-1,1,-1,0,1,};
    static const int dy[]={1,1,1,0,0,-1,-1,-1,};//八个方向
    
    for(size_t i = 0; i < 8; i++)
    {
        int newx = dx[i]+x;
        int newy = dy[i]+y;
    
        if(newx<0||newx>=mark.size()||newy<0||newy>=mark.size()){
            continue;
        }
        if(mark[newx][newy]==0&&grid[newx][newy]==1){
            nums++;
            DFS(mark,grid,x,y,nums);
            }
        }

    }

void find_team_num(vector<vector<int> > &grid){
    vector<vector<int> > mark(grid.size(),vector<int>(grid[0].size(),0));
    int team=0;
    int fans=0;
    int max=0;
    for(size_t i = 0; i < grid.size(); i++)
    {
        
        for(size_t j = 0; j < grid[i].size();  j++)
        {
                if(mark[i][j]==0&&grid[i][j]==1){
                    DFS(mark,grid,0,0,fans);
                    team++;
                    if(max<fans){
                        max = fans;
                    }
                }
        }
        cout<<"team:"<<team<<"fans"<<max<<endl;
    }
    
}
/*void DFS(vector<vector<int>> &mark, vector<vector<int>> &grid, int sum,int x,int y)
{
	mark[x][y] = 1;
	static int dx[] = {-1,1,0,0,1,-1,-1,1};
	static int dy[] = {0,0,-1,1,1,1,-1,-1};
	for (int i = 0; i < 8; i++)
	{
		int newx = dx[i] + x;
		int newy = dy[i] + y;
		if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark.size())
			continue;
		if (mark[newx][newy] == 0 && grid[newx][newy] == 1)
			DFS(mark, grid, sum + 1,newx, newy);
	}

}
void get(vector<vector<int>> &grid)
{
	int max = 0;
	int count=0;
	vector<vector<int>> mark;
	for (int i = 0; i < grid.size(); i++)
	{
		mark.push_back(vector<int>());
		for (int j = 0; j < grid[i].size(); j++)
			mark[i].push_back(0);
	}
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
			if (mark[i][j] == 0 && grid[i][j] == 1)
			{
				int temp = 1;
				DFS(mark, grid, temp, i, j);
				if (temp > max)
					max = temp;
				count++;
			}
	}
	cout << count<< "," << max << endl;


}
*/

int main(int argc, char const *argv[])
{
    int m,n;
    string s1;
    int temp=0;

    vector<vector<int> > grid,mark;
    scanf("%d,%d",&m,&n);
    /*
    cin>>s1;
    for(size_t i=0;i<s1.size();i++){
         if(s1[i]>='0'&&s1[i]<='9'){
             temp=temp*10+s1[i]-'0';

            }
        if(s1[i]==','){
            m=temp;
            temp=0;

        }
        
        if (i==s1.size()-1) {
            n=temp;
            temp=0;
        }
    }*/
    while(m--){
        vector<int> vtemp;
        string s;
        cin>>s;
        if(s.size()!=2*n-1){
            cout<<"input wrong"<<endl;
        }
        for(size_t i=0;i<s.size();i++){
            if(s[i]=='0'||s[i]=='1'){
                vtemp.push_back(s[i]-'0');

                }
            }
        grid.push_back(vtemp);
        vtemp.clear();

    }
    find_team_num(grid);

    /*
    for(size_t i = 0; i < grid.size(); i++)     
    {
        
        for(size_t j = 0; j < grid[i].size(); j++)
        {
            DFS(mark,grid);
        }
        
    }*/
    
        

    
    cin.get();
    return 0;
}
