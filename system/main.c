#include <stdlib.h>

int main() {
    int status;

    // Execute the 'ls -l' command
    status = system("ls -l");

    // Check if the command was executed successfully
    if (status == -1) {
        // Error occurred
        perror("system");
    } else {
        // Command executed successfully
        printf("Command executed, exit status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
