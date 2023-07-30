/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:32:15 by hchairi           #+#    #+#             */
/*   Updated: 2023/02/08 19:13:56 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	checker_pid(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		checker_pid(av[1]);
		server_pid = ft_atoi(av[1]);
		if (server_pid == -1 || server_pid == 0)
			exit(EXIT_FAILURE);
		while (av[2][i])
			sender(av[2][i++], server_pid);
	}
	return (0);
}
