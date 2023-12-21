/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:51:49 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/19 19:51:53 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../libft/libft.h"

void	fisher_yates_shuffle(int arr[], int size)
{
	int	i;
	int	j;
	int	temp;

	i = size;
	while (--i > 0)
	{
		j = rand() % (i + 1);
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void	introduce_noise(int arr[], int size, int numShuffles)
{
	int	i;

	i = -1;
	while (++i < numShuffles)
		fisher_yates_shuffle(arr, size);
}

int	main(void)
{
	int	n;
	int	*unique_ints;
	int	i;
	int	num_shuffles;

	srand(time(NULL));
	ft_putstr_fd("Enter the value of N: ", 1);
	scanf("%d", &n);
	unique_ints = malloc(n * sizeof(int));
	i = -1;
	while (++i < n)
		unique_ints[i] = i;
	fisher_yates_shuffle(unique_ints, n);
	num_shuffles = 10;
	introduce_noise(unique_ints, n, num_shuffles);
	ft_putstr_fd("Randomized Unique Integers: ", 1);
	i = -1;
	while (++i < n)
	{
		ft_putstr_fd(ft_itoa(unique_ints[i]), 1);
		ft_putstr_fd(" ", 1);
	}
	ft_putstr_fd("\n", 1);
	free(unique_ints);
	return (0);
}
