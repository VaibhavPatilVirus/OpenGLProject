#include "VendorAPIsPCH.h"
#include "Cube.h"

Cube::Cube(const float& sideLength) : mSideLength(sideLength), mpMesh(nullptr)
{
	createMesh();
}

Cube::~Cube() {
	if (mpMesh)
		delete mpMesh;
}

//Generate planar mesh in XY Plane and Z axis as normal

void Cube::createMesh() {
	VertexVec vertex;
	IndicesVec indices;
	float halfSide = mSideLength / 2;
	//Front face
	vertex.push_back(glm::vec3(-halfSide, -halfSide, halfSide));
	vertex.push_back(glm::vec3(halfSide, -halfSide, halfSide));
	vertex.push_back(glm::vec3(halfSide, halfSide, halfSide));
	vertex.push_back(glm::vec3(-halfSide, halfSide, halfSide));
	//Back face
	vertex.push_back(glm::vec3(-halfSide, -halfSide, -halfSide));
	vertex.push_back(glm::vec3(halfSide, -halfSide, -halfSide));
	vertex.push_back(glm::vec3(halfSide, halfSide, -halfSide));
	vertex.push_back(glm::vec3(-halfSide, halfSide, -halfSide));

	//Front face trianngles
	indices.push_back(glm::uvec3(0, 1, 2));
	indices.push_back(glm::uvec3(0, 3, 2));
	//Back face trianngles
	indices.push_back(glm::uvec3(5, 4, 7));
	indices.push_back(glm::uvec3(5, 6, 7));
	//Top face trianngles
	indices.push_back(glm::uvec3(3, 2, 6));
	indices.push_back(glm::uvec3(3, 7, 6));
	//Bottom face trianngles
	indices.push_back(glm::uvec3(4, 0, 1));
	indices.push_back(glm::uvec3(4, 5, 1));
	//Right face trianngles
	indices.push_back(glm::uvec3(1, 5, 6));
	indices.push_back(glm::uvec3(1, 2, 6));
	//Left face trianngles
	indices.push_back(glm::uvec3(4, 0, 3));
	indices.push_back(glm::uvec3(4, 7, 3));

	if (mpMesh)
		*mpMesh = Mesh(vertex, indices);
	else
		mpMesh = new Mesh(vertex, indices);
}

void Cube::rotate(const float& deg, const glm::vec3& rotAxis)
{
	mpMesh->rotate(deg, rotAxis);
}

// Inherited via IDrawable

bool Cube::draw()
{
	return drawMesh(mpMesh);
}
