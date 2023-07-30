#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train_assets)/sizeof(train_assets[0]))

float train_assets[][2] = {
        {0, 0 },
        {1, 4 },
        {2, 8 },
        {3, 12},
        {4, 16}
};

// Returns random float between 0 and RAND_MAX2
float random_float(void) {
    srand(time(0));
    return (float) rand() / (float) RAND_MAX * 10.0f;
}



int main(void) {
    float weight = random_float();
    printf("%f\n", weight);

    printf("%s\n", "--------------------");

    for(size_t i = 0; i < train_count; i++) {
        float x = train_assets[i][0];
        float y = x * weight;

        printf("Output: %f, Exprected: %f \n", y, train_assets[i][0]);
    }
}
