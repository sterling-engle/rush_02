/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 23:54:53 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 14:59:10 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

/*
**	int	check_negative(int nb, char *arr)
**
**	handles the special case of not being able to represent
**	-(-2,147,483,648) as a positive 32-bit integer, since the
**	largest positive int is 2,147,483,647.
*/

int		check_negative(int nb, char *arr)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			arr[0] = '8';
			nb /= 10;
		}
		return (-nb);
	}
	return (nb);
}

/*
**	void	ft_putnbr(int nb)
**
**	handles the special case of not being able to represent
**	-(-2,147,483,648) as a positive 32-bit integer, since the
**	largest positive int is 2,147,483,647.
*/

void	ft_putnbr(int nb)
{
	char	arr[10];
	int		i;

	i = 0;
	nb = check_negative(nb, arr);
	if (arr[0] == '8' && nb == 214748364)
		i++;
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (nb != 0)
	{
		arr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		ft_putchar(arr[i - 1]);
		i--;
	}
	return ;
}

/*
**	void print_rush(int rush_type, int width, int length, int count)
**
**	writes out the rush type and box dimensions per our assignment
*/

void	print_rush(int rush_type, int width, int length, int count)
{
	if (count > 0)
		write(1, " || ", 4);
	write(1, "[rush-0", 7);
	ft_putnbr(rush_type);
	write(1, "] [", 3);
	ft_putnbr(width);
	write(1, "] [", 3);
	ft_putnbr(length);
	write(1, "]", 1);
}
