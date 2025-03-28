#include <stdio.h>

#define BUFFER_SIZE 100

void copy(char source[], char destination[]) {
	int index = 0;

	while(source[index] != '\0') {
		destination[index] = source[index];
		++index;
	}
}

char isWhiteSpace(char input) {
	return (
		input == ' ' ||
		input == '\n' ||
		input == '\t'
	);
}

int main() {
	int character, index, longest;
	char word[BUFFER_SIZE];
	char longestWord[BUFFER_SIZE];

	index = longest = 0;

	while((character = getchar()) != EOF) {
		if (!isWhiteSpace(character)) {
			++index;
			word[index] = character;
			continue;
		}
		if (index > longest) {
			copy(word, longestWord);
			longest = index;
		}
		index = 0;
	}

	printf("%s\n", longestWord);
}
