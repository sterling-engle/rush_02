/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:34:06 by sjiseong          #+#    #+#             */
/*   Updated: 2019/07/31 15:31:58 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

/*
** static char array variables for each rectangle style type symbol
** indexed by type parameter for pattern recognization code
*/
static char	g_vertical[RUSH_TYPES] = { '|', '*', 'B', 'B', 'B' };
static char	g_horizontal[RUSH_TYPES] = { '-', '*', 'B', 'B', 'B' };
static char	g_upper_left[RUSH_TYPES] = { 'o', '/', 'A', 'A', 'A' };
static char	g_lower_left[RUSH_TYPES] = { 'o', '\\', 'C', 'A', 'C' };
static char	g_upper_right[RUSH_TYPES] = { 'o', '\\', 'A', 'C', 'C' };
static char	g_lower_right[RUSH_TYPES] = { 'o', '/', 'C', 'C', 'A' };

/*
**	int	check_first_line(int rush_num, char *buf, int width)
**
**	Algorithm:
**
**	For rush number rush_num, scan the first line of the rush 00 box:
**
**	1. While column < box width
**		a.	if column is zero and upper left character doesn't match return 0.
**		b.	if last column upper right character doesn't match return 0.
**		c.	if horizontal character for that rush type doesn't match return 0.
**		d.	next column.
**	2.	if next column is not a newline or the null character, return 0.
**	3.	return 1 (first line matches for rush 00 type rush_num).
*/

int	check_first_line(int rush_num, char *buf, int width)
{
	int	col;

	col = 0;
	while (col < width)
	{
		if (col == 0)
		{
			if (buf[col] != g_upper_left[rush_num])
				return (0);
		}
		else if (col == width - 1)
		{
			if (buf[col] != g_upper_right[rush_num])
				return (0);
		}
		else
		{
			if (buf[col] != g_horizontal[rush_num])
				return (0);
		}
		col++;
	}
	if (buf[col] != '\n' && buf[col] != '\0')
		return (0);
	return (1);
}

/*
**	int	check_middle_line(int rush_num, char *buf, int width)
**
**	Algorithm:
**
**	For rush number rush_num, scan a middle line of the rush 00 box:
**
**	1. While column < box width
**		a.	if column is zero or the last column on the line and
**			the character does not match g_vertical[rush_num] return 0.
**		b.	else if the character is not a space (inside box) return 0.
**		c.	next column.
**	2.	if next column is not a newline or the null character, return 0.
**	3.	return 1 (middle line matches for rush 00 type rush_num).
*/

int	check_middle_line(int rush_num, char *buf, int width)
{
	int	col;

	col = 0;
	while (col < width)
	{
		if (col == 0 || col == width - 1)
		{
			if (buf[col] != g_vertical[rush_num])
				return (0);
		}
		else
		{
			if (buf[col] != ' ')
				return (0);
		}
		col++;
	}
	if (buf[col] != '\n')
		return (0);
	return (1);
}

/*
**	int	check_last_line(int rush_num, char *buf, int width)
**
**	Algorithm:
**
**	For rush number rush_num, scan the last line of the rush 00 box:
**
**	1. While column < box width
**		a.	if column is zero and lower left character doesn't match return 0.
**		b.	if last column lower right character doesn't match return 0.
**		c.	if horizontal character for that rush type doesn't match return 0.
**		d.	next column.
**	2.	if next column is not a newline return 0.
**	3.	return 1 (last line matches for rush 00 type rush_num).
*/

int	check_last_line(int rush_num, char *buf, int width)
{
	int	col;

	col = 0;
	while (col < width)
	{
		if (col == 0)
		{
			if (buf[col] != g_lower_left[rush_num])
				return (0);
		}
		else if (col == width - 1)
		{
			if (buf[col] != g_lower_right[rush_num])
				return (0);
		}
		else
		{
			if (buf[col] != g_horizontal[rush_num])
				return (0);
		}
		col++;
	}
	if (buf[col] != '\n')
		return (0);
	return (1);
}

/*
**	int	check_each_line(char *buf, int width, int length, int rush_type)
**
**	Algorithm:
**
**	For rush type rush_type, parse each line of box input to see if it matches
**
**	1. For each line in the box
**		a.	if line is zero, call check_first_line to test the pattern match.
**		b.	else if last line, call check_last_line to test the pattern match.
**		c.	else if the middle line doesn't match break out of while loop
**	2.	return number of matching lines until pattern did not match.
*/

int	check_each_line(char *buf, int width, int length, int rush_type)
{
	int	line;

	line = -1;
	while (++line < length)
	{
		if (line == 0)
		{
			if (!check_first_line(rush_type, buf + line * (width + 1), width))
				break ;
		}
		else if (line == length - 1)
		{
			if (!check_last_line(rush_type, buf + line * (width + 1), width))
				break ;
		}
		else
		{
			if (!check_middle_line(rush_type, buf + line * (width + 1), width))
				break ;
		}
	}
	return (line);
}

/*
**	int check_rush(char *buf, int width, int length, int count)
**
**	Local variables
**
**	int rush_type		0 through 4 rush box patterns
**	int	matched_lines	number of matched lines returned by check_each_line
**
**	Algorithm:
**
**	1. for each rush_type
**		a. check_each_line in buf with width x length for rush_type.
**		b. if matched_lines == length we have a matching rush type
**			i.  print out the matching rush type and dimensions.
**			ii. increment count of matched rush types.
**	2.	return count of matched rush types.
*/

int	check_rush(char *buf, int width, int length, int count)
{
	int	rush_type;
	int	matched_lines;

	rush_type = -1;
	while (++rush_type < RUSH_TYPES)
	{
		matched_lines = check_each_line(buf, width, length, rush_type);
		if (matched_lines == length)
		{
			print_rush(rush_type, width, length, count);
			count++;
		}
	}
	return (count);
}
