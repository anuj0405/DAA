#Problem Statement: 
Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, 
what is the minimum number of coins to make the change?

#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:
<bits/stdc++.h>
<chrono>



#Input Of Program:
In this program we have taken the Amount for which we want change of coins and no of type of coins we have and we have
taken array of type coins we have and we taken supply as infinite of same coins 
time complexity of coin change in this is O(MV)	where M=no of coins and V=Amount for which we need change.
Auxiliary Space: O(V).


#Final Output:
In our final output we get optimal solution with less time complexity than our brute force algorithm with our time
complexity as O(MV)	where M=no of coins and V=Amount for which we need change.

#Conclusion:
This is the recursion method we have used but if use it directly then we are getting our time as O(2^n)
The minimum number of coins for a value V can be computed using below recursive formula.

If V == 0, then 0 coins required.
If V > 0
   minCoins(coins[0..m-1], V) = min {1 + minCoins(V-coin[i])} 
                               where i varies from 0 to m-1 
                               and coin[i] <= V 
If we draw the complete recursion tree, we can observer that many subproblems are solved again and again. 
For example, when we start from V = 11, we can reach 6 by subtracting one 5 times and by subtracting 5 one times. 
So the subproblem for 6 is called twice.Since same suproblems are called again, this problem has Overlapping Subprolems property. 
So the min coins problem has both properties (see this and this) of a dynamic programming problem. 

Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a temporary array 
table[][] in bottom up manner.so by using Dynamic programming we can solve this problem with less time complexity.
