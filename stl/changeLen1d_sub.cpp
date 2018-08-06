
#include "iostream"
#include "string"

using namespace std;


template <class T>
bool changeLen1d(T * &oldlen,int Length){
	T *newArrey = new T [Length];
	for (size_t i = 0; i <min((int)sizeof(oldlen),Length) ; i++)
	{
		newArrey[i]=oldlen[i];
		cout<<newArrey[i]<<endl;
	}
	//cout<<newArrey<<endl;
	delete []oldlen;
	oldlen = newArrey;
	return true;
}

/*template <class T>
bool changeLen2d(T **newArrey,T ** &oldlen,int row,int clu){
	
	newArrey = new T *[row];
	int len1 = sizeof(oldlen)/sizeof(T);//行数
	int len2 = sizeof(oldlen)/sizeof(oldlen[0]);//列数
	
	for (size_t i = 0; i <row; i++)
	{
		try
		{
			newArrey[i] = new T [clu];
		}
		catch (exception e)
		{
			cout<<e.what()<<endl;
			return false;
		}
		
	}
	
	for (size_t i = 0; i <min(len1,row) ; i++)
	{
		for (size_t j = 0; j < min(len2,clu); j++)
		{
			newArrey[i][j]= oldlen[i][j];
		}
		
	}
	return true;
}

template <class T>
void deleteArrey(T *arrey){
	delete []arrey;

}

template <class T>
void printarrey(T **& x,int row,int clu){

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < clu; j++)
		{
			cout<<x[i][j]<<endl;
		}
		
	}
	
}*/
int main(int argc, char *argv[])
{
	

	int *A;
	A = new int[5];
	for (size_t i = 0; i < 5; i++)
	{
		A[i]=i;
	}
	
	changeLen1d(A,3);
	cout<<A[2]<<endl;


	/*int C[3][2]={{1,2},{3,4},{5,6}};
	int **D;
	D = new int *[3];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j <2; j++)
		{
			D[i][j]= C[i][j];
			cout<<C[i][j]<<endl;
		}
		
	}
	

	//cout<<**C<<endl;
	printarrey(D,3,2);
	//changeLen2d(D,(int**&)C,2,2);
//	cout<<D[1][1]<<endl;*/
	

}