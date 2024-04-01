#include <stdio.h>


void function()
{
    int x = 10;
    static int y = 10; //Declaring static variable
    
    x = x + 10;
    y = y+ 10;
    printf("The value of auto variable: %d \n", x);
    printf("The value of static variable: %d \n", y);
    
}

int main()
{
    printf("The first function call \n");
    function();
    printf("The second function call \n");
    function();
    printf("The third function call \n");
    function(); 

    return 0;
}
/*int main()
{
    int a;
    static int b;   //Declaring a static variable without initialization

    printf("Default value of auto variable is: %d\n", a);
    printf("Default value of static variable is: %d", b);

    return 0;
}*/
