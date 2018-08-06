

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char *argv[])
{

	



	vector<int> v1;
	vector<char> v2{'a','b','c'};
	vector<int> v3={1,3,4};
	v3.push_back(5);//增加元素
	for (size_t i = 0; i < v3.size(); i++)//访问元素
	{
		cout<<v3[i]<<endl;
	}
	v2.pop_back();
	v2.clear();
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout<<v2[i]<<endl;
	}
	cout<<v2.empty()<<endl;
//	cout<v3.begin()<<endl;
//	cout<<v1<<"\n"<<v2<<"\n"<<v3<<endl;
	return 0;
}