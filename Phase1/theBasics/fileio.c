#include <stdio.h>

void write_file(char* text);
void read_file(char* text);

int main(){
    char* text = "Hellow,\nworld";
    char* file_write = "fileio_readfile.txt";
    write_file(text);
    read_file(file_write);
    return 0;
}


void write_file(char* text){

     //write to a file (will create if does not exist)
    FILE *pFile = fopen("fileio_output.txt", "w"); //-> can be "r" to read, "w" to write, "a" to append or "r+" to read and write (more options exist)
    // always good to check if the file has been open successfully
    if (pFile == NULL){
        printf("Error: failed to open file");
        return 1;
    }
    fprintf(pFile, "%s", text);
    printf("File written successfully\n");

    //must remember to close the file 
    fclose(pFile);
    
    return 0;
}


void read_file(char* src){


    FILE* pFile = fopen(src, "r");
    if (pFile == NULL){
        printf("Error: failed to open file");
        return 1;
    }

    char buffer[1024] = {0};
    
    while (fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);

    }
    printf("File read successfully");
    fclose(pFile);

    return 0;
}
