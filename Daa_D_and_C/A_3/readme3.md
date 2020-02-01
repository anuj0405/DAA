#problem statement:
compare your solution with the program
microresolutiontimer.c uploaded on the LMS. Give a critique of your comparison.

# comparision:

In 2nd Assignment we have Defined many timer which we can use in our programs in them we have selected 2 timer which we have used for our 
program which are insertion and merge sort 
1. In first timer we Use gettimeoftheday() fuction and struct timeval {start, end};
   to get the start time our program we use
			Prototype / Syntax : int gettimeofday(struct timeval *tv, struct timezone *tz);
			The tv argument is a struct timeval and gives the number of seconds and micro seconds since the Epoch.
			struct timeval {
					time_t tv_sec; // seconds
					suseconds_t tv_usec; // microseconds
					};
 
			gettimeofday(&start,NULL); //to get the start time where function started
			Function();
			gettimeofday(&end,NULL); //to get the End time were our fuction ended

and to get time of our function we find Difference between them and to find the difference we use 
			
			t= (end.tv_sec - start.tv_sec)*1e6; //First we subtract the seconds of our program and convert them in microseconds 
			t= (t + (end.tv_usec - start.tv_usec)) *1e-6;//In this we find the difference b/w Microsecond and add above "t" which 										we have find in it and then convert whole expression in seconds. 
			print(t)  //print the time in seconds with setprecision(6) 
	
2. 2nd timer which we have used is chrono which is available in c++ int this we use high_resolution_clock() function to find the start time 
   and end time of our programe and then we find the diffrence between end and start time in microseconds.
			auto start = high_resolution_clock::now(); //To get the start time of our function 
			auto stop = high_resolution_clock::now(); //to get the end time of our function
			auto duration = duration_cast<microseconds>(stop - start);//To get the running time of our program in microseconds
  
  Chrono library is used to deal with date and time. This library was designed to deal with the fact that timers and clocks might be
  different on different systems and thus to improve over time in terms of precision.chrono is the name of a header, but also of a 
  subnamespace, All the elements in this header are not defined directly under the std namespace (like most of the standard library) but 
  under the std::chrono namespace.

  In chrono we baicaly use three concept:
  1. Duration:A duration object expresses a time span by means of a count like a minute, two hours, or ten milliseconds. For example, “42 
	      seconds” could be represented by a duration consisting of 42 ticks of a 1-second time unit

  2. Clock:A clock consists of a starting point (or epoch) and a tick rate. For example, a clock may have an epoch of February 22, 1996 and 
	   tick every second. C++ defines three clock types:
  
     system_clock-It is the current time according to the system (regular clock which we see on the toolbar of the computer). It is written 
	          as std::chrono::system_clock

     steady_clock-It is a monotonic clock that will never be adjusted.It goes at a uniform rate. It is written as- std::chrono::steady_clock

     high_resolution_clock– It provides the smallest possible tick period. It is written as-std::chrono::high_resolution_clock 

  3. Timepoint:A time_point object expresses a point in time relative to a clock’s epoch. Internally, the object stores an object of a
       	       duration type, and uses the Clock type as a reference for its epoch

				Timeval							Chrono 				
   1.	In timeval we use two time which are seconds			 	In chrono we use three different time which are seconds,
	and microseconds.							microseconds and nanoseconds.
   
   2.   In this we calculate the time in seconds and 				Chrono provide precision-neutral concept by separating 
	microsecons since the Epoch for this we use tv				duration and point of time (“timepoint”) from specific clocks.
	argument.

   3.   Timeval is available in c and c++ both.					Chrono can only be used in c++ not in c.
 

#conclusion:
   After comparing Timeval and chrono in all sorting algorithm which we have implimented we can say that chrono gives us more 
   accurate time than TimeVal becouse it deals with different time concept than Timeval also we chrono is upgrade for Timeval 
   Timeval is not that reliable it some time gives time in negative if directly subtract Microseconds so to avoid it we first
   subtract seconds then we convert seconds into microseconds then we subtract microseconds and we add converted seconds into 
   difference of microseconds then we show time then our will be almost same as chrono. 
   microseconds 
    	







