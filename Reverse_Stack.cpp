QUESTION : You are given a stack St. You have to reverse the stack using recursion.
  
Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3};

Input:
St = {4,3,9,6}
Output:
{6,9,3,4};


Simple Approach For this Program :
Continue recursion till stack is empty; 
Before Calling, Push stack top into our new stack. Then pop the stack, then recurse...
  
  
### CODE BELOW ###
  
  
  
  
class Solution{
public:
    void reverse(stack<int>& St, stack<int>& ans)
    {
        if(St.empty())
        {
            return;
        }
        int temp = St.top();
        St.pop();
        ans.push(temp);
        reverse(St,ans);
    }
    
    stack<int> Reverse(stack<int> St){
        stack<int>ans;
        reverse(St,ans);
        return ans;
    }
};
