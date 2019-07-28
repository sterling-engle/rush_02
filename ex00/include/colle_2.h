/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:40:55 by sengle            #+#    #+#             */
/*   Updated: 2019/07/27 23:15:06 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef COLLE_2_H
# define COLLE_2_H

/*
** Rush 02
**
** sengle's group:
**
** Sterling Engle (sengle), 
*/

/*
** macro definitions for rectangle types, min & max, and top & bottom sides
*/
#define RUSH_TYPES 5
#define RUSH_TYPE_00 0
#define RUSH_TYPE_01 1
#define RUSH_TYPE_02 2
#define RUSH_TYPE_03 3
#define RUSH_TYPE_04 4
#define RUSH_MIN RUSH_TYPE_00
#define RUSH_MAX RUSH_TYPE_04
#define RECT_TOP 1
#define RECT_BOTTOM 2

#define RUSH_00	0x0001
#define	RUSH_01	0x0002
#define	RUSH_02	0x0004
#define	RUSH_03	0x0008
#define	RUSH_04	0x0010

typedef struct		s_rush_type
{
	char	upper_left;
	char	upper_right;
	char	lower_left;
	char	lower_right;
	char	horizontal;
	char	vertical;
	int		type;
}					t_rush_type;

/*
** static char array variables for each rectangle style type symbol
** indexed by type parameter
*/
/*
static char	g_vertical[NUM_TYPES] = { '|', '*', 'B', 'B', 'B' };
static char	g_horizontal[NUM_TYPES] = { '-', '*', 'B', 'B', 'B' };
static char	g_upper_left[NUM_TYPES] = { 'o', '/', 'A', 'A', 'A' };
static char	g_upper_left[NUM_TYPES][NUM_TYPES] = { 'o', 
	'/', 'A', 'A', 'A' };
static char	g_lower_left[NUM_TYPES] = { 'o', '\\', 'C', 'A', 'C' };
static char	g_upper_right[NUM_TYPES] = { 'o', '\\', 'A', 'C', 'C' };
static char	g_lower_right[NUM_TYPES] = { 'o', '/', 'C', 'C', 'A' };


'o', RUSH_OO
'/', RUSH_01
'A', RUSH_02 | RUSH_03 | RUSH_04		1 x 1  'A'

rush_size()

eat characters across the row ('B'
*/

#endif
