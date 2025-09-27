#include <stdio.h>

int extended_euclid(int a, int b, int *x, int *y){
    if(a ==0){
        (*x) = 0;
        (*y) = 1;
        return b;
    }
    int gcd = extended_euclid(b%a, a, x, y);
    int x1 = *x, y1 = *y;

    (*x) = y1 - ((b/a)*x1);
    (*y) = x1;
    return gcd;
}

int inverse(int a, int N){
    int x=0, y=1;
    int gcd = extended_euclid(a, N, &x, &y);

    if(gcd != 1){
        return -1;
    }

    int result = (x%N + N) %N;
    return result;
}

int crt(int residue[], int moduli[], int num){
    int N = 1, x=0;
    for(int i=0; i<num; i++) N *= moduli[i];
    for(int i=0; i<num; i++){
        int n = N/moduli[i];
        int y = inverse(n, moduli[i]);
        x += residue[i]*n*y;
    }
    return x % N;
}

int main(){
    int num;
    printf("Enter number of congruences: ");
    scanf("%d", &num);

    while(num < 1){
        printf("Invalid number entered. Enter again: ");
        scanf("%d", &num);
    }

    int a[num], m[num], x;

    printf("Enter %d lines of a and m [x ≡ a (mod m)]: \n", num);
    for(int i=0; i<num; i++){
        scanf("%d %d", &a[i], &m[i]);
        if(a[i]<1 || m[i]<1){
            printf("Enter a positive integer.\n");
            i--;
            continue;
        }
    }

    x = crt(a, m, num);

    printf("\n");
    for(int i=0; i<num; i++){
        printf("x ≡ %d (mod %d)\n", a[i], m[i]);
    }
    printf("\n");
    printf("The smallest positive integer x that satisfies the above system of simultaneous congruences is %d.\n", x);
}