#define _CRT_SECURE_NO_WARNINGS
#include"complex.h"
//�ڶѴ洢������һ������
struct complex* complex_init()
{
	struct complex* comp = NULL;
	comp = (struct complex*)malloc(sizeof(struct complex));
	comp->preal = (float*)malloc(sizeof(float));
	comp->pimag = (float*)malloc(sizeof(float));
	return comp;
}

void complex_free(struct complex* comp) //�ڶѴ洢�����ո����Ĵ洢�ռ�
{
	free(comp->pimag);
	free(comp->preal);
	free(comp);
}

void complex_set_real(struct complex* comp, float value)//����һ��������ʵ��
{
	*(comp->preal) = value;
}

float complex_get_real(struct complex* comp)//���һ��������ʵ��
{
	return *(comp->preal);
}

void complex_set_imag(struct complex* comp, float value)//����һ���������鲿
{
	*(comp->pimag) = value;
}

float complex_get_imag(struct complex* comp)//���һ���������鲿
{
	return *(comp->pimag);
}

void complex_add(struct complex* comp1, struct complex* comp2)//�ӷ������ͨ����һ����������
{
	*(comp1->preal) += *(comp2->preal);
	*(comp1->pimag) += *(comp2->pimag);
}

void complex_sub(struct complex* comp1, struct complex* comp2)//����
{
	*(comp1->preal) -= *(comp2->preal);
	*(comp1->pimag) -= *(comp2->pimag);
}

void complex_mul(struct complex* comp1, struct complex* comp2)//�˷�
{
	float z1 = *(comp1->preal);
	*(comp1->preal) = *(comp1->preal) * *(comp2->preal) - *(comp1->pimag) * *(comp2->pimag);
	*(comp1->pimag) = z1 * *(comp2->pimag) + *(comp1->pimag) * *(comp2->preal);
}

void complex_div(struct complex* comp1, struct complex* comp2)//����
{
	float z1 = *(comp1->preal);
	*(comp1->preal) = (*(comp1->preal) * *(comp2->preal) + *(comp1->pimag) * *(comp2->pimag))/
		(*(comp2->preal) * *(comp2->preal) + *(comp2->pimag) * *(comp2->pimag));
	*(comp1->pimag) = (*(comp1->pimag) * *(comp2->preal) - z1 * *(comp2->pimag))/
		(*(comp2->preal) * *(comp2->preal) + *(comp2->pimag) * *(comp2->pimag));
}
