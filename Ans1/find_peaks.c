#include <stdio.h>
#include <stdlib.h>

void load_data(const char *filename, double **data, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    int capacity = 1000; // Initial capacity
    *data = malloc(capacity * sizeof(double));
    *size = 0;

    while (fscanf(file, "%lf", &((*data)[*size])) != EOF) {
        (*size)++;
        if (*size >= capacity) {
            capacity *= 2;
            *data = realloc(*data, capacity * sizeof(double));
        }
    }
    fclose(file);
}

void find_peaks_and_minima(double *data, int size, int **peaks, int *num_peaks, int **minima, int *num_minima) {
    *num_peaks = 0;
    *num_minima = 0;
    *peaks = malloc(size * sizeof(int));
    *minima = malloc(size * sizeof(int));

    for (int i = 1; i < size - 1; i++) {
        if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
            (*peaks)[(*num_peaks)++] = i;
        } else if (data[i] < data[i - 1] && data[i] < data[i + 1]) {
            (*minima)[(*num_minima)++] = i;
        }
    }
}

int main() {
    double *data;
    int size;
    int *peaks, *minima;
    int num_peaks, num_minima;

    load_data("Data_1.txt", &data, &size);
    find_peaks_and_minima(data, size, &peaks, &num_peaks, &minima, &num_minima);

    printf("Peaks at indices: ");
    for (int i = 0; i < num_peaks; i++) {
        printf("%d ", peaks[i]);
    }
    printf("\n");

    printf("Minima at indices: ");
    for (int i = 0; i < num_minima; i++) {
        printf("%d ", minima[i]);
    }
    printf("\n");

    free(data);
    free(peaks);
    free(minima);

    return 0;
}
