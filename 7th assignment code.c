#include <stdio.h>
#include <string.h>

struct Device {
    int deviceId;
    char deviceType[20];
    float vf;
    float ir;
    float vr;
};

int main() {
    struct Device d[50];
    int n, i, outCount = 0;
    float maxVf, maxIr, maxVr;
    int isOut;

    printf("Enter number of semiconductor devices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Device %d:\n", i + 1);

        printf("Device ID: ");
        scanf("%d", &d[i].deviceId);

        printf("Device Type (Diode / BJT / MOSFET / LED): ");
        scanf("%s", d[i].deviceType);

        printf("Forward Voltage Vf (V): ");
        scanf("%f", &d[i].vf);

        printf("Reverse Leakage Current Ir (uA): ");
        scanf("%f", &d[i].ir);

        printf("Rated Voltage Vr (V): ");
        scanf("%f", &d[i].vr);
    }

    printf("\n--- DEVICE SPECIFICATION CHECK REPORT ---\n");

    for (i = 0; i < n; i++) {
        isOut = 0;

        // Set permissible operating limits based on device type
        if (strcmp(d[i].deviceType, "Diode") == 0) {
            maxVf = 0.7;
            maxIr = 10.0;
            maxVr = 100.0;
        } else if (strcmp(d[i].deviceType, "BJT") == 0) {
            maxVf = 0.8;
            maxIr = 50.0;
            maxVr = 60.0;
        } else if (strcmp(d[i].deviceType, "MOSFET") == 0) {
            maxVf = 4.0;
            maxIr = 100.0;
            maxVr = 200.0;
        } else if (strcmp(d[i].deviceType, "LED") == 0) {
            maxVf = 3.3;
            maxIr = 10.0;
            maxVr = 5.0;
        } else {
            // Default permissible limits
            maxVf = 5.0;
            maxIr = 50.0;
            maxVr = 100.0;
        }

        if (d[i].vf > maxVf || d[i].ir > maxIr || d[i].vr > maxVr) {
            isOut = 1;
            outCount++;
        }

        printf("\nDevice ID: %d | Type: %s\n", d[i].deviceId, d[i].deviceType);
        printf("Measured -> Vf: %.2f V, Ir: %.2f uA, Vr: %.2f V\n", d[i].vf, d[i].ir, d[i].vr);

        if (isOut == 1) {
            printf("Status: OUT OF SPECIFICATION\n");
            if (d[i].vf > maxVf) {
                printf("  - Forward Voltage (Vf) exceeded limit (Max: %.2f V)\n", maxVf);
            }
            if (d[i].ir > maxIr) {
                printf("  - Reverse Leakage Current (Ir) exceeded limit (Max: %.2f uA)\n", maxIr);
            }
            if (d[i].vr > maxVr) {
                printf("  - Rated Voltage (Vr) exceeded limit (Max: %.2f V)\n", maxVr);
            }
        } else {
            printf("Status: WITHIN SPECIFICATION\n");
        }
    }

    printf("\nTotal Devices Checked: %d\n", n);
    printf("Total Out of Specification Devices: %d\n", outCount);

    return 0;
}