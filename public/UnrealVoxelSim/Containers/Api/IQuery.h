#pragma once

#include <optional>
#include <vector>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"

namespace UnrealVoxelSim::Containers::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IQuery
	{
	public:
		virtual ~IQuery() = default;

		// Returns no value for an uncontained or non-live target.
		[[nodiscard]] virtual std::optional<Ecs::Api::EntityId> GetContainer(Ecs::Api::EntityId target) const = 0;

		// Returns an owned snapshot of direct contents, ordered by EntityId.
		// A non-live or empty container produces an empty snapshot.
		[[nodiscard]] virtual std::vector<Ecs::Api::EntityId> GetContents(Ecs::Api::EntityId container) const = 0;
	};
}
