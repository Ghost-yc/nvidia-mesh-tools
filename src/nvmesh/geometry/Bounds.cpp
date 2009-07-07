// This code is in the public domain -- castanyo@yahoo.es

#include <nvmesh/geometry/Bounds.h>

#include <nvmesh/BaseMesh.h>
#include <nvmesh/halfedge/HalfEdgeMesh.h>
#include <nvmesh/halfedge/HalfEdgeVertex.h>

using namespace nv;

Box MeshBounds::box(const BaseMesh * mesh)
{
	nvCheck(mesh != NULL);

	Box bounds;
	bounds.clearBounds();

	const uint vertexCount = mesh->vertexCount();
	for (uint v = 0; v < vertexCount; v++)
	{
		const BaseMesh::Vertex & vertex = mesh->vertexAt(v);
		bounds.addPointToBounds( vertex.pos );
	}

	return bounds;
}

Box MeshBounds::box(const HalfEdge::Mesh * mesh)
{
	nvCheck(mesh != NULL);

	Box bounds;
	bounds.clearBounds();

	const uint vertexCount = mesh->vertexCount();
	for (uint v = 0; v < vertexCount; v++)
	{
		const HalfEdge::Vertex * vertex = mesh->vertexAt(v);
		nvDebugCheck(vertex != NULL);
		bounds.addPointToBounds( vertex->pos() );
	}

	return bounds;
}


// TODO: Implement miniBall for bounding spheres:
// http://www.flipcode.com/archives/Smallest_Enclosing_Spheres.shtml
