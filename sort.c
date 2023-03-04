#include "push_swap.h"

static void	indexing(t_stack *a, int array[])
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		node->content = binary_search(array, 0, a->size - 1, node->content);
		node = node->next;
	}
}

void	imprimir(t_stack *stack)
{
	t_node	*node;
	node = stack->top;
	while(node)
	{
		printf("%d ", node->content);
		node = node->next;
	}
	printf("\n");
}

void	sort_3(t_stack	*a)
{
	int	first;
	int	mid;
	int	last;

	first = a->top->content;
	mid = a->top->next->content;
	last = a->top->next->next->content;
	if (first > mid && mid > last && first > last)
	{
		swap(a, 65);
		reverse_rotate(a, 65);
	}
	else if (first < mid && mid > last && first > last)
		reverse_rotate(a, 65);
	else if (first < mid && mid > last && first < last)
	{
		swap(a, 65);
		rotate(a, 65);
	}
	else if (first > mid && mid < last && first > last)
		rotate(a, 65);
	else if (first > mid && mid < last && first < last)
		swap(a, 65);
}

void sort_5(t_stack	*a, t_stack *b)
{
	int mid;
	int count_pb;

	count_pb = 0;
	mid = find_pivot_5(a);
	while(count_pb != 2)
	{
		if (a->top->content >= mid)
			rotate(a,65);
		else
		{
			pb(a, b);
			count_pb++;
		}
	}
	if (!check_sorted(a))
		sort_3(a);
	if (b->top->content < b->bottom->content)
		swap(b, 66);
	pa(a, b);
	pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b, int size)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	/*quantos bits tem o maior numero da stack*/
	while ((size - 1) >> count)
		count++;
	/*passará por todos os bits de, por exemplo, 0011, se for 0 joga para b, caso não, dá rotate a*/
	while (i < count)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->content >> i) & 1) == 1)
				rotate(a, 65);
			else
				pb(a,b);
			j++;
		}
		while(b->size)
			pa(a,b);
		i++;
	}
}

void	sort_others(t_stack *a, t_stack *b)
{
	int	*array;

	array = copy_toarray(a);
	bubble_sort(a->size, array);
	indexing(a, array);
	free(array);
	imprimir(a);
	radix_sort(a, b, a->size);
}

void	sort(t_stack *a, t_stack *b)
{

	if (!check_sorted(a))
	{
		if (a->size == 2)
		{
			if (a->top->content > a->top->next->content)
				swap(a, 65);
		}
		else if (a->size == 3)
			sort_3(a);
		else if (a->size == 5)
			sort_5(a,b);
		else
			sort_others(a,b);
	}
}