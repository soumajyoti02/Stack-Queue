/*
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Question : Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element 
of the array in order of their appearance in the array.

Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.
For example, next greater of the last element is always -1.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
----------------------------------------------------------
Main Approach for this program is as follows :
---> Start the Travarsal from the end because we know that stack is last in first out. FOR( i = n - 1 to 0 )

---> Then Check that Our Stack is Empty or not. If Not empty, Check that if Stack top is <= that number??

    -->> If yes then POP the stack untill stack top becomes less than that element or stack becomes empty.
---> Then if Stack becomes empty, push -1 in result vector. ELSE push stack.top();
---> push that element inside stack;

    EXAMPLE:  If Our Main Array is [1,3,2,4] then by travarsing from end, we 1st get 4. Now initially stack is empty so;
  |     |
  |     |
  |     |
  |__4__| 
  
  *** Now as the stack is empty, -1 is entered in ith index of our resultant vector.
  
  *** In the 2nd iteration, 2 will come out from main array --> [1,3,2,4]
  ---> Stack top is greater than 2, so No POPPING needed. Simply add the stack.top (Which is 4)  in the answer.
       Then push 3 inside stack.
  |     |
  |     |
  |  2  |
  |__4__|
  
  *** In 3rd iteration, 3 will come out from main array --> [1,3,2,4]
  ---> Stack top is lesser than 3; So 2 Will be popped out. NOW STACK TOP IS GREATER THAN 3;
       2 is popped out, so stack top becomes 4. This 4 again will be added in answer.
       Then push 3 inside stack.
   i) |     |                             
      |     |                                   
  3-->|  2------>                    
      |__4__| 
  
  ii) |     |
      |     |
      |  3  |
      |__4__|

   *** In 4th i.e. last iteration, 1 will come out from main array --> [1,3,2,4]
  --->  Stack top is greater than 1, so No POPPING needed. Simply add the stack.top (Which is 3)  in the answer.
       Then push 1 inside stack.

*/
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long > s;
        vector<long long > res (n);
        
        //traversing the array from last element in backward direction.
        for (int i = n-1; i >= 0; i--)
        {
            //while element at top of stack is less than or equal to
            //current array element, we pop elements from the stack.
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
            
            //if stack becomes empty, we store -1 in the answer list 
            //else we store the top element of the stack.   
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
            
            //pushing the current array element into the stack.  
            s.push (arr[i]);
        }
        //returning the list.
        return res;
    }
};
