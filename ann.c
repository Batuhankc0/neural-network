#include <stdio.h>
#include "matrix.h"

typedef struct {
    double weights_l1[4][4];
    double biases_l1[4];
    double weights_l2[4][4];
    double biases_l2[4];
} ANN;

void ann_inference(ANN *net, double inputs[], double outputs[]) {
    double layer1_sum[4];
    double layer1_outputs[4];
    double layer2_sum[4];
    double layer2_outputs[4];

    // Layer 1: weighted sum + bias + activation
    matrix_vector_mul(4, 4, net->weights_l1, inputs, layer1_sum);
    vector_add(4, layer1_sum, net->biases_l1, layer1_sum);
    apply_function(4, layer1_sum, relu, layer1_outputs);

    // Layer 2: weighted sum + bias + activation
    matrix_vector_mul(4, 4, net->weights_l2, layer1_outputs, layer2_sum);
    vector_add(4, layer2_sum, net->biases_l2, layer2_sum);
    apply_function(4, layer2_sum, relu, outputs);
}

int main() {
    ANN my_ann = {
        {
            {0.1, -0.2, 0.3, -0.4},
            {0.5, 0.6, -0.7, 0.05},
            {-0.9, 0.1, 0.25, 0.3},
            {0.4, -0.5, 0.65, 0.7}
        },
        {0.1, 0.05, -0.1, 0.2},
        {
            {0.8, -0.7, 0.6, -0.5},
            {-0.4, 0.3, 0.2, 0.15},
            {0.5, -0.6, 0.75, 0.8},
            {0.1, 0.25, -0.3, 0.4}
        },
        {-0.05, 0.1, -0.15, 0.25}
    };

    double inputs[4] = {1.0, 0.5, -0.25, 0.75};
    double outputs[4];

    ann_inference(&my_ann, inputs, outputs);

    printf("ANN Outputs:\n");
    for (int i = 0; i < 4; i++) {
        printf("Neuron %d: %f\n", i + 1, outputs[i]);
    }

    return 0;
}
