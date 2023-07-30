/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:28:31 by hchairi           #+#    #+#             */
/*   Updated: 2023/07/30 14:42:37 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int nb, int pow)
{
	int	res;

	res = 1;
	if (pow < 0 || nb < 0 || (nb == 0 && pow == 0))
		return (0);
	if (pow == 0)
		return (1);
	while (pow-- > 0)
		res = res * nb;
	return (res);
}

int	cnv_bin(int *tab)
{
	int	pow;
	int	res;
	int	i;

	pow = 7;
	res = 0;
	i = 0;
	while (pow >= 0)
		res += (tab[i++] * power(2, pow--));
	ft_printf("%c", (char)res);
	return (res);
}

void	reciever(int sig, siginfo_t *info, void *p)
{
	static int	tab[8];
	static int	pid_clt;
	static int	i;

	(void)*p;
	if (pid_clt != info->si_pid)
	{
		i = 0;
		pid_clt = info->si_pid;
	}
	if (sig == SIGUSR1)
		tab[i] = 0;
	else if (sig == SIGUSR2)
		tab[i] = 1;
	i++;
	if (i == 8)
	{
		i = 0;
		cnv_bin(tab);
	}
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &reciever;
	act.sa_flags = 0;
	ft_printf("server pid : %d\n", getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
