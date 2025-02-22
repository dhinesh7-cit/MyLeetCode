#include <stdlib.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int pos = 0;

int parseInteger(char* traversal) {
    int num = 0;
    while (traversal[pos] && isdigit(traversal[pos])) {
        num = num * 10 + (traversal[pos] - '0');
        pos++;
    }
    return num;
}

struct TreeNode* recoverHelper(char* traversal, int depth) {
    int curr = pos, dashCount = 0;
    while (traversal[curr] == '-') {
        dashCount++;
        curr++;
    }
    if (dashCount != depth)
        return NULL;
    pos = curr;
    int value = parseInteger(traversal);
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = node->right = NULL;
    node->left = recoverHelper(traversal, depth + 1);
    node->right = recoverHelper(traversal, depth + 1);
    return node;
}

struct TreeNode* recoverFromPreorder(char* traversal) {
    pos = 0;
    return recoverHelper(traversal, 0);
}
