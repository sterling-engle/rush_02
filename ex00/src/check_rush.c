/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:34:06 by sjiseong          #+#    #+#             */
/*   Updated: 2019/07/28 21:58:19 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

/*
** static char array variables for each rectangle style type symbol
** indexed by type parameter
*/
static char	g_vertical[RUSH_TYPES] = { '|', '*', 'B', 'B', 'B' };
static char	g_horizontal[RUSH_TYPES] = { '-', '*', 'B', 'B', 'B' };
static char	g_upper_left[RUSH_TYPES] = { 'o', '/', 'A', 'A', 'A' };
static char	g_lower_left[RUSH_TYPES] = { 'o', '\\', 'C', 'A', 'C' };
static char	g_upper_right[RUSH_TYPES] = { 'o', '\\', 'A', 'C', 'C' };
static char	g_lower_right[RUSH_TYPES] = { 'o', '/', 'C', 'C', 'A' };

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
	if (buf[i] != '\n' && buf[i] != '\0')
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

int	check_each_line(char *buf, int width, int length, int i)
{
	int	j;

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
	return (j);
}

int	check_rush(char *buf, int width, int length, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < RUSH_TYPES)
	{
		j = check_each_line(buf, width, length, i);
		if (j == length)
		{
			print_rush(i, width, length, count);
			count++;
		}
	}
	return (count);
}
