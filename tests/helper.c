#include "helper.h"

/* Macros ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */



/* Private Functions –––––––––––––––––––––––––––––––––––––––––––––––––––––––– */




/* Global Variables ––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */




/* Function Definitions ––––––––––––––––––––––––––––––––––––––––––––––––––––– */

s_list_item_t *helper__create_s_list_items(uint_fast8_t num_items)
{
  static s_list_item_t items[HELPER__S_LIST_ITEMS_MAX];
  assert(num_items <= HELPER__S_LIST_ITEMS_MAX);

  for (uint_fast8_t i = 0; i < num_items; i ++) {
    s_list_item__ctor(&items[i]);
  }

  return items;
}

bool_t helper__s_list_items_chained(uint_fast8_t num_items, ...)
{
  bool_t         is_chained = 1;
  s_list_item_t *item;
  s_list_item_t *next;
  va_list        ap;

  if (num_items == 0) {
    return 1;
  }

  va_start(ap, num_items);

  item = va_arg(ap, s_list_item_t *);

  while (--num_items) {
    next = va_arg(ap, s_list_item_t *);

    if (s_list_item__next(item) != next) {
      is_chained = 0;
    }

    item = next;
  }

  if (!s_list_item__is_last(item)) {
    is_chained = 0;
  }

  va_end(ap);

  return is_chained;
}

s_list_t *helper__s_list()
{
  static s_list_t list;
  
  s_list__ctor(&list);
  
  return &list;
}

bool_t helper__s_list_contains(s_list_t *list, uint_fast8_t num_items, ...)
{
  s_list_item_t *item;
  va_list        ap;
    
  if (num_items == 0) {
    return s_list__is_empty(list);
  }
  
  item = s_list__first(list);
  
  va_start(ap, num_items);
  
  while (item != NULL) {
    if (item != va_arg(ap, s_list_item_t *)) {
      num_items = -1;
      break;
    }
    
    item = s_list_item__next(item);
    --num_items;
  }
  
  va_end(ap);
  
  return (num_items == 0);
}


t_list_t *helper__t_list()
{
  static t_list_t list;

  t_list__ctor(&list);

  return &list;
}

bool_t helper__t_list_contains(t_list_t *list, uint_fast8_t num_items, ...)
{
  s_list_item_t *item;
  s_list_item_t *arg_item;
  va_list        ap;

  if (num_items == 0) {
    return t_list__is_empty(list);
  }

  item = t_list__first(list);

  va_start(ap, num_items);

  while (item != NULL) {
    arg_item = va_arg(ap, s_list_item_t *);
    if (item != arg_item) {
      num_items = -1;
      break;
    }

    item = s_list_item__next(item);
    --num_items;
  }

  va_end(ap);
  
  if (t_list__last(list) != arg_item)
  {
    return 0;
  }

  return (num_items == 0);
}
