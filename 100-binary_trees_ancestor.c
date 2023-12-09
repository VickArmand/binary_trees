#include "binary_trees.h"
binary_tree_t *trees_ancestor_first(
		const binary_tree_t *first, const binary_tree_t *second);
binary_tree_t *trees_ancestor_second(
		const binary_tree_t *first, const binary_tree_t *second);
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: Your function must return a pointer to the
 * lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *temp1, *temp2;

	if (first == NULL || second == NULL)
		return (NULL);
	temp1 = trees_ancestor_first(first, second);
	temp2 = trees_ancestor_second(first, second);
	if (!temp1 && !temp2)
		return (NULL);
	else if (temp1)
		return (temp1);
	return (temp2);
}
/**
 * trees_ancestor_first - finds the lowest common ancestor
 * using the first node
 * @first: node to use to get the lowest common ancestor
 * @second: node to use for comparison
 * Return: NULL or lowest common ancestor
 */
binary_tree_t *trees_ancestor_first(
		const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	else if (first == second ||
			first->left == second ||
			first->right == second)
		return ((binary_tree_t *)first);
	return (trees_ancestor_first(first->parent, second));
}
/**
 * trees_ancestor_second - finds the lowest common ancestor
 * using the second node
 * @first: node to use for comparison
 * @second: node to use to get the lowest common ancestor
 * Return: NULL or lowest common ancestor
 */
binary_tree_t *trees_ancestor_second(
		const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	else if (second == first ||
			second->left == first ||
			second->right == first)
		return ((binary_tree_t *)second);
	return (trees_ancestor_second(first, second->parent));
}
