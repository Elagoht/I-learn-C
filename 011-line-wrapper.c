#include <stdio.h>

#define MAX_LINE_LENGTH 80

int lineLength = 0;
int charOfWord = 0;
int character;
char currentWord[MAX_LINE_LENGTH];

void clearCurrentWord(void);
int isWhiteSpace(char);

int main() {
	while ((character = getchar()) != EOF) {
		if (isWhiteSpace(character)) {
			if (lineLength + charOfWord > MAX_LINE_LENGTH) {
				printf("\n");
				lineLength = 0;
			}
			
			printf("%s", currentWord);
			lineLength += charOfWord;
			clearCurrentWord();
			
			if (character == '\n') {
				printf("\n");
				lineLength = 0;
			} else {
				printf("%c", character);
				lineLength++;
			}
		} else {
			if (charOfWord < MAX_LINE_LENGTH - 1) {
				currentWord[charOfWord] = character;
				++charOfWord;
			}
		}
	}

	if (charOfWord > 0) {
		if (lineLength + charOfWord > MAX_LINE_LENGTH) {
			printf("\n");
		}
		printf("%s", currentWord);
	}
	printf("\n");

	return 0;
}

int isWhiteSpace(char character) {
	return (
		character == '\n' ||
		character == '\t' ||
		character == ' '
	);
}

void clearCurrentWord(void) {
	for (int i = charOfWord; i >= 0; --i) {
		currentWord[i] = '\0';
	}
	charOfWord = 0;
}

