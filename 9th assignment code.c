#include <stdio.h>
#include <stdlib.h>

#define MAX_SAFE_DEPTH 300.0
#define MAX_SAFE_PRESSURE 30.0
#define MAX_SAFE_TEMP 45.0
#define MIN_SAFE_BATTERY 20.0

struct RobotData {
    int recordId;
    float depth;
    float pressure;
    float temperature;
    float battery;
    int defects;
};

int main() {
    FILE *dataFile, *reportFile;
    struct RobotData r;
    int n, i, unsafeCount = 0;
    int isUnsafe;

    dataFile = fopen("robot_records.txt", "w");
    if (dataFile == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        r.recordId = i + 1;
        printf("\nEnter details for Record %d:\n", r.recordId);

        printf("Depth (m): ");
        scanf("%f", &r.depth);

        printf("Water Pressure (bar): ");
        scanf("%f", &r.pressure);

        printf("Temperature (C): ");
        scanf("%f", &r.temperature);

        printf("Battery Percentage: ");
        scanf("%f", &r.battery);

        printf("Structural Defects: ");
        scanf("%d", &r.defects);

        fprintf(dataFile, "%d %f %f %f %f %d\n", r.recordId, r.depth, r.pressure, r.temperature, r.battery, r.defects);
    }

    fclose(dataFile);

    dataFile = fopen("robot_records.txt", "r");
    reportFile = fopen("inspection_report.txt", "w");

    if (dataFile == NULL || reportFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    fprintf(reportFile, "UNDERWATER ROBOT INSPECTION REPORT\n\n");

    while (fscanf(dataFile, "%d %f %f %f %f %d", &r.recordId, &r.depth, &r.pressure, &r.temperature, &r.battery, &r.defects) != EOF) {
        isUnsafe = 0;

        fprintf(reportFile, "Record %d:\n", r.recordId);
        fprintf(reportFile, "Depth: %.2f m, Pressure: %.2f bar, Temp: %.2f C, Battery: %.2f%%, Defects: %d\n", r.depth, r.pressure, r.temperature, r.battery, r.defects);

        if (r.depth > MAX_SAFE_DEPTH) {
            fprintf(reportFile, "Warning: Unsafe depth!\n");
            isUnsafe = 1;
        }
        if (r.pressure > MAX_SAFE_PRESSURE) {
            fprintf(reportFile, "Warning: High water pressure!\n");
            isUnsafe = 1;
        }
        if (r.temperature > MAX_SAFE_TEMP) {
            fprintf(reportFile, "Warning: High temperature!\n");
            isUnsafe = 1;
        }
        if (r.battery < MIN_SAFE_BATTERY) {
            fprintf(reportFile, "Warning: Low battery!\n");
            isUnsafe = 1;
        }
        if (r.defects > 0) {
            fprintf(reportFile, "Warning: Structural defects found!\n");
            isUnsafe = 1;
        }

        if (isUnsafe == 1) {
            fprintf(reportFile, "Status: UNSAFE\n\n");
            unsafeCount++;
        } else {
            fprintf(reportFile, "Status: SAFE\n\n");
        }
    }

    fprintf(reportFile, "Total Records: %d\n", n);
    fprintf(reportFile, "Total Unsafe Records: %d\n", unsafeCount);

    fclose(dataFile);
    fclose(reportFile);

    printf("\nInspection report generated successfully.\n");

    return 0;
}