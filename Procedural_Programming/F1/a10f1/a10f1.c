#include <stdio.h>
#include <math.h>

int main(){
int height, weight;
    printf("Dwse to baros:");
    scanf("%d", &weight);
    height=ceil((1.12*weight + 65)*1.2) + 7.0;
    printf("To ypsos einai %d",height);
return 0;
}
