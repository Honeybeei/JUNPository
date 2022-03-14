#include "user_interface.h"
#include <stdio.h>
#include <unistd.h>

void print_title(char *title_str)
{
    printf("\n\n\t\t[ %s ]\n\n", title_str);
}

int get_user_choice(int start, int end)  // returns int what user typed in
{
    int n;

    while (1)
    {
        printf("Type a number between %d and %d : ", start, end);
        scanf("%d", &n);
        while (getchar() != '\n');

        if (start <= n && n <= end)
            break;
        else
            printf("\nPlease type a NUMBER between %d and %d\n\n", start, end);
    }
    return n;
}

menu **menu_node_generator(char **str_arr, menu *upper_category)
{
    menu **node_pointer_arr;
    menu *current_node;
    int i;
    int menu_count;
    int current_depth;

    current_node = upper_category;
    for (i = 0; current_node != NULL; i++)
        current_node = current_node->upper;
    current_depth = i;

    for (i = 0; str_arr[i] != NULL; i++);
    menu_count = i;

    node_pointer_arr = malloc(sizeof(menu*) * (menu_count + 2));
    // NULL guard
    if (node_pointer_arr == NULL)
        return 0;
    // Initialize all node pointers
    for (i = 0; i < menu_count + 2; i++)
        node_pointer_arr[i] = NULL;
    // Initialize node data
    for (i = 1; i < menu_count; i++)
    {
        node_pointer_arr[i] = malloc(sizeof(menu));
        if (node_pointer_arr[i] == NULL)
            return 0;
        node_pointer_arr[i]->str = str_arr[i];
        node_pointer_arr[i]->nth = i;
        node_pointer_arr[i]->depth = current_depth;
        node_pointer_arr[i]->next = NULL;
        node_pointer_arr[i]->prev = NULL;
        node_pointer_arr[i]->upper = upper_category;
        node_pointer_arr[i]->under = NULL;
    }
    // link nodes(next, prev)
    for (i = 1; i < menu_count; i++)
    {
        node_pointer_arr[i]->next = node_pointer_arr[i + 1];
        node_pointer_arr[i]->prev = node_pointer_arr[i - 1];
    }
    // link node(upper - under[1])
    if (upper_category != NULL)
        upper_category->under = node_pointer_arr[1];
    return node_pointer_arr;
}

void print_node_arr(menu **node_pointer_arr)  // for testing
{
    int i;
    int node_count;

    for (i = 1; node_pointer_arr[i] != NULL; i++);
    node_count = i;
    printf("node count : %d\n", node_count);

    if (node_pointer_arr[0] != NULL)
        print_node_info(node_pointer_arr[0]);
    else
        printf("starting pointer is NULL terminated\n\n");
    for (i = 1; i < node_count; i++)
        print_node_info(node_pointer_arr[i]);
    if (node_pointer_arr[i] != NULL)
        print_node_info(node_pointer_arr[i]);
    else
        printf("last pointer is NULL terminated\n\n");
}

void print_node_info(menu *current)  // for testing
{
    printf("menu.str     : %s\n", current->str);
    printf("menu.address : %p\n", current);
    printf("menu.nth     : %d\n", current->nth);
    printf("menu.depth   : %d\n", current->depth);
    printf("menu.next    : %p\n", current->next);
    printf("menu.prev    : %p\n", current->prev);
    printf("menu.upper   : %p\n", current->upper);
    printf("menu.under   : %p\n\n", current->under);

}

int print_menu(menu **menu_arr)  // returns user input
{
    int i;
    int menu_count;

    for (i = 1; menu_arr[i]->next != NULL; i++);
    menu_count = i;
    for (i = 1; i < menu_count + 1; i++)
    {
        printf("[%d] %s\n", i, menu_arr[i]->str);
    }
    printf("\n");

    return get_user_choice(1, menu_count);
}

void menu_node_terminator(menu *menu_node)
{
    menu *del_node;

    while (menu_node != NULL)
    {
        del_node = menu_node;
        if (menu_node->under != NULL)
            menu_node_terminator(menu_node->under);
        menu_node = menu_node->next;
        printf("Deleted node : %s %p\n", del_node->str, del_node);
        free(del_node);
    }
}

void print_all_nodes(menu **highest_menu_arr)
{
    menu *current;

    current = highest_menu_arr[1];
    recursive_print(current);
}

void recursive_print(menu *current)
{
    int i;

    for (i = 0; i < current->depth; i++)
        printf("\t");
    printf("[%d] %s\n", current->nth, current->str);

    if (current->under != NULL)
    {
        current = current->under;
        recursive_print(current);
    }
    else  // if there is no under menu
    {
        if (current->next != NULL)
        {
            current = current->next;
            recursive_print(current);
        }
        else // if current->next == NULL
        {
            if (current->upper != NULL)
            {
                if (current->upper->next != NULL)
                {
                    current = current->upper->next;
                    recursive_print(current);
                }
                else  // if current->upper->next == NULL
                {
                    while (current->next == NULL && current->upper != NULL)
                    {
                        current = current->upper;
                    }
                    if (current->next != NULL)
                    {
                        current = current->next;
                        recursive_print(current);
                    }
                }
            }
            else  // if current->upper == NULL
                printf("\nMenu END!!\n");
        }
    }
}
