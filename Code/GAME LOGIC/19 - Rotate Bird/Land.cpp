#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar
{
	Land::Land(GameDataRef data) : _data(data)
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(this->_data->assets.GetTexture("Land"));

		sprite.setPosition(0, this->_data->window.getSize().y - sprite.getLocalBounds().height);
		sprite2.setPosition(sprite.getLocalBounds().width, this->_data->window.getSize().y - sprite2.getLocalBounds().height);

		_landSprites.push_back(sprite);
		_landSprites.push_back(sprite2);
	}

	void Land::MoveLand(float dt)
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			sf::Vector2f position = _landSprites.at(i).getPosition();
			float movement = PIPE_MOVEMENT_SPEED * dt;

			_landSprites.at(i).move(-movement, 0.0f);

			if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getLocalBounds().width)
			{
				sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);

				_landSprites.at(i).setPosition(position);
			}
		}
	}

	void Land::DrawLand()
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			this->_data->window.draw(_landSprites.at(i));
		}
	}
}