#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train_assets)/sizeof(train_assets[0]))
#define epsilon 0.0001f
#define learning_rate 0.1f
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

// Loss function using mean squared error
float loss_function(float assets[][2], float output) {
    float distance = 0.0f;

    for(size_t i = 0; i < train_count; i++) {
        float x = assets[i][0];
        float y = assets[i][1];
        float y_hat = x * output;

        distance += (y - y_hat) * (y - y_hat);
    }

    float result = distance / (float) train_count;
    return result;
}

// Derivative of the loss function using finite difference for now
float dcost(float w,float esp){
    float dcost = (loss_function(train_assets, w + esp) - loss_function(train_assets,w - esp)) / (2 * esp);
    return dcost;
}

int main(void) {
    float weight = random_float();
    weight -= learning_rate * dcost(weight, epsilon);
    printf("%f\n", weight);

    printf("%s\n", "--------------------");

    for(size_t i = 0; i < train_count; i++) {
        float x = train_assets[i][0];
        float y = x * weight;

        printf("Output: %f, Exprected: %f \n", y, train_assets[i][0]);
        printf("Loss: %f\n", loss_function(train_assets, weight));
    }

}
