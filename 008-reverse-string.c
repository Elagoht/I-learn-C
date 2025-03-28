#include <stdio.h>

#define BUFFER_SIZE 256

int stringLength(char string[]) {
	int index = 0;
	while (string[index] != '\0') {
		++index;
	}
	return index;
}

void reverse(char input[]) {
	int length = stringLength(input);
	int start, end;

	start = 0; 
	end = length - 1;

	while (start < end) {
		// Swap chars
		char temp = input[start];
		input[start] = input[end];
		input[end] = temp;

		start++;
		end--;
	}
}

int main() {
	char input[BUFFER_SIZE];
	int currentChar;
	int index = 0;

	while (
		(currentChar = getchar()) != EOF &&
		index < BUFFER_SIZE - 2
	) {
		input[index] = (char) currentChar; 
		++index;
	}

	reverse(input);

	printf("%s\n", input);

	return 0;
}

