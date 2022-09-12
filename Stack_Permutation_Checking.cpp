//Stack Permutations
/*
<<<---- QUESTION ---->>>
You are given two arrays A and B of unique elements of size N. Check if one array is a stack permutation of the other array or not.
Stack permutation means that one array can be created from another array using a stack and stack operations.

Input:
N = 3
A = {1,2,3}
B = {2,1,3}
Output: 1

MAIN APPROACH FOR THIS PROGRAN IS AS FOLLOWS :
1. Firstly, take 2 variable and initialize with 0; they will work as index of the 2 given array
2. Declare a int type stack to store the values of Array 1.
3. Start a loop FOR i = 0 to N to travarse the 1st array

     3.1) PUSH values of array 1 into the stack.
     3.2) Check stack top is equal to J(= 0)th index or not, if yes then pop stack untill it becomes false 
          Increment j in every step. DO THIS USING A WHILE LOOP WITH CONDITION !stack.empty() and stack.top() == B[j]
          
4. Check If stack is empty or not. If empty return true i.e. they are permutation to each other, otherwise not.     
*/
#include <bits/stdc++.h>
using namespace std;
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        int i = 0, j = 0;
        stack<int> st;
        for(int i = 0; i < N; i++)
        {
            st.push(A[i]);
            while(!st.empty() and st.top() == B[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty() ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
