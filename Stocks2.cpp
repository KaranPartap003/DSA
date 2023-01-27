#include <iostream>
using namespace std;
// leetcode 122
//we can buy and sell multiple times  
class stomks{
public:
    int MaxProfit(int arr[], int n){
        int profit = 0;
        for(int i = 1; i<n; i++){
            if(arr[i] > arr[i-1]){
                profit += arr[i] - arr[i-1];
            }
        }
        return profit;
    }
};

int main(){
    int a[] = {5,2,7,3,6,1,2,4};
    stomks o1;
    cout<<o1.MaxProfit(a,8)<<"\n";
    return 0;
}