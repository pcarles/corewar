/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <jdouniol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:38:49 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/13 17:39:30 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "corewar.h"

static void	parse_flags(int ac, char **av, t_vm *vm)
{
	int		i;

	i = 1;
	while (i <= MAX_PLAYERS && i < ac)
	{
		vm->process[i - 1].file_path = av[i];
		vm->nb_champs = i++;
	}
}

int			main(int ac, char **av)
{
	t_vm	vm;

	if (ac < 1)
		return (EXIT_FAILURE);
	init_vm(&vm);
	parse_flags(ac, av, &vm);
	load_champs(&vm);
	vm.process[0].registers[0] = 0x124;
	vm.process[0].registers[1] = 0x024;
	//mem_dump(vm.memory, 4096);
	launch(&vm);
	reg_dump(&vm);
	mem_dump(vm.memory, 4096);
	return (EXIT_SUCCESS);
}