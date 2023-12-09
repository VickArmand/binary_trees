#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * Return: void If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return ;
	else if (tree->parent)
	{
		if (tree->parent->left == tree)
		{
			func(tree->parent->left->n);
			func(tree->parent->right->n);
		}
		binary_tree_levelorder(tree->left, func);
		binary_tree_levelorder(tree->right, func);
	}
	else if (tree->parent == NULL)
	{
		func(tree->n);
		binary_tree_levelorder(tree->left, func);
		binary_tree_levelorder(tree->right, func);
	}
}
