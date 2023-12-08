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

int	s_isnodedup(t_dll **head, t_dll *node)
{
	t_dll	*tmp;
	int		flag;

	flag = 0;
	tmp = *head;
	while (tmp)
	{
		if (*(int *)(tmp->content) == *(int *)(node->content))
			flag = 1;
		tmp = tmp->next;
	}
	return(flag);
}

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