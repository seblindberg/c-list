#include <d_list_item.h>


/* Private Functions -------------------------------------------------------- */

static inline void
  set_next(d_list_item_t *item, d_list_item_t *next);

/* Function Definitions ----------------------------------------------------- */

/* Initialize a new list item.
 */

void d_list_item__ctor(d_list_item_t *item)
{
  assert(item != NULL);
  
  s_list_item__ctor(&item->_super);
  item->prev = item;
}

/*
 *
 */

void d_list_item__prepend(d_list_item_t *item, d_list_item_t *other)
{
  d_list_item_t *other_last;
  
  assert(item != NULL);
  assert(other != NULL);
  
  other_last = d_list_item__last(other);
  
  
  /* We need to consider two cases:
   * 1. This item is the current head, so the list will
   *    need to be updated.
   * 2. This item is not the head. */
  // if (d_list_item__is_first(list_item)) {
  //   if (list != NULL) {
  //     list->first = other_item;
  //   }
  // }
}

void d_list_item__append(d_list_item_t *item, d_list_item_t *other)
{
  assert(item != NULL);
  assert(other != NULL);
  
  // // Make sure that the list item does not already belong to
  // // a list as this operation would corrupt that it.
  // assert(other_item->prev == other_item);
  // assert(other_item->next == NULL);
  //
  // other_item->prev = list_item;
  // other_item->next = list_item->next;
  // other_item->list = list;
  //
  // if (list_item__is_last(list_item)) {
  //   list_item_t *list_head;
  //
  //   if (list != NULL) {
  //     list_head = list->first;
  //   } else {
  //     list_head = list_item->prev;
  //
  //     while (!list_item__is_first(list_head)) {
  //       list_head = list_head->prev;
  //     }
  //   }
  //
  //   list_head->prev = other_item;
  // }
  //
  // list_item->next = other_item;
}

/* Delete the list item. This action is efficient for all but the last item.
 */
 
void d_list_item__delete(d_list_item_t *item)
{
  d_list_item_t *prev;
  d_list_item_t *next;
  d_list_item_t *first;
  
  assert(item != NULL);
  
  prev = d_list_item__prev(item);
  next = d_list_item__next(item);
  
  if (next == NULL) {
    first = d_list_item__first(item);
    first->prev = prev;
    set_next(prev, NULL);
  } else {
    next->prev = prev;
    set_next(prev, next);
  }
  
//   list_t *list = (list_t *) list_item->list;
//
//   /* If this is the first item we need to make sure that
//    * a) the next one links up correctly with the last item,
//    * b) the list is updated to point to the next item, if we
//    * are in a list. */
//   if (list_item__is_first(list_item)) {
//     list_item_t *new_list_head;
//
//     if (list_item__is_last(list_item)) {
//       new_list_head = NULL;
//     } else {
//       new_list_head = list_item->next;
//       new_list_head->prev = list_item->prev;
//     }
//
//     if (list != NULL) {
//       list->first = new_list_head;
//     }
//
//     goto reset_list_item;
//   }
//
//   /* If we get to this point we know for sure that
//    * list_item->prev is a List Item. */
//
//   /* If the item is last we need to find the chain head and
//    * change its prev pointer. */
//   if (list_item__is_last(list_item)) {
//     list_item_t *list_head;
//
//     if (list != NULL) {
//       list_head = list->first;
//     } else {
//       list_head = list_item->prev;
//
//       while (!list_item__is_first(list_head)) {
//         list_head = list_head->prev;
//       }
//     }
//
//     list_head->prev = list_item->prev;
//     list_item->prev->next = NULL;
//
//     goto reset_list_item;
//   }
//
//   /* If we get to this point we know that the list_item is
//    * neither first or last. */
//
//   list_item->prev->next = list_item->next;
//   list_item->next->prev = list_item->prev;
//
// reset_list_item:
//   /* Call the constructor on this list item again to reset
//    * it. This will not touch the value!
//    * TODO: Consider if this is the correct action here. */
//   list_item__ctor(list_item);
}

d_list_item_t *d_list_item__first(d_list_item_t const *item)
{
  d_list_item_t const *prev;
  assert(item != NULL);
  
  for (;;)
  {
    prev = d_list_item__prev(item);
    
    if (d_list_item__is_last(prev)) {
      break;
    }
    
    item = prev;
  }
  
  return (d_list_item_t *) item;
}


void set_next(d_list_item_t *item, d_list_item_t *next)
{
  item->_super.next = (s_list_item_t *) next;
}
