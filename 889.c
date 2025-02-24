struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* constructTree(int* preorder, int preStart, int preEnd, 
                               int* postorder, int postStart, int postEnd) {
    if (preStart > preEnd || postStart > postEnd)
        return NULL;

    struct TreeNode* root = newNode(preorder[preStart]);

    if (preStart == preEnd)
        return root;

    int leftRootVal = preorder[preStart + 1];
    int leftRootIndex = findIndex(postorder, postStart, postEnd, leftRootVal);
    int leftSize = leftRootIndex - postStart + 1;

    root->left = constructTree(preorder, preStart + 1, preStart + leftSize, 
                               postorder, postStart, leftRootIndex);
    root->right = constructTree(preorder, preStart + leftSize + 1, preEnd, 
                                postorder, leftRootIndex + 1, postEnd - 1);
    
    return root;
}

struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) {
    return constructTree(preorder, 0, preorderSize - 1, postorder, 0, postorderSize - 1);
}
