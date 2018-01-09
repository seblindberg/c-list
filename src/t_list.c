#include <list/t_list.h>

/* Macros ----------------------------------------+-------------------------- */


/* Private Functions -------------------------------------------------------- */

static inline void
  delete(t_list_t *list, s_list_item_t *prev, s_list_item_t *item);


/* Public Function Definitions ---------------------------------------------- */

/* Setup an empty list.
 */
void
t_list__ctor(t_list_t *list)
{
  s_list__ctor(&list->_super);
  list->tail = NULL;
}

/* Remove the first item from the list and return it.
 */
s_list_item_t *
t_list__shift(t_list_t *list)
{
  s_list_item_t *head = s_list__shift(&list->_super);
  
  if (head == NULL) {
    return NULL;
  }
  
  if (s_list__is_empty(&list->_super)) {
    list->tail = NULL;
  }
  
  return head;
}

/* Put a new list item at the head of the list.
 */
void
t_list__unshift(t_list_t *list, s_list_item_t *item)
{
  if (s_list__is_empty(&list->_super)) {
    t_list__ctor_with_list_item(list, item);
    
    return;
  }
  
  s_list__unshift(&list->_super, item);
}

/* Put a new list item at the tail of the list.
 */
void
t_list__push(t_list_t *list, s_list_item_t *item)
{
  s_list_item_t *tail = list->tail;
  
  /* The list is empty. */
  if (tail == NULL) {
    t_list__ctor_with_list_item(list, item);
    return;
  }
  
  s_list_item__append(tail, item);
  list->tail = s_list_item__last(item);
}

/* Removes an item from the list. Returns non-zero if the item was found in the
 * list.
 */
bool_t
t_list__delete(t_list_t *list, s_list_item_t *item)
{
  s_list_item_t *prev_item;
  s_list_item_t *list_item = s_list__first(&list->_super);
  
  if (s_list__is_empty(&list->_super)) {
    return 0;
  }

  /* If the item to delete is the first one. */
  if (item == list_item) {
    t_list__shift(list);
    return 1;
  }

  /* Search for the item. */
  do {
    prev_item = list_item;
    list_item = s_list_item__next(list_item);
    
    if (list_item == item) {
      delete(list, prev_item, list_item);
      return 1;
    }
  } while (list_item != NULL);

  return 0;
}



/* Private Function Definitions --------------------------------------------- */

/* Delete an item in the list that is not the first one.
 */
void
delete(t_list_t *list, s_list_item_t *prev, s_list_item_t *item)
{
  prev->next = item->next;

  /* If deleting the last item in the list we must
     update the tail. */
  if (item->next == NULL) {
    list->tail = prev;
  }

  item->next = NULL;
}