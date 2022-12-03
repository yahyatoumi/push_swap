#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_print(char *str);
char **ft_split(char *str);
int ft_atoi_checker(char *str);
void ft_do_magic_2(int *a, int *b, int len);
void ft_do_magic(int **a, int *a_len, int **b, int *b_len);
int is_a_sorted(int *a, int len);
void push_min_to_top(int *a, int len);
int min_index(int *a, int len);
int ft_check_dup(int *a, int len);
int *ft_set_a(char **av, int *len);
int ft_number_of_nbrs(char *str);
void ft_push_a(int **a, int **b, int *a_len, int *b_len);
void ft_push_b(int **a, int **b, int *a_len, int *b_len);
int *ft_stack_without_first(int *arr, int *len);
int *ft_add_to_stack(int *arr, int *len, int to_add);
void from_top_to_bottom(int *a, int len);
void swap_first_two(int *a);
void from_bottom_to_top(int *a, int len);
int ft_atoi_checker(char *str);

#endif