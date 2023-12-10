Subarray with given sum

Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Time Complexity::
    O(N)

Space Complexity::
    O(1)
   

Solution::
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int last=0;
        int start=0;
        unsigned long long  currsum=0;

        //iterating over the array.
        for(int i=0;i<n;i++)
        {
            currsum += arr[i];
            
            if(currsum>=s)
            {
                while(s<currsum && start<i)
                {
                    currsum -= arr[start];
                    ++start;
                }
                
                if(currsum==s)
                {
                   return {start+1,i+1};
                }
            }
        }
       return {-1};  
    }
};