/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:02:59 by pcarles           #+#    #+#             */
/*   Updated: 2019/01/15 14:07:53 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>
# include "op.h"

typedef struct	s_instruction
{
	uint8_t		buffer[14];
	size_t		size;
}				t_instruction;

int				parse_line(char *line, t_header *header, t_label **label_listp);

#endif