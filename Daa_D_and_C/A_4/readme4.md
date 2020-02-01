#Problem Statement: 
Write a program to implement Binary Exponent Algorithm explained in class, time the program and analyze as explained in the instructions. 
Compare your implementation with the Square-and-multiply method of exponentiation.

#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:
include<iostream>
include<stdio.h>
include<chrono>



#Input Of Program:
Any no in the form of a^x. 

#Final Output:

Our final Output Result of a^x and we use two different timer in our program to calculate time in microsecond which are chrono and time.h



#Conclusion:
Comparison table:

			Square and Multiply				 Binary_exponent
Input --------------------Chrono-------------No of Mul-------|------------Chrono-------------No of Mull--------------------------------

1. 2^4		       782 nenoseconds             2         | 		341 nenoseconds         3
---------------------------------------------------------------------------------------------------------------------------------------

2. 2^8		       1047 nenoseconds            3         | 		386 nenoseconds         4 
---------------------------------------------------------------------------------------------------------------------------------------

3. 2^16		       782 nenoseconds             4         | 		446 nenoseconds         5
---------------------------------------------------------------------------------------------------------------------------------------

4. 2^32		       1013 nenoseconds	          5          |		370 nenoseconds         6
---------------------------------------------------------------------------------------------------------------------------------------

5. 2^63		       1103 nenoseconds          10          | 		301 nenoseconds         11
---------------------------------------------------------------------------------------------------------------------------------------	

No of multiplications: In binary exponent no of multiplication will always going to be one more than in square multiple
		       becouse in this we multiply one extra even if we get our answer.
Time taken by our Binary exponent algorithm is less than square and multiple as we can see thye above table for time comparision
and also the Time complexity of both the algorithm is O(log n) 

