#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy_string(char *source, char *dest);

int main(){
	char *m = "XXX";
	char *n = "AAA";

	printf("%s is the string before copying\n", n);

	copy_string(m, n);

	printf("%s is the string after copying\n", n);
	return 0;
}

char *copy_string(char *source, char *dest){
	char *dest = malloc(sizeof(source));

	int size = sizeof(dest) / sizeof(char);

	for (int i = 0; i < size; i++){
		dest[i] = source[i];
	}

	return dest;

}

