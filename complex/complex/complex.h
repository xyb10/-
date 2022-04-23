#pragma once
#include<stdio.h>
#include<stdlib.h>

struct complex {
	float* preal;
	float* pimag;
};

struct complex* complex_init();//在堆存储区创建一个复数

void complex_free(struct complex* comp);//在堆存储区回收复数的存储空间

void complex_set_real(struct complex* comp, float value);//设置一个复数的实部

float complex_get_real(struct complex* comp);//获得一个复数的实部

void complex_set_imag(struct complex* comp, float value);//设置一个复数的虚部

float complex_get_imag(struct complex* comp);//获得一个复数的虚部

void complex_add(struct complex* comp1, struct complex* comp2);//加法

void complex_sub(struct complex* comp1, struct complex* comp2);//减法

void complex_mul(struct complex* comp1, struct complex* comp2);//乘法

void complex_div(struct complex* comp1, struct complex* comp2);//除法