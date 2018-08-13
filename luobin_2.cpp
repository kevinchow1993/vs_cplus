#include<vector>
#include<string>
#include<iostream>
using namespace std;

 void DFS(vector<vector<int>> &mark, vector<vector<int>> &grid, int &sum, int x, int y)
 {
	mark[x][y] = 1;
	static int dx[] = { -1,1,0,0,1,-1,-1,1 };
	static int dy[] = { 0,0,-1,1,1,1,-1,-1 };
	for (int i = 0; i < 8; i++)
	{
		int newx = dx[i] + x;
		int newy = dy[i] + y;
		if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark.size())
			continue;
		if (mark[newx][newy] == 0 && grid[newx][newy] == 1)
			DFS(mark, grid, sum + 1, newx, newy);
	}

}
void get(vector<vector<int>> &grid)
{
	int max = 0;
	int count = 0;
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
				int y = 1;
                int &temp=y;
				DFS(mark, grid, temp, i, j);
				if (temp > max)
					max = temp;
				count++;
			}
	}
	cout << count << "," << max << endl;


}
vector<int> stringtoint(string input)
{
	vector<int> a;
	input.push_back(',');
	int size = input.size();
	int nums = 0;
	for (int i = 0; i<size; i++)
	{


		if (input[i] == ',')
		{
			a.push_back(nums);
			nums = 0;
		}
		else
		{
			nums = nums * 10 + input[i] - '0';
		}
	}
	return a;
}

int main()
{
	string str;
	getline(cin, str);
	vector<int> a;
	vector<vector<int>> grid;
	a=stringtoint(str);
	int m, n;
	m = a[0];
	n = a[1];
	while (m--)
	{
		string str1;
		getline(cin, str1);
		vector<int> ab;
		ab= stringtoint(str1);
		grid.push_back(ab);

	}
	get(grid);
    cin.get();
	return 0;
}
