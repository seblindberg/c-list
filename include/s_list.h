/* Singly Linked List
 *
 */

#ifndef S_LIST_H
#define S_LIST_H

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <s_list_item.h>


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
  s_list__ctor(s_list_t *list);
  
static inline void
  s_list__ctor_with_list_item(s_list_t *list, s_list_item_t *item);

s_list_item_t *
  s_list__shift(s_list_t *list);
  
void
  s_list__unshift(s_list_t *list, s_list_item_t *item);
  
void
  s_list__push(s_list_t *list, s_list_item_t *item);

bool_t
  s_list__include(s_list_t const *list, s_list_item_t const *item);
  
bool_t
  s_list__delete(s_list_t *s_list_t, s_list_item_t *item);

size_t
  s_list__length(s_list_t const *list);

void
  s_list__insert_ordered(s_list_t *list, s_list_item_t *item,
                         s_list__insert_handler_t handler);

void
  s_list__unshift_list(s_list_t *list, s_list_t other);
  
void
  s_list__push_list(s_list_t *list, s_list_t other);

static inline bool_t
  s_list__is_empty(s_list_t const *list);
  
static inline s_list_item_t *
  s_list__first(s_list_t const *list);
  
static inline s_list_item_t *
  s_list__last(s_list_t const *list);
  
#ifndef NDEBUG
void
  s_list__inspect(s_list_t const *list);
#endif

/* Macros ----------------------------------------+--------+----------------- */




/* Inline Function Definitions ---------------------------------------------- */

void s_list__ctor_with_list_item(s_list_t *list, s_list_item_t *item)
{
  assert(s_list__is_empty(list));
  list->head = item;
}

bool_t s_list__is_empty(s_list_t const *list)
{
  assert(list != NULL);
  return list->head == NULL;
}

s_list_item_t *s_list__first(s_list_t const *list)
{
  assert(list != NULL);
  return list->head;
}

s_list_item_t *s_list__last(s_list_t const *list)
{
  assert(list != NULL);
  if (list->head == NULL) {
    return NULL;
  }
  
  return s_list_item__last(list->head);
}

#endif /* S_LIST_H */