#include <stdio.h>
int main() {

    float GPA;
    int marks;

    printf("Enter your marks?");
    scanf("%d",&marks);

    if (marks>=86) {
    GPA = 4;
    }

    else if (marks>=61 && marks<=85) {
    GPA = 3;
    }

    else if (marks<=60 && marks>=41) {
    GPA = 2;
    }

    else if (marks<=40 && marks>=31) {
    GPA = 1;
    }

    else {GPA = 0;}
    printf("GPA=%.2f", GPA);
    return 0;
}
