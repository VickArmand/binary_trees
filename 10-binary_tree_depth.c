#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: 0 If tree is NULL, otherwise return depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;
	binary_tree_t *temp;

	if (tree == NULL)
		return (0);
	temp = tree;
	while (temp)
	{
		temp = temp->parent;
		depth++;
	}
	return (depth);
}
