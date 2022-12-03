#include "push_swap.h"
void ft_sort_3(int *a)
{
    if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
        swap_first_two(a);
    else if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
    {
        swap_first_two(a);
        from_bottom_to_top(a, 3);
    }
    else if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
        from_top_to_bottom(a, 3);
    else if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
    {
        swap_first_two(a);
        from_top_to_bottom(a, 3);
    }
    else
        from_bottom_to_top(a, 3);
    return;
}
void ft_do_magic_2(int *a, int *b, int len)
{
    int i;

    i = 0;
    if (len == 1)
        return;
    else if (len == 2)
    {
        if (a[0] > a[1])
            swap_first_two(a);
        return;
    }
    else if (len == 3)
        ft_sort_3(a);
}