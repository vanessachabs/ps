
#include "push_swap.h"

void	write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int	check_sorted(t_stack *a)
{
	t_node  *node;

    node = a->top;
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}
void check_duplicate(t_stack *stack, int num)
{
    t_node  *aux;

    aux = stack->top;
	while(aux)
	{
		if(aux->content == num)
			write_error();
        aux = aux->next;
	}
}
/*Verifique se os dados recebidos estão no formato "4 5 3"*/
int	check_format(char *argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
		if (argv[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
/* void	isempty_arg(char **str)
{
	int	i;
	int	j;
	int flag;

	i = 1;
	flag = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if(str[i][j] >= '0' && str[i][j] <= '9')
			{
				flag = 1;
				break;
			}
			j++;
		}
		if (flag == 0)
			write_error();
		i++;
	}
} 


void check_duplicate(int *array, t_stack *stack)
{
	int	i;
	int	j;
	int	aux;

	while(i < stack->size)
	{
		j = i + 1;
		while(j < stack->size)
		{
			if(array[i] == array[j])
				write_error();
			j++;
		}
		i++;
	}
}*/
// 3 2 1 0 5 ou "  1 4 5"
void	check_arguments(int argc, char **argv)
{
	int	i;
	int	j;
	int flag;

	i = 1;
	flag = 0;
    if (argc <= 1) //Se não houver valor recebido
		exit(0);
	//str = argv[i];
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				flag = 1;
				break;
			}
			j++;
		}
		if (flag == 0)
			write_error();
		i++;
	}
}