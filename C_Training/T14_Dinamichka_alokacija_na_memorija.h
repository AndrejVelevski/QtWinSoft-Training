#ifndef T14_DINAMICHKA_ALOKACIJA_NA_MEMORIJA_H
#define T14_DINAMICHKA_ALOKACIJA_NA_MEMORIJA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int value;
    char character;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

typedef struct LinkedList
{
    ListNode* first;
    ListNode* last;
} LinkedList;

LinkedList* createList()
{
    LinkedList* list = malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;

    return list;
}

void add(LinkedList* list, int value, char character)
{
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;
    node->character = character;

    if (list->first == NULL)
    {
        list->first = node;
        node->prev = NULL;
        node->next = NULL;
        list->last = node;
    }
    else
    {
        list->last->next = node;
        node->prev = list->last;
        node->next = NULL;
        list->last = node;
    }
}

void print(LinkedList* list, int reversed)
{
    if (!reversed && list->first != NULL)
    {
        ListNode* node = list->first;
        while(node != NULL)
        {
            printf("%d%c%s", node->value, node->character, node->next==NULL?"\n":" -> ");
            node = node->next;
        }
    }
    else if (reversed && list->last != NULL)
    {
        ListNode* node = list->last;
        while(node != NULL)
        {
            printf("%d%c%s", node->value, node->character, node->prev==NULL?"\n":" -> ");
            node = node->prev;
        }
    }
}

void deleteList(LinkedList* list)
{
    if (list->first != NULL)
    {
        ListNode* node = list->first;
        while(node != NULL)
        {
            ListNode* next = node->next;
            free(node);
            node = next;
        }
    }

    free(list);
    list = NULL;
}

