#include <unistd.h>
int    main(int ac, char **av)
{
        int    i;
        int    s;
        int    e;       i = 0;
        s = 0;
        e = 0;
        if (ac > 1)
        {
                while (av[1][i] < 33)
                        i++;
                s = i;
                while (av[1][i] > 32)
                        i++;
                e = i;
                while (av[1][i] && av[1][i] < 33) // added another condition
                        i++;
                if (av[1][i])
                {
                        while(av[1][i])
                        {
                                if (av[1][i] < 33)
                        {
                                        while (av[1][i] < 33)
                                                i++;
                                        write(1, " ", 1);
                                }
                                write(1, &av[1][i], 1);
                                i++;
                        }
                        i = s;
                        write(1, " ", 1);
                }
                //write(1, " ", 1); // move up
		i = s; // set i = s as the previous if is not entered
                while (i < e)
                        write(1, &av[1][i++], 1);
        }
        write(1, "\n", 1);
        return (0);
}
/*
#include <unistd.h>
int     main(int ac, char **av)
{
        int     i;
        int     s;
        int     e;
        i = 0;
        s = 0;
        e = 0;
        if (ac > 1)
        {
                while (av[1][i] && av[1][i] < 33)
                        i++;
                s = i;
                while (av[1][i] && av[1][i] > 32)
                        i++;
                e = i;
                while (av[1][i] && av[1][i] < 33)
                        i++;
                if (av[1][i])
                {
                        while(av[1][i])
                        {
                                if (av[1][i] && av[1][i] < 33)
                        {
                                        while (av[1][i] < 33)
                                                i++;
                                        write(1, " ", 1);
                                }
                                write(1, &av[1][i], 1);
                                i++;
                        }
                        i = s;
                }
                write(1, " ", 1);
                while (i < e)
                        write(1, &av[1][i++], 1);
        }
        write(1, "\n", 1);
        return (0);
}
*/
