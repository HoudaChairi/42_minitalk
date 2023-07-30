/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:25:24 by hchairi           #+#    #+#             */
/*   Updated: 2023/05/30 17:30:30 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("message reçu");
}

void	checker_pid(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			exit(EXIT_FAILURE);
}

void	sender_b(char c, int pid)
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

int	main(int ac, char **av)
{
	int	server_pid;
	int	i;

	i = 0;
	signal(SIGUSR1, &handler);
	if (ac == 3)
	{
		checker_pid(av[1]);
		server_pid = ft_atoi(av[1]);
		if (server_pid == -1 || server_pid == 0)
			exit(EXIT_FAILURE);
		while (av[2][i])
			sender_b(av[2][i++], server_pid);
		sender_b(av[2][i], server_pid);
	}
	return (0);
}
