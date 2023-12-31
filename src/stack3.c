/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:52:36 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/23 17:04:23 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	s_updateindx(t_dll **head)
{
	size_t		i;
	t_dll		*tmp;
	t_content	*tmpcontent;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		tmpcontent = tmp->content;
		tmpcontent->indx = i;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	s_issorted(t_dll **head)
{
	t_dll	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (*(int *)(tmp->content) > *(int *)(tmp->next->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	s_isnodedup(t_dll **head, t_dll *node)
{
	t_dll	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (*(int *)(tmp->content) == *(int *)(node->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
