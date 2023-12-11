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

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
void	getcost(t_dll	**stack_a)
{
	t_dll		*node;
	t_content	*nodecont;
	const int	s_len = s_size(stack_a);
	//(1) lets count the cost for the number to be at the top of a
	int			sa = 0;
	int			ra = 0;
	int			rra = 0;
	int			cost_a; //sa + ra + rra

	node = (*stack_a);
	while (node)
	{
		nodecont = node->content;
		//we need to update content->cost for each node in this stack..
		//(1) cost to be at the top of a
		if (nodecont->indx == 0)
			cost_a = 0;
		if (nodecont->indx < (s_len / 2))
		{
			ra = (nodecont->indx - 1); //while indx > 1, indx--
			sa = 1;
		}
		else
		{
			rra = s_len - nodecont->indx;
		}
		cost_a = ra + sa + rra;
		//(2) it order to push it to b, we need to push it after the larger num
	}
}