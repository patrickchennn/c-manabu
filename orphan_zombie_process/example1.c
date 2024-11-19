#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void createOrphanProcess() {
    pid_t pid = fork();  // Fork a child process

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) is terminating, creating an orphan.\n", getpid());
        // Parent process exits
        exit(0);
    } else if (pid == 0) {
        // Child process
        sleep(5);  // Sleep for some time to ensure the parent terminates first
        printf("Orphan process (PID: %d) adopted by init process. Parent PID: %d\n", getpid(), getppid());
        // Child process continues to run independently
        while (1) {
            sleep(1);  // Keeps running to demonstrate orphan status
        }
    } else {
        // Fork failed
        perror("fork failed");
    }
}

void createZombieProcess() {
    pid_t pid = fork();  // Fork a child process

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) is sleeping. Child process will become a zombie.\n", getpid());
        sleep(10);  // Sleep for some time to let the child process terminate first
        wait(NULL); // Reap the zombie child
        printf("Zombie process has been cleaned up by parent.\n");
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is terminating, becoming a zombie.\n", getpid());
        // Child process exits immediately
        exit(0);
    } else {
        // Fork failed
        perror("fork failed");
    }
}

int main() {
    printf("Demonstrating orphan process:\n");
    createOrphanProcess();
    sleep(10);  // Wait for the orphan process to run

    printf("\nDemonstrating zombie process:\n");
    createZombieProcess();
    return 0;
}

/*
### Explanation

1. **Orphan Process:**
   - The `createOrphanProcess()` function demonstrates how an orphan process is created.
   - The parent process forks a child process using `fork()`.
   - The parent process exits immediately using `exit(0)`, leaving the child process running.
   - The child process is now orphaned and will be adopted by the `init` process (PID 1). After sleeping for 5 seconds, it prints that it has been adopted by the `init` process and continues to run in an infinite loop.

2. **Zombie Process:**
   - The `createZombieProcess()` function demonstrates how a zombie process is created.
   - The parent process forks a child process using `fork()`.
   - The child process exits immediately using `exit(0)`, but the parent process does not call `wait()` immediately.
   - The parent process sleeps for 10 seconds, during which the child process becomes a zombie because its termination status is not yet read by the parent.
   - After the sleep, the parent process calls `wait(NULL)` to reap the zombie child process, and the zombie is cleaned up.

### Compilation and Execution

To compile and run this code on a Unix-like system (e.g., Linux), follow these steps:

```bash
gcc -o orphan_zombie orphan_zombie.c
./orphan_zombie
```

You will see output indicating when the orphan and zombie processes are created and handled. You can also use commands like `ps aux` or `top` to observe these processes in action on your system.

### Note
Be careful when running this code, as it creates processes that run indefinitely. You might need to terminate them manually using `kill` or `Ctrl+C` if needed.
*/