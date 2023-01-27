#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    int moore(int arr[], int n){
        int CurElement = 0;
        int count = 0;
        int res = 0;//frequency of most occuring element
        for(int i = 0; i < n ; i++){
            if(arr[i]==arr[CurElement]){
                count++;
            }
            else
                count--;
            if(count==0){
                CurElement = i;
                count++;
            }
        }

        for(int i = 0 ; i<n ; i++){
            if(arr[i] == arr[CurElement]){
                res++;
            }
        }
        if(res >= n/2){
            return arr[CurElement];
        }
        else
            return -1;
    }
};

int main(){
    int arr[] = {0,7,3,4,7,7};
    int *ptr = arr;
    Solution obj1;
    cout << (obj1.moore(arr , 6));
}