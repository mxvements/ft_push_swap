/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
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
	size_t		i;
	int			cost;
	//by movements
	int			sw = 0;
	int			ro = 0;
	int			rro = 0;

	ndcontent = node->content;
	i = ndcontent->indx;
	if (i == 0)
		cost = 0;
	if (i <= (slen / 2))
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
	int			sw = 0;
	int			ro = 0;
	int			rro = 0;
	//cost_tot = cost + cost_ot (menos los movimiento dobles)

	content = node->content;
	//reverse engineer from the total cost, the cost of each node
	//this is to take into account the double moves
	if (content->indx <= (content->slen / 2) && content->indx_out <= (content->slen_out / 2))
		//cost == the hihger + push
	else if (content->indx < (content->slen / 2) && content->indx_out < (content->slen_out / 2))
		//cost = the higher + push
	else
		//the sum of boths, they need different moves, +1 (push)

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
		//(2) it order to push it to b, we need to push it after the larger num
		tmp = *stack_b;
		//find the node in stack_b that should be after the current node i st_a
		while (tmp && ((t_content *)tmp->content)->nbr > ndcontent->nbr)
			tmp = tmp->next;
		ndcontent->cost_out = slen_b;
		ndcontent->indx_out = ((t_content *)tmp->content)->indx;
		ndcontent->cost_out = getnodecost(tmp, slen_b);
	}
}
