======================================================================================================================
QUESTION : Complete the function max_of_subarrays() which takes the array, N, and K as input parameters and returns
a list of integers denoting the maximum of every contiguous subarray of size K.
======================================================================================================================+

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6

--------------------------------------------------
Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10 
3rd contiguous subarray = {10 7 9 4}, Max = 10 
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, Max = 15 
6th contiguous subarray = {4 15 12 90}, Max = 90 
7th contiguous subarray = {15 12 90 13}, Max = 90 

--------------------------------------------------

Simple Approach for this program is as follows :

This Could be implemented with the help of a deque.
While Shifting the window, We just push the rear element's index at the rare of deQue.
Every time while entering a new element, we have to check that where the front element is out of bound of our present size.
If so then pop the deQue front.

We will also check that the rear element is smaller than new element. If so then it also has to be popped out.

Then we insert the new number.

If i>=k-1 means the current window is full.



    ### CODE BELOW ###


class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i < n; i++)
        {
            if(!dq.empty() and dq.front() == i - k) 
                dq.pop_front();
            
            while(!dq.empty() and arr[dq.back()] < arr[i])
                dq.pop_back();
            
            dq.push_back(i);
            if(i >= k-1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};
