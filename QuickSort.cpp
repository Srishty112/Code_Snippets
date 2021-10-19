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
