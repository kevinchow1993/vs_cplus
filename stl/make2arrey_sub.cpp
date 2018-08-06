#include "ros/ros.h"
#include "std_msgs/String.h"
#include "iostream"
#include "exception"
#include "string"
using namespace std;

template <class T>
bool make2arrey(T **&x,int rows,int columns){
	try
	{
		x = new T * [rows];
		for (size_t i = 0; i < rows; i++)
		{
			x[i] = new T [columns];
			return true;
		}
		
	}
	catch (exception e)
	{
		cout<<e.what()<<endl;
		return false;
	}

}
int main(int argc, char *argv[])
{
	
	ros::init(argc, argv, "make2arrey");
	char **c;
	int a= sizeof("kevin");
	int b = sizeof("chow");
	make2arrey(c,a,b);
	//c[0]="kevin";
	cout<<c[0][2]<<endl;


	return 0;
}