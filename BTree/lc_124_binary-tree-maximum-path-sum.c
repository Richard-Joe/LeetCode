#include <stdio.h>
#include <limits.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

struct tnode
{
    int val;
    struct tnode *left;
    struct tnode *right;
};

#define init_node(v, l, r) { \
    .val = v, \
    .left = l, \
    .right = r \
}

int max_path_sum(struct tnode *root)
{
    if (!root) return 0;
    int l = max_path_sum(root->left);
    int r = max_path_sum(root->right);
    return root->val + max(l, r);
}

int ans = INT_MIN;
int maxPathSum(struct tnode* root){
    if (!root) return 0;
    int l = max(maxPathSum(root->left), 0);
    int r = max(maxPathSum(root->right), 0);
    ans = max(ans, l + r + root->val);
    return max(l, r) + root->val;
}

int main(void)
{
    struct tnode t5 = init_node(5, NULL, NULL);
    struct tnode t6 = init_node(6, NULL, NULL);
    struct tnode t7 = init_node(7, NULL, NULL);
    struct tnode t8 = init_node(8, NULL, NULL);

    //struct tnode t2 = init_node(2, &t5, &t7);
    struct tnode t2 = init_node(2, NULL, NULL);
    struct tnode t3 = init_node(3, &t6, &t8);

    struct tnode t1 = init_node(1, &t2, &t3);


    struct tnode t0 = init_node(0, NULL, NULL);


    maxPathSum(&t0);
    printf("%d\n", ans);

    return 0;
}
