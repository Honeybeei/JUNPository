#include "test.h"

int main(void)
{
    int c0;

    char *main_menu_str[] = {"", 
    "isalpha", 
    "isdigit", 
    "isalnum", 
    "isascii", 
    "isprint", 
    "strlen", 
    "memset", 
    "bzero", 
    "memcpy", 
    "memmove", 
    "strlcpy", 
    "strlcat", 
    "toupper", 
    "tolower", 
    "strchr", 
    "strncmp", 
    "memchr", 
    "memcmp", 
    "strnstr", 
    "atoi", 
    "Finish program", 
    NULL};

    menu **main_menu = menu_node_generator(main_menu_str, NULL);
    
    while(1)
    {
        system("clear");
        print_title("libft tester");
        c0 = print_menu(main_menu);
        switch (c0)
        {
            case 1:  // isalpha
                test_isalpha();
                break;
            case 2:
                // code
                break;
            case 3:
                // code
                break;
            case 4:
                // code
                break;
            case 5:
                // code
                break;

            case 21:
                menu_node_terminator(main_menu[0]);
                return 0;
                break;
            
            default:
                break;
        }
    }
    return 0;
}