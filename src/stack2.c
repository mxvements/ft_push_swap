/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:16:20 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/08 20:16:22 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	s_issorted(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (*(int *)(tmp->content) > *(int *)(tmp->next->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	s_isnodedup(t_stack **head, t_stack *node)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (*(int *)(tmp->content) == *(int *)(node->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	s_free(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmpnext;

	tmp = *head;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		s_freenode(tmp);
		tmp = tmpnext;
	}
	free(head);
}

void	s_freenode(t_stack *node)
{
	free(node->content);
	node->content = NULL;
	free(node);
}
