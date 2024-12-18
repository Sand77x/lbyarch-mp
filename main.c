#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMN_SIZE 3

// x86-64 implementation of acceleration function
// params: initial velocity, final velocity, time
// returns: integer acceleration
extern int get_acceleration(float VI, float VF, float T);
int sanity_check(float VI, float VF, float T);

int main()
{
    // get number of rows
    int Y;
    scanf_s("%d", &Y);

    // initialize matrix of Y * 3 floats
    float** matrix = (float**)malloc(Y * sizeof(float*));

    for (int i = 0; i < Y; i++) {
        matrix[i] = (float*)malloc(COLUMN_SIZE * sizeof(float));
    }

    // get input from stdin
    for (int i = 0; i < Y; i++) {
        scanf_s("%f, %f, %f", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }

    // print acceleration per row
    int correct = 0;
    clock_t start, end;
    double elapsed_c = 0;
    double elapsed_asm = 0;
    for (int i = 0; i < Y; i++) {
        float vi = matrix[i][0];
        float vf = matrix[i][1];
        float t = matrix[i][2];

        // ----x86-64 impl-----
        start = clock(); // start timer
        int accel = get_acceleration(vi, vf, t);
        end = clock(); // end timer
        elapsed_asm += (double)(end - start) * 1000 / CLOCKS_PER_SEC; // add time to total
        // --------------------

        // ----C impl-----
        start = clock(); // start timer
        int truth = sanity_check(vi, vf, t);
        end = clock(); // end timer
        elapsed_c += (double)(end - start) * 1000 / CLOCKS_PER_SEC; // add time to total
        // ---------------

        if (accel == truth) {
            correct++; // inc correct counter
            printf("%d (v)\n", accel);
        } else {
            printf("%d (should be %d)\n", accel, truth);
        }
    }

    printf("(%d/%d) Values Verified.\n", correct, Y);
    printf("ELAPSED (x86-64): %.2lfms\n", elapsed_asm);
    printf("ELAPSED (C): %.2lfms\n", elapsed_c);

    // free mallocd pointers
    for (int i = 0; i < Y; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

int sanity_check(float VI, float VF, float T)
{
    return rintf((VF - VI) * 1000 / 3600 / T);
}
