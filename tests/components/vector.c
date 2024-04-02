#include <assert.h>

#include "libgrll.h"

void test_vector(void) {
	vec v = vec_new(0, 5, sizeof(int));
	for (size_t i = 0; i < 11; ++i) {
		vec_push(v, i, int);
		assert(vec_len(v) == i + 1);
		assert(vec_i(v, i, int) == (int)i);
		assert(vec_i(v, vec_len(v) - 1, int) == (int)i);
	}

	vec u = vec_copy(v);
	vec_delete(v);
	for (; vec_len(u); vec_pop(u)) {
		assert(vec_top(u, int) == (int)vec_len(u) - 1);
	}
	vec_delete(u);
}
