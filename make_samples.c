#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_FLOAT(x) ((float)rand() / (float)(RAND_MAX / x))

#define PATHNAME "sample_input.txt"

int main(int argc, char* argv[])
{
    // set seed
    srand(time(NULL));

    // get command line argument
    const char* arg = argv[1];
    int n_samples = atoi(arg);
    if (n_samples == 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // open file to write
    FILE* f;
    errno_t err;
    err = fopen_s(&f, PATHNAME, "w");
    if (err == 0) {
        // print # samples
        fprintf(f, "%d\n", n_samples);

        for (int i = 0; i < n_samples; i++) {
            // randomize parameters
            float vi, vf, t;
            vi = RAND_FLOAT(40); // 0 - 40
            vf = 30 + RAND_FLOAT(300); // 30 - 330
            t = 1 + RAND_FLOAT(20); // 1 - 20
            fprintf(f, "%.2f, %.2f, %.2f\n", vi, vf, t);
        }

        printf("Wrote %d samples in %s.\n", n_samples, PATHNAME);
    } else {
        fclose(f);
        printf("Unable to open file for writing.\n");
        return 1;
    }

    return 0;
}
