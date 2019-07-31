/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:40:55 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 13:38:12 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_2_H
# define COLLE_2_H

/*
** Rush 02
**
** sengle's group: Son Jiseong, Sterling Engle and David Garces
**
** sengle, sjiseong, davigarc
**
** macro definitions for number of rectangle types, and public functions
*/
# define RUSH_TYPES 5

int			check_rush(char *buf, int width, int length, int count);
int			parse_rush(char *buf);
void		print_rush(int rush_type, int width, int length, int count);

#endif
