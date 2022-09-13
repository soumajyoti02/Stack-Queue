/*
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
QUESTION : Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output:  70 30 20 10 10 10 10 

Explanation: 
____________
1.First element in output indicates maximum of minimums of all windows of size 1.

2.Minimums of windows of size 1 are {10}, {20}, {30}, {50},{10}, {70} and {30}. Maximum of these minimums is 70. 
 
3. Second element in output indicates maximum of minimums of all windows of size 2. 

4. Minimums of windows of size 2 are {10}, {20}, {30}, {10}, {10}, and {30}.

5. Maximum of these minimums is 30 .Third element in output indicates maximum of minimums of all windows of size 3. 

6. Minimums of windows of size 3 are {10}, {20}, {10}, {10} and {10}.

7.Maximum of these minimums is 20.  Similarly other elements of output are computed.

----------------------------------------------------------------

Simple Approach For this program is as Follows : 
__________________________________________________________________________
--> Find the Next Smaller elements for the right part and store the indexes.
--> Find the next smaller element for the left part and store the indexes.
--> Get the Length of the Window by substracting the Right index with left index and -1;
--> If a value is already present find which one is maximum -> ans[length] or arr[i]; put that value in ans[len];
--> Some entries are not be fillled because in some case, the length will becommes -1. In that case, fill them by taking values
    from right side of ans i.e. ans[i] = max(ans[i], ans[i + 1]);
-->  Copy that values in a vector because we have to return a vector. Starting index of answer array is 1;
     So, take loop from i = 1 to <= n and put values in vector[i-1] fashion.
___________________________________________________________________________

<<<<<<<<<<<<<<<<-------- ALGORITHM : -------->>>>>>>>>>>>>>>>

1. Take a STACK for performing next Smaller element discussed in :
   https://github.com/soumajyoti02/Stack-Queue/blob/51c5d75d1ca0f85c0d0e713eba30dcc01dc9c4e1/Next_Smaller_Element.cpp
   
2. Take 2 array of Size n + 1 to store the next smaller element from right and left.
3. Store the RIGHT NEXT SMALLER ELEMENTS in --> right[i] by using FOR(i = n - 1 to 0);
4. Store the LEFT NEXT SMALLER ELEMENTS in --> left[i]by using FOR(i = 0 to n);
5. Declare our answer array ANS[N+1] and initialize it with 0;
6. Start a loop FOR ( i = 0 to n )

    6.1) Our Window Length of an index is --> right[i] - left[i] - 1;
    6.2) If any value is present in that index of ans array, we will take maximum value between current and that value.
         ans[len] = max(ans[len], arr[i]); 
         
7. Some entries in ans[] may not be filled yet. Filling them by taking values from right side of ans[].
        for (int i = n - 1; i >= 1; i--)
            ans[i] = max(ans[i], ans[i + 1]);
8. Because Window length Started with 1; So inside ans array, values is present from index 1 to n
9. Copy that values in (i - 1)th index of an vector and return that vector.

*/
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        //stack used to find previous and next smaller numbers.
        stack<int> s; 
    
        //using arrays to store previous and next smaller numbers.
        int left[n + 1];
        int right[n + 1];
    
        //initializing elements of left[] and right[].
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }
    
        //filling elements of left[] using logic discussed in 
        //next greater element problem.
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
            
            if (!s.empty()) 
            left[i] = s.top();
            s.push(i);
        }
    
        //emptying the stack as stack is going to be used for right[].
        while (!s.empty())
        {
            s.pop();
        }
    
        //filling elements of right[] using same logic.
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
    
            if (!s.empty()) 
                right[i] = s.top();
            s.push(i);
        }
    
        //creating and initializing answer list.
        int ans[n + 1];
        for (int i = 0; i <= n; i++) 
        {
            ans[i] = 0;
        }
    
        /*filling answer list by comparing minimums of all
          lengths computed using left[] and right[].*/
        for (int i = 0; i < n; i++) 
        {
            //length of the interval.
           int len = right[i] - left[i] - 1;
    
           /*arr[i] is a possible answer for this length 'len' interval
             check if arr[i] is more than max for 'len'.*/
           ans[len] = max(ans[len], arr[i]); // If already value is present in that index, take the maximum b/w old and present
        }
    
        /*some entries in ans[] may not be filled yet. Filling
          them by taking values from right side of ans[].*/
        for (int i = n - 1; i >= 1; i--) 
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }
    
        vector <int> res (n);
        for (int i = 1; i <= n; i++)  // i = 1 --> Because Window length is started from 1 to N
        {
            res[i-1] = ans[i];
        }
        
        //returning the answer list.
        return res;
    }
};
