#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
输入描述: 
一个字符串 
输出描述: 
输出最长的数字串,输出最长数字串个数； 
中间以逗号(,)隔开；

示例1 
输入 
abcd12345ed125ss123058789 
输出 
123058789,9

备注: 
1、如果存在长度相同的连续数字串，则输出最后一个连续数字串； 
2、数字串只需要是数字组成的就可以，并不要求顺序，比如数字串“1234”的长度就小于数字串“1359055”； 
3、如果没有数字，则输出空字符串（“”）而不是NULL；
*/

int main(int argc, char const *argv[])
{
    string res ="";
    string temp ="";
    string input;
    cin >>input;
    cout<<input<<endl;
    
    for(size_t i = 0; i < input.size(); i++)            
    {
        if(input[i]>='0'&&input[i]<='9'){
            while(input[i]>='0'&&input[i]<='9'){
                temp.push_back(input[i]);
                i++;
            }
            if(temp.size()>=res.size()){
                res=temp;
            }
        
                temp.clear();
            

        }
        
    }
    cout<<res<<','<<res.size()<<endl;
    cin.get();
    return 0;
}
