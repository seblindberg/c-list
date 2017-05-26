/*
 * Run with arguments
 *   -I../include ../lib/s_list_item.c ../lib/s_list.c ../lib/t_list.c
 */

#include <compiler.h>
#include <s_list_item.h>
#include <t_list.h>

#include "helper.h"

void test__empty()
{
  t_list_t list;

  t_list__ctor(&list);

  assert(t_list__is_empty(&list));
  assert(t_list__length(&list) == 0);
  assert(t_list__first(&list) == NULL);
  assert(t_list__last(&list) == NULL);
}

void test__push()
{
  t_list_t      *list = helper__t_list();
  s_list_item_t *item = helper__create_s_list_items(2);

  t_list__push(list, &item[0]);
  assert(helper__t_list_contains(list, 1, &item[0]));

  t_list__push(list, &item[1]);
  assert(helper__t_list_contains(list, 2, &item[0], &item[1]));
}

void test__unshift(void)
{
  t_list_t      *list = helper__t_list();
  s_list_item_t *item = helper__create_s_list_items(3);

  t_list__unshift(list, &item[0]);
  assert(helper__t_list_contains(list, 1, &item[0]));

  /* Connect item 1 and 2 in advance */
  s_list_item__append(&item[1], &item[2]);

  t_list__unshift(list, &item[1]);
  assert(helper__t_list_contains(list, 3,
    &item[1], &item[2], &item[0]));
}


void test__shift(void)
{
  t_list_t      *list = helper__t_list();
  s_list_item_t *item = helper__create_s_list_items(2);
  s_list_item_t *ret;

  t_list__push(list, &item[0]);
  t_list__push(list, &item[1]);

  ret = t_list__shift(list);

  assert(ret == &item[0]);
  assert(helper__t_list_contains(list, 1, &item[1]));

  assert(s_list_item__next(&item[0]) == NULL);
}

void test__list_length(void)
{
  t_list_t      *list = helper__t_list();
  s_list_item_t *item = helper__create_s_list_items(2);

  t_list__push(list, &item[0]);
  assert(t_list__length(list) == 1);

  t_list__unshift(list, &item[1]);
  assert(t_list__length(list) == 2);

  t_list__shift(list);
  assert(t_list__length(list) == 1);
}

bool_t insert_handler(s_list_item_t const *item, s_list_item_t const *other)
{
  return ((size_t) other) > ((size_t) item);
}

void test__insert_ordered()
{
  t_list_t      *list = helper__t_list();
  s_list_item_t *item = helper__create_s_list_items(3);

  t_list__insert_ordered(list, &item[1], insert_handler);
  assert(helper__t_list_contains(list, 1, &item[1]));

  t_list__insert_ordered(list, &item[0], insert_handler);
  assert(helper__t_list_contains(list, 2, &item[0], &item[1]));

  t_list__insert_ordered(list, &item[2], insert_handler);
  assert(helper__t_list_contains(list, 3, &item[0], &item[1], &item[2]));
}

void test__delete()
{
  t_list_t      *list = helper__t_list();
  s_list_item_t *item = helper__create_s_list_items(2);
  bool_t         res;

  t_list__push(list, &item[0]);
  t_list__push(list, &item[1]);

  res = t_list__delete(list, &item[1]);
  assert(res);
  assert(helper__t_list_contains(list, 1, &item[0]));
  assert(s_list_item__next(&item[1]) == NULL);

  res = t_list__delete(list, &item[0]);
  assert(res);
  assert(helper__t_list_contains(list, 0));

  res = t_list__delete(list, &item[0]);
  assert(!res);
}

int main(int argc, char *argv[])
{
  test__empty();
  test__push();
  test__unshift();
  test__shift();
  test__list_length();
  test__insert_ordered();
  test__delete();

  return 0;
}