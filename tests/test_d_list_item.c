#include <compiler.h>
#include <list/d_list_item.h>

/* Perform tests on a single list item.
 */
void test_single_item(void)
{
	d_list_item_t item;
	
	d_list_item__ctor(&item);
	
	assert(d_list_item__is_first(&item));
	assert(d_list_item__is_last(&item));
	
	assert(d_list_item__next(&item) == NULL);
	assert(d_list_item__prev(&item) == &item);
	assert(d_list_item__first(&item) == &item);
	assert(d_list_item__first(&item) == &item);
}

void test_append(void)
{
	d_list_item_t item_a;
	d_list_item_t item_b;
	
	d_list_item__ctor(&item_a);
	d_list_item__ctor(&item_b);
	d_list_item__append(&item_a, &item_b);
	
	assert(d_list_item__is_first(&item_a));
	assert(!d_list_item__is_last(&item_a));
	
	assert(!d_list_item__is_first(&item_b));
	assert(d_list_item__is_last(&item_b));
	
	assert(d_list_item__prev(&item_a) == &item_b);
	assert(d_list_item__next(&item_a) == &item_b);
	assert(d_list_item__prev(&item_b) == &item_a);
	assert(d_list_item__next(&item_b) == NULL);
}

void test_prepend(void)
{
	d_list_item_t item_a;
	d_list_item_t item_b;
	
	d_list_item__ctor(&item_a);
	d_list_item__ctor(&item_b);
	
	d_list_item__prepend(&item_a, &item_b);
	
	assert(d_list_item__is_first(&item_b));
	assert(!d_list_item__is_last(&item_b));
	
	assert(!d_list_item__is_first(&item_a));
	assert(d_list_item__is_last(&item_a));
	
	assert(d_list_item__prev(&item_a) == &item_b);
	assert(d_list_item__next(&item_a) == NULL);
	assert(d_list_item__prev(&item_b) == &item_a);
	assert(d_list_item__next(&item_b) == &item_a);
}

void test_delete(void)
{
	d_list_item_t item_a;
	d_list_item_t item_b;
	d_list_item_t item_c;
	
	d_list_item__ctor(&item_a);
	d_list_item__ctor(&item_b);
	d_list_item__ctor(&item_c);
	
	d_list_item__append(&item_a, &item_b);
	d_list_item__append(&item_b, &item_c);
	
	d_list_item__delete(&item_b);
	
	assert(d_list_item__next(&item_a) == &item_c);
	assert(d_list_item__prev(&item_c) == &item_a);
	
	assert(d_list_item__prev(&item_b) == NULL);
	assert(d_list_item__next(&item_b) == NULL);
}

int main(int argc, char *argv[])
{
	test_single_item();
	test_append();
	test_prepend();
	
	return 0;
}