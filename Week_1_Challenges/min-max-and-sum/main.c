#include <stdio.h>
#include <limits.h>

int sum(int array[], unsigned int length) {
	int total = 0;
	for(unsigned int i = 0; i < length; i++){
		total += array[i];
	}
	return total;
}

int max(int array[], unsigned int length) {
	int max_num = array[0];
	for(unsigned int i = 0; i < length; i++){
		if (array[i] > max_num) max_num = array[i];
	}
	return max_num;
}

int min(int array[], unsigned int length) {
	int min_num = array[0];
	for(unsigned int i =1; i < length; i++){
		if (array[i] < min_num) min_num = array[i];
	}
	return min_num;
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

	printf("SUM: %d\n", sum(array, length));
	printf("MAX: %d\n", max(array, length));
	printf("MIN: %d\n", min(array, length));

	return 0;
}

