/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:22:40 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 14:49:25 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"
#include <unistd.h>

/*
**	int	get_width(char *buf)
**
**	uses local variable width to accumulate the width of buffer buf
**	just like ft_strlen(3) does
**
*/

int	get_width(char *buf)
{
	int	width;

	width = 0;
	while (buf[width] != '\n' && buf[width] != '\0')
		width++;
	return (width);
}

/*
**	int	get_length(char *buf)
**
**	uses local variable length to accumulate the number of lines in buffer buf
**	by counting the number of newlines seen.
**
*/

int	get_length(char *buf)
{
	int	offset;
	int	length;

	offset = 0;
	length = 0;
	while (buf[offset])
	{
		if (buf[offset] == '\n')
			length++;
		offset++;
	}
	if (length > 0)
		return (length);
	else
		return (0);
}

/*
**	int	parse_rush(char *buf)
**
**	Local variables:
**
**	int width	rush box width
**	int length	rush box length
**	int count	number of rush box types, 0 = aucune (none in Francais)
**
**	Algorithm:
**
**	1.	get buffer width. (rush box width)
**	2.	get buffer length. (rush box length or height)
**	3.	call check_rush(buf, width, length, count) which returns the number
**		of rush box types represented by the given box design.
*/

int	parse_rush(char *buf)
{
	int	width;
	int	length;
	int	count;

	count = 0;
	width = get_width(buf);
	length = get_length(buf);
	count = check_rush(buf, width, length, count);
	if (count == 0)
		write(1, "aucune", 6);
	write(1, "\n", 1);
	return (0);
}