void deleteNode(LinkedList* list, ListNode n)
{
    ListNode* t = NULL;

    if (list->first != NULL)
    {
        ListNode* node = list->first;

        while(node != NULL)
        {

            if (node->value == n.value && node->character == n.character)
            {
                t = node;
                break;
            }
            node = node->next;
        }
    }

    if (t != NULL)
    {
        if (t == list->first)
        {
            list->first = t->next;
            list->first->prev = NULL;
        }
        else if (t == list->last)
        {
            list->last = t->prev;
            list->last->next = NULL;
        }
        else
        {

            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
        free(t);
    }
}

void sort(LinkedList* list, int descending)
{
    if (list->first != NULL)
    {
        ListNode* i = list->first;

        while (i != NULL)
        {
            ListNode* j = i;

            while(j != NULL)
            {
                if ((descending && j->value > i->value) || (!descending && j->value < i->value))
                {
                    ListNode temp = { i->value, i->character, NULL, NULL };
                    i->value = j->value;
                    i->character = j->character;
                    j->value = temp.value;
                    j->character = temp.character;
                }

                j = j->next;
            }

            i = i->next;
        }
    }
}

void pecatiListaNanazad(ListNode* node)
{
    if (node == NULL)
        return;

    printf("%d%c%s", node->value, node->character, node->prev==NULL?"\n":" -> ");

    pecatiListaNanazad(node->prev);
}

void zadaca14_01()
{
    LinkedList* list = createList();
    add(list, 4, 'A');
    add(list, 8, 'B');
    add(list, 2, 'C');
    add(list, 9, 'D');
    add(list, 7, 'E');
    add(list, 3, 'F');

    pecatiListaNanazad(list->last);

    deleteList(list);

    printf("\n");
}

void zadaca14_02()
{
    LinkedList* list = createList();
    add(list, 4, 'A');
    add(list, 8, 'B');
    add(list, 2, 'C');
    add(list, 9, 'D');
    add(list, 7, 'E');
    add(list, 3, 'F');

    printf("Normal: ");
    print(list, 0);
    printf("Reversed: ");
    print(list, 1);

    printf("Sort ascending...\n");
    sort(list, 0);
    print(list, 0);

    printf("Sort descending...\n");
    sort(list, 1);
    print(list, 0);

    printf("Deleting node 9D, 7E, 2C...\n");
    ListNode n1 = { 9, 'D', NULL, NULL };
    ListNode n2 = { 7, 'E', NULL, NULL };
    ListNode n3 = { 2, 'C', NULL, NULL };
    deleteNode(list, n1);
    deleteNode(list, n2);
    deleteNode(list, n3);
    printf("Normal: ");
    print(list, 0);
    printf("Reversed: ");
    print(list, 1);

    deleteList(list);

    printf("\n");
}

typedef struct StackNode
{
    char c;
    struct StackNode* under;
} StackNode;

typedef struct Stack
{
    StackNode* top;
} Stack;

Stack* createStack()
{
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;

    return stack;
}

void push(Stack* stack, char c)
{
    StackNode* node = malloc(sizeof(StackNode));
    node->c = c;
    node->under = stack->top;
    stack->top = node;
}

void pop(Stack* stack)
{
    if (stack->top == NULL)
        return;

    StackNode* tmp = stack->top;
    stack->top = tmp->under;
    free(tmp);
}

void zadaca14_03()
{
    Stack* stack = createStack();

    char string[100];
    printf("Vnesete tekst: ");
    scanf("%[^\n]%*c", string);

    for(int i=0;;++i)
    {
       char c = string[i];
       if (c == '\0')
           break;
       push(stack, c);
    }

    while(stack->top != NULL)
    {
        printf("%c%s", stack->top->c, stack->top->under==NULL?"\n":"");
        pop(stack);
    }
}

typedef struct TreeNode
{
    int value;
    //za baranje 2, ednostavno tuka bi imalo ushte edna vrednost
    //i slicno kako kaj double linked list bi se pristapilo do nea
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree
{
    TreeNode* root;
} Tree;

Tree* createTree()
{
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void addTreeValue(Tree* tree, int value)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    if (tree->root == NULL)
    {
        tree->root = node;
        return;
    }

    TreeNode* curr = tree->root;
    while(1)
    {
        if (node->value < curr->value)
        {
            if (curr->left == NULL)
            {
                curr->left = node;
                break;
            }
            else
            {
                curr = curr->left;
            }
        }
        else if (node->value > curr->value)
        {
            if (curr->right == NULL)
            {
                curr->right = node;
                break;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
}

void addTreeNode(TreeNode* curr, TreeNode* node)
{
    while(1)
    {
        if (node->value < curr->value)
        {
            if (curr->left == NULL)
            {
                curr->left = node;
                break;
            }
            else
            {
                curr = curr->left;
            }
        }
        else if (node->value > curr->value)
        {
            if (curr->right == NULL)
            {
                curr->right = node;
                break;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
}

void deleteTreeNode(Tree* tree, int value)
{
    TreeNode* parent = NULL;
    TreeNode* node = tree->root;

    while(1)
    {
        if (node->value == value)
            break;

        parent = node;
        if (value < node->value)
            node = node->left;
        else if (value > node->value)
            node = node->right;

        if (node == NULL)
            break;
    }

    if (node != NULL)
    {
        if (node->left == NULL && node->right == NULL)
        {
            if (parent != NULL)
            {
                if (parent->left == node)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else
            {
                tree->root = NULL;
            }
        }
        else if (node->left != NULL && node->right == NULL)
        {
            if (parent != NULL)
            {
                if (parent->left == node)
                    parent->left = node->left;
                else
                    parent->right = node->left;
            }
            else
            {
                tree->root = node->left;
            }
        }
        else if (node->left == NULL && node->right != NULL)
        {
            if (parent != NULL)
            {
                if (parent->left == node)
                    parent->left = node->right;
                else
                    parent->right = node->right;
            }
            else
            {
                tree->root = node->right;
            }
        }
        else
        {
            if (parent != NULL)
            {
                if (parent->left == node)
                    parent->left = node->right;
                else
                    parent->right = node->right;
            }
            else
            {
                tree->root = node->right;
            }
            addTreeNode(node->right, node->left);
        }

        free(node);
    }
}

void deleteTree(Tree* tree)
{
    if (tree->root == NULL)
    {
        free(tree);
        return;
    }

    deleteTreeNode(tree, tree->root->value);
    deleteTree(tree);
}

void preOrder(TreeNode* node)
{
    if (node != NULL)
    {
        printf("%d ", node->value);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TreeNode* node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->value);
        inOrder(node->right);
    }
}

void postOrder(TreeNode* node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->value);
    }
}

void deleteTreeNodePrint(Tree* tree, int number)
{
    printf("Deleting node %d\n", number);
    deleteTreeNode(tree, number);
    printf("In Order: ");
    inOrder(tree->root);
    printf("\n\n");
}

void zadaca14_04()
{
    /*
                8
               / \
              3  10
             / \   \
            1  6   14
              / \  /
             4  7 13
    */

    Tree* tree = createTree();

    addTreeValue(tree, 8);
    addTreeValue(tree, 3);
    addTreeValue(tree, 1);
    addTreeValue(tree, 10);
    addTreeValue(tree, 6);
    addTreeValue(tree, 14);
    addTreeValue(tree, 4);
    addTreeValue(tree, 7);
    addTreeValue(tree, 13);

    printf("Pre Order: ");
    preOrder(tree->root);
    printf("\n");
    printf("In Order: ");
    inOrder(tree->root);
    printf("\n");
    printf("Post Order: ");
    postOrder(tree->root);
    printf("\n");

    printf("\nIn Order: ");
    inOrder(tree->root);
    printf("\n\n");

    deleteTreeNodePrint(tree, 6);
    deleteTreeNodePrint(tree, 14);
    deleteTreeNodePrint(tree, 8);
    deleteTreeNodePrint(tree, 7);
    deleteTreeNodePrint(tree, 9);
    deleteTreeNodePrint(tree, 1);
    deleteTreeNodePrint(tree, 10);
    deleteTreeNodePrint(tree, 3);
    deleteTreeNodePrint(tree, 8);
    deleteTreeNodePrint(tree, 4);
    deleteTreeNodePrint(tree, 13);


    printf("Adding some values\n");
    addTreeValue(tree, 10);
    addTreeValue(tree, 6);
    addTreeValue(tree, 14);
    addTreeValue(tree, 4);

    printf("\nIn Order: ");
    inOrder(tree->root);
    printf("\n\n");

    printf("Deleting whole tree\n");
    deleteTree(tree);

    printf("\n");
}

#endif // T14_DINAMICHKA_ALOKACIJA_NA_MEMORIJA_H
