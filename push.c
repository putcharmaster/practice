typedef struct s_list
{
    int content;
    struct s_list   *next;
}   t_list;

int ft_lstsize(t_list **lst)
{
    t_list  *tmp;
    int     i;

    i = 0;
    tmp = *lst;
    while(tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    *lst = new;
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    tmp = *lst;
    if (!new)
        return ;
    if (!(*lst))
    {
        *lst = new;
        new->next = NULL;
        return ;
    }
    else
    {
        while (tmp && tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    new->next = NULL;
}

int main(int ac, char **av)
{
    t_list  *a_stack;
    t_list  *b_stack;

    a_stack = NULL;
    b_stack = NULL;
    if (ac == 1)
        return (0);
    if (ac >= 2 && !check_arg_for_errors(ac, av))
        return (ft_print_error());
    ft_init_stack(&a_stack, ac, av);
    if (ft_lstsize(&a_stack) == 1)
    {
        free_list(&a_stack);
        return (0);
    }
    if (!check_sorted(&a_stack))
        sort_stack(&a_stack, &b_stack);
    free_list(&a_stack);
    return (0);    
}
