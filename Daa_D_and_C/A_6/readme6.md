#Problem Statement: 
Write a program that illustrates the comparison of an ordinary Binary tree with any one of the
2-3, AVL, or Red Black trees and illustrates the specific benefits of one of the 2-3, AVL, or Red
Black trees that you have used in your implementation. Obviously for the implementation
and fairer comparison, use the same data set as input. Then, extend this program to compare
the 2-3, AVL, or Red Black trees with each other. Analyze the comparison and give concrete
conclusions.

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
We have given the same input to both the tree and we made two function insert and search and we have calculate the time complexity of our 
fucntions 

#Final Output:
Time takesn by Insert and Search program.
#Conclusion:
Comparison table:
			Binary tree						AVL Tree						
									                       
   Input ----------Insertion----------------Search-----------------------Insertion-----------------Search-------------------------
				    |			  |			       |		      |
1. 10    	  3 microseconds    |   2 microseconds    |  	  39 microseconds      |   1 microseconds     | 
---------------------------------------------------------------------------------------------------------------------------------------	
				    |			  |			       |		      |
2. 100 		 16 microseconds    |  6 microseconds     |  	  145 microseconds     |    1 microseconds    | 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
3. 1000    	152 microseconds    |    39 microseconds  |   	   2126 microseconds   |     2 microseconds   |
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |
4. 10000        723 microseconds    |    270 microseconds |  	 18295 microseconds    |      3 microseconds  | 
---------------------------------------------------------------------------------------------------------------------------------------
				    |			  |			       |		      |	
5. 100000        7599 Microseconds  |   574 Microseconds  |      129197 Microseconds   |       4 microseconds | 
---------------------------------------------------------------------------------------------------------------------------------------	
	    			    |			  |			       |		      |
6. 1000000       77938 Microseconds |   5260 Microseconds |      1225635 Microseconds  |        4 microseconds|
---------------------------------------------------------------------------------------------------------------------------------------	
	    			    |			  |			       |		      |
7. 10000000     776106 Microseconds |  129382 Microseconds|      12215890 Microseconds |        5 microseconds|
---------------------------------------------------------------------------------------------------------------------------------------	

As we can see insertion of level order binary tree is taking less time than Avl tree and searching time of Avl is very very lower than
our search in binary tree Insertions time For Binary tree is O(n) and for AVL it is O(nlog n)
and Search time of Binary is O(n) and Search time in AVL is O(Log n) where n is the no of nodes. 
