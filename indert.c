#include "Red_Black.h"

Status insert(T_node **root, int val)
{
    if (*root == NULL)
    {
        T_node *new = malloc(sizeof(T_node));
        // strcpy(new->bit, "Black");
        new->color = BLACK;
        new->data = val;
        new->left = NULL;
        new->right = NULL;
        new->parent = NULL;

        *root = new;
        return SUCCESS;
    }
    T_node *temp = *root;

    T_node *new = malloc(sizeof(T_node));
    // strcpy(new->bit, "RED");
    new->color = RED;
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    T_node *prev = NULL;
    int flag;
    while (temp != NULL)
    {
        if (new->data < temp->data)
        {
            prev = temp;
            flag = 1;
            temp = temp->left;
        }
        else if (new->data > temp->data)
        {
            prev = temp;
            flag = 0;
            temp = temp->right;
        }
        else
        {
            printf("Duplicate Element\n");
            free(new);
            return FAILURE;
        }
    }
    if (flag)
    {
        prev->left = new;
        new->parent = prev;
    }
    else
    {
        prev->right = new;
        new->parent = prev;
    }

    printf("before Balancing red Black Tree \n");
    Display(*root);
    printf("\n");

    // T_node *paren = new->parent;
    if (new->parent->color == BLACK)
    {
        printf("now tree is Balance\n");
        Display(*root);
        printf("\n");
        return SUCCESS;
    }
    else
    {
        T_node *uncle;

        while (new != *root && new->parent->color == RED)
        {
            T_node *grandparen = new->parent->parent;
            if (grandparen == NULL)
                break;

            if (grandparen->left == new->parent)
            {
                uncle = grandparen->right;

                if (uncle != NULL && uncle->color == RED)
                {
                    uncle->color = BLACK;
                    new->parent->color = BLACK;
                    grandparen->color = RED;

                    new = grandparen;
                }
                else
                {
                    if (new == new->parent->right)
                    {
                        new = new->parent;
                        leftrotate(root, new);
                    }
                    new->parent->color = BLACK;
                    new->parent->parent->color = RED;
                    rightrotate(root, new->parent->parent);
                }
            }
            else
            {
                uncle = grandparen->left;
                if (uncle != NULL && uncle->color == RED)
                {
                    uncle->color = BLACK;
                    new->parent->color = BLACK;
                    grandparen->color = RED;

                    new = grandparen;
                }
                else
                {
                    if (new == new->parent->left)
                    {
                        new = new->parent;
                        rightrotate(root, new);
                    }
                    new->parent->color = BLACK;
                    new->parent->parent->color = RED;
                    leftrotate(root, new->parent->parent);
                }
            }
        }
        (*root)->color = BLACK;
        printf("now tree is Balance\n");
        Display(*root);
        printf("\n");
        return SUCCESS;
    }
}

void leftrotate(T_node **root, T_node *node)
{

    T_node *ynode = node->right;

    node->right = ynode->left;
    if (ynode->left != NULL)
    {
        ynode->left->parent = node;
    }

    ynode->parent = node->parent;
    if (node->parent == NULL)
    {
        *root = ynode;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = ynode;
    }
    else
    {
        node->parent->right = ynode;
    }

    ynode->left = node;
    node->parent = ynode;
}

void rightrotate(T_node **root, T_node *node)
{

    T_node *ynode = node->left;

    node->left = ynode->right;
    if (ynode->right != NULL)
    {
        ynode->right->parent = node;
    }
    ynode->parent = node->parent;
    if (node->parent == NULL)
    {
        *root = ynode;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = ynode;
    }
    else
    {
        node->parent->right = ynode;
    }

    ynode->right = node;
    node->parent = ynode;
}

Status Display(T_node *root)
{
    if (root != NULL)
    {
        Display(root->left);
        printf("(%d)--(%s)  ", root->data, root->color == RED ? "RED" : "BLACK");
        Display(root->right);
    }
    // printf("\n");
    return SUCCESS;
}

T_node *bstDelete(T_node *root, int del, T_node **x, T_node **parent, color *detectc)
{
    T_node *temp = root;
    T_node *prev = NULL;
    int flag = 0;
    *detectc = -1;

    while (temp != NULL)
    {
        if (del > temp->data)
        {
            prev = temp;
            temp = temp->right;
            flag = 1;
        }
        else if (del < temp->data)
        {
            prev = temp;
            temp = temp->left;
            flag = 0;
        }
        else
        {
            *detectc = temp->color;

            /* CASE 1: leaf */
            if (temp->left == NULL && temp->right == NULL)
            {
                *x = NULL;
                *parent = prev;

                if (temp == root)
                    root = NULL;
                else if (flag)
                    prev->right = NULL;
                else
                    prev->left = NULL;

                free(temp);
                return root;
            }

            /* CASE 2: one child */
            if (temp->left == NULL || temp->right == NULL)
            {
                T_node *child = (temp->left) ? temp->left : temp->right;
                *x = child;
                *parent = prev;

                if (temp == root)
                {
                    root = child;
                    child->parent = NULL;
                }
                else if (flag)
                {
                    prev->right = child;
                    child->parent = prev;
                }
                else
                {
                    prev->left = child;
                    child->parent = prev;
                }

                free(temp);
                return root;
            }

            /* CASE 3: two children (SUCCESSOR DELETE) */
            T_node *temp1 = temp->right;
            T_node *prev1 = temp;

            while (temp1->left != NULL)
            {
                prev1 = temp1;
                temp1 = temp1->left;
            }

            temp->data = temp1->data;
            *detectc = temp1->color;

            *x = temp1->right;
            *parent = prev1;

            if (prev1->left == temp1)
                prev1->left = temp1->right;
            else
                prev1->right = temp1->right;

            if (temp1->right)
                temp1->right->parent = prev1;

            free(temp1);
            return root;
        }
    }
    return root;
}

