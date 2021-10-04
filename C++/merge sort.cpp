#include<iostream>
using namespace std;
int merging(int a[],int l, int m, int r)
{
    int i,j,k;
    int a1=m-l+1;
    int a2=r-m;

    int L[a1],M[a2];
    for(i=0;i<a1;i++)
    {
        L[i]=a[l+i];
    }
    for(j=0;j<a2;j++)
    {
        M[j]=a[m+1+j];
    }
    i=0,j=0,k=l;
    while(i<a1 && j<a2)
    {
        if(L[i]<=M[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=M[j];
            j++;
        }
        k++;
    }
    while(i<a1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
     while(j<a2)
    {
        a[k]=M[j];
        j++;
        k++;
    }
}
int mergesort(int a[],int l,int r)
{
    if(l<r)

    {
        int m=l+(r-l)/2;
         mergesort(a,l,m);
            mergesort(a,m+1,r);
            merging(a,l,m,r);
    }
}
int main()
{
    int arr[]={40,45,-75,47,42};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    cout<<"BEFORE SORTING: ";
    for(i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    mergesort(arr,0,n);
     cout<<endl<<"AFTER SORTING: ";
    for(i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

