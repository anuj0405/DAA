#Problem Statement: 
Compare the times in executing the programs in problems at Sr nos 4,5,6 and analyze your
results. Give appropriate inferences.
#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:
include <bits/stdc++.h> 
include <chrono>



#Input Of Program:
In this program we have made 4 Functions
1. Normal quick sort partition
2. Hoare quick sort partition
3. Median-of-three quick sort partition
4. Random quick sort partition
and we have taken 4 different vector with same input in all vector and given them as input to these 4 programs
and we have given the timer to all these programs to compare them and to analyze quick sort 


#Final Output:
our Final output is that we get all vector sorted and We get time taken by each quick sort 

#Conclusion:
Comparison table:

									                       
   Input ------Normal partition-------Hoare partition------Median of three partition-------Random partition-------------------------
				    |			  |			       |		      |
1. 10    	  3 microseconds    |   4 microseconds    |  	  5 microseconds       |   7 microseconds     | 
---------------------------------------------------------------------------------------------------------------------------------------	
				    |			  |			       |		      |
2. 100 		 63 microseconds    |  64 microseconds    |  	  83 microseconds      |   92 microseconds    | 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
3. 1000    	842 microseconds    |   922 microseconds  |   	  1007 microseconds    |   798 microseconds   |
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
4. 10000       4393 microseconds    |   4873 microseconds |  	  5161 microseconds    |   4492 microseconds  | 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |	
5. 100000       51234 Microseconds  | 50707 Microseconds  |       54698 Microseconds   |   54646 microseconds | 
---------------------------------------------------------------------------------------------------------------------------------------	
	    			    |			  |			       |		      |
6. 1000000      668559 Microseconds | 547962 Microseconds |      594603 Microseconds   |   591268 microseconds|
---------------------------------------------------------------------------------------------------------------------------------------	
	    			    |			  |			       |		      |
7. 10000000   18612800 Microseconds | 597463 Microseconds |      6379856 Microseconds  |  6407937 microseconds|
---------------------------------------------------------------------------------------------------------------------------------------	

Sorted Input ---Normal partition-------Hoare partition------Median of three partition-------Random partition-------------------------
				    |			  |			       |		      |
1. 10    	  2 microseconds    |   1 microseconds    |  	  3 microseconds       |   3 microseconds     | 
---------------------------------------------------------------------------------------------------------------------------------------	
				    |			  |			       |		      |
2. 100 		362 microseconds    |  111 microseconds   |  	   54 microseconds     |   64 microseconds    | 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
3. 1000        21374 microseconds   | 3015 microseconds   |   	   197 microseconds    |   223 microseconds   |
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
4. 10000     1285864 microseconds   |294793 microseconds  |  	    1992 microseconds  |   2375 microseconds  | 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |	
5. 100000   13216949 microseconds   |29948873 microseconds|       22379 microseconds   |   27255 microseconds | 
---------------------------------------------------------------------------------------------------------------------------------------

For Random input: Hoare partition is giving less time than all 4
For sorted input: Median of three and random partition is giving less time all 4

so we can say that if input is not sorted then Hoare partition can be used it will always given you the time complexity of O(Nlog N)
infact all four will give you the time complexity of O(Nlog N) but if we see Empirical analysis Hoare is giving less time than all 4
 
and if Input is already sorted then Hoare and Normal quick sort is giving us the time Complexity of O(N^2) and Median of Three and
Random partition is giving us the time Complexity O(Nlog N) even the array is sorted.

 
