/*
1. Calculate the total number of moves required i.e. "pow(2, n) - 1"; here n is number of disks.
2. If number of disks (i.e. n) is even then interchange destination pole and auxiliary pole.
--> char s = 'S', d = 'D', a = 'A';
3. FOR i = 1 to total number of moves --> (pow(2, No_Of_Disks) - 1):
  if i%3 == 1:
  --> Legal movement of top disk between source pole and  destination pole
  if i%3 == 2:
  --> Legal movement top disk between source pole and auxiliary pole    
  if i%3 == 0:
  --> Legal movement top disk between auxiliary pole and destination pole 
  
4. Inside the [move Disks Between Two Poles] function In Which, the swapping occurs : 
 i) POP 1 element from source stack and 1 from Destination Stack
 ii) If Source stack becomes empty then PUSH other element in Source stack.
     ELSE IF Destination Stack is empty then PUSH other element in that stack.
 iii) ELSE :
      A) If source disk is large then push source disk inside source and then push destination disk also in source.
      B) If destination disk is large then push destination disk inside source and then push source disk also in destination.
 iv) In every case; call [Move Disk] function; which takes from which stack to which stack we transferring.
      It prints : cout <<"Move the disk " << disk <<" from " << fromPeg << " to "<< toPeg << endl;
*/

// C++ Program for Iterative Tower of Hanoi
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a stack
struct Stack
{
unsigned capacity;
int top;
int *array;
};

// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack =
		(struct Stack*) malloc(sizeof(struct Stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array =
		(int*) malloc(stack -> capacity * sizeof(int));
	return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
return (stack->top == -1);
}

// Function to add an item to stack. It increases
// top by 1
void push(struct Stack *stack, int item)
{
	if (isFull(stack))
		return;
	stack -> array[++stack -> top] = item;
}

// Function to remove an item from stack. It
// decreases top by 1
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack -> array[stack -> top--];
}
//>>>>>>>>>>>>>>>>>>> MAIN TASK >>>>>>>>>>>>>>>>>>>

//Function to show the movement of disks
void moveDisk(char fromPeg, char toPeg, int disk)
{
	cout <<"Move the disk " << disk <<" from " << fromPeg << " to "<< toPeg << endl;
}

// Function to implement legal movement between
// two poles
void moveDisksBetweenTwoPoles(struct Stack *src,
			struct Stack *dest, char s, char d)
{
	int pole1TopDisk = pop(src);
	int pole2TopDisk = pop(dest);

	// When pole 1 is empty
	if (pole1TopDisk == INT_MIN)
	{
		push(src, pole2TopDisk);
		moveDisk(d, s, pole2TopDisk);
	}

	// When pole2 pole is empty
	else if (pole2TopDisk == INT_MIN)
	{
		push(dest, pole1TopDisk);
		moveDisk(s, d, pole1TopDisk);
	}

	// When top disk of pole1 > top disk of pole2
	else if (pole1TopDisk > pole2TopDisk)
	{
		push(src, pole1TopDisk);
		push(src, pole2TopDisk);
		moveDisk(d, s, pole2TopDisk);
	}

	// When top disk of pole1 < top disk of pole2
	else
	{
		push(dest, pole2TopDisk);
		push(dest, pole1TopDisk);
		moveDisk(s, d, pole1TopDisk);
	}
}

//Function to implement TOH puzzle
void tohIterative(int num_of_disks, struct Stack
			*src, struct Stack *aux,
			struct Stack *dest)
{
	int i, total_num_of_moves;
	char s = 'S', d = 'D', a = 'A';

	//If number of disks is even, then interchange
	//destination pole and auxiliary pole
	if (num_of_disks % 2 == 0)
	{
		char temp = d;
		d = a;
		a = temp;
	}
	total_num_of_moves = pow(2, num_of_disks) - 1;

	//Larger disks will be pushed first
	for (i = num_of_disks; i >= 1; i--)
		push(src, i);

	for (i = 1; i <= total_num_of_moves; i++)
	{
		if (i % 3 == 1)
		moveDisksBetweenTwoPoles(src, dest, s, d);

		else if (i % 3 == 2)
		moveDisksBetweenTwoPoles(src, aux, s, a);

		else if (i % 3 == 0)
		moveDisksBetweenTwoPoles(aux, dest, a, d);
	}
}

// Driver Program
int main()
{

	// Input: number of disks
	unsigned num_of_disks = 3;

	struct Stack *src, *dest, *aux;

	// Create three stacks of size 'num_of_disks'
	// to hold the disks
	src = createStack(num_of_disks);
	aux = createStack(num_of_disks);
	dest = createStack(num_of_disks);

	tohIterative(num_of_disks, src, aux, dest);
	return 0;
}

// This code is contributed by shivanisinghss2110
