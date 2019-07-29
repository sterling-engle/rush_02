/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:22:40 by sengle            #+#    #+#             */
/*   Updated: 2019/07/28 19:37:03 by davigarc         ###   ########.fr       */
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

int	parse_rush(char *buf)
{
	return (RUSH_02 | RUSH_03 | RUSH_04);
}
