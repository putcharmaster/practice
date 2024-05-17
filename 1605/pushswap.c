/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:27:41 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/17 12:06:52 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

1 3 5 7 9	swap(t_stack **h)
  t		t = (*h)->next;	
    hn		(*h)->next = t->next;
tn		t->next = *h;
  h		*h = t;


rotate(t_stack **head)
	if *head or (*head)->next empty(NULL)  then return;
	*last = *head;
	move *last to last node.
	last->next becomes last
	(*head)->next, aka the second one becomes *temp
	and (*head)->next becomes NULL
	*head becomes last->next
	temp aka ex)(*head)->next is now *head.

1		1		7
7	temp	'\0'		3
3		3		5
5 last		5 last		1
		1		'\0'

void	rotate(t_stack *h)
{
	t_stack 
}
