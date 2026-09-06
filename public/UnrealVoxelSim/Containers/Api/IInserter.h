#pragma once

#include <expected>
#include "UnrealVoxelSim/Containers/Api/InsertError.h"
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"

namespace UnrealVoxelSim::Containers::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IInserter
	{
	public:
		virtual ~IInserter() = default;

		// Establishes or transfers containment only; does not change position or enforce item policy.
		// Rejects self-containment, cycles, and insertion involving an entity being destroyed.
		// An existing identical relationship succeeds unchanged. Failure preserves the old relationship.
		[[nodiscard]] virtual std::expected<void, InsertError> InsertToContainer(Ecs::Api::EntityId target,
																				 Ecs::Api::EntityId container) = 0;
	};
}
