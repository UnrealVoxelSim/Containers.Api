#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"

namespace UnrealVoxelSim::Containers::Api
{
	// Authoritative relationship; mutation belongs to the Containers domain.
	struct ContainedComponent final
	{
		Ecs::Api::EntityId Container;
	};
}
