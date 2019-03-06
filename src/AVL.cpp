#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

using namespace std;

int AVL::height(struct Node *N)
{
    if (N == nullptr)
    {
        return 0;
    }
    return N->height;
}

Node *AVL::newNode(int key)
{
    Node *node = new Node();
    malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *AVL::rRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Rotaciones
    x->right = y;
    y->left = T2;

    // Actualizar alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *AVL::lRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int AVL::getBalance(struct Node *N)
{
    if (N == NULL)
    {
        return 0;
    }

    return height(N->left) - height(N->right);
}

Node *AVL::insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return (newNode(key));
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }

    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rRotation(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return lRotation(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = lRotation(node->left);
        return rRotation(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rRotation(node->right);
        return lRotation(node);
    }

    return node;
}

Node *AVL::deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        if ((root->left == nullptr) || (root->right == nullptr))
        {
            struct Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }

            else
            {
                *root = *temp;
            }

            free(temp);
        }
        else
        {
            struct Node *temp = minimumNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rRotation(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = lRotation(root->left);
        return rRotation(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return lRotation(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rRotation(root->right);
        return lRotation(root);
    }

    return root;
}

Node *AVL::minimumNode(struct Node *node)
{
    Node *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}