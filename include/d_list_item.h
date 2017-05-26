#ifndef D_LIST_ITEM_H
#define D_LIST_ITEM_H

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <s_list_item.h>


/* Data Types --------------------------------------------------------------- */

typedef struct d_list_item {
  s_list_item_t      _super;
  struct d_list_item *prev;
} d_list_item_t;


/* Global Variables --------------------------------------------------------- */

/* Public Functions --------------------------------------------------------- */

void
  d_list_item__ctor(d_list_item_t *item);

void
  d_list_item__prepend(d_list_item_t *item, d_list_item_t *other);

void
  d_list_item__append(d_list_item_t *item, d_list_item_t *other);

void
  d_list_item__delete(d_list_item_t *item);

static inline d_list_item_t *
  d_list_item__prev(d_list_item_t const *item);

static inline d_list_item_t *
  d_list_item__next(d_list_item_t const *item);

static inline bool_t
  d_list_item__is_first(d_list_item_t const *item);

static inline bool_t
  d_list_item__is_last(d_list_item_t const *item);
  
d_list_item_t *
  d_list_item__first(d_list_item_t const *item);

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


/* The first item has a reference to the last item, so check if the previous
 * item is the last.
 */

bool_t d_list_item__is_first(d_list_item_t const *item)
{
  assert(item != NULL);
  return d_list_item__is_last(d_list_item__prev(item));
}


/* All items but the last one points to the next item.
 */

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
