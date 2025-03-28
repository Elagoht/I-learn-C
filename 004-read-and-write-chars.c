#include <stdio.h>

int main() {
	int character;

	while ((character = getchar()) != EOF) {
		putchar(character);
	}
}

/* 
 * Try running:
 *
 * ```bash:
 * echo "Hello World \!" | ./a.out"
 */
