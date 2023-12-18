/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:37 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 23:15:43 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(void)
{
	t_dll	**stack_a;
	t_dll	**stack_b;

	/*
	100nbr -> 700movs
	500nbr -> 5500mvs
	*/

	/*if (argc != 2)
		return (0);*/
	//char *s = "1 7 2 12 590 3 4 571 15 6 981";
	char *s = "1 7 2 12 590 3 4 571 15 6 981 21 14 98 9 684 ";
	//char *s = "1 7 2 12 590 3 4 571 15 6 981 21 14 98 9 684 242 903 324 167 ";
	//char *s = "242 903 324 98 571 981 684 742 805 530 274 311 430 857 328 384 897 420 96 19 792 85 745 40 234 659 673 779 11 335 557 817 81 466 424 152 958 253 438 356 820 633 696 317 714 4 1000 793 589 780 706 640 861 449 366 201 975 148 558 757 232 946 821 325 670 725 834 164 616 609 750 291 843 976 35 309 880 772 61 913 488 10 412 146 212 678 737 129 980 724 471 611 207 37 982 900 801 472 353 535 365";
	//char *s = "242 903 590 324 98 571 167 981 684 742 805 530 274 762 311 430 857 328 384 897 420 96 19 792 85 40"; //25numbr

	
	stack_a = s_inithead();
	stack_b = s_inithead();
	//si uno si y el otro no qué..
	
	stack_a = a_parse(s, stack_a);
	
	//sort
	if (stack_a && stack_b)
	{
		sort(stack_a, stack_b);	

		write(1, "-fin-\n", 6);
		system("leaks -q push_swap");
		
		//check stack_b
		printf("size b: %d\n", s_size(stack_b));
		s_print(stack_b);
		//check stack_a
		printf("size a: %d\n", s_size(stack_a));
		s_print(stack_a);
		
		if (!stack_a || !(*stack_a))
			printf("stack vacio\n");
		if (s_issorted(stack_a) == 0)
		{
			printf("stack ordenado\n");
			s_free(stack_a);
		}
	}

	return (0);
}
