#include <list/s_list.h>

/* Macros ----------------------------------------+-------------------------- */

#define IS_EMPTY(list)                            ((list)->head == NULL)


/* Private Functions -------------------------------------------------------- */

static inline void shift(s_list_t *list);
static inline void delete(s_list_item_t *prev, s_list_item_t *item);


/* Public Function Definitions ---------------------------------------------- */

/* Setup an empty list.
 */
void s_list__ctor(s_list_t *list)
{
  list->head = NULL;
}

/* Remove the first item from the list and return it.
 */
s_list_item_t *s_list__shift(s_list_t *list)
{
  s_list_item_t *first_item;
  
  if (IS_EMPTY(list)) {
    return NULL;
  }
  
  first_item = list->head;
  shift(list);
    
  return first_item;
}

/* Put a new list item at the head of the list.
 */
void s_list__unshift(s_list_t *list, s_list_item_t *item)
{
  s_list_item_t *head = list->head;
  
  if (IS_EMPTY(list)) {
    s_list__ctor_with_list_item(list, item);
    return;
  }
  
  /* Insert the item at the head of the list. */
  s_list_item__prepend(head, item);
  list->head = item;
}

/* Put a new list item at the tail of the list.
 */
void s_list__push(s_list_t *list, s_list_item_t *item)
{
  s_list_item_t *tail = s_list__last(list);
  
  /* The list is empty. */
  if (tail == NULL) {
    s_list__ctor_with_list_item(list, item);
    return;
  }
  
  s_list_item__append(tail, item);
}

/* Returns true if the list includes the given item.
 */
bool_t s_list__include(s_list_t const *list, s_list_item_t const *item)
{
  s_list_item_t *s_list_item = list->head;
    
  while (s_list_item != NULL) {
    if (s_list_item == item) {
      return 1;
    }
    
    s_list_item = s_list_item->next;
  }
    
  return 0;
}

/* Removes an item from the list. Returns non-zero if the item was found in the
 * list.
 */
bool_t s_list__delete(s_list_t *list, s_list_item_t *item)
{
  s_list_item_t *prev_item;
  s_list_item_t *list_item = list->head;
  
  /* Nothing to delete. */
  if (IS_EMPTY(list)) {
    return 0;
  }
  
  /* If the item to delete is the first one. */
  if (item == list_item) {
    shift(list);
    return 1;
  }
  
  /* Search for the item. */
  do {
    prev_item = list_item;
    list_item = s_list_item__next(list_item);
    
    if (list_item == item) {
      delete(prev_item, list_item);
      return 1;
    }
  } while (list_item != NULL);
  
  return 0;
}

/* Returns the number of items in the list.
 */
size_t s_list__length(s_list_t const *list)
{
  size_t count = 0;
  s_list_item_t *list_item = list->head;
  
  while (list_item != NULL) {
    ++count;
    list_item = s_list_item__next(list_item);
  }
  
  return count;
}

/* Insert a single item into the list acorording to the output of the given insert handler. The list item will be inserted before the first item for which the handler returns non-zero.
 */
void s_list__insert_ordered(s_list_t *list, s_list_item_t *insert_item,
                            s_list__insert_handler_t handler)
{
  s_list_item_t *prev_item;
  s_list_item_t *list_item = list->head;
  
  if (IS_EMPTY(list)) {
    s_list__ctor_with_list_item(list, insert_item);
    return;
  }
  
  /* Check if the first item is the correct insertion point. */
  if (handler(insert_item, list_item)) {
    s_list_item__prepend(list_item, insert_item);
    list->head = insert_item;
    return;
  }
  
  for (;;) {
    prev_item = list_item;
    list_item = s_list_item__next(list_item);
    
    if (list_item == NULL) {
      break;
    }
    
    if (handler(insert_item, list_item)) {
      /* Same as a prepend to the list_item. */
      s_list_item__append(prev_item, insert_item);
      return;
    }
  }
  
  /* Else put the item last. prev_item will now point to the list tail. */
  s_list_item__append(prev_item, insert_item);
}

#ifndef NDEBUG
void s_list__inspect(s_list_t const *list)
{
  s_list_item_t *item;
  printf("The list (%zX) contains:\n", (size_t) list);
  
  item = s_list__first(list);
  
  while (item != NULL) {
    printf("  - (%zX)\n", (size_t) item);
    item = s_list_item__next(item);
  }
}
#endif


/* Private Function Definitions --------------------------------------------- */

/* Takes the first item in the list and removes it, making the second item the
 * new head. Note that this function assumes a non-empty list.
 */
void shift(s_list_t *list)
{
  s_list_item_t *head = list->head;
  
  /* Make the second item the new head of the list. */
  list->head = head->next;
  /* Clear the next field of the removed head. */
  head->next = NULL;
}

/* Delete an item in the list that is not the first one.
 */
void delete(s_list_item_t *prev, s_list_item_t *item)
{
  prev->next = item->next;
  item->next = NULL;
}