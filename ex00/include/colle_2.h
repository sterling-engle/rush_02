/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:40:55 by sengle            #+#    #+#             */
/*   Updated: 2019/07/28 21:43:24 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_2_H
# define COLLE_2_H

/*
** Rush 02
**
** sengle's group:
**
** Sterling Engle (sengle),
** macro definitions for rectangle types, min & max, and top & bottom sides
*/
# define RUSH_TYPES 5

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

int			check_rush(char *buf, int width, int length, int count);
int			parse_rush(char *buf);
void		print_rush(int rush_type, int width, int length, int count);

#endif
