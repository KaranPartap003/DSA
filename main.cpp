#include <iostream>
#include <vector>
using namespace std;

bool IsPossible(int Barrier , vector<int> vec , int n){//n = no of students to deistribute pages among
    int students = 1;
    int pages = 0;
    for (size_t i = 0; i < vec.size() ; i++)
    {
        if (vec[i] > Barrier) // first element is bigger
        {
            return false;
        }
        if ( pages + vec[i] > Barrier )// adding another student if pages exceeds barrier
        {
            students += 1;
            pages = vec[i];
        }
        else
        {
            pages += vec[i]; //incrementing no of pages 
        }
    }
    if (students > n )
    {
        return false;
    }
    return true;
}

int minimum(vector<int> vec){ // finding out the lowest element of vector
    int min = vec[0];
    for (size_t i = 1; i < vec.size()-1 ; i++)
    {
        if(vec[i] < min){
            min = vec[i];
        }
    }
    return min;
}

int highest(vector<int> vec){ // finding out the highest element of vector
    int h = vec[0];
    for (size_t i = 1; i < vec.size()-1 ; i++)
    {
        if(vec[i] > h){
            h = vec[i];
        }
    }
    return h;
}

class solution{
public:
    int MaxAlloc(vector <int> vec , int n){//n = no of students
        int low = minimum(vec);
        int high = highest(vec);
        int mid = (low + high)/2 ;
        int res = -1;
        while (low <= high)
        {
            if (IsPossible(mid , vec , n))
            {
                res = mid;
                high = mid - 1; 
            }    
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main(){
    vector<int> v = {10,10,20,30};
    solution o1;
    cout<<o1.MaxAlloc(v , 2);
    return 0;
}
