#include <stdio.h>
#include <stdlib.h>
#include "bit_vector.h"

#define MAX 10
#define VEC_SIZE 1

int
main (void)
{
	FILE* f = fopen("output.txt", "r");
	if (f == NULL) {
		return 1;
	}

	uint64_t bit_vector[VEC_SIZE] = {0};

	while(1) {
		uint64_t a;
		if (fscanf(f, "%llu", &a) == EOF)
			break;
		set_bit(bit_vector, VEC_SIZE, a);
	}

	fclose(f);

	if ((f = fopen("sorted_output.txt", "w")) == NULL)
		return 1;

	for (int i = 0; i < MAX; ++i) {
		if (get_bit(bit_vector, VEC_SIZE, i, NULL)) {
			fprintf(f, "%i\n", i);
		}
	}

	fclose(f);
	return 0;
}