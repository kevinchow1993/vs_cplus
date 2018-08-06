#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
bool cmp( pair<int,int> &a, pair<int,int> &b){
        return a.first<b.first;
    }
class Solution {
public:
   
    
    int findMinArrowShots(vector<pair<int, int> >& points) {
        if(points.size()==0){
            return 0;
        }
        int shoot_num = 1;
        
        sort(points.begin(),points.end(),cmp);
        int start = points[0].first;
        int end =points[0].second;
        for(int i=1;i<points.size();i++){
            if(end>=points[i].first){
                start = points[i].first;
            
            if(end>points[i].second){
                end = points[i].second;
            }
        }
            else{
                shoot_num++;
                start = points[i].first;
                end = points[i].second; 
            }
        }
        return shoot_num;
    }
};


int main(int argc, char const *argv[])
{
    pair<int,int> a(7,15);
    pair<int,int> b(6,14);
    pair<int,int> c(8,12);
    pair<int,int> d(3,4);
    pair<int,int> e(4,13);
    pair<int,int> f(6,14);
    pair<int,int> g(9,11);
    pair<int,int> h(6,12);
    pair<int,int> j(4,13);
    vector<pair<int,int> > input;
    input.push_back(make_pair(7,15));
    input.push_back(make_pair(6,14));
    input.push_back(c);
    input.push_back(d);
    input.push_back(e);
    input.push_back(f);
    input.push_back(g);
    input.push_back(h);
    input.push_back(j);
    Solution solve;
    cout<<solve.findMinArrowShots(input)<<endl;
     cin.get();
    return 0;
   
}
