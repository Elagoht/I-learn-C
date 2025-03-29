/*
 * This program is written to remove
 * all comments on a C program and make
 * it harder to work on for your team
 * mates.
 */
#include <stdio.h>

// Create an enum to determine current and previous
// state of the stream of source code.
enum State {
	Source,
	Comment,
	MultiLineComment,
};

enum State state, prevState;
int current, previous;
int buffer;

void setCharacters(char);
void setState();
void printCharacters(char);


int main() {
	int character;

	state = prevState = Source;

	while((character = getchar()) != EOF) {
		setCharacters(character);
		setState();
		printCharacters(character);
	}
}

void setCharacters(char new) {
	previous = current;
	current = new;
}

void printCharacters(char character) {
	if (state == Comment || state == MultiLineComment) {
		return;
	}

	if (character == '/') {
		if (prevState == Source && state == Source) {
			buffer = '\0';
		} else if (prevState == Source && state != Source) {
			buffer = '/';
		}
		if (buffer != '\0') {
			putchar(buffer);
		}
	} else {
		putchar(character);
	}
}

void setState(void) {
	prevState = state;
	switch (state) {
		case Source:
			if (previous == '/' && current == '*') {
				state = MultiLineComment;
			}
			else if (previous == '/' && current == '/') {
				state = Comment;
			}
			break;
		case Comment:
			if (current == '\n') state = Source;
			break;
		case MultiLineComment:
			if (previous == '*' && current == '/') {
				state = Source;
			}
			break;
	}
}
