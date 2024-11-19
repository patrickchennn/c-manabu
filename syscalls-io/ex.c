#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char *filename = "example.txt";
    const char *dataToWrite = "This is an example of read and write operations in C.\n";
    char buffer[256];
    
    // Step 1: Create and open the file for writing
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to create/open file for writing");
        return 1;
    }
    
    // Step 2: Write data to the file
    ssize_t bytesWritten = write(fd, dataToWrite, strlen(dataToWrite));
    if (bytesWritten == -1) {
        perror("Failed to write to the file");
        close(fd); // Close the file even if there's an error
        return 1;
    }
    printf("Wrote %zd bytes to the file: %s\n", bytesWritten, filename);

    // Step 3: Close the file after writing
    if (close(fd) == -1) {
        perror("Failed to close the file after writing");
        return 1;
    }
    
    // Step 4: Re-open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file for reading");
        return 1;
    }

    // Step 5: Read the data back from the file
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1); // Leave space for null terminator
    if (bytesRead == -1) {
        perror("Failed to read from the file");
        close(fd); // Close the file even if there's an error
        return 1;
    }
    
    buffer[bytesRead] = '\0';  // Null-terminate the buffer
    printf("Read %zd bytes from the file:\n%s\n", bytesRead, buffer);

    // Step 6: Close the file after reading
    if (close(fd) == -1) {
        perror("Failed to close the file after reading");
        return 1;
    }

    return 0;
}
