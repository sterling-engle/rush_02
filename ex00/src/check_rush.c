/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:34:06 by sjiseong          #+#    #+#             */
/*   Updated: 2019/07/28 19:58:25 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

int	check_first_line(int rush_num, char *buf, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
		{
			if (buf[i] != g_upper_left[rush_num])
				return (0);
		}
		else if (i == width - 1)
		{
			if (buf[i] != g_upper_right[rush_num])
				return (0);
		}
		else
		{
			if (buf[i] != g_horizontal[rush_num])
				return (0);
		}
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	return (1);
}

int	check_middle_line(int rush_num, char *buf, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0 || i == width - 1)
		{
			if (buf[i] != g_vertical[rush_num])
				return (0);
		}
		else
		{
			if (buf[i] != ' ')
				return (0);
		}
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	return (1);
}

int	check_last_line(int rush_num, char *buf, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
		{
			if (buf[i] != g_lower_left[rush_num])
				return (0);
		}
		else if (i == width - 1)
		{
			if (buf[i] != g_lower_right[rush_num])
				return (0);
		}
		else
		{
			if (buf[i] != g_horizontal[rush_num])
				return (0);
		}
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	return (1);
}

int	check_rush(char *buf, int width, int length, int count)
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
			{
				if (!check_first_line(i, buf + j * (width + 1), width))
					break ;
			}
			else if (j == length - 1)
			{
				if (!check_last_line(i, buf + j * (width + 1), width))
					break ;
			}
			else
			{
				if (!check_middle_line(i, buf + j * (width + 1), width))
					break ;
			}
		}
		if (j == length)
		{
			print_rush(i, width, length, count);
			count++;
		}
	}
	return (count);
}
