
#include "list"

#include "iostream"
using namespace std;

template <class T>
void showlist(list<T> v){
	for ( typename std::list<T>::iterator it = v.begin() ; it != v.end(); it++)
	{
		cout<<*it;
	}
	cout<<endl;
}
int main(int argc, char *argv[])
{
	list<int> l1;
	showlist(l1);
	list<double> l2;
	list<char> l3(10);
	list<int> l4(4,2);
	showlist(l4);
	l1.sort();
	showlist(l1);

	return 0;
}