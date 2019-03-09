/***********************
 * @file 	sw_menu.h
 * @author	Zoltan Resi
 * @date	Mar 8, 2019
 * @version	vx_x
 ************************/

#ifndef SW_MENU_H_
#define SW_MENU_H_

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

typedef void(*onSelectCallback_t)(menu_p_t);

struct item {
	char* name_;
	onSelectCallback_t onSelectCallback_;
	item_parr_t *items_;
	item_it_t first_;
	item_it_t item_iterator_;
	item_it_t last_item_;
};

struct menu {
	item_p_t curr_item_;// = NULL;
};

#define NUMARGS(...)  (sizeof((int[]){ __VA_ARGS__})/sizeof(int))

#define SUBMENU(name, ...)									\
	item_p_t name##_subitems[] = {NULL , __VA_ARGS__};		\
	item_t name = {											\
		.name_ = #name,										\
		.onSelectCallback_ = enterSubmenu,					\
		.items_ = &name##_subitems,							\
		.first_ = &name##_subitems[0],						\
		.item_iterator_= &name##_subitems[0],				\
		.last_item_= &name##_subitems[NUMARGS(__VA_ARGS__)]	\
	}

#define ACTION(name, onSelectCallback)						\
	item_t name = {											\
		.name_ = #name,										\
		.onSelectCallback_ = onSelectCallback,				\
		.items_ = NULL,										\
		.first_ = NULL,										\
		.item_iterator_= NULL,								\
		.last_item_= NULL									\
	}

#define MENU(name, root)									\
	menu_t name = {											\
		.curr_item_ = root									\
	}


void initMenu(menu_p_t menu_p);
void initNextItem(item_p_t parent_p, item_p_t current_p);

void incrementItemIterator(item_p_t item_p);
void resetItemIterator(item_p_t item_p);

void selectItem(menu_p_t menu_p);
void nextItem(menu_p_t menu_p);
/**
 * @}
 * end of menu
 */
/**
 * @}
 * end of software_modules
 */

#endif /* SW_MENU_H_ */

