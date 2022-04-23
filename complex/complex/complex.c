#define _CRT_SECURE_NO_WARNINGS
#include"complex.h"
//在堆存储区创建一个复数
struct complex* complex_init()
{
	struct complex* comp = NULL;
	comp = (struct complex*)malloc(sizeof(struct complex));
	comp->preal = (float*)malloc(sizeof(float));
	comp->pimag = (float*)malloc(sizeof(float));
	return comp;
}

void complex_free(struct complex* comp) //在堆存储区回收复数的存储空间
{
	free(comp->pimag);
	free(comp->preal);
	free(comp);
}

void complex_set_real(struct complex* comp, float value)//设置一个复数的实部
{
	*(comp->preal) = value;
}

float complex_get_real(struct complex* comp)//获得一个复数的实部
{
	return *(comp->preal);
}

void complex_set_imag(struct complex* comp, float value)//设置一个复数的虚部
{
	*(comp->pimag) = value;
}

float complex_get_imag(struct complex* comp)//获得一个复数的虚部
{
	return *(comp->pimag);
}

void complex_add(struct complex* comp1, struct complex* comp2)//加法，结果通过第一个参数返回
{
	*(comp1->preal) += *(comp2->preal);
	*(comp1->pimag) += *(comp2->pimag);
}

void complex_sub(struct complex* comp1, struct complex* comp2)//减法
{
	*(comp1->preal) -= *(comp2->preal);
	*(comp1->pimag) -= *(comp2->pimag);
}

void complex_mul(struct complex* comp1, struct complex* comp2)//乘法
{
	float z1 = *(comp1->preal);
	*(comp1->preal) = *(comp1->preal) * *(comp2->preal) - *(comp1->pimag) * *(comp2->pimag);
	*(comp1->pimag) = z1 * *(comp2->pimag) + *(comp1->pimag) * *(comp2->preal);
}

void complex_div(struct complex* comp1, struct complex* comp2)//除法
{
	float z1 = *(comp1->preal);
	*(comp1->preal) = (*(comp1->preal) * *(comp2->preal) + *(comp1->pimag) * *(comp2->pimag))/
		(*(comp2->preal) * *(comp2->preal) + *(comp2->pimag) * *(comp2->pimag));
	*(comp1->pimag) = (*(comp1->pimag) * *(comp2->preal) - z1 * *(comp2->pimag))/
		(*(comp2->preal) * *(comp2->preal) + *(comp2->pimag) * *(comp2->pimag));
}
