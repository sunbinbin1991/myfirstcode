#pragma once
#include "BinaryTree.h"
#include "typedef.h"
bool isSameTree(BinaryTreeNode* s, BinaryTreeNode* t) {
	if (s == nullptr || t == nullptr) return true;
	if (s == nullptr && t != nullptr) return false;
	return isSameTree(s->m_pLeft, t->m_pLeft) && isSameTree(s->m_pRight, t->m_pRight);
}

bool isSubtree(BinaryTreeNode* s, BinaryTreeNode* t) {
	if (s == nullptr || t == nullptr) return true;
	if (s == nullptr && t != nullptr) return false;

	if (s->m_nValue == t->m_nValue) {
		return isSameTree(s, t);
	}
	else {
		return isSubtree(s->m_pLeft, t) || isSubtree(s->m_pRight, t);
	}
}