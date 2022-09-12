/*
Our Main Approach is:
1. Store the index of opening parenthesis.
2. If any Closing parenthesis Found while storing, Pop 1 opening parenthesis index for 1 closing parenthesis.

3. After that process; if our stack becomes empty i.e. all opening parenthesis are popped out for their consecutive closing
parenthsis then we simply return the length of the main string.

4. Declare a variable CHECK to store main string length; it will used in future to store the last valid closing parenthesis
position By : --->>> calculating stack-top(last opening invalid parenthesis) - 1; <<<----

5. We will also record the maximum index for last valid string because we have to calculate the longest valid string.

6. Run a LOOP while(!stack.empty())
              {
                  if((check - st.top() - 1) > max)
                  {
                       max = (check - st.top() - 1);
                  }
                  check = st.top();
                  st.pop();
              }
              
7. if max is greater then it's the valid substring length
   else check is greater i.e. the string contains all fixed brackets and
   left opening brackets at the end.
   More clearly, stack top contains string's last index consiquitively in 
   decreasing order.
   Example: 
   If string length is 8 then :
          8
          7
          6
*/
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        
        stack<int>st; // To Store the Index Of opening Parenthesis in the stack
        int cnt = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')' and !st.empty())
            {
                if(s[st.top()] == '(')
                {
                    st.pop();
                }
                else
                    st.push(i);
            }
            else
                st.push(i);
            
        }
        if(st.size() == 0) // Means No Invalid Parenthesis Left
            return s.size();
            
        int check = s.size(); // It Will Return The Given String Length
        int max = -1;
        
        /* To Store the Maximum index 
        where the last invalid parenthesis ends*/
        
        while(!st.empty())
        {
            if((check - st.top() - 1) > max)
            {
                max = (check - st.top() - 1);
            }
            check = st.top();
            st.pop();
        }
        
        /* Now Check Which one is greater,
        if max is greater then it's the valid substring length
        else check is greater i.e. the string contains all fixed brackets and
        left opening brackets at the end.
        More clearly, stack top contains string's last index consiquitively in 
        decreasing order.
        Example: 
        If string length is 8 then :
                8
                7
                6
        */
        
        if(max >= check)
            return max;
        else
            return check;
    }
};
