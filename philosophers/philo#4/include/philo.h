/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:30:22 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/06 14:34:10 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <thread_db.h>
# include <stdbool.h>
# include <sys/time.h>

# define CORRECT_SYNTAX "Correct syntax :\n\t./philo <number_of_philosophers>\
 <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n\
If confusion, check subject -> Global Rules\n"

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	size_t				last_meal;
	int					time_eaten;
	int					id;
}	t_philo;

typedef struct s_data
{
	t_philo				*philos;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_meals;
	bool				someone_ded;
	size_t				start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		writing;
	pthread_mutex_t		dying;
}	t_data;

void			error_exit(t_data *data, char *strerror);
void			init(t_data *data, int argc, char **argv);
void			*routine(void *philo);
void			*god_routine(t_data *data);
size_t			get_time(void);
void			ft_usleep(size_t time);
bool			starving(t_philo *philo);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			philos_printf(t_philo *philo, char *str, bool death_message);
void			free_data(t_data *data);

#endif