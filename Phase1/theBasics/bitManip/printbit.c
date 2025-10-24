#include <stdio.h>
#include <stdint.h>

// a function that takes in an int and returns he binary representation in a string.
void getBitRepresentation(uint8_t n, char* buffer);

int main(){
    uint8_t number = 232;
    printf("%u\n", number);
    char binstr[9];
    getBitRepresentation(number, binstr);
    printf("%s", binstr);


    return 0;
}

void getBitRepresentation(uint8_t n, char* buffer){
    buffer[8] = '\0';

    // Alternativa com aritmética comum
    // for(int i = 0; i < 7; i++){
    //     buffer[i] = (n % 2) + '0';
    //     n = n/2;
    // }

    //laternativa com manipulação de bits

    for (int i = 0; i < 7; i++){
        uint8_t bit = (n >> (7-i)) & 1;
        buffer[i] = bit + '0'; 
    }


}