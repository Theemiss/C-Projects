#ifndef _SUM_H_
#define _SUM_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
int sum_dlistint(dlistint_t *head);
void free_dlistint(dlistint_t *head);

#endif
