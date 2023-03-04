
#include "push_swap.h"

int	*copy_toarray(t_stack *a)
{
	t_node	*node;
	int		i;
	int		*array;
	int		size;

	i = 0;
	size = a->size;
	array = (int *) malloc(sizeof(int) * (size));
	if (!array)
		return (0);
	node = a->top;
	while (i < size)
	{
		array[i++] = node->content;
		node = node->next;
	}
	return (array);
}

int		*copy_stack_to_array(t_stack *a, int n)
{
	int	i;
	int	*array;

	i = 0;
	array = (int *) malloc(sizeof(int) * (n + 1));
	if (!array)
		return (0);
	t_node	*node;
	node = a->top;
	while(i < n)
	{
		array[i++] = node->content;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (array);
} 


int		find_pivot_5(t_stack	*a)
{
	int	*array;
	int	i;
	int	j;
	int	tmp;
	int size;

	i = 0;
	size = 5;
	array = copy_stack_to_array(a, 5);
	while(i < size)
	{
		j = 0;
		while(j < size - 1)
		{
			if(array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array[2]);
}
