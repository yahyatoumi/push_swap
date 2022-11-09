#include "push_swap.h"

int ft_atoi_checker(char *str)
{
	int i;

	i = 1;
	if (str[0] != '-' && str[0] != '+' && (str[0] < '0' || str[0] > '9'))
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void from_bottom_to_top(int *a, int len)
{
	int i;
	int tmp;
	int tmp2;

	i = 1;
	tmp = a[0];
	a[0] = a[len - 1];
	while (i < len)
	{
		tmp2 = a[i];
		a[i] = tmp;
		tmp = tmp2;
		i++;
	}
}

void swap_first_two(int *a)
{
	int tmp;

	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void from_top_to_bottom(int *a, int len)
{
	int i;
	int tmp;
	int tmp2;

	i = 2;
	tmp = a[len - 1];
	a[len - 1] = a[0];
	while (i <= len)
	{
		tmp2 = a[len - i];
		a[len - i] = tmp;
		tmp = tmp2;
		i++;
	}
}

int	*ft_add_to_stack(int *arr, int len, int to_add)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(sizeof(int) * (len + 1));
	if (!new_arr)
		return (0);
	i = 1;
	new_arr[0] = to_add;
	while (i <= len)
	{
		new_arr[i] = arr[i - 1];
		i++;
	}
	free(arr);
	return (new_arr);
}

int	*ft_stack_without_first(int *arr, int len)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(sizeof(int) * (len - 1));
	if (!new_arr)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		new_arr[i] = arr[i + 1];
		i++;
	}
	free(arr);
	return (new_arr);
}

void	ft_push_b(int *a, int *b, int a_len, int b_len)
{
	b = ft_add_to_stack(b, b_len, a[0]);
	a = ft_stack_without_first(a, a_len);
}

void	ft_push_a(int *a, int *b, int a_len, int b_len)
{
	a = ft_add_to_stack(a, a_len, b[0]);
	b = ft_stack_without_first(b, a_len);
}

int	*ft_set_a(char **av, int len)
{
	int	*a;
	int	i;

	a = (int *)malloc(sizeof(int) * len);
	if (!a)
		return (0);
	i = 0;
	while (i < len)
	{
		a[i] = atoi(av[i + 1]);
		i++;
	}
	return (a);
}

void	ft_do_magic(int *a, int *b, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return ;
	if (len == 1)
		return ;
	if (len == 2)
	{
		if (a[0] > a[1])
			swap_first_two(a);
		return ;
	}
	if (len == 3)
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
		else if(a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
		{
			swap_first_two(a);
			from_top_to_bottom(a, len);
		}
		else
			from_bottom_to_top(a, 3);
		return ;
	}
}

int	ft_check_dup(int *a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	len;
	int	*a;
	int	*b;

	i = 0;
	len = ac - 1;
	while (ac > 1)
	{
		if (!ft_atoi_checker(av[ac - 1]))
			return (printf("Error\n"));
		ac--;
	}
	a = ft_set_a(av, len);
	if (ft_check_dup(a, len))
	{
		printf("Error\n");
		return (0);
	}
	b = (int *)malloc(sizeof(int));
	ft_do_magic(a, b, len);
	while (i < len)
		printf("%i\n", a[i++]);
}

/* int main(int ac, char **av)
{
	int len;
	t_list	*lst;

	len = ac - 1;
	lst = (t_list *)malloc(sizeof(t_list *));
	if (!lst)
		return (0);
	lst->a = (int *)malloc(sizeof(int) * len);
	if (!lst->a)
	{
		free(lst);
		return (0);
	}
	lst->b = (int *)malloc(sizeof(int) * 1);
	if (!lst->b)
	{
		free(lst);
		free(lst->a);
		return (0);
	}
	while (ac > 1)
	{
		if (!ft_atoi_checker(av[ac - 1]))
		{
			free(lst->a);
			free(lst->b);
			return (printf("Error\n"));
		}
		lst->a[ac - 2] = atoi(av[ac - 1]);
		ac--;
	}
	while (len > 0)
	{
		printf("len == %i\n", len);
		printf("%i\n", lst->a[len - 1]);
		len--;
	}
} */
