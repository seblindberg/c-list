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
  s_list_item__ctor(s_list_item_t *item);

void
  s_list_item__append(s_list_item_t *item, s_list_item_t *first);
  
void
  s_list_item__append_single(s_list_item_t *item, s_list_item_t *other);

void
  s_list_item__prepend(s_list_item_t *item, s_list_item_t *first);
  
void
  s_list_item__prepend_single(s_list_item_t *item, s_list_item_t *first);

s_list_item_t *
  s_list_item__last(s_list_item_t const *item);

static inline s_list_item_t *
  s_list_item__next(s_list_item_t const *item);
  
static inline bool_t
  s_list_item__is_last(s_list_item_t const *item);


/* Inline Function Definitions ---------------------------------------------- */

s_list_item_t *s_list_item__next(s_list_item_t const *item)
{
  return item->next;
}

bool_t s_list_item__is_last(s_list_item_t const *item)
{
  return item->next == NULL;
}


#endif /* s_list_item_H */