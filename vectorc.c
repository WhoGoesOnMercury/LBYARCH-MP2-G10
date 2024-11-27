#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float calculate_distance(int n, float* x1, float* x2, float* y1, float* y2, float* z);

int main() { // Add proper main parameters {
    int n = 4;
    int i;
    float x1[4], x2[4], y1[4], y2[4];  // Fixed size arrays
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    
    printf("Enter values for X1: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x1[i]);
    }
    printf("Enter values for X2: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x2[i]);
    }
    printf("Enter values for Y1: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &y1[i]);
    }
    printf("Enter values for Y2: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &y2[i]);
    }

    float* z = (float*)malloc(n * sizeof(float));
    
    calculate_distance(n, x1, x2, y1, y2, z);
    
    for(i = 0; i < n; i++){
        printf("%.8f ", z[i]);
    }
    printf("\n");
    
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Execution time: %f seconds\n", cpu_time_used);
    
    return 0;
}
