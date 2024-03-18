/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:44:54 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/17 18:58:55 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	
}

/*
** This a vanilla question for interviews :
** Write a function that determines if a given number is a power of 2.
** This function returns 1 if the given number is a power of 2, otherwise it returns 0.
** Your function must be declared as follows:
** int	    is_power_of_2(unsigned int n);
*/

#include "bitwise.h"

/*
** first the basic function
*/

int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) // or alternatively (!(n % 2))
		n /= 2;
	return ((n == 1) ? 1 : 0); // equivalent to : if (n == 1) return 1; else return (0);
}

/*
** Now the bitwise version :
** we apply n - 1 mask to n, and then check that is equal to 0
** it will be true for all numbers that are power of 2.
** Lastly we make sure that n is superior to 0.
*/

int		is_power_of_2(unsigned int n)
{
    return (n > 0 && !(n & (n - 1)));
}

- If `n` is a power of 2, it has a single bit set to 1, and `n - 1` will have all bits set to 1 up to the position of the bit in `n`. The bitwise AND of `n` and `n - 1` will be 0, because there are no positions where both `n` and `n - 1` have a bit set to 1.
- If `n` is not a power of 2, it will have more than one bit set to 1, and `n - 1` will have all bits set to 1 up to the position of the rightmost bit in `n`. The bitwise AND of `n` and `n - 1` will not be 0, because there will be at least one position where both `n` and `n - 1` have a bit set to 1.

If the bitwise AND of `n` and `n - 1` is 0, it means that `n` is a power of 2. This is because powers of 2 have a unique property in binary representation: they have exactly one bit set to 1, and all other bits set to 0. When you subtract 1 from a power of 2, you flip all the bits after the rightmost 1 bit to 1. This results in a number where all bits are set to 1, except for the rightmost bit, which remains 0.

For example, let's consider the number 4, which is 2^2. In binary, 4 is represented as `100`. When you subtract 1 from 4, you get `011`. The bitwise AND operation between `100` (4) and `011` (3) results in `000`, which is 0. This is because there are no positions where both `100` and `011` have a bit set to 1.

This property is used to efficiently check if a number is a power of 2. The expression `n & (n - 1)` checks if the result of the bitwise AND operation is 0. If it is, it means that `n` is a power of 2 because the only way for the result to be 0 is if `n` has exactly one bit set to 1, and all other bits are 0. This method is very efficient because it performs the check in constant time, regardless of the size of `n` [1][2][3].

Citations:
[1] https://www.geeksforgeeks.org/bitwise-and-operator-in-programming/
[2] https://www.programiz.com/c-programming/bitwise-operators
[3] https://dev.to/stephengade/mastering-bitwise-operations-a-simplified-guide-2031
[4] https://www.geeksforgeeks.org/complete-reference-for-bitwise-operators-in-programming-coding/
[5] https://en.wikipedia.org/wiki/Bitwise_operation
[6] https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
[7] https://en.wikipedia.org/wiki/Bitwise_operations_in_C
[8] https://eng.libretexts.org/Courses/Delta_College/C___Programming_I_(McClanahan)/04%3A_Data_and_Operators/4.13%3A_Bitwise_Operators
[9] https://medium.com/swlh/an-illustrated-guide-to-bitwise-operators-60b1b1ad5ac
[10] https://www.theserverside.com/definition/bitwise-operator
[11] https://betterprogramming.pub/master-bitwise-operations-in-10-minutes-7842c65608d7
[12] https://www.codecademy.com/resources/docs/general/bitwise-operator
[13] https://www.programiz.com/java-programming/bitwise-operators
[14] https://www.programiz.com/cpp-programming/bitwise-operators
[15] https://www.codewithc.com/bitwise-operations-explained-in-c-programming/
/*
** Test program
*/

int	main(int ac, char **av)
{
	if (ac == 2)
    {
        printf("%s is power of 2 ?");
        is_power_of_2(atoi(av[1])) ? printf("Yes\n") : printf("No\n");
    }
    return (0);
}


int     ft_is_prime(int nb)
{
        int     i;

        i = 2;
        if (nb <= 1)
                return (0);
        while (i <= nb / i)
        {
                if (nb % i == 0)
                        return (0);
                i++;
        }
        return (1);
}

