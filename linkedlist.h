#ifndef __LINKEDLIST__
#define __LINKEDLIST__
// Performing header file management to avoid duplicate inclusion of header file.


typedef struct _doublylinkedlist
{
    struct _doublylinkedlist *left;
    struct _doublylinkedlist *right;
} doublylinkedlist_t;
// We are implementing an updated version of Linked List where data is stored as
// a part of the node, not as a pointer which points to some structure.


// Declaring the functions to be defined in the c file.
void doubly_linkedlist_add_next(doublylinkedlist_t *base_doublylinkedlist, 
                                doublylinkedlist_t *new_doublylinkedlist);

void doubly_linkedlist_add_before(doublylinkedlist_t *base_doublylinkedlist,
                                    doublylinkedlist_t *new_doublylinkedlist);

void remove_doubly_linkedlist(doublylinkedlist_t *doublylinkedlist);

void initialize_doubly_linkedlist(doublylinkedlist_t *doublylinkedlist);

void doubly_linkedlist_add_last(doublylinkedlist_t *base_doublylinkedlist,
                                doublylinkedlist_t *new_doublylinkedlist);

void delete_doubly_linkedlist(doublylinkedlist_t *base_doublylinkedlist);

unsigned int get_doubly_linked_list_count(doublylinkedlist_t *base_doublylinkedlist);

void doubly_linkedlist_priority_insert(doublylinkedlist_t *base_doublylinkedlist,     
                                        doublylinkedlist_t *doublylinkedlist,
                                        int (*compare_function)(void *, void *),
                                        int offset);
// Finishing the declarations.


#define IS_DOUBLY_LINKED_LIST_EMPTY(dllptr)                                                                 \
    ((dllptr)->right == 0 && (dllptr)->left == 0)
// Checks if right and left pointers of the linked list are both empty, if so returns True.
// Else, it returns false.


#define BASE(dllptr)                                                                                        \
    ((dllptr)->right)
// Returns the Base Node (Starting Node) of the Linked List as the first right
// element will point to the starting node.


#define ITERATE_DOUBLY_LINKED_LIST_BEGINING(dllptr_start, dllptr)                                           \
{                                                                                                           \
    doublylinkedlist_t *_doublylinkedlist_ptr = NULL;                                                       \
    dllptr = BASE(dllptr_start);                                                                            \
    for(; dllptr!=NULL; dllptr = _doublylinkedlist_ptr)                                                     \
    {                                                                                                       \
        _doublylinkedlist_ptr = (dllptr)->right;

        #define ITERATE_DOUBLY_LINKED_LIST_END(dllptr_start, dllptr)                                        \
    }                                                                                                       \
}
// Iterates over the doubly linked list from the begining to end.
// Returns the next element in each iteration so as to achieve the loop, two declarations are required.
// Returns the link which doesn't have a '\' at the end of the line.
// To mark the continuity, another Macro is defined.


#define LINKED_LIST_DATA_FROM_OFFSET(dllptr, offset)                                                        \
    (void *)((char *)(dllptr) - offset)
// Returns the data pointer pointing to the data at a specified offset.
// (char *)(dllptr) : Converts the pointer to the character so that offset can be seperated and 
// address value is returned.
// (void *) typecasts the result to the void pointer so as to handle any type of the data.


#define LINKED_LIST_TO_STRUCT(function_name, structure_name, field_name)                                    \
    static inline structure_name * function_name(doublylinkedlist_t *dllptr)                                \
    {                                                                                                       \
        return (structure_name *)((char *)(dllptr) - (char *)&(((structure_name *)0)->field_name));         \
    }
// Takes a Linked List, and returns a structure part from it.


#endif
// Ending Header File Management