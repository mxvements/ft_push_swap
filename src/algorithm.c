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

void	movenodes(t_dll *node, t_dll **stack_a, t_dll **stack_b)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = node->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	if (moves_self == 0 && moves_out == 0)
		return ;
	//indexes at the same range
	else if ((int)cont->indx <= (cont->slen / 2)
		&& (int)cont->indx_out <= (cont->slen_out / 2))
	{
		while (moves_self > 0 && moves_out > 0)
		{
			//need to bring stacks
			drot(stack_a, stack_b);
			moves_self--;
			moves_out--;
		}
		while (moves_self == 0 && moves_out > 0)
		{
			rot(stack_b, 'b');
			moves_out--;
		}
		while (moves_out == 0 && moves_self > 0)
		{
			rot(stack_a, 'a');
			moves_self--;
		}
	}
	else if ((int)cont->indx > (cont->slen / 2)
		&& (int)cont->indx_out > (cont->slen_out / 2))
	{
		while (moves_self > 0 && moves_out > 0)
		{
			drvrot(stack_a, stack_b);
			moves_self--;
			moves_out--;
		}
		while (moves_self == 0 && moves_out > 0)
		{
			rvrot(stack_b, 'b');
			moves_out--;
		}
		while (moves_self > 0 && moves_out == 0)
		{
			rvrot(stack_a, 'a');
			moves_self--;
		}
	}
	//indexes at different ranges
	else if ((int)cont->indx <= (cont->slen / 2)
		&& (int)cont->indx_out > (cont->slen_out / 2))
	{
		while (moves_self > 0)
		{
			rot(stack_a, 'a');
			moves_self--;
		}
		while (moves_out > 0)
		{
			rvrot(stack_b, 'b');
			moves_out--;
		}
	}
	else if ((int)cont->indx > (cont->slen / 2)
		&& (int)cont->indx_out <= (cont->slen_out / 2))
	{
		while (moves_out > 0)
		{
			rot(stack_b, 'b');
			moves_out--;
		}
		while (moves_self > 0)
		{
			rvrot(stack_a, 'a');
			moves_self--;
		}
	}
}

int		getcheapest(t_dll **stack_a)
{
	t_dll	*tmp;
	int		cheapest_idx;
	int		cheapest_cost;

	tmp = (*stack_a);
	cheapest_cost = ((t_content *)tmp->content)->cost_tot;
	cheapest_idx = ((t_content *)tmp->content)->indx;
	while (tmp)
	{
		if (((t_content *)tmp->content)->cost_tot > cheapest_cost)
			return (cheapest_idx);
		if (((t_content *)tmp->content)->cost_tot < cheapest_cost)
		{
			cheapest_cost = ((t_content *)tmp->content)->cost_tot;
			cheapest_idx = ((t_content *)tmp->content)->indx;
		}
		tmp = tmp->next;
	}
	return (cheapest_idx);
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
		if ((int)(ndcontent->indx) != cheapest)
			node = node->next;
		if ((int)(ndcontent->indx) == cheapest)
		{
			/*
			//check stack_b
			printf("size b: %d\n", s_size(stack_b));
			s_print(stack_b);
			//check stack_a
			printf("size a: %d\n", s_size(stack_a));
			s_print(stack_a);
			write(1, "\n", 1);*/


			
			movenodes(node, stack_a, stack_b);
			push_b(stack_a, stack_b); //push to b
			break;
		}
	}
	
}
