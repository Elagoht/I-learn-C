#include <stdio.h>

int main() {
	int character;

	while ((character = getchar()) != EOF) {
		if (
			character == ' ' ||
			character == '\t'
		) {
			printf("\n");
		} else {
			printf("%c", character);
		}
	}
}

