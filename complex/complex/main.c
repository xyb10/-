#define _CRT_SECURE_NO_WARNINGS
#include"complex.h"

int main()
{
	struct complex* comp1, * comp2;
	comp1 = complex_init();
	complex_set_real(comp1, 1.32);
	complex_set_imag(comp1, 3.71);
	comp2 = complex_init();
	complex_set_real(comp2, 3.63);
	complex_set_imag(comp2, -1.54);

	complex_add(comp1, comp2);
	printf("%0.2f+%0.2fi\n", *(comp1->preal), *(comp1->pimag));

	complex_sub(comp1, comp2);
	printf("%0.2f+%0.2fi\n", *(comp1->preal), *(comp1->pimag));

	complex_mul(comp1, comp2);
	printf("%0.2f+%0.2fi\n", *(comp1->preal), *(comp1->pimag));

	complex_div(comp1, comp2);
	printf("%0.2f+%0.2fi\n", *(comp1->preal), *(comp1->pimag));
	return 0;
}