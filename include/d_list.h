#ifndef LIST_H
#define LIST_H

/* Includes ----------------------------------------------------------------- */

#include "compiler.h"

#include "list_item.h"


/* Data Types --------------------------------------------------------------- */

typedef struct list {
  list_item_t *first;
} list_t;

typedef uint8_t (*list_insert_handler_t)(list_item_t const *item_a,
                                         list_item_t const *item_b);


/* Global Variables --------------------------------------------------------- */


/* Public Functions --------------------------------------------------------- */

/* List contrsuctor. */
void list__ctor(list_t *list);

/* Insert a List Item at the end of the list. */
bool_t list__push(list_t *list, list_item_t *list_item);

/* Insert a List Item at the beginning of the list. */
bool_t list__unshift(list_t *list, list_item_t *list_item);

bool_t list__delete(list_t *list, list_item_t *list_item);

/* Remove the last List Item from the list. Returns NULL if
 * the list is empty. */
list_item_t *list__pop(list_t *list);

/* Remove the first List Item from the list. Returns NULL if
 * the list is empty. */
list_item_t *list__shift(list_t *list);

/* Insert a List Item at the first place in the list where
 * the insert handler returns a non zero integer. If the
 * list is empty the handler will not be called. */
void list__insert_before(list_t *list, list_item_t *list_item,
                         list_insert_handler_t handler);
                        
uint8_t list__is_empty(list_t const *list);

uint8_t list__include(list_t const *list, list_item_t const *list_item);

size_t list__length(list_t const *list);

list_item_t *list__first(list_t const *list);
list_item_t *list__last(list_t const *list);

#endif /* LIST_H */
