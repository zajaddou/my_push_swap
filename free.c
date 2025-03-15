
#include "push_swap.h"

void    *ft_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
        ft_exit("Out of memory");
    ft_free(ptr);
    return (ptr);
}

void    ft_free(void *ptr)
{
    static  void *total[INT_MAX];
    static  int in;
    int         out;

    out = 0;
    if (!ptr)
        while (total[out])
            free(total[out++]);
    else
        total[++in] = ptr;
}

void    ft_exit(char *why)
{
	ft_free(NULL);
    if (why)
	    printf("\033[1;31mE: %s\033[0m\n", why);
	exit(1);
}