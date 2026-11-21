struct Node {
    struct Node *left;
    struct Node *right;
};

/* The main NSO imports C++ operator delete(void *) under this ELF symbol. */
extern void _ZdlPv(void *);

/* nnMain calls this function at main+0x36249c. */
void f_7002362258(struct Node *node) {
    if (node) {
        f_7002362258(node->left);
        f_7002362258(node->right);
        _ZdlPv(node);
    }
}
