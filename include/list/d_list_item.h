#ifndef D_LIST_ITEM_H
#define D_LIST_ITEM_H

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <list/s_list_item.h>


/* Data Types --------------------------------------------------------------- */

typedef struct d_list_item {
  s_list_item_t      _super;
  struct d_list_item *prev;
} d_list_item_t;


/* Global Variables --------------------------------------------------------- */



/* Public Functions --------------------------------------------------------- */

void
  d_list_item__ctor(d_list_item_t *item);

/* Insert a list item between `item` and the item directly following it. If
 * `other` is connected to anything that whole chain will be inserted, with the
 * last item linking to item after `item`.
 */
void
  d_list_item__append(d_list_item_t *item, d_list_item_t *other);

/* Insert a list item between `item` and the item directly before it. If `other`
 * is connected to anything that whole chain will be inserted, with the last
 * item linking to `item`.
 */
void
  d_list_item__prepend(d_list_item_t *item, d_list_item_t *other);

/* Remove item from the chain it is connected to.
 */
void
  d_list_item__delete(d_list_item_t *item);

/* Returns the item directly before `item`. If `item` is the first one in the
 * chain NULL is returned.
 */
static inline d_list_item_t *
  d_list_item__prev(d_list_item_t const *item);

/* Returns the item directly after `item`. If `item` is the last one in the
 * chain NULL is returned.
 */
static inline d_list_item_t *
  d_list_item__next(d_list_item_t const *item);

/* Returns non zero if `item` is the first one in the chain.
 */
static inline bool_t
  d_list_item__is_first(d_list_item_t const *item);

/* Returns non zero if `item` is the last one in the chain.
 */
static inline bool_t
  d_list_item__is_last(d_list_item_t const *item);

/* Returns the first item in the chain connected to `item`.
 */
d_list_item_t *
  d_list_item__first(d_list_item_t const *item);

/* Returns the last item in the chain connected to `item`.
 */
static inline d_list_item_t *
  d_list_item__last(d_list_item_t const *item);


/* Inline Function Definitions ---------------------------------------------- */

d_list_item_t *d_list_item__prev(d_list_item_t const *item)
{
  assert(item != NULL);
  return item->prev;
}

d_list_item_t *d_list_item__next(d_list_item_t const *item)
{
  assert(item != NULL);
  return (d_list_item_t *) s_list_item__next(&item->_super);
}

bool_t d_list_item__is_first(d_list_item_t const *item)
{
  assert(item != NULL);
  /* The first item has a reference to the last item, so
     check if the previous item is the last. */
  return d_list_item__is_last(d_list_item__prev(item));
}

bool_t d_list_item__is_last(d_list_item_t const *item)
{
  assert(item != NULL);
  return s_list_item__is_last(&item->_super);
}

d_list_item_t *d_list_item__last(d_list_item_t const *item)
{
  assert(item != NULL);
  return (d_list_item_t *) s_list_item__last(&item->_super);
}

#endif /* d_list_item__H */
