#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <locale.h> 
double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++)
    {
        ptr_array[i] = -1 + 1.f * 2 * rand() / RAND_MAX;
    }
    return ptr_array;
}
double* calc_elements(double* ptr_array, int size)
{
    double* ptr_array2 = (double*)malloc(size * sizeof(double));
    if (ptr_array2 == NULL)
    {
        puts("error");
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        ptr_array2[i] = ptr_array[i] - ptr_array[size - 1];
    }
    return ptr_array2;
}
int put_elements(double* ptr_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%2d ] = %5.2lf\n", i + 1, ptr_array[i]);
    }
    printf("\n");
}
int delete_k(double* ptr_array, int size, int k, int K)
{
    for (int i = k; i < size - K; i++)
    {
        ptr_array[i] = ptr_array[i + K];
    }
}
int arr999(double* ptr_array, int size, int K, int a)
{
    int min = 0;
    for (int i = 1; i < size; i++)
    {
        if (ptr_array[i] < ptr_array[min]) {
            min = i;
        }
    }
    for (int i = size - 1; i > min; i--)
    {
        ptr_array[i + K] = ptr_array[i];
    }
    for (int i = 0; i < K; i++)
    {
        ptr_array[min + 1 + i] = a;
    }
    size += K;
}
int main()
{
    double* ptr_array = NULL;
    double* res_arr = NULL;
    int size, k, K;
    setlocale(LC_ALL, "RUS");
    printf("Размер массива = ");
    scanf("%d", &size);
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL)
    {
        puts("error");
        return -1;
    }
    full_elements(ptr_array, size);
    res_arr = calc_elements(ptr_array, size);
    if (res_arr == NULL)
    {
        free(ptr_array);
        return -1;
    }
    printf("Исходный массив:\n");
    put_elements(ptr_array, size);
    printf("Преобразованный массив:\n");
    put_elements(res_arr, size);
    printf("Введите k K: ");
    scanf("%d %d", &k, &K);
    delete_k(ptr_array, size, k, K);
    size = size - K;
    put_elements(ptr_array, size);
    printf("Введите K: ");
    scanf("%d", &K);
    arr999(ptr_array, size, K, -999);
    size = size + K;
    put_elements(ptr_array, size);
    free(ptr_array);
    free(res_arr);
}