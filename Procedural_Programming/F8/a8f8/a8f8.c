#include <stdio.h>

typedef struct
{
    int width, height, depth, area, volume;
}box;

box Dimensions(box dim);
void calc_box_area(box *a_box);
void calc_box_volume(box *a_box);




box Dimensions(box dim)
{
    printf("Enter the width of the box(in cm): ");
    scanf("%d", &dim.width);
    printf("Enter the height of the box(in cm): ");
    scanf("%d", &dim.height);
    printf("Enter the depth of the box(in cm): ");
    scanf("%d", &dim.depth);

    return dim;
}

void calc_box_area(box *a_box)
{
    a_box->area = 4*a_box->height*a_box->width + 2*a_box->height*a_box->depth;
}

void calc_box_volume(box *a_box)
{
    a_box->volume = a_box->depth*a_box->height*a_box->width;
}

int main()
{
    box ask;
    box *parea;
    ask = Dimensions(ask);

    parea = &ask;

    calc_box_area(parea);
    printf("\nTo emvadon tou koutiou einai %d cm2\n", parea->area);

    calc_box_volume(parea);
    printf("O ogkos tou koutiou einai %d cm3\n\n", parea->volume);

    return 0;
}
