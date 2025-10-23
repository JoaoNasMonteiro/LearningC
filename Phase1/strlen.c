#include <stdio.h>

int string_legth(char* str);

int main() {
	char *str = "Hellow, orld";
	int size = string_legth(str);

	printf("The size of the string is %d characterrs long as per my implementantionb", size);
	return 0;
}

int string_legth(char* str){

	return (sizeof(str) / sizeof(char));
}