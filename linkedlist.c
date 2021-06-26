#include "linkedlist.h"
#include <stdlib.h>
// Including the required header files.


void initialize_doubly_linkedlist(doublylinkedlist_t *doublylinkedlist)
{
    doublylinkedlist->left = NULL;
    doublylinkedlist->right = NULL;
}
// Takes a doubly linked list pointer, initialises the left as well as right pointer as null because at the begining 
// the doubly linked list is empty.


void doubly_linkedlist_add_next(doublylinkedlist_t *current_doublylinkedlist,
                                doublylinkedlist_t *new_doublylinkedlist)
{
// Adds an element at the next position of the current linked list node.

    if(!current_doublylinkedlist->right)
    {
    // If current linked list node's right is empty. (Ending Node)
        current_doublylinkedlist->right = new_doublylinkedlist;
        new_doublylinkedlist->left = current_doublylinkedlist;
        return;
        // Add new to right of current.
        // Add current to left of new.
    }

    // Else
    doublylinkedlist_t *temp = current_doublylinkedlist->right;
    current_doublylinkedlist->right = new_doublylinkedlist;
    new_doublylinkedlist->left = current_doublylinkedlist;
    new_doublylinkedlist->right = temp;
    temp->left = new_doublylinkedlist;
    // Assigns the right node to a temporary pointer.
    // Assign new node as right of current node and current to the left of new.
    // Assign temp to the right of new and point temp's left to new.
}


void doubly_linkedlist_add_before(doublylinkedlist_t *current_doublylinkedlist,
                                    doublylinkedlist_t *new_doublylinkedlist)
{
// Adds a element at the previous position of the current linked list.

    if(!current_doublylinkedlist->left)
    {
    // If current linked list node's left is empty. (Starting Node).
        new_doublylinkedlist->left = NULL;
        new_doublylinkedlist->right = current_doublylinkedlist;
        current_doublylinkedlist->left = new_doublylinkedlist;
        return;
        // Point left of new to NULL and right of new to current.
        // Point left of current to new.
    }
    
    doublylinkedlist_t *temp = current_doublylinkedlist->left;
    temp->right = new_doublylinkedlist;
    new_doublylinkedlist->left = temp;
    new_doublylinkedlist->right = current_doublylinkedlist;
    current_doublylinkedlist->left = new_doublylinkedlist;
    // Assign left of current to a temporary node.
    // Assign right of temp to new.
    // Assign left of new to temp and right of temp to current.
    // Assign left of current to new.
}


void remove_doubly_linkedlist(doublylinkedlist_t *current_doublylinkedlist)
{
// Removes the current node from doubly linked list.
    
    if(!current_doublylinkedlist->left)
    {
    // If left node is empty (First Node)

        if(current_doublylinkedlist->right)
        {
        // If right node is present (Linked List is not empty)
            current_doublylinkedlist->right->left = NULL;
            current_doublylinkedlist->right = 0;
            return;
            // Assign left of right of current to NULL
            // Assign right of current to 0
        }
        return;
    }

    if(!current_doublylinkedlist->right)
    {
    // If right node is empty (Last Node),
        current_doublylinkedlist->left->right = NULL;
        current_doublylinkedlist->left = NULL;
        return;
        // Assign null to right of left of current (Second Last Node)
        // Assign null to left of current node
    }

    // Else,
    current_doublylinkedlist->left->right = current_doublylinkedlist->right;
    current_doublylinkedlist->right->left = current_doublylinkedlist->left;
    current_doublylinkedlist->left = 0;
    current_doublylinkedlist->right = 0;
    // Assign right of previous node to next node.
    // Assign previous node to left of next node.
}


void delete_doubly_linkedlist(doublylinkedlist_t *base_doublylinkedlist)
{
// Deletes the whole doubly linked list by iterating from begining to end.

    doublylinkedlist_t *dllptr = NULL;
    // Create a pointer to iterate so that valuecan be assigned.
               
    ITERATE_DOUBLY_LINKED_LIST_BEGINING(base_doublylinkedlist, dllptr)
    {
        remove_doubly_linkedlist(dllptr);
    } ITERATE_DOUBLY_LINKED_LIST_END(base_doublylinkedlist, dllptr);
    // Using macrodefined loop to iterate over each element of list.
}


