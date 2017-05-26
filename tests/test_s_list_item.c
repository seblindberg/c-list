/*
 * Run with arguments
 *   -I../include ../lib/s_list_item.c ../lib/s_list.c ../lib/t_list.c
 */

#include <compiler.h>
#include <s_list_item.h>

#include "helper.h"

/* Perform tests on a single list item.
 */
void test__single_item(void)
{
  s_list_item_t s_list_item;
  
  s_list_item__ctor(&s_list_item);
  
  assert(s_list_item__is_last(&s_list_item));
  assert(s_list_item__next(&s_list_item) == NULL);
}

void test__append(void)
{
  s_list_item_t *item = helper__create_s_list_items(4);
  
  /* 0 -> 1 */
  s_list_item__append(&item[0], &item[1]);
  
  assert(helper__s_list_items_chained(2,
    &item[0], &item[1]));
    
  /* 2 -> 3 */
  s_list_item__append(&item[2], &item[3]);
  
  /* 0 -> 2 -> 3 -> 1 */
  s_list_item__append(&item[0], &item[2]);
  
  assert(helper__s_list_items_chained(4,
    &item[0], &item[2], &item[3], &item[1]));
}

void test__append_single(void)
{
  s_list_item_t *item = helper__create_s_list_items(3);
  
  /* 0 -> 1 */
  s_list_item__append_single(&item[0], &item[1]);
  
  assert(helper__s_list_items_chained(2,
    &item[0], &item[1]));
    
  /* 0 -> 1 -> 2 */
  s_list_item__append_single(&item[1], &item[2]);
  
  assert(helper__s_list_items_chained(3,
    &item[0], &item[1], &item[2]));
}

void test__prepend(void)
{
  s_list_item_t *item = helper__create_s_list_items(3);
  
  /* 1 -> 0 */
  s_list_item__prepend(&item[0], &item[1]);
  
  assert(helper__s_list_items_chained(2,
    &item[1], &item[0]));
  
  /* 1 -> 0 -> 2 */
  s_list_item__prepend(&item[2], &item[1]);
  
  assert(helper__s_list_items_chained(3,
    &item[1], &item[0], &item[2]));
}

void test__prepend_single(void)
{
  s_list_item_t *item = helper__create_s_list_items(3);
  
  /* 1 -> 0 */
  s_list_item__prepend(&item[0], &item[1]);
  
  assert(helper__s_list_items_chained(2,
    &item[1], &item[0]));
  
  /* 1 -> 0 -> 2 */
  s_list_item__prepend(&item[2], &item[0]);
  
  assert(helper__s_list_items_chained(3,
    &item[1], &item[0], &item[2]));
}

void test__last(void)
{
  s_list_item_t *item = helper__create_s_list_items(3);
  
  /* 0 -> 1 */
  s_list_item__append_single(&item[0], &item[1]);
  
  assert(s_list_item__last(&item[0]) == &item[1]);
  
  /* 0 -> 1 -> 2 */
  s_list_item__append_single(&item[1], &item[2]);
  
  assert(s_list_item__last(&item[0]) == &item[2]);
}

void test__delete()
{
  
}


int main(int argc, char *argv[])
{
  test__single_item();
  test__append();
  test__append_single();
  test__prepend();
  test__prepend_single();
  test__last();
  
  return 0;
}