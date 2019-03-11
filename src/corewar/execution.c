/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:06:58 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/06 15:46:09 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// debug
#include <stdio.h>

#include <stddef.h>
#include "corewar.h"

static void	do_op(t_process *process, t_vm *vm)
{
	uint8_t	op_code;

	op_code = vm->memory[process->program_counter];
	if (op_code > 0 && op_code < 17 && vm->op_table[op_code])
		vm->op_table[op_code](process, vm);
	else
		process->next_op++;
	return ;
}

void		launch(t_vm *vm)
{
	size_t	i;

	while (42)
	{
		//printf("cycle: %zu\n", vm->cycle);
		if (vm->cycle == 500)
			break ;
		i = 0;
		while (i < vm->nb_champs)
		{
			if (vm->process[i].next_op == vm->cycle)
				do_op(&vm->process[i], vm);
			vm->process[i++].program_counter %= MEM_SIZE;
		}
		vm->cycle++;
	}
}
