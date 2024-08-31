#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char *s1 = argv[1]; // Correct: s1 is now a pointer to the string

        printf("s1=%s\n", s1); // Correct: Using %s to print a string
    } else {
        printf("No command-line argument provided.\n");
    }
    return 0;
}
