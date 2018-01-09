#ifndef S_LIST_ITEM_H
#define S_LIST_ITEM_H

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>


/* Data Types --------------------------------------------------------------- */

typedef struct s_list_item {
  struct s_list_item *next;
} s_list_item_t;


/* Public Functions --------------------------------------------------------- */

void
  s_list_item__ctor(s_list_item_t *item)
  NONNULL;

/* Insert a list item between `item` and the item directly following it. If
 * `other` is connected to anything that whole chain will be inserted, with the
 * last item linking to item after `item`. The last item connected to other is
 * returned.
 */
s_list_item_t *
  s_list_item__append(s_list_item_t *item, s_list_item_t *other)
  NONNULL;

/* Insert a single list item between `item` and the item directly following it.
 * Use `s_list_item__append` when `other` might be connected to something.
 */
void
  s_list_item__append_single(s_list_item_t *item, s_list_item_t *other)
  NONNULL;

/* Insert a list item between `item` and the item directly before it. If `other`
 * is connected to anything that whole chain will be inserted, with the last
 * item linking to `item`.
 */
s_list_item_t *
  s_list_item__prepend(s_list_item_t *item, s_list_item_t *other)
  NONNULL;

/* Insert a single list item between `item` and the item directly before it. Use
 * `s_list_item__prepend` when `other` might be connected to something.
 */
void
  s_list_item__prepend_single(s_list_item_t *item, s_list_item_t *other)
  NONNULL;

/* Returns the last item in the chain connected to `item`.
 */
s_list_item_t *
  s_list_item__last(s_list_item_t const *item)
  NONNULL;

/* Returns the item directly after `item`. If `item` is the last one in the
 * chain NULL is returned.
 */
static inline s_list_item_t *
  s_list_item__next(s_list_item_t const *item)
  NONNULL;
  
/* Returns non zero if `item` is the last one in the chain.
 */
static inline bool_t
  s_list_item__is_last(s_list_item_t const *item)
  NONNULL;


/* Inline Function Definitions ---------------------------------------------- */

s_list_item_t *
s_list_item__next(s_list_item_t const *item)
{
  return item->next;
}

bool_t
s_list_item__is_last(s_list_item_t const *item)
{
  return s_list_item__next(item) == NULL;
}


#endif /* s_list_item_H */