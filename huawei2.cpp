#include<vector>
#include<iostream>
#include<string>

using namespace std;

/*
花了好大功夫才看懂这道题的意思。它的意思是，字节流中的各元素是以二进制01的形式连续排列的，
指定bit的个数以从二进制字节流取出若干bit，然后转化为十进制输出。例如 0x62 0x80 实际上连在一起是
 0110 0010 1000 0000，输入4，表示取4个bit得到0110，转化为十进制是6，接着输入5，
 表示接着取5个bit得到00101，转化为十进制是5。另外，这道题的难点主要在于进制准换以及相关的输入操作。

输入 
3 
0x62 0x80 0x00 
2 
4 
5 
输出 
6 
5

*/
int main(int argc, char const *argv[])
{
    int n;

    cin >>n;
    vector<unsigned int> v;
    int num;
  for(size_t i = 0; i < n; i++)
    {
        cin>>hex>>num;
        v.push_back(num);
        
    }
    
    int times; 
    vector<int> bits; 
    vector<bool> binary;
    cin>>times;

    for(int i = 0; i < times; i++)
    {   
        int m;
        cin>>m;
        bits.push_back(m);
    }
    for(int j =0;j<v.size();j++)  {
        
        for(int i = 0x80; i>=1; i>>=1)    
        {
            binary.push_back(v[j]&i);
        }
        
    } 
    int start=0;
    int result = 0 ;
    for(size_t i = 0; i < times; i++)
    {
        
        for(size_t j = 0; j <bits[i]; j++)     
        {
            int a = (bits[i]-j-1);
            int b = binary[j+start];
            int c= b<<a;
            result = result+c;
        }
        cout<<result<<endl;
        result = 0;
        start=bits[i];
        
    }
    
    cin.get();
    cin.get();

    return 0;
}
