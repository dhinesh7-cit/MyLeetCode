#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TARGET 1000000

typedef struct {
    bool exists[MAX_TARGET + 1];
} FindElements;

void recover(struct TreeNode* root, int val, bool exists[]) {
    if (root == NULL) return;
    root->val = val;
    if (val <= MAX_TARGET)
        exists[val] = true;
    recover(root->left, 2 * val + 1, exists);
    recover(root->right, 2 * val + 2, exists);
}

FindElements* findElementsCreate(struct TreeNode* root) {
    FindElements* obj = (FindElements*)malloc(sizeof(FindElements));
    if (!obj) return NULL;
    memset(obj->exists, 0, sizeof(obj->exists));
    recover(root, 0, obj->exists);
    return obj;
}

bool findElementsFind(FindElements* obj, int target) {
    if (target < 0 || target > MAX_TARGET) return false;
    return obj->exists[target];
}

void findElementsFree(FindElements* obj) {
    free(obj);
}
