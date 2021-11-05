#include <stdio.h>

int buyuk(int x, int y) {
    if( x > y ) return x;
    else return y;
}

int kucuk(int x, int y) {
    if( x > y )
        return y;
    else
        return x;
}

int solve(int array[], int n) {

    int toplam = 0;
    for(int i = 0; i < n; i++) {
        int leftMax = 0;
        int rightMax = 0;

        for(int j = i; j >= 0; j--)
            leftMax = buyuk(array[j], leftMax);

        for(int k = i; k < n; k++)
            rightMax = kucuk(array[k], rightMax);


        toplam += kucuk(leftMax, rightMax) - array[i];
    }
    return toplam;
}
int main() {

    int array[]= {6,0,2,2,3,0,5,4,0,3};
    printf("%d", solve(array,10));

    return 0;
}
