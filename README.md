# Stack-Queue
## Stack 
It is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out) .Initially We Declare a Top Variable and store -1 inside it. It is the starting index of our Stack.

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

<hr><hr><hr>
<h2>Queue</h2>
A queue is defined as a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order.

We define a queue to be a list in which all additions to the list are made at one end, and all deletions from the list are made at the other end.  The element which is first pushed into the order, the operation is first performed on that.
<hr>
<img src="https://user-images.githubusercontent.com/103195837/189983487-f6d3c493-7c51-4a7d-8d4e-85db7b88fce9.png" alt="Queue" width="500" height="250">
<hr>
<h2>FIFO Principle of Queue:</h2>
--> A Queue is like a line waiting to purchase tickets, where the first person in line is the first person served. (i.e. First come first serve).
Position of the entry in a queue ready to be served, that is, the first entry that will be removed from the queue, is called the front of the queue(sometimes, head of the queue), similarly, the position of the last entry in the queue, that is, the one most recently added, is called the rear (or the tail) of the queue. See the below figure.
<hr>
<img src="https://user-images.githubusercontent.com/103195837/189983598-d65ad03c-1a86-4144-91f5-65740ae786e5.png" alt="Queue" width="500" height="250">
<hr>
<h2>Characteristics of Queue:</h2>
Queue can handle multiple data.
We can access both ends.
They are fast and flexible. 
<hr>
<h2>Queue Representation:</h2>
Like stacks, Queues can also be represented in an array: In this representation, the Queue is implemented using the array. Variables used in this case are

Queue: the name of the array storing queue elements.
Front: the index where the first element is stored in the array representing the queue.
Rear: the index where the last element is stored in an array representing the queue.

<hr>
In queue, insertion and deletion happen at the opposite ends, so implementation is not as simple as stack. 
To implement a queue using array, create an array arr of size n and take two variables front and rear both of which will be initialized to 0 which means the queue is currently empty. Element rear is the index upto which the elements are stored in the array and front is the index of the first element of the array. Now, some of the implementation of queue operations are as follows: 

<h2>Enqueue</h2>
Addition of an element to the queue. Adding an element will be performed after checking whether the queue is full or not. If rear < n which indicates that the array is not full then store the element at arr[rear] and increment rear by 1 but if rear == n then it is said to be an Overflow condition as the array is full.
<h2>Dequeue</h2>
Removal of an element from the queue. An element can only be deleted when there is at least an element to delete i.e. rear > 0. Now, element at arr[front] can be deleted but all the remaining elements have to shifted to the left by one position in order for the dequeue operation to delete the second element from the left on another dequeue operation.
<h2>Front</h2>
Get the front element from the queue i.e. arr[front] if queue is not empty.
<h2>Display</h2>
Print all element of the queue. If the queue is non-empty, traverse and print all the elements from index front to rear.

