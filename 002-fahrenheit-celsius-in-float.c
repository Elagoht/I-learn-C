#include <stdio.h>

int main() {
	float fahrenheit, celsius;
	float lower, upper, step;

	lower = 0.0;
	upper = 300.0;
	step = 20.0;

	fahrenheit = lower;

	while (fahrenheit <= upper) {
		celsius = 5.0 / 9.0 * (fahrenheit - 32.0);
		printf("%3.0f fahrenheit = %5.1f celsius\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + step;
	}
}
