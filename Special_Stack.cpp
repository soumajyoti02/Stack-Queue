/*
<<<<<<<<<<<<- PROCEDURE ->>>>>>>>>>>>>>>>>>>>>>
To find minimum value:
1. Recursively stored all values of the stack inside a Vector.
2. Sort the Vector
3. Return the 0th Index value of that Vector.
*/

#include<bits/stdc++.h>
void puting(vector<int>& v, stack<int> s,int key)
{
    if(!s.empty())
    {
        key = s.top();
        v.push_back(key);
        s.pop();
        puting(v,s,key);
    }
    s.push(key);
}

int getMin(stack<int>& s){
	// Your code goes here
	vector<int> v;
	int key;
    puting(v,s,key);
    sort(v.begin(),v.end());
    return v[0];
}

void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size() == n)
	    return true;
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.empty())
	    return true;
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	int t = s.top();
	s.pop();
	return t;
}
