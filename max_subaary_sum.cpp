//kadane's algo

// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;
    int maxSubarraySum(int a[], int n){
        
        // Your code here
        int max=INT_MIN,max_upto=0;
        for(int i=0;i<n;i++)
        {
            max_upto=max_upto+a[i];
            if(max<max_upto)
                max=max_upto; 
            if(max_upto<0)
                max_upto=0;
        }
        return max;
    }

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-5,-2};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubarraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
