#pragma once

#include <SFML/Graphics.hpp>

namespace Sonar
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);

	};
}