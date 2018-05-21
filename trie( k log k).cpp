#include <cstdlib>
#include <map>
 
using namespace std;
 
/**
 * Namespaces: std
 * Libraries: <cstdlib>, <map>
 */
 
struct Node {
    bool leaf;
    Node *parent;
    map<char, Node *> child;
    Node(Node *parent = NULL)
        : parent(parent), leaf(false), child()
    {}
};
 
/**
 * Complexity: O(|key| * log(k))
 */
Node *trie_find(Node *root, char *key) {
    Node *it;
    for (it = root; *key != 0; key++) {
        if (it->child.find(*key) == it->child.end())
            return NULL;
        it = it->child[*key];
    }
    return (it->leaf) ? it : NULL;
}
 
/**
 * Complexity: O(|key| * log(k))
 */
void trie_insert(Node *root, char *key) {
    Node *it;
    for (it = root; *key != 0; key++) {
        if (it->child.find(*key) == it->child.end())
            it->child[*key] = new Node(it);
        it = it->child[*key];
    }
    it->leaf = true;
}
 
/**
 * Complexity: O(|key| * log(k))
 */
void trie_erase(Node *root, char *key) {
    Node *it;
    for (it = root; *key != 0; key++) {
        if (it->child.find(*key) == it->child.end())
            return;
        it = it->child[*key];
    }
    it->leaf = false;
    while (it->parent != NULL) {
        if (it->child.size() > 0 || it->leaf)
            break;
        it = it->parent, key--;
        it->child.erase(*key);
    }
}