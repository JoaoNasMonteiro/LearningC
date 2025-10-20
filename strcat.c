#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_string(char * str1, char* str2);

int main(){
	char * m = "Hello,";
	char * n = " World";
	char * out = concat_string(m, n);
	printf("%s\n", out);
	free(out);
	return 0;
}

char *concat_string(char * str1, char* str2){
	// Get size of strings 1 and 2 -> allocate output string with size of 1 + 2 -> loop over one by one of the members of 1 and 2 and write to out
	int size_str1 = strlen(str1) / sizeof(char);
	int size_str2 = strlen(str2) / sizeof(char);
	int size_out = size_str1 + size_str2;

	char *out_str = malloc(size_out * sizeof(char));

	for (int i = 0; i < size_str1; i ++){
		*(out_str + i) = *(str1 + i);
	}
	for (int i = 0; i < size_str2; i ++){
		*(out_str + (i + size_str1)) = *(str2 + i);
	}
	return(out_str);
}