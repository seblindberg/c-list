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
  t_list__ctor(t_list_t *list);
  
static inline void
  t_list__ctor_with_list_item(t_list_t *list, s_list_item_t *item);

s_list_item_t *
  t_list__shift(t_list_t *list);
  
void
  t_list__unshift(t_list_t *list, s_list_item_t *item);

void
  t_list__push(t_list_t *list, s_list_item_t *item);

bool_t
  t_list__delete(t_list_t *t_list_t, s_list_item_t *item);

void
  t_list__unshift_list(t_list_t *list, t_list_t other);
  
void
  t_list__push_list(t_list_t *list, t_list_t other);

static inline size_t
  t_list__length(t_list_t const *list);
  
static inline void
  t_list__insert_ordered(t_list_t *list, s_list_item_t *item,
                         s_list__insert_handler_t handler);
                         
static inline bool_t
  t_list__include(t_list_t const *list, s_list_item_t const *item);
  
static inline bool_t
  t_list__is_empty(t_list_t const *list);
  
static inline s_list_item_t *
  t_list__first(t_list_t const *list);
  
static inline s_list_item_t *
  t_list__last(t_list_t const *list);


/* Macros ----------------------------------------+--------+----------------- */




/* Inline Function Definitions ---------------------------------------------- */

void t_list__ctor_with_list_item(t_list_t *list, s_list_item_t *item)
{
  s_list_item_t *tail = s_list_item__last(item);
  s_list__ctor_with_list_item(&list->_super, item);
  list->tail = tail;
}

bool_t t_list__is_empty(t_list_t const *list)
{
  return s_list__is_empty(&list->_super);
}

s_list_item_t *t_list__first(t_list_t const *list)
{
  return s_list__first(&list->_super);
}

s_list_item_t *t_list__last(t_list_t const *list)
{
  return list->tail;
}

/* Returns true it the list includes the given item.
 */
 
bool_t t_list__include(t_list_t const *list, s_list_item_t const *item)
{
  return s_list__include(&list->_super, item);
}

size_t t_list__length(t_list_t const *list)
{
  return s_list__length(&list->_super);
}


/* Insert a single item into the list acorording to the output of the given insert handler. The list item will be inserted before the first item for which the handler returns non-zero.
 */
 
void t_list__insert_ordered(t_list_t *list, s_list_item_t *item,
                            s_list__insert_handler_t handler)
{
  s_list__insert_ordered(&list->_super, item, handler);

  if (s_list_item__next(item) == NULL) {
    list->tail = item;
  }
}

#endif /* T_LIST_H */