#include<iostream>

#include <stdio.h>
#include <math.h>

using namespace std;
int calc(int dSalary)
{

    double dTax,dNetIncome,Dvalue;
	Dvalue=dSalary-5000;
    if(Dvalue<=0)
    dTax=0;
    else if(Dvalue>0&&Dvalue<=3000)
    dTax = round(Dvalue*0.03 - 0); 
	else if(Dvalue>3000&&Dvalue<=12000)
	dTax = round(Dvalue*0.1 - 210); 
	else if(Dvalue>12000&&Dvalue<=25000)
    dTax = round(Dvalue*0.2 - 1410);
    else if(Dvalue>25000&&Dvalue<=35000)
    dTax = round(Dvalue*0.25 - 2660);
	else if(Dvalue>35000&&Dvalue<=55000)
	dTax = round(Dvalue*0.3 - 4410);
	else if(Dvalue>55000&&Dvalue<=80000)
	dTax = round(Dvalue*0.35 - 7160);
	else if(Dvalue>80000)
    dTax=dTax = round(Dvalue*0.45 - 15160);
    return dTax;
}

int main()
{
    int T;
    cin>>T;
    int a[T];
    for(int i=0;i<T;i++)
        cin>>a[i];
    for(int i=0;i<T;i++)
        cout<<int(calc(a[i])+0.5)<<endl;
}