void doubly_linkedlist_add_last(doublylinkedlist_t *base_doublylinkedlist,
                                doublylinkedlist_t *new_doublylinkedlist)
{
// Adds an element to the last of a linked list.

    doublylinkedlist_t *dllptr = NULL;
    doublylinkedlist_t *prevdllptr = NULL;
    // Assigns a null pointer to be used later.
    
    ITERATE_DOUBLY_LINKED_LIST_BEGINING(base_doublylinkedlist, dllptr)
    {
        prevdllptr = dllptr;
    } ITERATE_DOUBLY_LINKED_LIST_END(base_doublylinkedlist, dllptr);
    // Using macrodefined loop to iterate over each element of list to reach to the end of the list.
  
    if(prevdllptr)
    {
        doubly_linkedlist_add_next(prevdllptr, new_doublylinkedlist);
        // If the list has any element, add it to the last of linked list.
    }
    else
    {
        doubly_linkedlist_add_next(base_doublylinkedlist, new_doublylinkedlist);
        // If the linked list is empty, then add the new element to the base of the linked list.
    }
}


unsigned int get_doubly_linked_list_count(doublylinkedlist_t *base_doublylinkedlist)
{
// Returns the count of elements present in the linked list.

    unsigned int count = 0;
    doublylinkedlist_t *dllptr = NULL;
    // Variables initialised for further use.

    ITERATE_DOUBLY_LINKED_LIST_BEGINING(base_doublylinkedlist, dllptr)
    {
        count++;
    } ITERATE_DOUBLY_LINKED_LIST_END(base_doublylinkedlist, dllptr);
    // Using macrodefined loop to iterate over each element of list and increasing the count on each iteration.

    return count;
    // Returning the count variable as expected by the function.
}


void doubly_linkedlist_priority_insert(doublylinkedlist_t *base_doublylinkedlist, 
                                        doublylinkedlist_t *doublylinkedlist,
                                        int (*compare_function)(void *, void *),
                                        int offset)
{
// Performing priority insertion on a linked list.

    doublylinkedlist_t *current = NULL;
    doublylinkedlist_t *previous = NULL;
    // Initialising the pointers to be used later.

    initialize_doubly_linkedlist(doublylinkedlist);
    // Initialising the doubly linked list.

    if(IS_DOUBLY_LINKED_LIST_EMPTY(base_doublylinkedlist))
    {
    // Checking if doubly linked list is empty.

        doubly_linkedlist_add_next(base_doublylinkedlist, doublylinkedlist);
        return;
        // Adding the node to the begining of the list.
    }

    if(base_doublylinkedlist->right && !base_doublylinkedlist->right->right)
    {
    // If only one node is present in the linked list.

        if(compare_function(LINKED_LIST_DATA_FROM_OFFSET(base_doublylinkedlist->right, offset), 
                            LINKED_LIST_DATA_FROM_OFFSET(doublylinkedlist, offset)) == -1)
        {
            doubly_linkedlist_add_next(base_doublylinkedlist->right, doublylinkedlist);
        }
        else
        {
            doubly_linkedlist_add_next(base_doublylinkedlist, doublylinkedlist);
        }
        // Compares the priority of the elements in the list and check whose priority is greater, then adding accordingly.
        return;
    }

    if(compare_function(LINKED_LIST_DATA_FROM_OFFSET(doublylinkedlist, offset), 
                        LINKED_LIST_DATA_FROM_OFFSET(base_doublylinkedlist->right, offset)) == -1)
    {
        doubly_linkedlist_add_next(base_doublylinkedlist, doublylinkedlist);
        // Compares the priority of the elements in the list and check whose priority is greater, then adding accordingly at the begining
        return;
    }

    ITERATE_DOUBLY_LINKED_LIST_BEGINING(base_doublylinkedlist, current)
    {
        if(compare_function(LINKED_LIST_DATA_FROM_OFFSET(doublylinkedlist, offset), 
                            LINKED_LIST_DATA_FROM_OFFSET(current, offset)) != -1)
        {
            previous = current;
            continue;
        }

        doubly_linkedlist_add_next(current, doublylinkedlist);
        return;
    } ITERATE_DOUBLY_LINKED_LIST_END(base_doublylinkedlist, current);
    // Iterating the list completely to check the priority and add at the specified position.

    doubly_linkedlist_add_next(previous, doublylinkedlist);
    // If no condition is satisfied, then adding to the last of linked list.
} 