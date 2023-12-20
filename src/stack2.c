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

void	s_free(t_dll **head)
{
	t_dll	*tmp;
	t_dll	*tmpnext;

	tmp = *head;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		s_freenode(tmp);
		tmp = tmpnext;
	}
	free(head);
}

void	s_freenode(t_dll *node)
{
	free(node->content);
	node->content = NULL;
	free(node);
}

void	s_findbounds(t_dll **stack, t_dll **min, t_dll **max)
{
	t_dll		*tmp;
	t_content	*tmpcont;

	tmp = *stack;
	while (tmp)
	{
		tmpcont = tmp->content;
		if (((t_content *)(*min)->content)->nbr > tmpcont->nbr)
			(*min) = tmp;
		if (((t_content *)(*max)->content)->nbr < tmpcont->nbr)
			(*max) = tmp;
		tmp = tmp->next;
	}
}
