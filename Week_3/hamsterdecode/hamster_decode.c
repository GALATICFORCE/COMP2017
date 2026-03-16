#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODES (10)
#define MAX_STRING (512)

void decode(const char* data, int length) {
	//Main function to decode
	int split = 0;
	while (split < length && !isdigit(data[split])) split++;
		
		if (split > MAX_CODES) return;

		for (int i = split; i < length; i++)
		{
			int idx = data[i] - '0';
			if(idx >= split) return ;
			putchar(data[idx]);
		}
		putchar('\n');
	}


int main(void) {
	//Some test statements
	const char* hlo = "HELOWRD0122343526"; //HELLOWORLD
	const char* dib = "Dibd aou0121314254313143674367"; //Dibidi ba didi dou dou
	decode(hlo,strlen(hlo));
	decode(dib,strlen(dib));
	return 0;
}
