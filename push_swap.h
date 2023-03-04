#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MIN 0
# define MAX 1
# define A 0
# define B 1
/* Lista duplamente encadeada é bom pq vc ja pode colocar
o tamanho da lista(size), além do mais, o big O no quesito
adicionar elemento é melhor do que com array. E, se você
nao sabe o tamanho de numeros, é melhor utilizar uma lista*/
typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	int 			size;
}	t_stack;
void imprimir(t_stack *stack);
/*escreve error*/
void 	write_error(void);
/*checa argumentos*/
void	check_arguments(int argc, char **argv);
void 	check_duplicate(t_stack *stack, int num);
int		check_sorted(t_stack *a);
int		check_format(char *argv);
/*atoi*/
int		ft_atoi(const char *str);
/*split*/
char	**ft_split(char const *s, char c);
/*sort*/
void	sort(t_stack *a, t_stack *b);
int		find_pivot_5(t_stack	*a);
/*free*/
int		free_stack(t_stack *stack);
int		free_stacks(t_stack *stack_a, t_stack *stack_b);
void 	free_array(char **tab, size_t size);
/*pop*/
int		pop_node_bottom(t_stack *stack);
int		pop_node_top(t_stack *stack);
/*push*/
void	push_node_bottom(t_stack *stack, int num, int flag);
void	push_node_top(t_stack *stack, int num);
/*ações*/
void    pa(t_stack	*a, t_stack *b);
void    pb(t_stack	*a, t_stack *b);
void 	reverse_rotate(t_stack *stack, int flag);
void 	reverse_rotate_all(t_stack	*a, t_stack	*b);
void    rotate(t_stack	*stack, int flag);
void 	rotate_all(t_stack	*a, t_stack	*b);
void 	swap(t_stack *stack, int flag);
void 	swap_all(t_stack	*a, t_stack	*b);
/*copia os numeros da stack para array*/
int		*copy_stack_to_array(t_stack *a, int n);
int		*copy_toarray(t_stack *a);

int		binary_search(int array[], int low, int high, int x);
void	bubble_sort(int size, int array[]);

#endif