#pragma once

namespace UnrealVoxelSim::Containers::Api
{
	enum class InsertError
	{
		TargetNotAlive,
		ContainerNotAlive,
		TargetDestroying,
		ContainerDestroying,
		ContainmentCycle,
	};
}
