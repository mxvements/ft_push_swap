/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:14:45 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 23:15:38 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		getcheapest(t_dll **stack)
{
	t_dll	*tmp;
	int		cheapest_idx;
	int		cheapest_cost;

	tmp = (*stack);
	cheapest_cost = ((t_content *)tmp->content)->cost_tot;
	cheapest_idx = ((t_content *)tmp->content)->indx;
	while (tmp)
	{
		if (((t_content *)tmp->content)->cost_tot < cheapest_cost)
		{
			cheapest_cost = ((t_content *)tmp->content)->cost_tot;
			cheapest_idx = ((t_content *)tmp->content)->indx;
		}
		tmp = tmp->next;
	}
	return (cheapest_idx);
}

void	move_b_to_a(t_dll **stack_a, t_dll **stack_b)
{
	int			cheapest;
	t_dll		*node;
	t_content	*ndcontent;

	cheapest = getcheapest(stack_b);
	node = (*stack_b);
	while (node)
	{
		ndcontent = node->content;
		if ((int)(ndcontent->indx) != cheapest)
			node = node->next;
		if ((int)(ndcontent->indx) == cheapest)
		{
			movenode(node, stack_a, stack_b);
			push_a(stack_a, stack_b);
			break;
		}
	}
	
}
