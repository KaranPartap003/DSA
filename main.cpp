#include <iostream>
#include <list>
#define N 8
using namespace std;

int binarysearch(int arr[], int n, int k) {
    int s=0;
    int e=n;   
    while (s<=e)
    {
        int mid;
        mid = (s+e)/2;
        if (k==arr[mid])
        {
            return mid;
        }
        else if (k < arr[mid])
        {
            e = mid - 1;
        }
        else if(k > arr[mid])
        {
            s = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[N];
    cout<<"enter elements"<<"\n";
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << "enter key" << "\n";
    int key;
    cin >> key;
    cout << binarysearch(arr,N,key);
    
}