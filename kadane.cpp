# include <iostream>
using namespace std;

class kadanes{
    public:
        void MaxSum(int a[] , int n){
            int CurSum = 0;
            int MaxSum = 0;
            int l = 0;
            int r = 0;
            for(int i = 0; i<n; i++){
                CurSum += a[i];
                if(CurSum > MaxSum){
                    MaxSum = CurSum;
                    r = i;
                }
                if(CurSum<0){
                    CurSum = 0;
                    l = i+1;
                }
            }
            cout<<l<<" " << r << "\n";
            cout<<MaxSum;
        }
};

int main(){
    kadanes o1;
    int arr[] = {9,-7,-2,7,6,-5};
    o1.MaxSum(arr,6);
    return 0;
}