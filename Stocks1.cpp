#include <iostream>
using namespace std;
//leetcode 121
// Buy and sell only once
class stomks{
    public:
    int MaxProfit(int a[] , int n){
        int MinSoFar = a[0];
        int maxprofit = 0;
        for(int i = 0 ; i<n ; i++){
            MinSoFar = min(a[i] , MinSoFar);
            int profit = a[i] - MinSoFar;
            maxprofit = max(profit,maxprofit);
        }
        return maxprofit;
    }
};

int main(){
    int arr[] = {1,5,2,3,6,7,4};
    stomks obj1;
    cout << obj1.MaxProfit(arr , 8);
    return 0;
}