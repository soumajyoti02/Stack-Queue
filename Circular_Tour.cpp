/*
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
QUESTION : Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
-------------------------------------------------------------
Main Approach to Solve this Program is as follows :
Inside Our printTour function, which returns starting point if there is a possible Solution, else returns -1;

->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

---> We will check the difference Of Petrol and distance. WE CAN GET THE AMOUNT OF EXCESS PETROL SAVED from the substruction.

---> If at any point, That difference becomes zero, it means that previous starting path is not a valid solution. So we will 
start travelling from next path. So inside START variable, we will store the index of next path i.e.( i+1 ) .

---> We will also store the amound of petrol needed in that path in a variable DEFICIT. 

---> Deficit is Used to store the Extra petrol Needed to travel that root i.e. the negetive petrol demand in that root.
We will start travelling from next point but we have to check at last that; from last point, One can come to that
point or not. We don't have to use another loop for that. 

---> At last, as deficit has a negetive value; if ( capacity + deficit ) is >= 0 i.e. 
     From last, one can travel back to that path circularly, return the start index.
     
     ELSE there is no possible ways to travel all Path, so Return -1


*/
// C++ program to find circular tour for a truck
#include <bits/stdc++.h>
using namespace std;

// A petrol pump has petrol and distance to next petrol pump
class petrolPump {
public:
    int petrol;
    int distance;
};

int printTour(petrolPump p[], int n)
{
    int start = 0, deficit = 0;
    int capacity = 0;
    for (int i = 0; i < n; i++) {
        capacity += p[i].petrol - p[i].distance; // To store how much petrol is saved in that path.
        if (capacity < 0) // If that much petrol is not available to travel this path.
        {
            start = i + 1;
            deficit += capacity; // Store the need of petrols. At the end check the end capacity can cover that distance ?
            capacity = 0;
        }
    }
    return (capacity + deficit >= 0) ? start : -1;
}
// Driver code
int main()
{
    petrolPump arr[] = { { 6, 4 }, { 3, 6 }, { 7, 3 } };

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1) ? cout << "No solution"
                  : cout << "Start = " << start;

    return 0;
}
