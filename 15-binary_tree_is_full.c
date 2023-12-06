#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		printf("%d\n", tree->n);
		if (((tree->left && tree->right) ||
				(!tree->left && !tree->right)) &&
				binary_tree_is_full(tree->left) == 1 &&
				binary_tree_is_full(tree->right) == 1)
		{
			return (1);
		}
	}
	return (0);
}
