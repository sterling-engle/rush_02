/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sengle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:26:53 by sengle            #+#    #+#             */
/*   Updated: 2019/07/27 22:40:28 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle-2.h"

#define	MAX_BUF	32768

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
