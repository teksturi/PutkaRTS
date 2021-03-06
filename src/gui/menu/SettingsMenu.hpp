#ifndef PUTKARTS_GUI_Menu_SettingsMenu_HPP
#define PUTKARTS_GUI_Menu_SettingsMenu_HPP

#include "gui/menu/Menu.hpp"

#include "gui/widget/Widget.hpp"
#include "gui/widget/List.hpp"
#include "gui/widget/TabPanel.hpp"

#include <SFML/Graphics.hpp>

namespace GUI {
	namespace Menu {
		class SettingsMenu;
	}
}

/**
 * Class for the setting menu.
 */
class GUI::Menu::SettingsMenu: public Menu {
	/** Manager for the tabs. */
	std::shared_ptr<GUI::Widget::TabPanel> tabManager;

	/** Index for the selected video mode. */
	std::size_t videoMode;

	/** Selected fullscreen state. */
	bool fullscreen;

	/** Selected drag mode. */
	bool reverseDrag;

	/** Selected border scroll speed. */
	float borderScrollSpeed;

	/** Selected keyboard scroll speed. */
	float keyboardScrollSpeed;

	/** Selected zoom speed. */
	float zoomSpeed;

	/**
	 * Build graphics tab.
	 */
	void buildGraphicsTab(const GUI::Widget::TabPanel::TabKeyType& key);

	/**
	 * Build input tab.
	 */
	void buildInputTab(const GUI::Widget::TabPanel::TabKeyType& key);

	/**
	 * Save changes and return to main menu.
	 */
	void applyChanges(sf::RenderWindow& window);

	/**
	 * Set fullscreen state.
	 */
	void setFullScreen(bool state);

	/**
	 * Set selected video mode.
	 */
	void setVideoMode(const GUI::Widget::List::Item& item);

	/**
	 * Set the border scroll speed.
	 */
	void setBorderScrollSpeed(float value);

	/**
	 * Set the border keyboard speed.
	 */
	void setKeyboardScrollSpeed(float value);

	/**
	 * Set the zoom speed.
	 */
	void setZoomSpeed(float value);

	/**
	 * Set reverse drag.
	 */
	void setReverseDrag(bool state);

public:
	/**
	 * @copydoc Menu::Menu
	 * @param window The window to use for input and rendering.
	 */
	SettingsMenu(std::shared_ptr<Widget> parent, sf::RenderWindow& window);
};

#endif
