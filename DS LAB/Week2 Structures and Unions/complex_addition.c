#include <stdio.h>
typedef struct{
float real;
float imag;
} complex;
complex add(complex n1, complex n2) {
complex temp;
temp.real = n1.real + n2.real;
temp.imag = n1.imag + n2.imag;
return (temp);
}

int main() {
complex n1, n2, result;
printf("Enter the real and imaginary parts for 1st complex number: ");
scanf("%f %f", &n1.real, &n1.imag);
printf("\nEnter the real and imaginary parts for 2nd complex number: ");
scanf("%f %f", &n2.real, &n2.imag);
result = add(n1, n2);
printf("Sum = %.2f + %.2fi", result.real, result.imag);
}
