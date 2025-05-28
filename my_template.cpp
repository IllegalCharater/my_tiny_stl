#include "my_template.h"

void my_swap(int& a, int& b)
{
    printf("特化模板\n");
    int tmp = a;
    a = b;
    b = tmp;
}
