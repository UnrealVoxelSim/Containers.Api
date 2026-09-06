#pragma once

#include <expected>
#include "UnrealVoxelSim/Containers/Api/RemoveError.h"
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"

namespace UnrealVoxelSim::Containers::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IRemover
	{
	public:
		virtual ~IRemover() = default;

		// Removes only the containment relationship, including during destruction cleanup.
		// Does not restore a position. Failure leaves the relationship unchanged.
		[[nodiscard]] virtual std::expected<void, RemoveError> RemoveFromContainer(Ecs::Api::EntityId target) = 0;
	};
}
