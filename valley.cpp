#include<iostream>
using namespace std;
int countvalleys(int n1,char arr[])
{
    int up=0;
    int count=0;
    for(int i=0;i<n1;i++)
    {
        if(arr[i]=='u' || arr[i]=='U')
        up++;
        else
        up--;
        if(up==0 && (arr[i]!='d' && arr[i]!='D'))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cout<<"no. of steps in gray's hike";
    cin>>n;
    char v[n];
    for(int i=0;i<n;i++)
    cin>>v[i];
    int c=countvalleys(n,v);
    cout<<" "<<c;
    return 0;
}