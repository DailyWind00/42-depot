/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:01:44 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/22 14:07:31 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define SLEEP 200

# include <signal.h>
# include <sys/types.h>
# include "libft.h"

void	get_int(int signum, int *value);
void	str_alloc(int str_size, int client_pid);
void	next_byte(int *i, int *count, int *c);
void	write_str_reset(int *count, int *i, int *client_pid, int *str_size);

#endif
