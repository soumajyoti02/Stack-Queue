// C++ program to find duplicate parenthesis in a balanced expression
/*
Main Approach of This Program is as Follows : 

1. Declare a Stack to Store '(' parenthesis.
2. Start a loop to scan the full expression.
        3. If a '(' is found then push it into the stack.
        4. If a ')' i.e. closing parenthesis is found then POP AN ELEMENT 1ST from the stack to get proper count
           because : -- An Expression has duplicate parenthesis when 
            i) No element is found inside an parenthesis set i.e. () or
            ii) A single element is found inside that parenthesis i.e. (X).

        5. Then Start a loop till stack.top() != '('
                i) Start Incrementing the counter variable.
                ii) pop an element from stack i.e. stack.pop().

        6. If value of counter variable is less than 1 i.e. 0 then no element is present inside that parenthesis set.
           So invalid parenthesis is found. Then We return true.

7. When Loop ends but No such set is found there counter variable is 0; then no duplicate element is found 
        Then Simply return true.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to find duplicate parenthesis in a
// balanced expression
bool findDuplicateparenthesis(string str)
{
	//CODE HERE
	stack<char>st; //Stack to Store opening Parenthesis
	for(int i = 0; i < str.size(); i++)
	{
	    int cnt = 0;
	    if(str[i] != ')')
	    {
	        st.push(str[i]);
	    }
	    else
	    {
	        st.pop();
	        while(st.top() != '(' and !st.empty())
	        {
	            cnt++; // Counter variable to Check if any element is present between 2 parenthesis.
	            st.pop();
	        }
	        if(cnt < 1) // Means No variable is found; i.e. Duplicate parenthesis.
	        {
	            return true;
	        }
	    }
	}
	return false; //No such Duplicate Parenthesis is found. So return false.
}


// Driver code
int main()
{
	// input balanced expression
	string str = "(a+b)+(c+d)";

	if (findDuplicateparenthesis(str))
		cout << "Duplicate Found ";
	else
		cout << "No Duplicates Found ";

	return 0;
}
