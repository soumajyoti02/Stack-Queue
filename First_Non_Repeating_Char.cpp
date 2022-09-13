/*
----------------------------------------------------------
QUESTION: Given an input stream of A of n characters consisting only of lower case alphabets. 
The task is to find the first non repeating character, each time a character is inserted to the stream.
If there is no such character then append '#' to the answer.
----------------------------------------------------------
Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'


Main Approach For This Program is as Follows :
1. Take a vector (V) of size 26 (because in English, there are 26 letters present) and fill with zero. It will work as a letter counter.
2. Declare a int type queue to store temporary results. 
  --> We are taking Queue because we have to find the 1st non repeating character. In queue it's easy to access and remove front elements.
  
3. Start a loop FOR i = 0 to SIZE of given string to check every letter of the string.

  3.1) Push str[i] into Queue.
  3.2) Increase the count of that letter in vector V (STEP 1) by V(str[i] - 'a')++;
       -->That str[i] - 'a' will give us proper index by substracting that letter with starting ascii value of A;
       
  3.3) Now Queue-front is our 1st Non-repeting letter. So, in every iteration we have to check if that Queue-front is repeated or Not.
  
       ---> We can check this by checking Q.front()'s count in our counter vector V; 
       ---> DO THIS BY STARTING A LOOP till Queue is not empty;
       
       3.3.1) Check Queue.front() count in V vector by IF V[Queue.front()-'a']>1. 
              --> If it's true then POP elements untill Queue top becomes a Non repeating element i.e. such a element is found whose count is 1;
              
  3.4) If Queue Becomes empty in that process then Just print '#';
  3.5) ELSE the Queue top is our current 1st Non Repeating Character. So add it in ANSWER string which we will have to return at the end.
       
*/
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    string ans;
		    vector<int>v(26,0);
		    queue<char>q;
		    for(int i=0;i<a.size();i++)
		    {
		        q.push(a[i]);
		        v[a[i]-'a']++;
		        while(!q.empty())
		        {
		            if(v[q.front()-'a']>1)
		            q.pop();
		            else
		            break;
		        }
		        if(q.empty())ans+='#';
		        else ans+=q.front();
		    }
		    return ans;
		}

};
