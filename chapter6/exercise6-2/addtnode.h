/*
 * Package Name: exercise6-2
 *
 * File Name: addtnode.h
 *
 * Abstract:
 * Declare addtree() function.
 *
 * Created: yanice  2024/4/12
 *
 * History: null    null
 *
 */


#ifndef addtnode_h
#define addtnode_h

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);

#endif /* addtnode_h */
