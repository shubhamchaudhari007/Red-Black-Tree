#include "Red_Black.h"

int main()
{
    int choice;
    T_node *root = NULL;
    do
    {
        printf("====================================\n");
        printf("1. Create a Tree \n");
        printf("2. Display\n");
        printf("3. Search a node\n");
        printf("4. Find Maximum node in Tree\n");
        printf("5. Find Minimum node in Tree\n");
        printf("6. Deletion\n");
        printf("7. Deletion Minimum node\n");
        printf("8. Deletion Maximum node\n");
        printf("9. Exit\n");
        printf("====================================\n");
        printf("Enter the choice \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char ch;
            do
            {
                int val;
                printf("Enter the Element : ");
                scanf("%d", &val);

                insert(&root, val);

                printf("Do you want to continue (y/n) : \n");
                scanf(" %c", &ch);
            } while (ch != 'n');
        }
        break;

        case 2:
            Display(root);
            printf("\n");
            break;

        case 3:
        {
            int val;
            printf("Enter the Element which you want to search from the red black tree : ");
            scanf("%d", &val);

            if (Search(root, val) == FAILURE)
            {
                printf("Node not found \n");
            }
        }
        break;

        case 4:
            find_maximum(root);
            break;

        case 5:
            find_minimum(root);
            break;

        case 6:
        {
            int del;
            printf("Enter the node which you want to delete : ");
            scanf("%d", &del);
            if (rbDelete(&root, del) == SUCCESS)
            {
                printf("Node Delete SuccessFully \n");
            }
            else
            {
                printf("Node is not present in tree to delete \n");
            }
        }
        break;

        case 7:
            delete_minimum(&root);
            break;

        case 8:
            delete_maximum(&root);
            break;

        case 9:
            break;

        default:
            printf("Invalid Choice !!\n");
        }

    } while (choice != 9);
}