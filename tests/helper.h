#ifndef HELPER_H
#define HELPER_H 1

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <stdarg.h>

#include <s_list_item.h>
#include <s_list.h>
#include <t_list.h>


/* Constants -------------------------------------+-------------------------- */

#define HELPER__S_LIST_ITEMS_MAX                  5


/* Data Types --------------------------------------------------------------- */




/* Global Variables --------------------------------------------------------- */




/* Public Functions --------------------------------------------------------- */

bool_t helper__s_list_items_chained(uint_fast8_t num_items, ...);
s_list_item_t *helper__create_s_list_items(uint_fast8_t num_items);

s_list_t *helper__s_list();
bool_t helper__s_list_contains(s_list_t *list, uint_fast8_t num_items, ...);

t_list_t *helper__t_list();
bool_t helper__t_list_contains(t_list_t *list, uint_fast8_t num_items, ...);


/* Macros ----------------------------------------+--------+----------------- */




/* Inline Function Definitions ---------------------------------------------- */



#endif /* HELPER_H */