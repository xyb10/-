#pragma once
#include<stdio.h>
#include<stdlib.h>

struct complex {
	float* preal;
	float* pimag;
};

struct complex* complex_init();//�ڶѴ洢������һ������

void complex_free(struct complex* comp);//�ڶѴ洢�����ո����Ĵ洢�ռ�

void complex_set_real(struct complex* comp, float value);//����һ��������ʵ��

float complex_get_real(struct complex* comp);//���һ��������ʵ��

void complex_set_imag(struct complex* comp, float value);//����һ���������鲿

float complex_get_imag(struct complex* comp);//���һ���������鲿

void complex_add(struct complex* comp1, struct complex* comp2);//�ӷ�

void complex_sub(struct complex* comp1, struct complex* comp2);//����

void complex_mul(struct complex* comp1, struct complex* comp2);//�˷�

void complex_div(struct complex* comp1, struct complex* comp2);//����