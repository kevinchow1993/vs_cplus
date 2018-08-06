#include<iostream>
#include<string>
#include<vector>

using namespace std;


//调用递归函数，打印所有可能 
void generate(string item, int n, vector<string> &result){
    if(item.size()==2*n){
        result.push_back(item);
        return;
    }
    generate(item+'(',n,result);
    generate(item+')',n,result);

}
int main(int argc, char const *argv[])
{
    vector<string> result;
    generate("",2,result);
    for(int i =0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
     cin.get();
    return 0;
}
