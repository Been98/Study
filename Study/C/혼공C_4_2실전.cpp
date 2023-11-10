#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int main()
{
    float kg, cm;
    scanf("%f%f",&kg,&cm);

    float bmi = kg / (cm*cm);
    (bmi >= 20.0) && (bmi < 25.0) ? printf("표준입니다") : printf("체중관리가 필요합니다.");

    return 0;
}