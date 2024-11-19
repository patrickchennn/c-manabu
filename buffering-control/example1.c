#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "w");
    setvbuf(file, NULL, _IOFBF, BUFSIZ); // Full buffering with default size

    // Writing data in a loop
    for (int i = 0; i < 1000; i++) {
        fprintf(file, "Line %d\n", i);
    }

    fclose(file);
    return 0;
}
