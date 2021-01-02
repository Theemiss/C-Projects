#include "header.h"

int main(int argc, char *argv[])
{
    pid_t childpid;
    int i, x=0;
	char *buff = NULL;
	size_t s;
    int fd[2];
    int val = 0;
	dlistint_t *head = NULL;
	int sum = 0;

	while (1)
	{	
    // create pipe descriptors
    pipe(fd);

    childpid = fork();
    if(childpid != 0)  // parent
    {
        close(fd[1]);
        // read the data (blocking operation)
        read(fd[0], &val, sizeof(val));
		add_dnodeint(&head,val);
		sum = sum_dlistint(head);
        printf("%d\n", sum);
        // close the read-descriptor
        close(fd[0]);
    }
    else  // child
    {
        // writing only, no need for read-descriptor:
        close(fd[0]);
		printf(">");
        getline(&buff,&s,stdin);
		x = atoi(buff);
        // send the value on the write-descriptor:
        write(fd[1], &x, sizeof(x));

        // close the write descriptor:
        close(fd[1]);

        return x;
    }
	}
	free_dlistint(head);
	return(0);
}
/**
 * add_dnodeint - add new element at begin
 * @head:pointer
 * @n:element in list
 * Return:new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->prev = NULL;
	new->next = *head;
	new->n = n;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
/**
 * sum_dlistint - sum of element in list
 * @head:list
 * Return: int
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
/**
 * free_dlistint - free a list
 * @head:list
 * Return:void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *start, *check;

	start = head;
	while (start != NULL)
	{
		check = start->next;
		free(start);
		start = check;
	}
}