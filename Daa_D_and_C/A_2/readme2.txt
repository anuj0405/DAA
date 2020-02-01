1:Using time() function in C & C++.
time() : time() function returns the time since the Epoch(jan 1 1970) in seconds.
Header File : “time.h”
Prototype / Syntax : time_t time(time_t *tloc);
Return Value : On success, the value of time in seconds since the Epoch is returned, on error -1 is returned.


2: Using clock() function in C & C++.
clock() : clock() returns the number of clock ticks elapsed since the program was launched.
Header File : “time.h”
Prototype / Syntax : clock_t clock(void);
Return Value : On success, the value returned is the CPU time used so far as a clock_t; To get the number of seconds used, divide by CLOCKS_PER_SEC.on error -1 is returned.


3: using gettimeofday() function in C & C++.
gettimeofday() : The function gettimeofday() can get the time as well as timezone.
Header File : “sys/time.h”.
Prototype / Syntax : int gettimeofday(struct timeval *tv, struct timezone *tz);
The tv argument is a struct timeval and gives the number of seconds and micro seconds since the
Epoch.
struct timeval {
time_t tv_sec; // seconds
suseconds_t tv_usec; // microseconds
};
Return Value : return 0 for success, or -1 for failure.

4: Using clock_gettime() function in C & C++.
clock_gettime() : The clock_gettime() function gets the current time of the clock specified by clock_id, and puts it into the buffer pointed to by tp.
Header File : “time.h”.
Prototype / Syntax : int clock_gettime( clockid_t clock_id, struct timespec *tp );
tp parameter points to a structure containing atleast the following members :

struct timespec {
time_t tv_sec; //seconds
long tv_nsec; //nanoseconds
};

Return Value : return 0 for success, or -1 for failure.
clock_id : clock id = CLOCK_REALTIME,
CLOCK_PROCESS_CPUTIME_ID, CLOCK_MONOTONIC … etc.
CLOCK_REALTIME : clock that measures real i.e., wall-clock) time.
CLOCK_PROCESS_CPUTIME_ID : High-resolution per-process timer from the CPU.
CLOCK_MONOTONIC : High resolution timer that is unaffected by system date changes (e.g. NTP daemons).

5:Using chrono::high_resolution_clock in C++.
chrono : Chrono library is used to deal with date and time. This library was designed to deal with the fact that timers and clocks might be different on different systems and thus to improve over time in terms of precision.chrono is the name of a header, but also of a sub-namespace, All the elements in this header are not defined directly under the std namespace (like most of the standard library) but under the std::chrono namespace.


6:time command in Linux is used to execute a command and prints a summary of real-time, user CPU time and system CPU time spent by executing a command when it terminates. ‘real‘ time is the time elapsed wall clock time taken by a command to get executed, while ‘user‘ and ‘sys‘ time are the number of CPU seconds that command uses in user and kernel mode respectively.

Synatx:

time [option] [COMMAND]
