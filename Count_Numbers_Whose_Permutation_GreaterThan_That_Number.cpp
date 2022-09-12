/*
<<<---- Question ---->>>
Count natural numbers whose all permutation are greater than that number

Input: 15
Output: 14 --> [1,2,3,4,5,6,7,8,9,11,12,13,14,15]

Approach of This Program is as Follows :

***Answer will be Every Number from 1 to 9 and numbers which are in non decresing order like 123,259,1125 etc...***

1. Declare a int type stack to store the possible numbers temporarily.

2. From 1 to 9, every number is our possible answer; So start a loop FOR i = 1 to 9

  2.1) Check that, i is less than or equal to N (Given Upper Limit); if true then push that number inside our stack; also we will increment our result because this is a answer.

  2.2) After that, We have to check for all possible numbers starting with i (coming from FOR LOOP [Step 2])
       for that, let's take a while loop and give condition till stack is not empty:

     2.2.1) Extract the Top of the stack into a variable T and pop it;

     2.2.2) Since Our answers lies only in the non-Decresing Number range, so let's take a loop --->
     
i) Extract the end digit of the number and

ii) Run the FOR loop FOR J =  that number (T) to <= 9

iii) i.e. if our number is 17; then end digit is 7. Loop will run FOR J =  7 to 9;

iv) It will give the non decresing numbers.

       2.2.2.1) Check the next decimal range by multiplying that number with 10 and ADD J WITH IT
                [T (Which was stored in 2.2.1 step) * 10 + j]

       2.2.2.2) If that value is lesser or equal to N (given range) then push this number in stack; also increment result;

Example:
i) If the number is 1 then loop [Step 2.2.2 i.e. J = stack.top(T)%10 to 9] will run from 1 to 9

ii) Then by (T * 10 + J) we will get 11,12,13,14,15,16,17,18,19

iii) We will now PUSH the numbers in stack which are <= N;

iv) AFTER ENDING THE LOOP, IN THE NEXT ITERATION OF OUR WHILE (!stack.empty()) LOOP

v) Stack top will be T = 19;

vi) So 19 % 10 gives 9;

vii) FOR LOOP Will run 1 time for 9 = 9 condition.

viii) Now, T * 10 + j (= 9) gives 199; if this number is <= N then it PUSHed into stack;

ix) In next Iteration of WHILE loop; T = 199; 199 % 10 = 9; So J will run from 9 to 9 i.e. 1 time;

x) T * 10 + j gives 1999 and it will enter in stack if it <= N;

---->>>>>>>> Thus every Number which are in assending digit order and <= N will be added in Stack and our counter will store the data. <<<<<<<---------

*/
#include <bits/stdc++.h>
using namespace std;

// Return the count of the number having all
// permutation greater than or equal to the number.
int countNumber(int n)
{
    // Code Here
    int result = 0;
    stack<int> st;
    for (int i = 1; i <= 9; i++)
    {
        if (i <= n)
        {
            st.push(i);
            result++;
        }
        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            for (int j = t % 10; j <= 9; j++)
            {
                int val = t * 10 + j;
                if (val <= n)
                {
                    st.push(val);
                    result++;
                }
            }
        }
    }
    return result;
}

// Driven Code
int main()
{
    int n = 15;
    cout << countNumber(n) << endl;
    return 0;
}
