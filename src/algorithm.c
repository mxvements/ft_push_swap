/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:14:45 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/13 16:14:46 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	movenodes(t_dll *node, t_dll *next)
{
	t_content	*nodecont;
	t_content	*nextcont;
	int			i;

	if (nodecont->indx == 0 && nodecont->indx_out == 0)
		return ;
	else if (nodecont->indx <= (nodecont->slen / 2)
		&& nodecont->indx_out <= (nodecont->slen_out / 2))
		{
			i = nodecont->indx;
			while (i > 1)
			{
				//need to bring stacks
				drot(stack_a, stack_b);
				i--;
			}
			//check if any of the stacks needs more rotations
			dswap(stack_a, stack_b);
		}
}

int		getcheapest(t_dll **stack_a)
{
	t_dll	*tmp;
	int		cheapest;
	int		cost_tot;

	tmp = (*stack_a);
	cheapest = NULL;
	while (tmp)
	{
		if (!tmp->prev)
			cost_tot = ((t_content *)tmp->content)->cost_tot;
		if (((t_content *)tmp->content)->cost_tot > cost_tot)
		{
			cost_tot = ((t_content *)tmp->content)->cost_tot;
			cheapest = ((t_content *)tmp->content)->indx;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

void	move_a(t_dll **stack_a, t_dll **stack_b)
{
	int			cheapest;
	int			i;
	t_dll		*node;
	t_content	*ndcontent;
	t_dll		*tmp;

	cheapest = getcheapest(stack_a);
	i = -1;
	node = (*stack_a);
	tmp = (*stack_b);
	while (node)
	{
		ndcontent = node->content;
		if (ndcontent->indx != cheapest)
			node = node->next;
		if (ndcontent->indx == cheapest)
		{
			//get node in stack be that should be under the node we are moving
			while (tmp && ((t_content *)tmp->content)->nbr > ndcontent->nbr)
				tmp = tmp->next;
			movenodes(node, tmp);

			write(1, ">> ", 1);
			s_print(stack_a);

			push_b(stack_a, stack_b); //push to b
			break;
		}
	}
	
}