void rbDeleteFixup(T_node **root, T_node *x, T_node *parent)
{
    T_node *sibling;

    while (x != *root && COLOR(x) == BLACK)
    {
        if (x == parent->left)
        {
            sibling = parent->right;

            /* Case 1: sibling RED */
            if (COLOR(sibling) == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;
                leftrotate(root, parent);
                sibling = parent->right;
            }

            /* Case 2: sibling BLACK, both children BLACK */
            if (COLOR(sibling->left) == BLACK &&
                COLOR(sibling->right) == BLACK)
            {
                sibling->color = RED;
                x = parent;
                parent = x->parent;
            }
            else
            {
                /* Case 3: sibling BLACK, near child RED */
                if (COLOR(sibling->right) == BLACK)
                {
                    if (sibling->left)
                        sibling->left->color = BLACK;
                    sibling->color = RED;
                    rightrotate(root, sibling);
                    sibling = parent->right;
                }

                /* Case 4: sibling BLACK, far child RED */
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right)
                    sibling->right->color = BLACK;
                leftrotate(root, parent);
                x = *root;
            }
        }
        else
        {
            /* Mirror cases (x is right child) */
            sibling = parent->left;

            if (COLOR(sibling) == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;
                rightrotate(root, parent);
                sibling = parent->left;
            }

            if (COLOR(sibling->left) == BLACK &&
                COLOR(sibling->right) == BLACK)
            {
                sibling->color = RED;
                x = parent;
                parent = x->parent;
            }
            else
            {
                if (COLOR(sibling->left) == BLACK)
                {
                    if (sibling->right)
                        sibling->right->color = BLACK;
                    sibling->color = RED;
                    leftrotate(root, sibling);
                    sibling = parent->left;
                }

                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left)
                    sibling->left->color = BLACK;
                rightrotate(root, parent);
                x = *root;
            }
        }
    }

    if (x)
        x->color = BLACK;
}

Status rbDelete(T_node **root, int key)
{
    T_node *x = NULL;
    T_node *parent = NULL;
    color deletedColor;

    *root = bstDelete(*root, key, &x, &parent, &deletedColor);

    if (deletedColor == -1)
    {
        return FAILURE;
    }

    if (deletedColor == BLACK)
        rbDeleteFixup(root, x, parent);

    if (*root)
        (*root)->color = BLACK;

    return SUCCESS;
}

Status find_minimum(T_node *root)
{

    T_node *temp = root;
    if (temp == NULL)
    {
        printf("Tree is Empty \n");
        return FAILURE;
    }

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    printf("Minimum node in the given Red Black Tree is : (%d)--(%s)\n", temp->data, temp->color == RED ? "RED" : "BLACK");
    return SUCCESS;
}

Status find_maximum(T_node *root)
{
    T_node *temp = root;
    if (temp == NULL)
    {
        printf("Tree is Empty\n");
        return FAILURE;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    printf("Maximum node in the given Red Black Tree is : (%d)--(%s)\n", temp->data, temp->color == RED ? "RED" : "BLACK");
    return SUCCESS;
}

Status Search(T_node *root, int val)
{

    T_node *temp = root;

    while (temp != NULL)
    {
        if (val < temp->data)
        {
            temp = temp->left;
        }
        else if (val > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            printf("Node Found  (%d)--(%s)\n", temp->data, temp->color == RED ? "RED" : "BLACK");
            return SUCCESS;
        }
    }
    return FAILURE;
}

Status delete_minimum(T_node **root)
{
    T_node *temp = *root;
    if (temp == NULL)
    {
        printf("Tree is Empty \n");
        return FAILURE;
    }

    printf("Tree Before Deleting Minimum node:\n");
    Display(*root);
    printf("\n");

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    rbDelete(root, temp->data);

    printf("Tree After Deleting minimun node:\n");
    Display(*root);
    printf("\n");

    return SUCCESS;
}

Status delete_maximum(T_node **root)
{

    T_node *temp = *root;
    if (temp == NULL)
    {
        printf("Tree is Empty\n");
        return FAILURE;
    }
    printf("Tree Before Deleting Maximum node:\n");
    Display(*root);
    printf("\n");

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    rbDelete(root, temp->data);

    printf("Tree After Deleting maximun node:\n");
    Display(*root);
    printf("\n");

    return SUCCESS;
}