#include <stdio.h>
#include <math.h>

const float PI = 3.1415;

float volume(int radius){
    return (4.0/3.0)*PI*pow(radius,3);
}

int main(){
    int r = 0;
    printf("Specify the radius of the sphere: ");
    scanf("%d", &r);
    printf("Volume is: %f\n", volume(r));
}
