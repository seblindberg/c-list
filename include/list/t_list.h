/* Singly Linked List With a Tail
 *
 * The singly linked list holds.
 */

#ifndef T_LIST_H
#define T_LIST_H

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <list/s_list_item.h>
#include <list/s_list.h>


/* Constants -------------------------------------+-------------------------- */




/* Data Types --------------------------------------------------------------- */

typedef struct t_list {
  s_list_t      _super;
  s_list_item_t *tail;
} t_list_t;


/* Global Variables --------------------------------------------------------- */




/* Public Functions --------------------------------------------------------- */

void
  t_list__ctor(t_list_t *list)
  NONNULL;

/* Initialize a list containing a list item.
 */
static inline void
  t_list__ctor_with_list_item(t_list_t *list, s_list_item_t *item)
  NONNULL;

/* Removes the first item from the list and returns it.
 */
s_list_item_t *
  t_list__shift(t_list_t *list)
  NONNULL;
  
/* Inserts `item` before the first item in the list. If `item` is connected to
 * anything that whole chain is inserted.
 */
void
  t_list__unshift(t_list_t *list, s_list_item_t *item)
  NONNULL;

/* Inserts `item` after the last item in the list. If `item` is connected to
 * anything that whole chain is inserted..
 */
void
  t_list__push(t_list_t *list, s_list_item_t *item)
  NONNULL;

/* Removes `item` from the list if it is included. Returns non zero if the item
 * was found and could be removed.
 */
bool_t
  t_list__delete(t_list_t *t_list_t, s_list_item_t *item)
  NONNULL;

void
  t_list__unshift_list(t_list_t *list, t_list_t *other)
  NONNULL;
  
void
  t_list__push_list(t_list_t *list, t_list_t *other)
  NONNULL;

/* Returns the number if items in the list.
 */
static inline size_t
  t_list__length(t_list_t const *list)
  NONNULL;
  
/* Insert `item` before the first item in the list for which `handler` returns
 * non zero, given the two items as arguments. See `s_list__insert_handler_t`
 * for the function signature.
 */
static inline void
  t_list__insert_ordered(t_list_t *list, s_list_item_t *item,
                         s_list__insert_handler_t handler)
  NONNULL;

/* Returns non zero if the list includes `item`.
 */
static inline bool_t
  t_list__include(t_list_t const *list, s_list_item_t const *item)
  NONNULL;
  
/* Return non zero if the list contains no items.
 */
static inline bool_t
  t_list__is_empty(t_list_t const *list)
  NONNULL;
 
/* Return the first item in the list.
 */
static inline s_list_item_t *
  t_list__first(t_list_t const *list)
  NONNULL;
  
/* Return the last item in the list.
 */
static inline s_list_item_t *
  t_list__last(t_list_t const *list)
  NONNULL;

/* Debug function for inspecting the contents of a list. Defining NDEBUG removes
 * this function completely.
 */
#ifndef NDEBUG
static inline void
  t_list__inspect(t_list_t const *list)
  NONNULL;
#else
#define t_list__inspect(list)
#endif

/* Macros ----------------------------------------+--------+----------------- */




/* Inline Function Definitions ---------------------------------------------- */

void
t_list__ctor_with_list_item(t_list_t *list, s_list_item_t *item)
{
  s_list_item_t *tail = s_list_item__last(item);
  s_list__ctor_with_list_item(&list->_super, item);
  list->tail = tail;
}

bool_t
t_list__is_empty(t_list_t const *list)
{
  return s_list__is_empty(&list->_super);
}

s_list_item_t *
t_list__first(t_list_t const *list)
{
  return s_list__first(&list->_super);
}

s_list_item_t *
t_list__last(t_list_t const *list)
{
  return list->tail;
}

bool_t
t_list__include(t_list_t const *list, s_list_item_t const *item)
{
  return s_list__include(&list->_super, item);
}

size_t
t_list__length(t_list_t const *list)
{
  return s_list__length(&list->_super);
}
 
void
t_list__insert_ordered(t_list_t *list, s_list_item_t *item,
                       s_list__insert_handler_t handler)
{
  s_list__insert_ordered(&list->_super, item, handler);

  if (s_list_item__next(item) == NULL) {
    list->tail = item;
  }
}

#ifndef NDEBUG
void
t_list__inspect(t_list_t const *list)
{
  s_list__inspect(&list->_super);
}
#endif

#endif /* T_LIST_H */