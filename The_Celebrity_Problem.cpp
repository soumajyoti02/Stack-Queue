/*
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
QUESTION : A celebrity is a person who is known to all but does not know anyone at a party.
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party
such that if an element of row i and column j  is set to 1 it means ith person knows jth person.
Here M[i][i] will always be 0.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
-----------------------------------------------------------------------------------------------

Approach to solve this program is as Follows :[FIND AN ELEMENT WHO KNOWS SOMEONE FROM END; THEN FIND IF HE KNOWS EVERYONE ?]

$$$ A index is a Celebrity if : 
-->In that row, All column values are zero [i.e. It doesn't knows anyone];
--> In that Column, All row values are Zero except that row = column value (because he himself knows him is absurd); 
    [i.e. Everyone knows him]

1. Take a variable (A) and initialize it with starting Row index i.e. 0; It will be used to check Row-wise
2. Take another variable (B) and initialize with maximum Column value i.e. n - 1. It will be used to check Column-wise

3. Start a Loop with condition a < b --> because every diagonal element is 0; 
   So when we reached a diagonal point then all the elements have been checked
   Because we started the travarsal from start and end.
   So We will meet up in the middle point. Diagonal point is the middle point.
   
4. If 0 found in M[a][b] position i.e. 1st row last column position;
   --> Then decrement b by 1 i.e. b--; 
       ----->>>>> !! Because here our Motive is To Find an element Who knows Someone. !!
       
    i.e.      <--(b)
         0  0  1  0 
         0  0  1  0 
         0  0  0  0
         0  0  1  0
         
   --> ELSE 1 found in any M[a][b] position it means that element knows that column index, so Start checking next row i.e.
          next element also knows him or not.
          ----->>>> !! We Found an element Who Knows Someone. So let's Check if he knows everyone ?? !!
          
   i.e. 1 --> b  |
        1 --> b  |
        1 --> b \/
        0 -->Suppose Diagonal element
   

*/
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //initializing two pointers for two corners.
        int a = 0;
        int b = n - 1;
        
        //we keep moving till the a<b. 
        while (a < b) {
            if (M[a][b])
                a++; // We found an element who knows someone; So checking if he knows it's lower row also.
            else
                b--;
        }
        
        //checking if a is actually a celebrity or not.
        for (int i = 0; i < n; i++)
        {
            /*if any person doesn't know a or a knows any person, we return -1. 
            If it's Celebrity then Sum of that Row = 0 and Sum of that Column will be n-1
            
            i.e. All row values of that column will be 1 and all Column values of that row will be zero ( 0 )
          */
            if ( (i != a) && (M[a][i] || !M[i][a]) ) 
                return -1;
        }
        //if we reach here a is celebrity so we retun a.
        return a;
    }
};
