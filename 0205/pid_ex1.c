/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_ex1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:27:08 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/02 11:27:21 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    printf("PID = %d\n", (int)getpid());

    int x = 10;
    int y = 10;

    int pid = fork();
    if (pid != 0)
    {
       x++;
       y--;
    }
    printf("1: x = %i y = %i (PID %d, PPID %d)\n",
           x, y, (int)getpid(), (int)getppid());

    pid = fork();
    if (pid != 0)
    {
       x++;
       y--;
    }
    printf("2: x = %i y = %i (PID %d, PPID %d)\n",
           x, y, (int)getpid(), (int)getppid());

    int status;
    int corpse;
    while ((corpse = wait(&status)) > 0)
    {
        printf("%d: child %d exited with status 0x%.4X\n",
               (int)getpid(), corpse, status);
    }

    return (getpid() % 16);
}
