#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* 
nasm -f win64 vector.asm
gcc -c randvectorc.c -o vectorc.obj -m64
gcc vectorc.obj vector.obj -o vector.exe -m64
vector.exe

*/


extern float calculate_distance(int n, float* x1, float* x2, float* y1, float* y2, float* z);

int main() {
    int n, i;
    
    srand(time(NULL));
    
    printf("Enter the size of the vectors (n): ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the vectors
    float *x1 = (float*)malloc(n * sizeof(float));
    float *x2 = (float*)malloc(n * sizeof(float));
    float *y1 = (float*)malloc(n * sizeof(float));
    float *y2 = (float*)malloc(n * sizeof(float));
    float *z = (float*)malloc(n * sizeof(float));

    if (x1 == NULL || x2 == NULL || y1 == NULL || y2 == NULL || z == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }


    clock_t start = clock();

    for (i = 0; i < n; i++) {
        x1[i] = (float)(rand() % 100);  
        x2[i] = (float)(rand() % 100);  
        y1[i] = (float)(rand() % 100);  
        y2[i] = (float)(rand() % 100); 
    }

   
    calculate_distance(n, x1, x2, y1, y2, z);

    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);

    free(x1);
    free(x2);
    free(y1);
    free(y2);
    free(z);

    return 0;
}

