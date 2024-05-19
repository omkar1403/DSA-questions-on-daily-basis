/*isme maine kaise dummyhead ka use kiya hai vo dekho and passed it using
curr and then different element vo notice karo*/

Node *intersect_ll(Node *L1, Node *L2)
{
    Node *curr1 = L1;
    Node *curr2 = L2;
    Node *dummyhead = new Node(0);
    Node *curr = dummyhead;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data > curr2->data)
        {
            curr2 = curr2->next;
        }
        else if (curr1->data < curr2->data)
        {
            curr1 = curr1->next;
        }
        else if (curr1->data == curr2->data)
        {
            curr->next = new Node(curr1->data);
            curr = curr->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    Node *curr3 = dummyhead;
    curr3 = curr3->next;
    return curr3;
}