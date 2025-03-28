#include <stdio.h>

int main() {
	for (float fahrenheit = 300; fahrenheit >= 0; fahrenheit -= 20) {
		printf("%3.0f fahrenheit = %5.1f celsius\n", fahrenheit, 5.0 / 9.0 * (fahrenheit - 32.0));
	}
}
