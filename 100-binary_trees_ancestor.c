#include "binary_trees.h"
int binary_trees_levels(const binary_tree_t *node);
binary_tree_t *binary_trees_fill(const binary_tree_t *node, binary_tree_t *array, int n);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first:  is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *array_first, *array_second;
	int a, b;

	if (!first || !second)
		return (NULL);
	a = binary_trees_levels(first);
	array_first = malloc(sizeof(binary_tree_t) * a);
	if (!array_first)
		return (NULL);
	b = binary_trees_levels(second);
	array_second = malloc(sizeof(binary_tree_t) * b);
	if (!array_second)
	{
		free(array_first);
		return (NULL);
	}
	array_first = binary_trees_fill(first, array_first, a);
	array_second = binary_trees_fill(second, array_second, b);

	a = 0;
	while (array_first[a] && array_second[a])
	{
		if (array_first[a] != array_second[a])
			return (array_second[a - 1]);
		a++;
	}
	return (NULL);
}

int binary_trees_levels(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (1 + binary_trees_levels(node->parent));
}
binary_tree_t *binary_trees_fill(const binary_tree_t *node, binary_tree_t *array, int n)
{
	if (!node)
		return (array);

	array[n] = node;
	binary_trees_fill(node->parent, array, n - 1);
}
