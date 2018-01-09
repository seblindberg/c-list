/* Singly Linked List
 *
 */

#ifndef S_LIST_H
#define S_LIST_H

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <list/s_list_item.h>


/* Constants -------------------------------------+-------------------------- */




/* Data Types --------------------------------------------------------------- */

typedef struct s_list {
  s_list_item_t *head;
} s_list_t;

typedef bool_t (*s_list__insert_handler_t)(s_list_item_t const *item,
                                           s_list_item_t const *compare_to);

/* Global Variables --------------------------------------------------------- */




/* Public Functions --------------------------------------------------------- */

void
  s_list__ctor(s_list_t *list)
  NONNULL;
  
/* Initialize a list containing a list item.
 */
static inline void
  s_list__ctor_with_list_item(s_list_t *list, s_list_item_t *item)
  NONNULL;

/* Removes the first item from the list and returns it.
 */
s_list_item_t *
  s_list__shift(s_list_t *list)
  NONNULL;
  
/* Inserts `item` before the first item in the list. If `item` is connected to
 * anything that whole chain is inserted.
 */
void
  s_list__unshift(s_list_t *list, s_list_item_t *item)
  NONNULL;
  
/* Inserts `item` after the last item in the list. Note that the performance of
 * this call depends on the length of the list. Prefer using `s_list__unshift
 * ` or switch to using `t_list`.
 */
void
  s_list__push(s_list_t *list, s_list_item_t *item)
  NONNULL;

/* Returns non zero if the list includes `item`.
 */
bool_t
  s_list__include(s_list_t const *list, s_list_item_t const *item)
  NONNULL;
  
/* Removes `item` from the list if it is included. Returns non zero if the item
 * was found and could be removed.
 */
bool_t
  s_list__delete(s_list_t *s_list_t, s_list_item_t *item)
  NONNULL;

/* Returns the number if items in the list.
 */
size_t
  s_list__length(s_list_t const *list)
  NONNULL;

/* Insert `item` before the first item in the list for which `handler` returns
 * non zero, given the two items as arguments. See `s_list__insert_handler_t`
 * for the function signature.
 */
void
  s_list__insert_ordered(s_list_t *list, s_list_item_t *item,
                         s_list__insert_handler_t handler)
  NONNULL;

void
  s_list__unshift_list(s_list_t *list, s_list_t *other)
  NONNULL;
  
void
  s_list__push_list(s_list_t *list, s_list_t *other)
  NONNULL;

/* Return non zero if the list contains no items.
 */
static inline bool_t
  s_list__is_empty(s_list_t const *list)
  NONNULL;
  
/* Return the first item in the list.
 */
static inline s_list_item_t *
  s_list__first(s_list_t const *list)
  NONNULL;
  
/* Return the last list item in the list. Note that the performance of this call
 * depends on the length of the list. Prefer using `t_list` if this is an issue.
 */
static inline s_list_item_t *
  s_list__last(s_list_t const *list)
  NONNULL;
  
/* Debug function for inspecting the contents of a list. Defining NDEBUG removes
 * this function completely.
 */
#ifndef NDEBUG
void
  s_list__inspect(s_list_t const *list)
  NONNULL;
#else
#define s_list__inspect(list)
#endif

/* Macros ----------------------------------------+--------+----------------- */




/* Inline Function Definitions ---------------------------------------------- */

void
s_list__ctor_with_list_item(s_list_t *list, s_list_item_t *item)
{
  list->head = item;
}

bool_t
s_list__is_empty(s_list_t const *list)
{
  return list->head == NULL;
}

s_list_item_t *
s_list__first(s_list_t const *list)
{
  return list->head;
}

s_list_item_t *
s_list__last(s_list_t const *list)
{
  if (list->head == NULL) {
    return NULL;
  }
  
  return s_list_item__last(list->head);
}

#endif /* S_LIST_H */