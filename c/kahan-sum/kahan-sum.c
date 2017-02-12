#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float read_val()
{
    float f;
    f = rand() / (float)RAND_MAX;
    f *= pow(10, rand()%40-20);
    return f;
}

// Uses compensated summation alg - Kahan
float process(int n, float* p)
{
    float sum = 0;
    float c = 0;
    for (int i = 0; i < n; i++)
    {
        float y = p[i] - c;
        float t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

// naive
float process2(int n, float* p)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i];
    }
    return sum;
}

float read_and_process(int n)
{
    float vals[n];

    FILE* f = fopen("sum.txt","wt");
    for (int i = 0; i < n; i++) 
    {
        vals[i] = read_val();
        fprintf(f, "%f ", i, vals[i]);
    }
    fclose(f);

    float sum1 = process(n, vals);
    printf("s1 = %f\n", sum1);
    float sum2 = process2(n, vals);
    printf("s2 = %f\n", sum2);

    return sum1 - sum2;
}

int main(int argc, const char *argv[])
{
    int a;
    printf("a=");
    scanf("%d", &a);

    float sum = read_and_process(a);

    printf("diff = %f\n", sum);
    return 0;
}
