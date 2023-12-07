/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:37 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/02 18:37:38 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
void	a_evaluate(char *s)
{
	size_t	i;
	size_t	state;
	size_t	ostate;
	size_t	startnbr;
	int		nbr;

	i = 0;
	state = 0;
	while (s[i] != '\0')
	{
		ostate = a_changestate(s[i], state);
		if ((state == 0 || state == 4) && (ostate == 2 || ostate == 3))
			startnbr = i;
		if (state == 3 && (ostate == 4 || s[i + 1] == '\0'))
		{
			nbr = ft_atoi(ft_substr(s, startnbr, (i - startnbr + 1)));
			printf("%d\n", nbr); //ADD NODE
		}
		if (state == 1)
			printf("error\n");
		state = ostate;
		i++;
	}

}
int main(void)
{
	char *s = "4 67 -3 87 23"; //5 nbrss
	a_evaluate(s);

	return (0);
}