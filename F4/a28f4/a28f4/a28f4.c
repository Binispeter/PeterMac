#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int get_code();
double discount_percentage (int code);
int product_points(int code, double fprice);
int main()
{
    int code, points;
    double price, finalPrice, discount, total, discountSum;

        total = discountSum = 0;
        points = 0;
        do {
        code = get_code();
        if (code != 0) {
            printf("Dwse thn timh: ");
            scanf("%lf", &price);

        discount = discount_percentage(code) * price;
        discountSum += discount;
        finalPrice = price - discount;
        total += finalPrice;
        points += product_points(code, finalPrice);
        }
        } while (code !=0);



        printf("--------------\n");
        printf("Teliko synolo: %.2f\n", total);
        printf("Ekptwsh: %.2f Euro\n", discountSum);
        printf("Pontoi: %d", points);

        return 0;
}


int get_code()
{
    int code;
    printf("Dwse ton kwdiko: ");
    scanf("%d", &code);

    while (code > 2000 || code < 0)
    {
        printf("Lathos kwdikos (0-2000)\n");
        printf("Dwse ton kwdiko: ");
        scanf("%d", &code);
    }
    return code;
}

double discount_percentage(int code)
{
    if (code <= 300)
    return 0.05;

    else if (code <= 500)
        return 0.10;

    else if (code <= 1000)
        return 0.15;

    else return 0.20;
}

int product_points(int code, double fprice)
{
    int points = 1;
    if (code >= 1000 && code <= 1500)
    {
        points += ceil(fprice / 5);
    }
        return points;

}
