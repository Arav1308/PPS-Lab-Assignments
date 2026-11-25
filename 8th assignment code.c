#include <stdio.h>

float findNearest(float *ptr, int n) {
    float min = *ptr;
    int i;

    for (i = 1; i < n; i++) {
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }

    return min;
}

int main() {
    int n, i;
    float distance[50], min;

    printf("Enter number of sensors: ");
    scanf("%d", &n);

    printf("Enter %d distance readings:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &distance[i]);
    }

    min = findNearest(distance, n);

    printf("\nNearest obstacle distance = %.2f\n", min);

    if (min < 20) {
        printf("Warning: Obstacle is too close!\n");
    } else {
        printf("Path is clear.\n");
    }

    return 0;
}
