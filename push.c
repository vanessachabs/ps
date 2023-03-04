#include "push_swap.h"

t_node* create_node()
{
    //malloc recebe um ponteiro do tipo void
    t_node* new = (t_node*)malloc(sizeof(t_node));
    if (!new)
       write_error();
    new->content = 0;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void push_node_bottom(t_stack *stack, int num, int flag)
{
    if (flag == 0)
        check_duplicate(stack, num);
    t_node* new_node = create_node();
    new_node->content= num; 
    new_node->next = NULL;
    new_node->prev = stack->bottom;
    if (stack->bottom == NULL && stack->top == NULL )
    {
        stack->top = new_node;
        stack->bottom = new_node;
    }
    else
    {
        if (stack->bottom != NULL)
            stack->bottom->next = new_node;
        stack->bottom = new_node;
    }
    stack->size++;
}

void push_node_top(t_stack *stack, int num)
{
    t_node* new_node = create_node();

    new_node->content= num; 
    new_node->prev = NULL;
    if (stack->top == NULL)
    {
        new_node->next = NULL;
        stack->top = new_node;
        stack->bottom = new_node;
    }
    else
    {
        stack->top->prev = new_node;
        new_node->next = stack->top;
        stack->top = new_node;
    }
    stack->size++;
}

void    pa(t_stack	*a, t_stack *b)
{
    //t_node  *aux;
    int aux;
    if (b->size < 1)
        return ;
    //aux = b->top;
    aux = b->top->content;
    pop_node_top(b);
    push_node_top(a, aux);
    write(1, "pa\n", 3); 
}

void    pb(t_stack	*a, t_stack *b)
{
    //t_node  *aux;
    int aux;
    if (a->size < 1)
        return ;
    aux = a->top->content;
    pop_node_top(a);
    push_node_top(b, aux);
    write(1, "pb\n", 3); 
}