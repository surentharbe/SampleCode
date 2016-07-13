//Write a class template which allows you add elements to it, sort it, display, display in reverse order.

/*#include<iostream>
using namespace std;

template <class T>
void Display(T a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}

template <class T>
void Sort(T a[],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}

template <class T>
void Reverse(T a[],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}

int main()
{
	int a[100],i,n;
	cout<<"\nEnter The number of Element: ";
	cin>>n;
	cout<<"\nEnter Elements: ";
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter:";
		cin>>a[i];
	}
	cout<<"\nDisplay the Element\n";
	Display(a,n);
	
	cout<<"\nDisplay in Sort Order\n";
	Sort(a,n);
	
	cout<<"\nDisplay in Reverse order\n";
	Reverse(a,n);
	
	return 0;
}
*/