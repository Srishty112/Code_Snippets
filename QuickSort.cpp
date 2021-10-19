#include "bits/stdc++.h"
using namespace std;

void quickSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int i=l-1, j=l;
        while(j<r)
        {
            if(arr[j]<arr[r])
            {i++;
            int k= arr[j]; arr[j]=arr[i];arr[i]=k;}
            j++;
        }
        int a= arr[i+1];arr[i+1]=arr[r]; arr[r]=a;
        quickSort(arr, l, i); 
        quickSort(arr, i+2, r); 
    }
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    quickSort(arr,0, n-1);
    for(int i=0; i<n; i++)
    cout<<arr[i]<<"  ";
}