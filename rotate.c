#include "push_swap.h"

void    rotate(t_stack	*stack, int flag)
{
    int tmp;
    if (stack->size < 2)
        return ;
    tmp = stack->top->content;
    pop_node_top(stack);
    push_node_bottom(stack, tmp, 1);
    if(flag == 65)
        write(1, "ra\n", 3);
    else if(flag == 66)
        write(1, "rb\n", 3);
    else
        write(1, "rr\n", 3);
}

void    rotate_all(t_stack	*a, t_stack	*b)
{
    rotate(a, 67);
    rotate(b, 67);
}