#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void traversal(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
        printf("%d ", tmp->data);
    printf("\n");
}

int search(Node *head, int key)
{
    Node *tmp = head;
    int index = 0;
    while (tmp != NULL)
    {
        if (tmp->data == key)
        {
            return index;
        }
        else
        {
            index++;
            tmp = tmp->next;
        }
    }
    return -1;
}

int length(Node *head)
{
    int count = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

int insertAtBeginning(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Memory error");
        return -1;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return 1;
}

int insertAtTheEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Memory error");
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return 1;
}

int insertAtPosition(Node **head, int data, int position)
{
    if (position < 1 || position > length(*head) + 1)
    {
        perror("Invalid position");
        return -1;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Memory error");
        return -1;
    }

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *tmp = *head;
        int count = 1;
        while (tmp != NULL && count < position - 1)
        {
            count++;
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    return 1;
}

int deleteAtBeginning(Node **head)
{
    if (*head == NULL)
    {
        perror("List is empty");
        return -1;
    }
    Node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
    return 1;
}

int deleteAtEnd(Node **head)
{
    if (*head == NULL)
    {
        perror("List is empty");
        return -1;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        Node *tmp = *head;
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        free(tmp->next);
        tmp->next = NULL;
    }
    return 1;
}

int deleteAtPosition(Node **head, int position)
{
    if (position < 1 || position > length(*head))
    {
        perror("Invalid position");
        return -1;
    }
    if (*head == NULL)
    {
        perror("List is empty");
        return -1;
    }

    if (position == 1)
    {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    else
    {
        Node *tmp = *head;
        int count = 1;
        while (tmp != NULL && count < position - 1)
        {
            count++;
            tmp = tmp->next;
        }
        Node *tmp1 = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp1);
    }
    return 1;
}
