/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:43 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/07 23:43:32 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_print(t_stack **head)
{
	size_t	i;
	t_stack	*tmp;

	if (head == NULL || *head == NULL)
	{
		printf("empty list\n");
		return ;
	}
	tmp = *head;
	i = 1;
	while (tmp)
	{
		printf("node %zu: %p -> %d\n", i, tmp->content, *(int *)(tmp->content));
		i++;
		tmp = tmp->next;
	}
	return ;
}

void	s_push(t_stack **head, t_stack *newnode)
{
	t_stack	*oldhead;

	if (!head || !newnode)
		return ;
	oldhead = *head;
	if (oldhead != NULL)
		oldhead->prev = newnode;
	newnode->next = oldhead;
	*head = newnode;
	return ;
}

void	*s_pop(t_stack **head)
{
	void	*popnode;
	t_stack	*tmp;

	if (*head == NULL)
		return (NULL);
	popnode = (*head)->content;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return (popnode);
}

int	s_size(t_stack **head)
{
	int		count;
	t_stack	*tmp;

	if (!head || !(*head))
		return (0);
	tmp = *head;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_stack	**s_inithead(void)
{
	t_stack	**stack;

	stack = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack)
		return (0);
	*stack = NULL;
	return (stack);
}
