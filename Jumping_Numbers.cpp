QUESTION : Given a positive number X. Find the largest Jumping Number which is smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single-digit numbers are considered as Jumping Numbers;
For example 7, 8987 and 4343456 are Jumping numbers but 796, 677 and 89098 are not;

Input:
X = 10
Output:
10
Explanation:
10 is the largest Jumping Number
possible for X = 10.;

Input:
X = 50
Output:
45
Explanation:
45 is the largest Jumping Number
possible for X = 50.;


APPROACH : Any number is a jumping number if each digit differenec is exactly 1; So all numbers from 1 to 10 is jumping numbers. So add all into a queue;
Extract numbers 1 by 1 till queue becomes empty;
Extract the last digit of that number by %10 and go to next decimal range by multiplying with 10; 
Increase last digit by 1 and decrease by 1, Both are jumping numbers. Add them into the queue;


CODE BELOW ::::::::




class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        queue<long long> q;
        long long ans = INT_MIN;
        for(int i = 0; i < 10; i++) q.push(i);
        
        while(!q.empty())
        {
            long long fr = q.front();
            q.pop();
            if(fr > X) continue;
            ans = max(ans,fr);
            int rem = fr % 10;
            if(rem != 0) q.push(fr*10+(rem-1));
            if(rem != 9) q.push(fr*10+(rem+1));
        }
        
        return ans;
    }
};
