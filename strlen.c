#include <stdio.h>
// #include <stdlib.h>

int main() {
	char str[20] = "";

	scanf("%s", str);


	// Figure out size of the string from the size of the characters
	int size = sizeof(str) / sizeof(char);
	printf("The size of the string is %d characterrs long as per my implementantion", size);
	return 0;
}

