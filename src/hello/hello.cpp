#include <iostream>
#include <stdio.h>

int main(int argc, char** argv) {

	int* chars = new int[20];

	chars[0] = 72;
	chars[1] = 101;
	chars[2] = 108;
	chars[3] = 0;

	for (int i = 0; i < sizeof(chars) && chars[i]; i++) {
		int c = chars[i];
		printf("%c", (char)c);
	}

	printf("lo World!\n");

	return 0;
}
