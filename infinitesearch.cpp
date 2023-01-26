#include <iostream>
#define N 6
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

class solution{
public:
    void SearchInfinite(int arr[] , int key){
        int l = 0;
        int r = 1;
        while (arr[r] < key)
        {
            l = r;
            r *= 2;
        }
        binarysearch(arr , N , key);
    }
};

int main(){

    return 0;
}