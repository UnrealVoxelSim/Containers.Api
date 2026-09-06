# UnrealVoxelSim.Containers.Api

Header-only containment contracts: `IQuery`, `IInserter`, `IRemover`, and `ContainedComponent`.

Each entity has at most one direct container. Insertion transfers the relationship without item-specific effects or
position changes. Self-containment and cycles are rejected. Removal is permitted during destruction cleanup.
Queries return no container or empty contents for non-live entities; contents are ordered by `EntityId`.
Failures preserve relationships; insertion into the current container is an unchanged success.

Insertion rejects a destroying target or destination. The V1 implementation will delete contained entities when their
container is destroyed, before removing relationships. No destruction behavior is implemented by these declarations.

All capabilities are synchronous and confined to the owning simulation thread. Returned query containers are owned
snapshots. Entity references are non-owning and scoped to one registry; they are not persistent save identities.
Components are public read contracts; composition grants mutation authority only to the owning domain.

## Build validation

Use a Visual Studio developer environment with CMake, Ninja, and `VCPKG_ROOT` available:

```powershell
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
cmake --preset windows-msvc-release
cmake --build --preset windows-msvc-release
```

The default build compiles each public header in isolation and verifies that interfaces remain abstract with virtual
destructors. This module contains no runtime implementation or behavioral tests yet. Linux Clang presets are also provided.
