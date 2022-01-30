#pragma once
#include "TypeDefs.h"

/**
 * @brief Triangular mesh.
*/
class Mesh
{
private:
	VertexVec mVertices;
	IndicesVec mIndices;
public:
	Mesh(const VertexVec& vertices, const IndicesVec& indices);

	GLfloat* getVertexArray();

	GLuint* getIndexArray();

	GLuint getVertexCount();

	GLuint getIndixesCount();

	void rotate(const float& deg, const glm::vec3& rotAxis);
};

