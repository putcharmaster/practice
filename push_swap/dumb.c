#include "../inc/push_swap.h"

void    dumb_way(t_stack **a, t_stack **b)
{   
    send two elements to stack b
    send top element a to stack b. 
    b stack should be in descending order(using sort_three_descending)
    now 
        if a->value is the bigger than the biggest of b, it should be on the top of the biggest of b
        if a->value is the smaller than the smallest of b, it should be on the top of the biggest of b
        if a->value is in between the biggest and smallest of b, 
            rotate x times of b, 
                it should be on the top of the closest smaller value of b.

            but rb if it's close to top , rrb if it's close to bottom
    pb the top element of a to b

inside the struct store a value index and *next;
rb or rrb index amount.

}