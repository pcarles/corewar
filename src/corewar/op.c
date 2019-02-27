/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:21:51 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/27 16:08:04 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//WIP

void		live(t_process *process, t_vm *vm)
{
	uint32_t	*arg;

	arg = (uint32_t*)vm->memory[++process->program_counter];
	if (*arg <= MAX_PLAYERS && *arg > 1)
		vm->process[(*arg) - 1].live_counter++;
	process->program_counter += 4;;
	process->next_op = vm->cycle + 10;
}

void		ld(t_process *process, t_vm *vm)
{
	process->next_op = vm->cycle + 5;
}