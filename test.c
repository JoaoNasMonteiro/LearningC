#include <stdio.h>
#include <stdlib.h> // Required for malloc, realloc, and free
#include <string.h>

/**
 * @brief Reads a line of arbitrary size from standard input (stdin).
 *
 * This function dynamically allocates memory to hold a string of any length,
 * resizing the buffer as needed. The caller is responsible for freeing the
 * memory allocated for the returned string.
 *
 * @return A pointer to the dynamically allocated string, or NULL if memory
 * allocation fails or no characters were read.
 */
char *get_arbitrary_string() {
    // 1. Start with an initial capacity. A small number is fine.
    int capacity = 10;
    int size = 0;

    // Allocate the initial buffer.
    char *buffer = malloc(capacity * sizeof(char));
    if (buffer == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory");
        return NULL;
    }

    int c; // Use an int to properly handle EOF

    // 2. Loop to read characters one by one.
    while ((c = getchar()) != '\n' && c != EOF) {
        // 3. Check if we have run out of space.
        if (size >= capacity - 1) { // -1 to save space for the null terminator
            // Double the capacity
            capacity *= 2;
            
            // Try to reallocate the buffer to the new, larger size.
            char *temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL) {
                // Handle reallocation failure. The original buffer is still valid.
                perror("Failed to reallocate memory");
                free(buffer); // Free the original memory before returning
                return NULL;
            }
            // Point our buffer to the new, larger memory block.
            buffer = temp;
        }

        // Store the character and increment the size.
        buffer[size++] = (char)c;
    }

    // 4. Add the null terminator to make it a valid C string.
    buffer[size] = '\0';

    // If EOF was the first thing we read, the string is empty.
    if (size == 0 && c == EOF) {
        free(buffer);
        return NULL; // No input, return NULL
    }

    return buffer;
}

int main() {
    printf("Please enter a long string and press Enter:\n");

    // Call our function to get the string
    char *input_string = get_arbitrary_string();

    // Always check if the pointer is not NULL before using it.
    if (input_string != NULL) {
        printf("\n--- You entered ---\n");
        printf("%s\n", input_string);
        printf("String length: %zu\n", (size_t)strlen(input_string)); // Requires #include <string.h>

        // 5. IMPORTANT: Free the memory that was allocated by the function.
        // The caller is always responsible for freeing memory.
        free(input_string);
    } else {
        printf("No input was read or an error occurred.\n");
    }

    return 0;
}