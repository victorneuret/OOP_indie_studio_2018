/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AEntity.hpp
*/

#include "ECS/Interfaces/IEntity.hpp"

namespace Engine {
    namespace ECS {
		class AEntity;
	}
}

class Engine::ECS::AEntity : public Engine::ECS::IEntity {
public:
	virtual ~AEntity() override = default;
};
