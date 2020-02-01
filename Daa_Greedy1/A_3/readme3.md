#Problem Statement: 
Write programs to count the number of inversions in a given array using the brute force
approach and using the algorithm applying the merge-sort discussed in the class (with time
complexities O(n^2 ) and O(nlg n) respectively). Compare both the programs with timing
analysis with input size starting with n = 10 upto n = 10 5 . Comment on the results obtained.

#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:

include <chrono>
include <vector>
include <fstream>
include <iostream> 




#Input Of Program:
In this program we have have taken vector to store our input and we have given input to the vector by using random function
and we have used two algorithm Brute force and Merge Algorithm and we have given them input vector which contain our Data. 


#Final Output:

Our final Output is 
1. No of Inversion and Time taken By Brute Force Algorithm.
2. No of Inversion and Time taken By Merge Algorithm
 
#Conclusion:
Comparison table:

									                       
----Input -----No of Inversion and Time taken By Brute Force ----------------No of Inversion and Time taken by Merge algorithm--------
				    				  |	
1. 10	    Inversion=26	42 Microseconds			  |	Inversion=26		5 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
				        			  |
2. 100      Inversion=2502	276 Microseconds		  |	Inversion=2502		79 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				  				  |	
3. 1000     Inversion=244788	14724 Microseconds		  |	Inversion=244788	602 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				        			  |
4. 10000    Inversion=24925183	895520 Microseconds		  |	Inversion=24925183	4331 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				        			  |	
5. 100000   Inversion=2502690779   91553074 Microseconds	  |	Inversion=2502690779	57437 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------		

In this Assignment we have two algorithm Brute Force(B) and Merge Algorithm(M) 
B has time complexity O(n^2) in worst case and O(n) in best case.
M has time complexity O(nlog n) in all cases.
No of inversion should be the same in both the algorithm.

We can clearly see the difference between both algorithm our merge algorithm is taking very less time than Brute force method
 
