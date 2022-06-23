#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coefficient;
    int exponent;
    struct node* next;
};

void Display(struct node *head)
{
    if (head == NULL)
        printf("there is no input given");

    else
    {
        struct node *temp = head;

        while (temp != NULL)
        {
            printf("(%.1fx^%d) ", temp->coefficient, temp->exponent);

            temp = temp->next;

            if (temp != NULL)
                printf("+");

            else
                printf("\n");
        }
    }
};
struct node *insert(struct node *head, float coeff, int ex)
{
    struct node *temp;
    struct node *nl = malloc(sizeof(struct node));
    nl->coefficient = coeff;
    nl->exponent = ex;
    nl->next = NULL;

    if (head == NULL || ex > head->exponent)
    {
        nl->next = head;
        head = nl;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exponent >= ex)
            temp = temp->next;

        nl->next = temp->next;
        temp->next = nl;
    }

    return head;
};
struct node *Create(struct node *head)
{
    int i, n, ex;
    float coeff;
    printf("enter total number of terms \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter coefficient of term %d \n", i + 1);
        scanf("%f", &coeff);
        printf("enter exponent of term %d \n", i + 1);
        scanf("%d", &ex);

        head = insert(head, coeff, ex);
    }
    printf("your polynomial is \n");
    Display(head);
    return head;
};

void Addition(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exponent == ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exponent > ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent < ptr2->exponent)
        {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }
    Display(head3);
};
void Subtraction(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exponent == ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient - ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        else if (ptr1->exponent < ptr2->exponent)
        {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
        else if (ptr1->exponent > ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
    }

    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        head3 = insert(head3, -ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }
    Display(head3);
};

void Multiplication(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    if (head1 == NULL && head2 == NULL)
    {
        printf("no input provided ");
        return;
    }

    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coefficient * ptr2->coefficient, ptr1->exponent + ptr2->exponent);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }
    struct node *ptr3 = head3;
    struct node *temp = NULL;
    while (ptr3->next != NULL)
    {
        if (ptr3->exponent == ptr3->next->exponent)
        {

            ptr3->coefficient = ptr3->coefficient + ptr3->next->coefficient;
            temp = ptr3->next;

            ptr3->next = ptr3->next->next;
            free(temp);
        }
        else
        {
            ptr3 = ptr3->next;
        }
    }
    Display(head3);
};
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf(" first expression  \n");
    head1 = Create(head1);

    printf(" second expression  \n");
    head2 = Create(head2);
    printf("\n\n");
    printf("result of Addition is \n");
    Addition(head1, head2);
    printf("\n\n");
    printf("result of subtraction is \n");
    Subtraction(head1, head2);
      printf("\n\n");
    printf("result of Multiplicationtion is \n");
    Multiplication(head1, head2);

    return 0;
}