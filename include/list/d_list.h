#ifndef D_LIST_H
#define D_LIST_H

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <s_list.h>
#include <d_list_item.h>


/* Data Types --------------------------------------------------------------- */

typedef struct {
  s_list_t _super;
} d_list_t;

typedef bool_t (*d_list__insert_handler_t)(d_list_item_t const *item,
                                           d_list_item_t const *compare_to);


/* Global Variables --------------------------------------------------------- */


/* Public Functions --------------------------------------------------------- */

void
  d_list__ctor(d_list_t *list)
  NONNULL;

/* Removes the first item from the list and returns it.
 */
d_list_item_t *
  d_list__shift(d_list_t *list)
  NONNULL;

/* Inserts `item` before the first item in the list. If `item` is connected to
 * anything that whole chain is inserted.
 */
void
  d_list__unshift(d_list_t *list, d_list_item_t *item)
  NONNULL;

/* Inserts `item` after the last item in the list. If `item` is connected to
 * anything that whole chain is inserted..
 */
void
  d_list__push(d_list_t *list, d_list_item_t *item)
  NONNULL;

/* Removes the last item from the list and returns it. Returns NULL if the list
 * is empty. */
d_list_item_t *
  d_list__pop(d_list_t *list)
  NONNULL;

/* Removes `item` from the list if it is included. Returns non zero if the item
 * was found and could be removed.
 */
void
  d_list__delete(d_list_t *list, d_list_item_t *item)
  NONNULL;

/* Insert a List Item at the first place in the list where
 * the insert handler returns a non zero integer. If the
 * list is empty the handler will not be called. */
void
  d_list__insert_ordered(d_list_t *list, d_list_item_t *item,
                         d_list_insert_handler_t handler)
  NONNULL;

/* Return non zero if the list contains no items.
 */
static inline bool_t
  d_list__is_empty(d_list_t const *list)
  NONNULL;

/* Returns non zero if the list includes `item`.
 */
static inline bool_t
  d_list__include(d_list_t const *list, d_list_item_t const *item)
  NONNULL;

/* Return the first item in the list.
 */
static inline d_list_item_t *
  d_list__first(d_list_t const *list)
  NONNULL;
  
static inline d_list_item_t *
  d_list__last(d_list_t const *list)
  NONNULL;

static inline size_t
  d_list__length(d_list_t const *list)
  NONNULL;


/* Inline Function Definitions ---------------------------------------------- */

bool_t
d_list__is_empty(d_list_t const *list)
{
  return s_list__is_empty(&list->_super);
}

bool_t
d_list__include(d_list_t const *list, d_list_item_t const *item)
{
  return s_list__include(&list->_super, (s_list_item_t const *) item);
}

d_list_item_t *
d_list__first(d_list_t const *list)
{
  return (d_list_item_t *) s_list__first(&list->_super);
}

d_list_item_t *
d_list__last(d_list_t const *list)
{
  d_list_item_t *first = d_list__first(list);
  
  if (first == NULL) {
    return NULL;
  }
  
  return d_list_item__prev(first);
}

size_t
d_list__length(d_list_t const *list)
{
  return s_list__length(&list->_super);
}

#endif /* D_LIST_H */
