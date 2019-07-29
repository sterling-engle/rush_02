/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:22:40 by sengle            #+#    #+#             */
/*   Updated: 2019/07/28 20:07:43 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"
#include <unistd.h>

int	get_width(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	return (i);
}

int	get_length(char *buf)
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
