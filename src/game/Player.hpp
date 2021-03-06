#ifndef PUTKARTS_Game_Player_HPP
#define PUTKARTS_Game_Player_HPP

#include <string>

namespace Game {
	class Player;
}

struct Game::Player {
	/** Type for player's id */
	typedef int IdType;

	/** Id of the player */
	IdType id;

	/** Name of the player */
	std::string name;
};

#endif
