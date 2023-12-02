#include "binary_trees.h"
/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: is a pointer to the root node of the tree to delete
 * If tree is NULL, do nothing
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *templ, *tempr;

	if (tree == NULL)
		return;
	tempr = tree;
	templ = tree;
	while (templ->left || templ->right || tempr->right || tempr->left)
	{
		if (templ->left == NULL && templ != tree)
			templ = templ->right;
		else
			templ = templ->left;
		if (tempr->right == NULL && tempr != tree)
			tempr = tempr->left;
		else
			tempr = tempr->right;
	}
	while (tempr->parent != templ->parent)
	{
		tempr = tempr->parent;
		free(tempr->left);
		free(tempr->right);
		templ = templ->parent;
		free(templ->left);
		free(templ->right);
	}
	tempr = tempr->parent;
	free(tempr->left);
	free(tempr->right);
	free(tempr);
}
