#Problem Statement:

Implement MEDIAN-OF-THREE-PARTITION routine for Quicksort as discussed in the
class. Time the program on ten different randomly generated integer vectors of size 1024
each and time the programs. Analyze the result and document it.

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
and we have used MEDIAN-OF-THREE-PARTITION routine and we have used this partition in quick sort. 


#Final Output:

Our final Output is 
Sorted array of size 1024
 
#Conclusion:
Comparison table:

									                       
----Input -------------------------------------Time taken by MEDIA-OF-THREE_PARTITION--------------------------------------------------
		
1.  1024				396 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
2.  1024 				682 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------
3.  1024				422 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------
4.  1024				740 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------
5.  1024(Given as sorted order)		310 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
6.  1024				563 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
7.  1024				674 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
8.  1024				530 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
9.  1024				911 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	
10. 1024				449 Microseconds
---------------------------------------------------------------------------------------------------------------------------------------	

In this Assignment we have Use median of three to partition to sort our array and we have computed 10 Different times on 
different vector of same size 1024 and in that we have also give the given one sorted order vector and as we can see it gives 
very less complexity normal quick sort would have given you O(n^2) time complexity but it is giving us O( nlog n) T.C.


