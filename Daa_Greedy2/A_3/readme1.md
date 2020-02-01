#Problem Statement: 
Write a program for Insertion sort,Merge sort to count number of exchanges/swaps required to sort the input data.
Consider the worst case, the best case and the average case inputs to test your program. 
Use appropriate dataset that contains at least 10000 values to test your program

#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:
<bits/stdc++.h>
<chrono>
<sys/time.h>
<vector>
<fstream>




#Input Of Program:
In this program we have taken three text file as in input to sort each containing {10,100,1000,10000,100000} Elements
to count No of Swaps and also to Find the time Complexity of our program in Best, average, Worst case for Insertion and Merege Algorithm 
Which is For Insetion O(n) for best case,O(n^2) for Average case,O(n^2) For worst case and In Merger sort for all cases O(nlog n) will be the 
time complexity Asymptoticaly.

Insertion sort:
1. To find the Best case we have taken file wich is already sorted . 
2. To find the Average case we have taken a random input file.
3. To find the Worst case we have taken a Sorted file Decreacing order of Input.

Merge sort:
1. To find the Best case we have taken file wich is already sorted . 
2. To find the Average case we have taken a random input file.
3. To find the Worst case we have taken a Sorted file Decreacing order of Input.

#Final Output:
Our final Output is what we required. we get our elements sorted and we store them a new file
and we have calculated no of swaps in Inserion sort and Merge sort which are 0 for Insertion sort in Best case and 0 For merge sort for all 
the three cases and we use two different timer in our program to calculate time in microsecond which are chrono and time.h



#Conclusion:
Comparison table:

			Insertion Sort						                       Merge Sort
   Input --------------------Chrono-----------Timeval----------No of Swaps--|-------Chrono----------Timeval-------------No of swaps--------
1. 10--Best case:     30 microseconds   37 microseconds       0             | 7 microsecods	   5 microsecods	    0
	Average case: 49 microseconds   40 microseconds       26            | 7 microsecods	   7 microsecods            0
 	Worst case:   74 microseconds	48 microseconds       45	    | 5 microsecods        6 microsecods            0
---------------------------------------------------------------------------------------------------------------------------------------	

2. 100--Best case:    32 microseconds   48 microseconds       0             | 45 microsecods       35 microsecods           0
	Average case: 165 microseconds  141 microseconds      2502          | 59 microsecods       52 microsecods           0
	Worst case:   161 microseconds	225 microseconds      4950          | 42 microsecods	   33 microsecods           0
---------------------------------------------------------------------------------------------------------------------------------------

3. 1000-Best case:    45 microseconds   49 microseconds        0            | 559 microsecods      563 microsecods          0
	Average case: 8018 microseconds 9288 microseconds      244788       | 751 microsecods      735 microsecods          0
	Worst case:   0.015072 seconds	0.013160 seconds       499500       | 510 microsecods      502 microsecods          0
---------------------------------------------------------------------------------------------------------------------------------------

4. 10000-Best case:   49 microseconds	28 microseconds	       0	    | 4356 microsecods     2812 microsecods         0
	Average case: 0.435119 seconds  0.439823 seconds       24925183     | 4272 microsecods     5010 microsecods         0
	Worst case:   0.869290 seconds	0.882270 seconds       49995000	    | 2836 microsecods     2798 microsecods         0
---------------------------------------------------------------------------------------------------------------------------------------

5. 100000-Best case:  24 microseconds   27 microseconds        0            | 34341 microsecods    34449 microsecods        0
	Average case: 43.410520 seconds 43.631748 seconds      2502690779   | 51907 microsecods    51071 microsecods        0
	Wosrt case:   86.540443 seconds	87.339026 seconds      4999950000   | 33890 microsecods    33934 microsecods        0
---------------------------------------------------------------------------------------------------------------------------------------	


For Best case:
As we can se Insertion sort will always perform Better than Merge sort in best case the time difference between them is much greater as we 
increase our input size.

For all other cases:
Merge sort will always perform better in all other cases than insertion sort.

Asyptotic and Emperical time complexity comparision:
		Insertion		Best case: O(n)			Average case: O(n^2)			Worst case:O(n^2)
			         Emperical    |	  Asymptotic          Emperical    |  Asymptotic      Emperical    |    Asymptotic
Input:	100				32    |    32                   165        |     165               161     |      161
        1000                            45    |    320                  8018       |     16500             15072   |      16100
	10000                           49    |    3200                 435119     |     1650000           869290  |      1610000
	100000				24    |    32000		43410520   |     165000000         86540443|      161000000

----------------------------------------------------------------------------------------------------------------------------------------
1. As we can see our Emperical time complexity is much less than our Asymptotic time complexity but as we are increasing our input the are getting closer in my analysis i have taken base input to be 100 to compare our algorithm so thats why i am getting diference in our output between Emperical and Asymtotic but if we take base to be 10000 than our difference will reduce .
example: if we 10000 as base for average case our emperical T.C 435119

	but as we increase our input to 10 times our time should have increased by 100 time becouse of o(n^2) so our output should be 
43511900 and our T.C in	100000 is  43410520 is almost comparable.
so, in conlusion we can say that if increase our output to be more they will get almost same orr even we can say that Asymptotic T.C will 
be less than Empirical T.C.

2. simillar goes for merge sort if we take 10000 as a base so our time complexity is 4272 for Asymptotic it is O(nlogn) is so our next input should be approximetly 42720 and we have achived 51907 so we can say that our assumption is correct. 

3. In merge sort we have our best and worst is almost same but average is more than both of them becouse no of comparision in merge sort in average case is more than no of comparision in best and worst case which we have taken.

4. Nof swaps in insertition sort worst case is N(N-1)/2 always , Where N=no of element to be sorted 
