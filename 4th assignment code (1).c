#include <stdio.h>
int main(){
int i, j;
int r, c;
float Wafer1st[4][4];
float Wafer2nd[4][4];
float Sum[4][4];
printf("Enter the no. of rows and columns: ");
scanf("%d %d",&r, &c);
printf("Enter the Wafer 1 readings:\n");
for (i = 0; i < r; i++) {
for (j = 0; j < c; j++){
scanf("%f", &Wafer1st[i][j]);
}
}

printf("Wafer 2 readings:\n");
for (i = 0; i < r; i++) {
for (j = 0; j < c; j++) {
scanf("%f", &Wafer2nd[i][j]);
}
}

printf("\nThe sum of readings of wafers is:\n");
for (i = 0; i < r; i++) {
for (j = 0; j < c; j++) {
Sum[i][j] = Wafer1st[i][j] + Wafer2nd[i][j];
printf("%.2f\t",Sum[i][j]);
}
printf("\n");
}
return 0;
}

