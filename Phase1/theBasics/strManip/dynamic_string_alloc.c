#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16

char* read_dynamic_string();


int main(){

    char* input = read_dynamic_string();
    printf("%s", input);
    free(input);

    return 0;
}

char* read_dynamic_string(){
    size_t len = 0;
    size_t capacity = INITIAL_CAPACITY;

    char* buffer = malloc(capacity * sizeof(char));

    // TODO handle error if failed buffer allocation
    if (buffer == NULL){
        fprintf(stderr, "Error: failed to assign buffer");
        return NULL;
    }

    int c;

    while ((c = getchar()) != '\n' && c != EOF){
        // Growth logic
        if (len + 1 >= capacity){
            // DONE add string size overflow error
            size_t new_capacity = capacity * 2;

            if (new_capacity <= capacity){
                fprintf(stderr, "Error: String Size Overflow");
                return NULL;
            }

            char* new_buffer = realloc(buffer, new_capacity);
            // DONE add realloc faled error
            if (new_buffer == NULL){
                fprintf(stderr, "Error: falied to assign buffer" );
                return NULL;
            }

            buffer = new_buffer;
            capacity = new_capacity;
        }
        

        // assign buffer, increment loop variable
        buffer[len] = (char)c; // -> interpreting c as a char
        len ++;
    }

    buffer[len] = '\0';

    char* final_buffer = realloc(buffer, len +1);
    if (final_buffer == NULL){
        fprintf(stderr, "Warning: failed to shrink buffer");
        return buffer;
    }

    return final_buffer;


}