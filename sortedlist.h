
// Define guard to prevent compilation problems if we add the module more
//  than once in the project.
#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_

// Libraries
#include <stdlib.h>					// To use dynamic memory.

// Constants to manage the list's error codes.
#define LIST_NO_ERROR 0
#define LIST_ERROR_FULL 1			// Error, the list is full.
#define LIST_ERROR_EMPTY 2			// Error, the list is empty.
#define LIST_ERROR_MALLOC 3			// Error, a malloc failed.
#define LIST_ERROR_END 4			// Error, the POV is at the end.


// Data types
typedef struct{
    int circuit_number;
    char *name;
    int speed;
    int acceleration;
    int consumption;
    int reliability;
    float time;
    int pit_stop_time;
    int num_pit_stop;
}Element;

typedef struct _Node {
	Element element;
	struct _Node * next;
} Node;

typedef struct {
	int error;			// Error code to keep track of failing operations;
	Node * head;	 	// Head/First element or Phantom node;
	Node * previous; 	// Previous node before the point of view;
} SortedList;


// Procedures & Functions

/**************************************************************************** 
 *
 * @Objective: Creates an empty sorted list.
 *			   If the list fails to create the phantom node, it will set
 *				the error code to LIST_ERROR_MALLOC.
 *
 *        +---+
 *   head | o-|---------
 *        +---+         |
 *   prev | o-|---------|--
 *        +---+         | |
 *                      v v          Point of View (After the last element)
 *                    +---+----+   
 *                    |   |NULL| 
 *                    +---+----+   
 *
 * @Parameters: ---
 * @Return: An empty sorted list
 *
 ****************************************************************************/
SortedList SORTEDLIST_create ();


/**************************************************************************** 
 *
 * @Objective: Inserts the specified element in this list to the position
 *			    defined by the sorting algorithm. Shifts the point of view
 *				element (if any) and any subsequent elements to the right.
 *			   If the list fails to create the new node to store the element,
 *				it will set	the error code to LIST_ERROR_MALLOC.
 *
 * @Parameters: (in/out) list    = the sorted list where to add the new element
 *				(in)     element = the element to add to the list
 * @Return: ---
 *
 ****************************************************************************/
void 	SORTEDLIST_sortedAdd (SortedList * list, Element element);


/**************************************************************************** 
 *
 * @Objective: Removes the element currently at the point of view in this 
 *				list. Shifts any subsequent elements to the left.
 *			   This operation will fail if the POV is after the last valid
 *				element of the list. That will also happen for an empty list.
 *				In that situation, this operation will set the error code to
 *				LIST_ERROR_END.
  *
 *        +---+
 *   head | o-|---------                        aux (free aux!)
 *        +---+         |                        |
 *   prev | o-|---------|-----------             |
 *        +---+         |           |            |
 *                      v           v          	 v  POV         NEW POV
 *                    +---+---+   +---+---+     +---+---+     +---+----+ 
 *                    |   | o-|-->| 1 | o-|--X->| 2 | o-|---->| 3 |NULL| 
 *                    +---+---+   +---+---+ |   +---+---+     +---+----+
 *										    |                   ^
 *										    |                   |
 *										     -------------------
 *
 * @Parameters: (in/out) list = the sorted list where to remove the element
 * @Return: ---
 *
 ****************************************************************************/
void 	SORTEDLIST_remove (SortedList * list);


/**************************************************************************** 
 *
 * @Objective: Returns the element currently at the point of view in this list.
 *			   This operation will fail if the POV is after the last valid
 *				element of the list. That will also happen for an empty list.
 *				In that situation, this operation will set the error code to
 *				LIST_ERROR_END.
 * @Parameters: (in/out) list = the sorted list where to get the element.
 *								in/out because we need to set the error code.
 * @Return: ---
 *
 ****************************************************************************/
Element SORTEDLIST_get (SortedList * list);


/**************************************************************************** 
 *
 * @Objective: Returns true (!0) if this list contains no elements.
 * @Parameters: (in)     list = the sorted list to check
 * @Return: true (!0) if this list contains no elements, false (0) otherwise
 *
 ****************************************************************************/
int 	SORTEDLIST_isEmpty (SortedList list);


/**************************************************************************** 
 *
 * @Objective: Moves the point of view to the first element in the list.
 * @Parameters: (in/out) list = the sorted list to move the POV.
 * @Return: ---
 *
 ****************************************************************************/
void 	SORTEDLIST_goToHead (SortedList * list);


/**************************************************************************** 
 *
 * @Objective: Moves the point of view to the next element in the list.
 *				If the POV is after the last element in the list (or when 
 *				the list is empty), this function will set the list's error 
 *				to LIST_ERROR_END. 
 * @Parameters: (in/out) list = the sorted list to move the POV.
 * @Return: ---
 *
 ****************************************************************************/
void 	SORTEDLIST_next (SortedList * list);


/**************************************************************************** 
 *
 * @Objective: Returns true (!0) if the POV is after the last element in the
 *				list.
 * @Parameters: (in)     list = the sorted to check.
 * @Return: true (!0) if the POV is after the last element in the list
 *
 ****************************************************************************/
int 	SORTEDLIST_isAtEnd (SortedList list);


/**************************************************************************** 
 *
 * @Objective: Removes all the elements from the list and frees any dynamic
 *				memory block the list was using. The list must be created
 *				again before usage.
 * @Parameters: (in/out) list = the sorted list to destroy.
 * @Return: ---
 *
 ****************************************************************************/
void 	SORTEDLIST_destroy (SortedList * list);


/**************************************************************************** 
 *
 * @Objective: This function returns the error code provided by the last 
 *				operation run. The operations that update the error code are:
 *				Create, Add, Remove and Get.
 * @Parameters: (in)     list = the sorted list to check.
 * @Return: an error code from the list of constants defined.
 *
 ****************************************************************************/
int		SORTEDLIST_getErrorCode (SortedList list);


#endif

