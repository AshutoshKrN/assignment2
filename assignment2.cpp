#include<bits/stdc++.h>
using namespace std;

//Function to find First occurence positive number

int firstOccPositve(int arr[], int low, int high)
{
	if(high >= low)
    {
        int mid = (low + high)/2;
        if(mid == arr[mid]){
            return mid;
        }
        if(mid > arr[mid]){
             return firstOccPositve(arr, (mid + 1), high);
        }

        else{
            return firstOccPositve(arr, low, (mid -1));
        }
    }
    return -1;
}

//Removing duplicate elements

void removeDuplicate(vector<int> &v){
    vector<int>::iterator it;
    it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
}

int main(){
    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter the value of array: :"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    vector<int> v(arr, arr + n+1);
    cout<<"Array Elemts Before Sorting :"<<endl<<"\t";
    //cout<<"\t";
    for(int i=1;i<=n;i++)
    {
        cout<<v[i]<< " ";
    }
    sort(v.begin() + 1, v.begin() + n+1);
    cout<<"\nAfter Sorting :"<<endl<<"\t";
    for(int i=1;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

        // *****************Remove Duplicate value:****************;
    removeDuplicate(v);
    cout<<"\nAfter Removal of duplicates elements :"<<endl<<"\t";
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    int *vec_arr = new int[v.size()];
    for(int i=1;i<v.size();i++)
    {
        vec_arr[i]=v[i];
    }

    int index = firstOccPositve(vec_arr,1, n-1);
    if (index != -1){
        cout<<"\nfirst positive :"<<index;
       }
    else{
        cout<<"\nnot found";
    }

    return 0;
}
