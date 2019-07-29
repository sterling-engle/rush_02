/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:33:22 by davigarc          #+#    #+#             */
/*   Updated: 2019/07/28 19:36:04 by davigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle-2.h"

#define MAX_BUF	32768

int	main(int argc, char **argv)
{
	int		buf_size;
	char	*buf[MAX_BUF];

	buf = malloc(MAX_BUF);
	buf_size = read(0, &buf, MAX_BUF);
	if (buf_size > 0)
	{
		parse_rush(buf);
		free(buf);
	}
	return (0);
}
