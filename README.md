# Stack-Queue
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out) .Initially We Declare a Top Variable and store -1 inside it. It is the starting index of our Stack.

![image](https://user-images.githubusercontent.com/103195837/189612513-86b51337-159e-4c33-a67c-71318e82073e.png)

<h3>In Stack Data Structure, there are mainly 5 Operations:</h3> 

1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
<hr>
<h2><b>Basic Syntax of Stack is :</b></h2>
<pre>
struct Stack
{
    int *arr;
    int top;
    int size;
};
</pre>

<h2><b>Push</b></h2>  It means adding a data inside stack. In this case, we will increament top 1st. Then we store that value in that top index.
<hr>
<h2><b>Pop</b></h2>  It means removing the last data added inside stack. In this case, we will store the value of the stack top. Then we decreamented the top bt -1 and return the value at previous index. 
<br>
<hr>
<img src="https://user-images.githubusercontent.com/103195837/189615162-5e8c75a4-b1df-4005-8aaa-d0c87b120c1d.png" alt="image" width="600" height="300">

<hr>
<h2><b>Peek</b></h2> To retrive the top of the Stack without removing it.
<hr>
<h2><b>isEmpty</b></h2> To Check if the stack is empty or not i.e value of top == -1 ?
<hr>

<h2><b>isFull</b></h2> To Check if the stack is full or not i.e value of stack == stack size?


<h2><b>IN C++ STL</b></h2>

![image](https://user-images.githubusercontent.com/103195837/189615691-c2211dfb-8e7d-4be8-9f04-37f9bb423bd3.png)

