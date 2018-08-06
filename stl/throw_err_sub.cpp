
#include "iostream"
using namespace std;



int abc(const int &a,const int &b, const int &c){
	if(a==0||b==0){
		throw "a or b is 0";
	}
	if(c==0){
		throw c;
	}
	return (a+b)*c;
}
int main(int argc, char *argv[])
{

	try{
		cout<<abc(1,0,3)<<endl;
		//cout<<abc(1,2,0)<<endl;;
	}
	catch(int e){
		cout<<e<<endl;

	}
	catch(const char *c){
		cout<<c<<endl;
	}

	return 0;
}