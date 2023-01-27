#include <iostream>
using namespace std;
#define n 8

class solution{
public:
    int RainWater(int arr[]){
        int left[n];
  
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
        int right[n];
  
    // Initialize result
        int water = 0;
  
    // Fill left array
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);
  
    // Fill right array
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], arr[i]);
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i]
        for (int i = 1; i < n - 1; i++) {
            int var = min(left[i - 1], right[i + 1]);
            if (var > arr[i]) {
                water += var - arr[i];
            }
        }
        return water;
        }    
};

int main(){
    int a[] = {3,1,2,4,0,1,3,2};
    solution o1;
    cout<<o1.RainWater(a);
return 0;
}