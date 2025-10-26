#include <stdio.h>
#include <string.h>

// 0000. 1000 -> execute perm. 0100 -> write perm. -> 0010 -> read perm. 0001 -> append perm

void getBitRepresentation(unsigned char n, char* buffer);
void setPerm(unsigned char *flag, char* mode);

int main(){

    unsigned char flag = 0;
    char* mode = "arw";
    char binbuf[9];

    getBitRepresentation(flag, binbuf);
    printf("%s, n: %d \n", binbuf, (int)flag);
    setPerm(&flag, mode);
    getBitRepresentation(flag, binbuf);
    printf("%s, n: %d \n", binbuf, (int)flag);

    return 0;
}

void setPerm(unsigned char *flag, char* mode){

    //loop over the mode string, set flags based on the mode 
    for (int i = 0; i < strlen(mode); i++){
        switch (mode[i]){
            //set append perm
            case 'a':
                *flag |= 1;
                break;
            //set read perm
            case 'r':
                *flag |= 1 << 1;
                break;
            //set write perm
            case 'w':
                *flag |= 1 << 2;
                break;
            //set execute perm
            case 'x':
                *flag |= 14;
                break;
            default:
                printf("Error: no valid mode operator found");
        }
    }

}

void getBitRepresentation(unsigned char n, char* buffer){

    for (int i = 0; i < 8; i++){
        unsigned char bit = (n >> (7-i)) & 1;
        buffer[i] = bit + '0'; 
    }

    buffer[8] = '\0';


}






