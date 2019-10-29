#include <stdio.h>
#include <math.h>



double min(double x, double y){
    return (x < y) ? x : y;
}

double max(double x, double y){
    return (x < y) ? y : x;
}


void sort_arr(double* arr) {
    double maxi, mini;
    double sum = arr[0] + arr[1] + arr[2];

    maxi = max(max(arr[0], arr[1]), arr[2]);
    mini = min(min(arr[0], arr[1]), arr[2]);
    arr[0] = maxi;
    arr[1] = sum - maxi - mini;
    arr[2] = mini;
}


int read_triangle(double* trg, int order) {
    printf("Trojuhelnik #%d:\n", order);
    if (scanf("%lf %lf %lf", &trg[0], &trg[1], &trg[2]) != 3
        || trg[0] <= 0
        || trg[1] <= 0
        || trg[2] <= 0){
        return 0;
    }
    return 1;
}


int is_triangle(double* trg){
    if (trg[0] + trg[1] <= trg[2])
        return 0;
    else
        return 1;
}

int jsou_shodne(double* trg1, double* trg2){
    if (trg1[0] + trg1[1] + trg1[2] == trg2[0] + trg2[1] + trg2[2])
        return 1;
    else
        return 0;
}


int jsou_podobne(double* trg1, double* trg2){
    double a, b, c;
    a = trg1[0] / trg2[0];
    b = trg1[1] / trg2[1];
    c = trg1[2] / trg2[2];
    if (fabs(a - b) <= 0.001 && fabs(b - c) <= 0.001){
        return 1;
    }
    return 0;
}


int main(void) {
    double trg1[3], trg2[3];

    if (!read_triangle(trg1, 1)){
        printf("%s\n", "Nespravny vstup.");
        return 0;
    }
    else if (!is_triangle(trg1)){
        printf("%s\n", "Strany netvori trojuhelnik.");
        return 0;
    }

    if (!read_triangle(trg2, 2)){
        printf("%s\n", "Nespravny vstup.");
        return 0;
    }
    else if (!is_triangle(trg2)){
        printf("%s\n", "Strany netvori trojuhelnik.");
        return 0;
    }

    if (jsou_shodne(trg1, trg2)){
        printf("%s\n", "Trojuhelniky jsou shodne.");
        return 0;
    }
    sort_arr(trg1);
    sort_arr(trg2);
    if (!jsou_podobne(trg1, trg2) && !jsou_shodne(trg1, trg2)){
        printf("%s\n", "Trojuhelniky nejsou shodne ani podobne.");
        return 0;
    }
    if (!jsou_shodne(trg1, trg2) && jsou_podobne(trg1, trg2)){
        printf("%s\n", "Trojuhelniky nejsou shodne, ale jsou podobne.");
        return 0;
    }

    return 0;
}
