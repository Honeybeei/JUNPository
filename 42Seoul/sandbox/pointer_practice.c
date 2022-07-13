#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
linked list, linked node manage
How to use Function pointer

*/

typedef struct s_human
{
    int hight_;
    int weight_;
    char *name_;
} t_human;

typedef struct s_node
{
    void    *data_;
    struct s_node *next_;
} t_node;

t_node *make_new_node(void *data)
{
    t_node  *new_node;

    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
        return (NULL);
    new_node->data_ = data;
    new_node->next_ = NULL;
    return (new_node);
}

t_human *make_new_human(int height, int weight, const char *name)
{
    t_human *new_human;

    new_human = malloc(sizeof(t_human));
    if (new_human == NULL)
        return (NULL);
    new_human->hight_ = height;
    new_human->weight_ = weight;
    new_human->name_ = malloc(sizeof(char) * (strlen(name) + 1));
    if (new_human->name_ == NULL)
        return (NULL);
    for (size_t i = 0; i < strlen(name); i++)
        new_human->name_[i] = name[i];
    new_human->name_[strlen(name)] = '\0';
    return (new_human);
}

int print_human_info(t_human *human)
{
    if (human == NULL)
        return (0);
    printf("Printing Human Info\n");
    printf("Height : %d\n", human->hight_);
    printf("Weight : %d\n", human->weight_);
    printf("Name   : %s\n", human->name_);
    return (1);
}

int sum(int i)
{
    static int total = 0;
    total += i;
    return total;
}

int main(void)
{
    t_node *node = make_new_node((void *)"Hello world!\n");
    printf("%s", (char *)(node->data_));
    printf("%d\n", sum(2));
    printf("%d\n", sum(2));
    printf("%d\n", sum(2));
    printf("%d\n", sum(2));
    printf("%d\n", sum(2));
    printf("%d\n", sum(2));
    printf("%d\n", sum(2));
    printf("%d\n", sum(2));
}