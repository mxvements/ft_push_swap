/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:46 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/11 16:04:47 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	getnodecost(t_dll *node, int slen)
{
	t_content	*ndcontent;
	int			i;
	int			cost;
	//by movements
	int			sw = 0;
	int			ro = 0;
	int			rro = 0;

	ndcontent = node->content;
	i = ndcontent->indx;
	if (i == 0)
		cost = 0;
	else if (i <= (slen / 2))
	{
		ro = (i - 1);
		sw = 1;
	}
	else
		rro = slen - i;
	cost = ro + sw + rro;
	return (cost);
}

int	gettotalcost(t_dll *node)
{
	t_content	*content;
	int			indx;
	int			indx_out;
	int			cost_max;
	int			cost_tot;

	content = node->content;
	indx = content->indx;
	indx_out = content->indx_out;
	if (content->cost >= content->cost_out)
		cost_max = content->cost;
	else
		cost_max = content->cost_out;
	if ((indx <= (content->slen / 2) && indx_out <= (content->slen_out / 2))
		|| (indx > (content->slen / 2) && indx_out > (content->slen_out / 2)))
		cost_tot = cost_max + 1; //cost = the higher + push
	else
		cost_tot = content->cost + content->cost_out + 1;
	return (cost_tot);
}

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
void	getcost_a(t_dll **stack_a, t_dll **stack_b)
{
	t_dll		*tmp;
	t_dll		*node;
	t_content	*ndcontent;
	const int	slen_a = s_size(stack_a);
	const int	slen_b = s_size(stack_b);

	node = (*stack_a);
	while (node)
	{
		ndcontent = node->content;
		ndcontent->slen = slen_a;
		ndcontent->cost = getnodecost(node, slen_a);
		tmp = *stack_b;
		while (tmp && ((t_content *)tmp->content)->nbr > ndcontent->nbr)
			tmp = tmp->next;
		ndcontent->cost_out = slen_b;
		ndcontent->indx_out = ((t_content *)tmp->content)->indx;
		ndcontent->cost_out = getnodecost(tmp, slen_b);
		ndcontent->cost_tot = gettotalcost(node);
		node = node->next;
	}
}
