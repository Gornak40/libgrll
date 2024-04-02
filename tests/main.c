#include <assert.h>
#include <string.h>

#define STR_(s) #s
#define STR(s) STR_(s)

int tests_passed = 0;

#define ADD_TEST(s, comp)            \
	void test_##comp(void);          \
	if (strcmp(s, STR(comp)) == 0) { \
		test_##comp();               \
		++tests_passed;              \
	}

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		const char* s = argv[i];
		ADD_TEST(s, vector)
	}
	assert(tests_passed == argc - 1);
}
