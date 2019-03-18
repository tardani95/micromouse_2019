/***********************
 * @file 	sw_menu.c
 * @author	tard
 * @date	Mar 8, 2019
 * @version	vx_x
 ************************/

#include "sw_menu.h"
#include "stddef.h"
#include "sw_debug.h"
/** @addtogroup software_modules
 * @{
 */

/** @defgroup menu Menu
 * @brief menu system
 * @{
 */


/**
 * @brief Initialize menu.
 * @verbatim
  Initializes the menu pointed to by menu_p:
  	  Starts recursive initialization process by calling initNextItem(menu_p).
  @endverbatim
 *
 * @param menu_p Pointer to the menu to be initialized.
 */
void initMenu(menu_p_t menu_p) {
	initNextItem(menu_p->curr_item_, menu_p->curr_item_);
	DEBUG("Menu initialized: ");
	DEBUG(menu_p->name_);
	return;
}


/**
 * @brief Initialize next item.
 * @verbatim
  Initializes the item pointed to by current_p:
  	  Sets the first subitem to be the parent item.
  	  Increments iterator, which originally pointed to the first item.
  	  Call initNextItem() for each subitem.
  @endverbatim
 *
 * @param parent_p Pointer to the parent item of the current item.
 * @param current_p Pointer to the current item.
 */
void initNextItem(item_p_t parent_p, item_p_t current_p) {

	if (current_p->first_ != NULL){
		*current_p->first_ = parent_p;
		incrementItemIterator(current_p);
		while (current_p->item_iterator_ != current_p->first_) {
			initNextItem(current_p, *current_p->item_iterator_);
			incrementItemIterator(current_p);
		}
	}
	return;
}

/**
 * @brief Increment the subitem iterator of the item
 * @param item_p Pointer to the item that needs its iterator to be incremented.
 */
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

/**
 * @brief Reset the subitem iterator to point to the first child subitem.
 * @param item_p Pointer to the item that needs its iterator to be reset.
 */
void resetItemIterator(item_p_t item_p) {
	item_p->item_iterator_ = item_p->first_;
	incrementItemIterator(item_p);
	return;
}


/**
 * @brief Select the currently highlighted item of the currently active item of the menu.
 * @param menu_p Pointer to the menu.
 */
void selectItem(menu_p_t menu_p) {
	item_it_t it = menu_p->curr_item_->item_iterator_;
	(*it)->onSelectCallback_(menu_p);
	return;
}


/**
 * @brief Makes the next subitem to be the highlighted item.
 * @param menu_p Pointer to the menu.
 */
void nextItem(menu_p_t menu_p) {
	incrementItemIterator(menu_p->curr_item_);

	INFO("Looking at: ");
	INFO((*menu_p->curr_item_->item_iterator_)->name_);
	return;
}
/** @defgroup menu_callbacks Menu Callbacks
 * @brief Callback function definitions for the items in the menu system.
 * @{
 */

/**
 * @brief Callback for entering the selected submenu item.
 * @verbatim
  Sets the current item pointer to point to the selectable item of the current item.
  @endverbatim
 * @param menu_p Pointer to the menu.
 */
void enterSubmenu(menu_p_t menu_p) {
	item_p_t old_item_p = menu_p->curr_item_;
	item_p_t new_item_p = *(old_item_p->item_iterator_);
	resetItemIterator(new_item_p);
	menu_p->curr_item_ = new_item_p;

	INFO("Entered: ");
	INFO(menu_p->curr_item_->name_);
	INFO("Looking at: ");
	INFO((*menu_p->curr_item_->item_iterator_)->name_);

	return;
}

/**
 * @}
 */

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
SUBMENU(main_root, &configure, &run);
/**
 * @brief Main menu for the micromouse project.
 *
 *Diagram:\n
 * ![Diagram (.png)](/waldlaeufer_main_menu.png )\n
 * [Open .io](https://www.draw.io/#G16V72VMnYVvCvvIUJUxI6ZndSpA8F2fbj)
 * @param root Address of the root item of the main menu.
 */
MENU(main_menu, &main_root);


SUBMENU(exit_to_main_menu);
SUBMENU(reset_map);
SUBMENU(after_run_root, &reset_map, &exit_to_main_menu);
/**
 * @brief After run menu for the micromouse project.
 *
 *Diagram:\n
 * ![Diagram (.png)](/waldlaeufer_after_run_menu.png )\n
 * [Open .io](https://www.draw.io/#G1xwH4rXKdAM4zQYDQKu97RqXQWLk7L4p0)
 * @param root Address of the root item of the after run menu.
 */
MENU(after_run_menu, &after_run_root);


void initMenus(menu_p_t *main_menu_p, menu_p_t *after_run_menu_p){
	initMenu(&main_menu);
	initMenu(&after_run_menu);
	*main_menu_p = &main_menu;
	*after_run_menu_p = &after_run_menu;
}

/**
 * @}
 */

/**
 * @}
 */
