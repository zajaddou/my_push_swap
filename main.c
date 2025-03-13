
#include <stdio.h>

void add_one(int *ptr)
{
    *ptr = 1;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    int *ptr = &n;

    add_one(ptr);

    printf("%d\n", n);
}
