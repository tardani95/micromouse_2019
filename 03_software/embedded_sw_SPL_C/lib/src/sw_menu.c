/***********************
 * @file 	sw_menu.c
 * @author	tard
 * @date	Mar 8, 2019
 * @version	vx_x
 ************************/

#include "sw_menu.h"
#include "stddef.h"
/** @addtogroup software_modules
 * @{
 */

/** @defgroup menu Menu
 * @brief menu system
 * @{
 */

void initMenu(menu_p_t menu_p) {
	initNextItem(menu_p->curr_item_, menu_p->curr_item_);
	return;
}

void initNextItem(item_p_t parent_p, item_p_t current_p) {

	if (current_p->first_ == 0)
		return;

	*current_p->first_ = parent_p;
	incrementItemIterator(current_p);
	while (current_p->item_iterator_ != current_p->first_) {
		initNextItem(current_p, *current_p->item_iterator_);
		incrementItemIterator(current_p);
	}
	return;
}

void incrementItemIterator(item_p_t item_p) {
	item_it_t *it_p = &(item_p->item_iterator_);
	if (*it_p != item_p->last_item_) {
		(*it_p)++;
	}
	else{
		*it_p = item_p->first_;
	}
	return;
}

void resetItemIterator(item_p_t item_p) {
	item_p->item_iterator_ = item_p->first_;
	incrementItemIterator(item_p);
	return;
}

void selectItem(menu_p_t menu_p) {
	item_it_t it = menu_p->curr_item_->item_iterator_;
	(*it)->onSelectCallback_(menu_p);
	return;
}

void nextItem(menu_p_t menu_p) {
	incrementItemIterator(menu_p->curr_item_);
	//printf("Looking at: ");
	//printf((*menu_p->curr_item_->item_iterator_)->name_);
	//printf("\n");
	return;
}

void enterSubmenu(menu_p_t menu_p) {
	item_p_t old_item_p = menu_p->curr_item_;
	item_p_t new_item_p = *(old_item_p->item_iterator_);
	resetItemIterator(new_item_p);
	menu_p->curr_item_ = new_item_p;
	//printf("Entered ");
	//printf(menu_p->curr_item_->name_);
	//printf("\nLooking at: ");
	//printf((*menu_p->curr_item_->item_iterator_)->name_);
	//printf("\n");
	return;
}


SUBMENU(explore);
SUBMENU(speedrun);
SUBMENU(run, &explore, &speedrun);
SUBMENU(algorithm);
SUBMENU(manoeuvre);
SUBMENU(control_parameters);
SUBMENU(speedrun_config, &algorithm, &manoeuvre, &control_parameters);
SUBMENU(direct_route_algorithm);
SUBMENU(map_extension_method);
SUBMENU(map_control);
SUBMENU(explore_config, &direct_route_algorithm, &map_extension_method, &map_control);
SUBMENU(configure, &explore_config, &speedrun_config);
SUBMENU(root, &configure, &run);

MENU(main_menu, &root);

//TODO user code here
/**
 * @}
 */

/**
 * @}
 */
