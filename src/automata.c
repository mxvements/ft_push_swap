/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:34:26 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/08 13:34:27 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_dll	**evalerror(t_dll **stack)
{
	s_free(stack);
	stack = NULL;
	printf("Error\n");
	return (stack);
}

t_dll	**evalnewnode(t_dll **stack_a, const char *s)
{
	t_dll		*node;
	t_content	*content;
	int			nbr;
	int			flag;

	flag = 0;
	nbr = ft_atoif(s, &flag);
	if (flag < 0)
		return (evalerror(stack_a));
	content = (t_content *)malloc(sizeof(t_content));
	if (!content)
		return (evalerror(stack_a));
	//function to initcontent?
	content->nbr = nbr;
	node = ft_dllnew((void *)(content));
	if (s_isnodedup(stack_a, node) == 1)
	{
		s_freenode(node);
		return (evalerror(stack_a));
	}
	ft_dlladd_back(stack_a, node);
	return (stack_a);
}

/**
 * @brief 
 * states array:
 * 	 0, 1, 2, 3
 * 	/s, -+, D, ^ 
  	{0, 2, 3, 1},	0 INIT 
  	{1, 1, 1, 1},	1 ERR
  	{1, 1, 3, 1},	2 NEGSIGN		'-''+'
  	{4, 1, 3, 1},	3 DIGIT			'Digit'
 * 	{1, 2, 3, 1},	4 SPACE AFTER	'\s'
 * @param i, int, state from which we are moving (row)
 * @param j, int state into which we move to (col)
 * @return size_t, result state
 */
size_t	a_getstate(int i, int j)
{
	const size_t	t_states[][5] = {\
		{0, 2, 3, 1}, \
		{1, 1, 1, 1}, \
		{1, 1, 3, 1}, \
		{4, 1, 3, 1}, \
		{1, 2, 3, 1} \
	};

	return (t_states[i][j]);
}

size_t	a_changestate(char c, size_t state)
{
	size_t	ostate;

	if (c == ' ')
		ostate = a_getstate(state, 0);
	else if (ft_issign(c) != 0)
		ostate = a_getstate(state, 1);
	else if (ft_isdigit(c) != 0)
		ostate = a_getstate(state, 2);
	else
		ostate = a_getstate(state, 3);
	return (ostate);
}

t_dll	**a_evaluate(char *s, t_dll **stack_a)
{
	size_t	i;
	size_t	state;
	size_t	ostate;
	size_t	startnbr;

	i = 0;
	state = 0;
	while (s[i] != '\0')
	{
		ostate = a_changestate(s[i], state);
		if ((state == 0 || state == 4) && (ostate == 2 || ostate == 3))
			startnbr = i;
		if ((state == 3 && ostate == 4) || (state == 4 && s[i + 1] == '\0'))
		{
			stack_a = evalnewnode(stack_a, (s + startnbr));
			if (!stack_a)
				return (NULL);
		}
		if (ostate == 1)
			return (evalerror(stack_a));
		state = ostate;
		i++;
	}
	return (stack_a);
}
