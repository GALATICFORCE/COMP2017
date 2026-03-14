#include <stdio.h>

void reverse(int array[], unsigned int length) {
	// TODO
	for (unsigned int i = 0; i < length/2; i++)
	{
		int temp = array[i];
		array[i] = array[length - 1 - i];
		array[length - 1 - i] = temp;
	}
}

int main() {
	unsigned int length = 0;
	scanf("%u", &length);
	int array[length];
	int temp = -1;
	for(int i = 0; i < length; i++) {
		scanf("%d", &temp);
		array[i] = temp;
	}
	reverse(array, length);
	for(int i = 0; i < length; i++) {
		printf("%d\n", array[i]);
	}

	return 0;
}

