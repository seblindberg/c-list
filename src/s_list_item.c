#include <s_list_item.h>


/* Private Functions -------------------------------------------------------- */



/* Public Function Definitions ---------------------------------------------- */

void s_list_item__ctor(s_list_item_t *item)
{
  /* Check parameters */
  assert(item != NULL);
  
  item->next = NULL;
}

/* Append one or more list items to this one. It will be linked in between this
 * and the next.
 */

void s_list_item__append(s_list_item_t *item, s_list_item_t *first)
{
  /* Check parameters */
  assert(item  != NULL);
  assert(first != NULL);
  
  s_list_item_t *next = item->next;
  s_list_item_t *last = s_list_item__last(first);
    
  item->next = first;
  last->next = next;
}

/* Append a single list item to this one. Use this function over
 * s_list_item__append for its performance.
 */
 
void s_list_item__append_single(s_list_item_t *item, s_list_item_t *other)
{
  s_list_item_t *next;
  
  /* Check parameters */
  assert(item != NULL);
  assert(other != NULL);
  assert(other->next == NULL);
  
  next        = item->next;
  item->next  = other;
  other->next = next;
}

/* Insert one or more list items after this one. For single items this is
 * equivalent to an append with the arguments reversed. Longer chains of items
 * will be spliced in between this item and the next.
 */

void s_list_item__prepend(s_list_item_t *item, s_list_item_t *first)
{
  s_list_item_t *last;
  
  /* Check parameters */
  assert(item != NULL);
  assert(first != NULL);
  
  last = s_list_item__last(first);
  
  last->next = item;
}

void s_list_item__prepend_single(s_list_item_t *item, s_list_item_t *first)
{
  /* Check parameters */
  assert(item != NULL);
  assert(first != NULL);
  assert(first->next == NULL);
  
  first->next = item;
}

/* Return the last list item in the chain of items connected to the given one.
 */
 
s_list_item_t *s_list_item__last(s_list_item_t const *item)
{
  s_list_item_t const *next;
  
  /* Check parameters */
  assert(item != NULL);
  
  for (;;) {
    next = item->next;
    
    if (next == NULL) {
      break;
    }
    
    item = next;
  }
  
  return (s_list_item_t *) item;
}


/* Private Function Definitions --------------------------------------------- */

