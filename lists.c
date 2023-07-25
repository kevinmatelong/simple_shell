#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @nodehead: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **nodehead, const char *str, int num)
{
	list_t *new_nodehead;

	if (!nodehead)
		return (NULL);
	new_nodehead = malloc(sizeof(list_t));
	if (!new_nodehead)
		return (NULL);
	_memset((void *)new_nodehead, 0, sizeof(list_t));
	new_nodehead->num = num;
	if (str)
	{
		new_nodehead->str = _strdup(str);
		if (!new_nodehead->str)
		{
			free(new_nodehead);
			return (NULL);
		}
	}
	new_nodehead->next = *nodehead;
	*nodehead = new_nodehead;
	return (new_nodehead);
}

/**
 * add_node_end - adds a node to the end of the list
 * @nodehead: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **nodehead, const char *str, int num)
{
	list_t *new_node, *node;

	if (!nodehead)
		return (NULL);

	node = *nodehead;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*nodehead = new_node;
	return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @nodehead: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **nodehead, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!nodehead || !*nodehead)
		return (0);

	if (!index)
	{
		node = *nodehead;
		*nodehead = (*nodehead)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *nodehead;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @nodehead_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **nodehead_ptr)
{
	list_t *node, *next_node, *nodehead;

	if (!nodehead_ptr || !*nodehead_ptr)
		return;
	nodehead = *nodehead_ptr;
	node = nodehead;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*nodehead_ptr = NULL;
}
