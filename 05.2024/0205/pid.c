/*
pid == 0 occurs in two scenarios.
	1. when a process is created using the fork system call
		the child process receives a PID of 0(return value of fork parent process).
		the child process is an exact copy of the parent process but it has its own PID.
	2. the swapper or sched process
init process is responsible for starting and shutting down the system, and it has a PPID of 0,
indicatign that it has no parent process.
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process, with PID: %d\n", getpid());
    } else {
        // Parent process
        printf("This is the parent process, with PID: %d\n", getpid());
    }

    return 0;
}

/*
can use the wait or waitpid system calls in the parent process.
these will pause the parent proess until the child process has terminated, ensuting that 
the child's output is printed before the parent's.


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process, with PID: %d\n", getpid());
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to complete
        printf("This is the parent process, with PID: %d\n", getpid());
    }

    return 0;
}



-1	error
0	parent process success -> pass return value of 0 to child process.
>0	getpid() positive int 
*/

