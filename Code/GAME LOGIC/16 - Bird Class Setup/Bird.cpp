#include "Bird.hpp"

namespace Sonar
{
	Bird::Bird(GameDataRef data) : _data(data)
	{
		_birdSprite.setTexture(this->_data->assets.GetTexture("Bird Frame 1"));
	}

	Bird::~Bird()
	{
	}

	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
	}
}