#include <stdio.h>

#define IN_A_WORD 1
#define OUT_A_WORD 0

int main() {
	int currentCharacter, characterCount, wordCount, lineCount, state;

	state = OUT_A_WORD;
	characterCount = wordCount = lineCount = 0;

	while ((currentCharacter = getchar()) != EOF) {
		++characterCount;
		
		if (currentCharacter == '\n') {
			++lineCount;
		}

		if (
			currentCharacter == '\n' ||
			currentCharacter == '\t' ||
			currentCharacter == ' '
		) {
			state = OUT_A_WORD;
		} 
		else if (state == OUT_A_WORD) {
			state = IN_A_WORD;
			++wordCount;
		}
	}

	printf("%dc, %dw, %dl", characterCount, wordCount, lineCount);
}

