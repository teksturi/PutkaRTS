#include <algorithm>

#include "Checkbox.hpp"

GUI::Widget::Checkbox::Checkbox(float x, float y, float width, float height, bool initialState, CallbackType callback):
	Widget(x, y, width, height),
	action(callback),
	isChecked(initialState) {
}

bool GUI::Widget::Checkbox::handleEvent(const sf::Event& e, const sf::RenderWindow& window) {
	if (e.type != sf::Event::MouseButtonPressed || e.mouseButton.button != sf::Mouse::Left) {
		return false;
	}

	sf::Vector2f mouse(window.mapPixelToCoords(sf::Vector2i(e.mouseButton.x, e.mouseButton.y)));

	if (position.contains(mouse)) {
		isChecked = !isChecked;
		if (action) {
			action(isChecked);
		}
		return true;
	}

	return false;
}

void GUI::Widget::Checkbox::draw(sf::RenderWindow& window) {
	const int bw = (std::min(position.width, position.height) < 40 ? 2 : 4); // Border width

	sf::RectangleShape tmp;
	tmp.setSize(sf::Vector2f(position.width - 2 * bw, position.height - 2 * bw));
	tmp.setPosition(position.left + bw, position.top + bw);
	tmp.setFillColor(Color::background);
	tmp.setOutlineColor(Color::border);
	tmp.setOutlineThickness(bw);
	window.draw(tmp);

	if (isChecked) {
		sf::RectangleShape tmp;
		tmp.setSize(sf::Vector2f(1.41421 * (position.width - 4 * bw), bw));
		tmp.setOrigin(tmp.getSize() * 0.5f);
		tmp.setPosition(position.left + position.width / 2, position.top + position.height / 2);
		tmp.setFillColor(Color::text);
		tmp.rotate(45);
		window.draw(tmp);
		tmp.rotate(90);
		window.draw(tmp);
	}
}

void GUI::Widget::Checkbox::setState(bool newState) {
	isChecked = newState;
}

bool GUI::Widget::Checkbox::getState() const {
	return isChecked;
}
