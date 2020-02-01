#Problem Statement: 
For this program, you are to fill in the functions, writing versions of 
(1) insertion sort 
(2) merge sort 
(3) myownsort. 
myownsort() is a variant of the existing sorting algorithms that is to be devised by you with an attempt to improve upon the performance of 
the merge sort. Use the skeleton of the codes including here for writing your programs - filling in the functions required. The sorting 
functions that you write must be modeled on the illustration of the Bubble sort shown. Assume N is the input array that you use for 
evaluating the programs.

After successfully writing and exeuting the code, answer the following questions:
(a) For each algorithm, how large (approximately) can N be if the sort must take no moren than 10 seconds?
(b) Can you think of a quick way to improve bubble sort by a factor of 2? Write a ”semibubbleSort(a)” function to do so.

#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:
include <iostream>
include <vector>
include <fstream>
include <sys/time.h>
include <chrono> 




#Input Of Program:
In this program we have made random function which will give use the random value it will ask us the no of input and It will give us 
array of that much no. and we are going to give that array to our sorting algorithms for all five sorting we have done the same thing we have 
also given the timer to this programer which is chrono timer.


#Final Output:

Our final Output is what we required. we get our elements sorted and we have checked them using check function and we have also solved the 
questions related to this assignment
(a) For each algorithm, how large (approximately) can N be if the sort must take no moren than 10 seconds?
Answer: For Bubble sort input size is:43000
	For Semi Bubble sort input size:43000
	For Insertition sort input size:80000
	For Merge sort input size:33554432
	For my own sort input size:33554432 
(b) Can you think of a quick way to improve bubble sort by a factor of 2? Write a ”semibubbleSort(a)” function to do so.
	To improve bubble sort we can compare our array after each pass and if we get same array then we can stop at that time.
	becouse our input is already sorted at that point of time. 


#Conclusion:
Comparison table:

									                       
   Input --------------Bubbel-------------semi-bubbel---------------Insertion----------------Merge sort-------------My own sort--------
				    |			  |			       |		      |
1. 10    	  2 microseconds    |   1 microseconds    |  	  26 microseconds      |   5 microseconds     |	  4 microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
				    |			  |			       |		      |
2. 100 		 96 microseconds    |  97 microseconds    |  	  105 microseconds     |   45 microseconds    |   35 microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
3. 1000    	8443 microseconds   |   49 microseconds   |   	  1747 microseconds    |   255 microseconds   |   235 microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
4. 10000       493520 microseconds  |   28 microseconds	  |  	  162065 microseconds  |   3171 microseconds  |   2967 microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |	
5. 43000       10.269025 seconds    | 10.598327 seconds   |       3.062606 seconds     |   15586 microseconds |   15891 microseconds 
---------------------------------------------------------------------------------------------------------------------------------------	
	    			    |			  |			       |		      |
6. 80000       36.401419 seconds    | 37.200394 seconds   |       10.188343 seconds    |   30238 microseconds |   28405 microseconds 
---------------------------------------------------------------------------------------------------------------------------------------	

as we can see our program we have implemented 
1. Bubble sort 
2. semi Bubbel sort: It is to improvement in Bubbel sort so we get best time complexity of bubbel sort as Omega(n).
3. Insertition sort
4. Merge sort
5. My own sort: In this i have tried to improve my merge sort algorithm to get my time complexity less so what we did is before 
	        calling merge procedure in merge sort we compare the last element of our first sub array and first element of second sub
	        array which are already sorted individualy if last element of our first sub array and first element of second sub
	        array is less then we directly skip our merge procedure which will save O(n) time.

		In best case(Array is already sorted) we can get our equation as T(n)=2T(n/2)+O(1)
		so we get in best case time complexity as Omega(n).

		also it has reduced the time complexity in average case as we can see on our time table.

 
