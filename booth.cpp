#include<iostream>
using namespace std;
static int bits=0;
void complement(int a1[ ])
{
	int n=bits-1;
	while(a1[n]!=1)
	n--;
	for(int i=n-1;i>=0;i--)
	{
		if(a1[i]==0)
		a1[i]=1;
		else
		a1[i]=0;
    	}
}
int right_shift(int ac[ ],int a2[ ],int q)
{
	int t=ac[bits-1];
	q=a2[bits-1];
	for(int i=bits-1;i>=1;i--)
	{
		a2[i]=a2[i-1];
		ac[i]=ac[i-1];
	}
	a2[0]=t;
	return q;
}
void add(int ac[ ],int a1[ ])
{
    int c=0;
	for(int i=bits-1;i>=0;i--)
	{
		ac[i]=ac[i]+a1[i]+c;
		if(ac[i]>1)
		{
			ac[i]=ac[i]%2;
			c=1;
		}
		else
		c=0;
	}
}
void booth(int a[ ] , int b[ ],int c[ ])
{
	int ac[bits];
	for(int i=0;i<bits;i++)
	ac[i]=0;
	int q=0;
	int mq[bits];
	for(int i=0;i<bits;i++)
	{
		mq[i]=a[i];
	}
    int j=0;
	while(j!=bits)
    {
    if(q==mq[bits-1])
	{
		q=right_shift(ac,mq,q);
		cout<<endl;
		for(int i=0;i<bits;i++)
		cout<<ac[i];
		cout<<" ";
		for(int i=0;i<bits;i++)
		cout<<mq[i];
		cout<<" "<<q<<endl;
	}
	else
	{
	if(q==1 && mq[bits-1]==0)
	{
		add(ac,b);
		q=right_shift(ac,mq,q);
		cout<<endl;
        for(int i=0;i<bits;i++)
		cout<<ac[i];
		cout<<" ";
		for(int i=0;i<bits;i++)
		cout<<mq[i];
		cout<<" "<<q<<endl;
	}
	else if(q==0 && mq[bits-1]==1)
	{
		add(ac,c);
		q=right_shift(ac,mq,q);
		cout<<endl;
		for(int i=0;i<bits;i++)
		cout<<ac[i];
		cout<<" ";
		for(int i=0;i<bits;i++)
		cout<<mq[i];
		cout<<" "<<q<<endl;
	}
    }
    j++;
    }
   cout<<"acc content  ";
	for(int i=0;i<bits;i++)
	cout<<ac[i];
	cout<<endl;
	cout<<"MQ content  ";
    for(int i=0;i<bits;i++)
	cout<<mq[i];
	cout<<endl;
}
void binary_convert(int a[ ],int m)
{
	int i=0;
	int n=bits;
    int st=0;
    if(m<0)
    {
        m=-m;
        st=1;
    }
	while(m)
	{
		a[n-1]=m%2;
		m=m/2;
		n--;i++;
	}
    n--;
	while(n>=0)
	{
		a[n]=0;
		n--;
	}
	if(st==1)
	complement(a);
}
int main()
{
	int m1 ,m2,i=0;
	cout<<"enter the value of multiplicant\n";
	cin>>m1;
	cout<<"enter the value of multiplier\n";
	cin>>m2;
	int a=m1;
	int b=m2;
	while(a!=0 || b!=0)
	{
		a=a/2;
		b=b/2;
		i++;
	}
	bits=i+1;
	int arr1[bits],arr2[bits],arr3[bits];
	
	for(int i=0;i<bits;i++)
	arr1[i]=arr2[i]=0;

	binary_convert(arr1,m1);
	binary_convert(arr2,m2);
	for(int i=0;i<bits;i++)
	arr3[i]=arr2[i];
	complement(arr3);
	booth(arr1,arr2,arr3);

	return 0;
}
