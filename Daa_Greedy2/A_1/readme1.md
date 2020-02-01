#Problem Statement: 
Consider the following variation on the Interval Scheduling Problem. You have a processor
that can operate 24 hours a day, every day. People submit requests to run daily jobs on the
processor. Each such job comes with a start time and an end time; if the job is accepted to
run on the processor, it must run continuously, every day, for the period between its start
and end times. (Note that certain jobs can begin before midnight and end after midnight;
this makes for a type of situation different from what we saw in the Interval Scheduling
Problem). Given a list of n such jobs, your goal is to accept as many jobs as possible
(regardless of their length), subject to the constraint that the processor can run at most
one job at any given point in time. Provide an algorithm to do this with a running time
that is polynomial in n. You may assume for simplicity that no two jobs have the same
start or end times. Example. Consider the following four jobs, specified by (start-time, end-
time) pairs. (6P.M., 6A.M.), (9P.M., 4A.M.), (3A.M., 2P.M.), (1P.M., 7P.M.) The optimal
solution would be to pick the two jobs (9P.M., 4A.M.) and (1P.M., 7P.M.), which can be
scheduled without overlapping.

#Language Used: 
C++


#Platform:
OS:Ubuntu 18.04.3 LTS 2019(64 bit)
Processor: i3-4005U CPU @ 1.7GHz x 4

#Library Used:
<bits/stdc++.h>
<chrono>


#Input Of Program:
In this program we have taken array of structure which contain start and end time ans input and the no of jobs which we
wants to schedule


#Final Output:
Our final Output is what we required. we get no jobs which we can scehdule without overlapping with each other
so in this we get our time comlexity as O(n^2)


#Conclusion:
In this algorithm we have taken all jobs which starting before Mid-night and ending after Mid-night becouse the are only job 
which are surely be overlping with each other after that we can solve it as Class interval problem with selecting midnight job each
at a time and after that we solve it by taking midnight job at first and check the which job is giving us the optimal solution.

 
