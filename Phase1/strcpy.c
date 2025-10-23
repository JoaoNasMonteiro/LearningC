#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_string(char *source, char **dest);

int main(){
	char *src = "XXX";
	char *dst = ""; 

	dst = malloc(strlen(src) + 1);
	if (dst == NULL){
		printf("Falha ao alocar memória");
		return 1;
	}

	printf("%s is the string before copying\n", dst);

	copy_string(src, &dst);

	printf("%s is the string after copying\n", dst);

	free(dst);
	return 0;
}

void copy_string(char *source, char **dest){

	int len = strlen(source);

	*dest = malloc(len + 1);
	
	if (*dest == NULL){
		printf("Falha ao alocar memória");
		return 1;
	}

	for (int i = 0; i < len; i++){
		*(*dest + i) = *(source + i);
	}

	*(*dest + len) = '\0';

	return;
}

