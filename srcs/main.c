/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:54:29 by dfinn             #+#    #+#             */
/*   Updated: 2023/08/13 17:27:25 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int len, t_stack **stack_a, t_stack **stack_b)
{
	if (has_double(*stack_a))
		print_error("Error", *stack_a, NULL);
	if (is_stack_sorted(*stack_a))
		return ;
	put_index(*stack_a);
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		sort_all(stack_a, stack_b);
}

int	ft_sort(t_stack *stack, t_stack *stackb, char * temp)
{
	char	**tab;

	tab = ft_split(temp, ' ');
	if (!tab)
		return (0);
	if (not_number(tab, 0))
		print_error("Error", NULL, tab);
	stack = create_stack(stack, 0, tab, tab);
	free_tab(tab);
	sort(get_stack_len(stack), &stack, &stackb);
	free_stack(stack);
	// system("leaks push_swap");
	exit(0);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*stackb;
	char	*temp[2];
	int		i;

	i = 1;
	stack = NULL;
	stackb = NULL;
	if (ac == 1)
		return (1);
	temp[1] = ft_strdup(av[1]);
	while (++i < ac)
	{
		temp[0] = ft_strjoin(temp[1], " ");
		if (!temp[0])
			return (0);
		temp[1] = ft_strjoin(temp[0], av[i]);
		if (!temp[1])
			return (0);
	}
	ft_sort(stack, stackb, temp[1]);
	return (0);
}
