/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:22:40 by sengle            #+#    #+#             */
/*   Updated: 2019/07/28 17:14:57 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

/*
**	o----o\no----o\n\0
**	It is best to use a finite state machine to do the parsing. google and see:
**
**	https://yakking.branchable.com/posts/state-machines-in-c/
**
**	Or it could be parsed in the code logic
**
**	returns or-ed RUSH_[00..04] bits
*/

int	get_width(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	return (i);
}

int	get_legnth(char *buf)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			length++;
		i++;
	}
	return (length);
}

int	check_rush(char *buf, int width, int length. int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < RUSH_TYPES)
	{
		j = -1;
		while (++j < length)
		{
			if (j == 0)
				if (!check_first_line(buf + j * (width + 1), width))
					break ;
			else if (j == length - 1)
				if (!check_middle_line(buf + j * (width + 1), width))
					break ;
			else
				if (!check_last_line(buf + j * (width + 1), width))
					break ;
		}
		if (j == length)
			print_rush(i);
		if (j == length)
			count++;
	}
	return (count);
}

int	parse_rush(char *buf)
{
	int	width;
	int	length;
	int	count;

	count = 0;
	width = get_width(buf);
	length = get_length(buf);
	count = check_rush(buf, width, length, count);
	return (RUSH_02 | RUSH_03 | RUSH_04);
}
