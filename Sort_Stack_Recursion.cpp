/*
QUESTION: 
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2


Approach for this program is as follows :
1. Set Base Case : when stack.empty() return;
2. Store the Top element in a variable (ele) and pop the stack.
3. Recursion will Sort the rest of the stack; call this function recursively;
4. Insert the elements in the right position by clling insert FUNCTION

5. INSIDE INSERT FUNCTION : 
  i) SET BASE CONDITION AS : if stack.empty() or stack.top() <= key
      stack.push(key);
      return;
      
  ii) Store the top of stack in eachTop. This Will store the every value of the top in different recursive frames. Then POP the stack.
  iii) CALL THE FUNCTION RECURSIVELY TO DO THIS TILL BASE CASE ARRIVES.
  iv) Then push eachTop in stack. Data of all tops from every recursion frame will pushed one by one.
      After we inserted the element into the sorted stack, we will come back , and while returning at every step we will push the stored top 

*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};
void arranging(stack<int>& s, int y)
{
    if(s.empty() or s.top() <= y)
    {
        s.push(y);
        return;
    }
    int temp = s.top();
    s.pop();
    arranging(s,y);
    
    s.push(temp);
    
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
   {
       return;
   }
   int y = s.top();
   s.pop();
   sort();
   arranging(s,y);
}
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      SortedStack *ss = new SortedStack();
      int n;
      cin>>n;
      for(int i=0;i<n;i++)
      {
      int k;
      cin>>k;
      ss->s.push(k);
      }
      ss->sort();
      printStack(ss->s);
    }
}
