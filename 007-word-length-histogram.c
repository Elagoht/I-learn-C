#include <stdio.h>

#define MAX_LENGTH 20

int main() {
	int character, currentLength;
	int histogram[MAX_LENGTH + 1] = {0};

	currentLength = 0;

	while ((character = getchar()) != EOF) {
		if (
			character != '\n' &&
			character != '\t' &&
			character != ' '
		) {
			++currentLength;
			continue;
		}
		if (currentLength > 0) {
			int index = 0;

			if (currentLength > MAX_LENGTH) {
				index = MAX_LENGTH + 1;
			} else {
				index = currentLength;
			}
			++histogram[index];
		}
		currentLength = 0;
	}

	for (int index = 0; index <= MAX_LENGTH + 1; ++index) {
		if (histogram[index] == 0) {
			continue;
		}

		printf("%2d: ", index);

		for (int line = 0; line < histogram[index]; ++line) {
			 printf("🬋");
		}

		printf("\n");
	}
}
