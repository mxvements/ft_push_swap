/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:37 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/07 16:39:58 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_dllprint(t_dll **head)
{
	t_dll	*tmp = *head;
	int		*tmpnbr;
	while(tmp != NULL)
	{
		tmpnbr = (int *)(tmp->content);
		printf("mem: %p\n", tmp);
		printf("content: %d\n", *tmpnbr);
		tmp = tmp->prev;
	}
}

t_dll	**getnode(t_dll **stack_a, char *s)
{
	int		nbr;
	t_dll 	*node;
	
	nbr = ft_atoi(s);
	free(s);
	
	printf("%d\n", nbr);
	node = ft_dllnew((void *)ft_intdup(nbr));
	if (*stack_a == NULL)
		*stack_a = node;
	else
		ft_dlladd_front(stack_a, node);
	/* 
	* no sé muy bien como continuar..
	*/
return (stack_a);
}

size_t	a_getstate(int i, int j)
{
	//i -> state from which were moving
	//j -> state into which we move to
	size_t	t_states[][5] =
	{
		//  0, 1, 2, 3
		//\s, - , D, ^ 
		{0, 2, 3, 1},	//0 INIT, empty input
		{1, 1, 1, 1},	//1 ERR, invalid char
		{1, 1, 3, 1},	//2 NEGSIGN
		{4, 1, 3, 1},	//3 DIGIT
		{1, 2, 3, 1},	//4 SPACE AFTER
	};
	return (t_states[i][j]);
}

size_t	a_changestate(char c, size_t state)
{
	size_t	ostate;

	if (c == ' ')
		ostate = a_getstate(state, 0);
	else if (c == '-')
		ostate = a_getstate(state, 1);
	else if (isdigit(c) != 0) //ft_isdigit()
		ostate = a_getstate(state, 2);
	else
		ostate = a_getstate(state, 4);
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
		if (state == 3 && (ostate == 4 || s[i + 1] == '\0'))
		{
			stack_a = getnode(stack_a, ft_substr(s, startnbr, (i - startnbr + 1)));
		}
		if (state == 1)
			printf("error\n");
		state = ostate;
		i++;
	}
	return (stack_a);
}

int main(void)
{
	char *s = "4 67 -3 87 23"; //5 nbrss
	t_dll	**stack_a;
	
	stack_a = (t_dll **)malloc(sizeof(t_dll *));
	if (!stack_a)
		return (0);
	stack_a = a_evaluate(s, stack_a);
	printf("%d\n", ft_dllsize(*stack_a));
	ft_dllprint(stack_a);

	return (0);
}
