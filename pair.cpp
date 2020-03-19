#include <iostream>
using namespace std;
void sort(int n1,int t[])
{
    for(int i=0;i<n1;i++)
    {
        for(int j=i+1;j<n1;j++)
        if(t[i]>t[j])
        {
            int tmp;
            tmp=t[i];
            t[i]=t[j];
            t[j]=tmp;
        }
    }
}
int merchant(int n,int a[])
{
    int count=0;
    sort(n,a);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
        if(a[i]==a[j] && a[i]!=a[i-1])
        {
            count++;
        }
        }
    }
    return (count/2 +1);
}
int main() {
    cout<<"no. of socks represent in ar";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int pair=merchant(n,arr);
    cout<<" "<<pair;
    return 0;
}
