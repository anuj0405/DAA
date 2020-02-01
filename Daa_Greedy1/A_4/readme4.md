#Problem Statement:
Observe that the algorithm PARTITION() for Quicksort given in the text is different from
the one discussed in the class. Implement two different Quicksort routines that use the two
different PARTITION routines. Test your implementation on an input vector of size at least
a 2048 integers and time the programs. Analyze the result and document it.


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
and we have used two Different partition one is hoare partition and another is normal partition and we have used these two partition
on same vector to analyize our result. 


#Final Output:

Our final Output is 
1. Time Taken by Hoare partiton
2. Time taken by Normal partition
 
#Conclusion:
Comparison table:

									                       
----Input --------Time taken By Hoare Partition ----------------------------------Time taken by Normal Partition--------
				    				  |	
1. 10	    	    2 Microseconds				  |			2 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
				        			  |
2. 100      	    24 Microseconds				  |			24 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				  				  |	
3. 1000     	    434 Microseconds				  |			439 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				        			  |
4. 10000    	    4106 Microseconds				  |			3884 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------
				        			  |	
5. 100000         50994 Microseconds	  			  |			53913 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------	
	    			        			  |	
6. 1000000 	  558793 Microseconds				  |			682778	Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------	
	    			        			  |	
7. 10000000 	  6036925 Microseconds				  |			18647263 Microseconds 
---------------------------------------------------------------------------------------------------------------------------------------	

In this Assignment we have two Partition algorithm  for Quick sort we have used them on same vector and as we can see them they both 
give the Asymptotic time complexity of O(nlogn) on an average case but hoare partition is 3.0889 times faster than our Normal partition
but for this Size of vector has to be Size>10000000 as per My laptop becouse it is empirical analysis so it very from System to system.

