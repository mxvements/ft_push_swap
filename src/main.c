/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:37 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 23:15:43 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(char *s, t_dll **stack_a, t_dll **stack_b)
{
	if (stack_a && stack_b)
	{
		stack_a = a_parse(s, stack_a);
		if (!stack_a)
		{
			s_free(stack_b);
			return ;
		}
		if (*stack_a && s_issorted(stack_a) != 0)
			sort(stack_a, stack_b);
	}
	if (stack_a || stack_b)
	{
		s_free(stack_a);
		s_free(stack_b);
	}
}

void	push_swap_wrapper(char *s)
{
	t_dll	**stack_a;
	t_dll	**stack_b;

	if (*s == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	stack_a = s_inithead();
	stack_b = s_inithead();
	if (!stack_a || !stack_b)
	{
		ft_putstr_fd("Error\n", 2);
		s_free(stack_a);
		s_free(stack_b);
		return ;
	}
	return (push_swap(s, stack_a, stack_b));
}

char	*strargs(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*s;

	i = 1;
	s = "";
	while (i < argc)
	{
		tmp = ft_strjoin(s, argv[i]);
		if (i != 1)
			free(s);
		s = tmp;
		tmp = ft_strjoin(s, " ");
		free(s);
		s = tmp;
		i++;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*s;

	i = 1;
	if (argc == 2)
		push_swap_wrapper(argv[i]);
	else if (argc > 2)
	{
		s = strargs(argc, argv);
		push_swap_wrapper(s);
		free(s);
	}
	/*else
		ft_putstr_fd("Error\n", 2);*/
	return (0);
}
