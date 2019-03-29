/***********************
 * @file 	sw_menu.h
 * @author	Zoltan Resi
 * @date	Mar 8, 2019
 * @version	vx_x
 ************************/

#ifndef SW_MENU_H_
#define SW_MENU_H_

#include "stm32f4xx.h"

/** @addtogroup software_modules
 * @{
 */

/** @addtogroup menu
 * @{
 */
typedef struct item item_t;
typedef item_t* item_p_t;
typedef item_p_t* item_it_t;
typedef item_p_t* item_parr_t;

typedef struct menu menu_t;
typedef menu_t* menu_p_t;

typedef void (*onSelectCallback_t)(menu_p_t);

/**
 * Struct for the items in the menu system.
 */
struct item {
	char *name_; /**<Name of the item. */
	onSelectCallback_t onSelectCallback_; /**<Callback function to be called when item is selected. */
	item_parr_t *items_; /**<Pointer to the pointer array which contains the child items of this item. */
	item_it_t first_; /**<Iterator which points to the first child item (parent). */
	item_it_t item_iterator_; /**<Iterator which points to the currently highlighted child item. */
	item_it_t last_item_; /**<Iterator which points to the last child item. */
};

/**
 * Struct for the menu.
 */
struct menu {
	char *name_;
	item_p_t curr_item_; /**<Pointer to the currently active item of the menu*/
};

/**
 * @brief Count of input arguments.
 *
 * Macro for counting the number of input arguments.
 */
#define NUMARGS(...)  (sizeof((int[]){ __VA_ARGS__})/sizeof(int))


/**
 * @brief Create submenu.
 * @verbatim
  Macro for creating a submenu item.
  	Creates the pointer array for the child items and the parent. First element will be set to the parent element upon initialization.
  	Sets .name to the input name.
  	Sets .onSelectCallback_ to enterSubmenu.
  	Sets .items_ to point to the just created subitems array.
  	Sets .first_ and .item_iterator_ to point to the first element in the subitems array.
  	Sets .last_item_ to point to the last item in the subitems array.
  @endverbatim
 * @param name name of the item
 * @param ... memory addresses of desired child items
*/
#define SUBMENU(name, ...)									\
	item_p_t name##_subitems[] = {NULL , __VA_ARGS__};		\
	char name##_name[MAX_STRING_SIZE] = #name;				\
	item_t name = {											\
		.name_ = name##_name,								\
		.onSelectCallback_ = enterSubmenu,					\
		.items_ = &name##_subitems,							\
		.first_ = &name##_subitems[0],						\
		.item_iterator_= &name##_subitems[0],				\
		.last_item_= &name##_subitems[NUMARGS(__VA_ARGS__)]	\
	}

/**
 * @brief Create action.
 * @verbatim
  Macro for creating an action item.
  	No pointer array for the child items is created, because an action item cannot be entered and cannot have child items.
  	Sets .name to the input name.
  	Sets .items_ and all the iterators to NULL, because they are not used in an action item.
  @endverbatim
 * @param name name of the item
 * @param onSelectCallback Callback function to be executed upon selection of this item.
 */
#define ACTION(name, onSelectCallback)						\
	char name##_name[MAX_STRING_SIZE] = #name;				\
	item_t name = {											\
		.name_ = name##_name,								\
		.onSelectCallback_ = onSelectCallback,				\
		.items_ = NULL,										\
		.first_ = NULL,										\
		.item_iterator_= NULL,								\
		.last_item_= NULL									\
	}

/**
 * @brief Create menu.
 * @verbatim
  Macro for creating a menu.
  	 Only items descending from the root item (and the root item itself) will be available in this menu system.
  	 The root item will be the initial current item.
  @endverbatim
 * @param name name of the menu
 * @param root The root submenu for this menu.
 */
#define MENU(name, root)									\
	char name##_name[MAX_STRING_SIZE] = #name;				\
	menu_t name = {											\
		.name_ = name##_name,								\
		.curr_item_ = root									\
	}



void initMenu(menu_p_t menu_p);
void initNextItem(item_p_t parent_p, item_p_t current_p);


void initMenus(menu_p_t *main_menu_p, menu_p_t *after_run_menu_p);

void incrementItemIterator(item_p_t item_p);
void resetItemIterator(item_p_t item_p);

void selectItem(menu_p_t menu_p);
void nextItem(menu_p_t menu_p);


/**
 * @addtogroup menu_callbacks
 * @{
 */
void enterSubmenu(menu_p_t menu_p);


/**
 * @}
 * end of menu_callbacks
 */
/**
 * @}
 * end of menu
 */
/**
 * @}
 * end of software_modules
 */

#endif /* SW_MENU_H_ */

