#Problem Statement: 
Consider a highway of M miles. The task is to place billboards on the highway such that revenue is maximized. The possible sites for 
billboards are given by number x1 < x2 < ….. < xn-1 < xn, specifying positions in miles measured from one end of the road. If we place a 
billboard at position xi, we receive a revenue of ri > 0. There is a restriction that no two billboards can be placed within t miles or less 
than it.

#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:
<bits/stdc++.h>
<chrono>




#Input Of Program:
In this program we have taken length of our highway and no bill-boards we are placing and after we have taken two array in this
in which we have stored position of our bill-boards and and its revenue cost respectively.
time complexity in we are having is O(M) 	where M=length of our Highway.



#Conclusion:
Let maxRev[i], 1 <= i <= M, be the maximum revenue generated from beginning to i miles on the highway. 
Now for each mile on the highway, we need to check whether this mile has the option for any billboard, 
if not then the maximum revenue generated till that mile would be same as maximum revenue generated till one mile before.
But if that mile has the option for billboard then we have 2 options:
1. Either we will place the billboard, ignore the billboard in previous t miles, and add the revenue of the billboard placed.
2. Ignore this billboard. So maxRev[i] = max(maxRev[i-t-1] + revenue[i], maxRev[i-1])
so we have implemented it using Dynamic Programming which is giving us the
Time Complexity: O(M), where M is distance of total Highway.
Auxiliary Space: O(M).


