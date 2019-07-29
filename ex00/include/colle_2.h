/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:40:55 by sengle            #+#    #+#             */
/*   Updated: 2019/07/28 21:55:45 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_2_H
# define COLLE_2_H

/*
** Rush 02
**
** sengle's group:
**
** sengle, sjiseong, davigarc
**
** macro definitions for rectangle types, min & max, and top & bottom sides
*/
# define RUSH_TYPES 5

int	check_rush(char *buf, int width, int length, int count);
int	parse_rush(char *buf);
void	print_rush(int rush_type, int width, int length, int count);

#endif
