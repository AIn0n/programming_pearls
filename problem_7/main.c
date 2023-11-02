#include <stdio.h>
#include <stdlib.h>
#include "bit_vector.h" /* file from  problem_2 */

#define MAX 10
#define VEC_SIZE 1

int
main (void)
{
	FILE* f = fopen("output.txt", "r");
	if (f == NULL)
		return 1;

	uint64_t bit_vector[VEC_SIZE] = {0};

	for (uint64_t i = 1;; ++i) {
		uint64_t n;
		const int err = fscanf(f, "%llu", &n);
		if (err == EOF)
			break;
		if (err != 1) {
			printf("incorrect data in line %llu\n", i);
			fclose(f);
			return 1;
		}
		/* handler for repetition of number */
		if (get_bit(bit_vector, VEC_SIZE, n, NULL)) {
			printf("error: number = %llu was twice in file\n", n);
			fclose(f);
			return 1;
		}

		set_bit(bit_vector, VEC_SIZE, n);
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