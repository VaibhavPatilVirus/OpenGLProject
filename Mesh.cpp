#include "VendorAPIsPCH.h"
#include "Mesh.h"

Mesh::Mesh(const VertexVec& vertices, const IndicesVec& indices) : mVertices(vertices), mIndices(indices) {}

GLfloat* Mesh::getVertexArray() {
	GLfloat* vertArray = new GLfloat[mVertices.size() * 6];
	for (int vert = 0; vert < mVertices.size(); ++vert)
	{
		vertArray[6 * vert] = mVertices[vert].x;
		vertArray[6 * vert + 1] = mVertices[vert].y;
		vertArray[6 * vert + 2] = mVertices[vert].z;
		//Color
		vertArray[6 * vert + 3] = 1.0f;
		vertArray[6 * vert + 4] = 0.0f;
		vertArray[6 * vert + 5] = 0.0f;
		//Texture
		//vertArray[8 * vert + 6] = 0.0f;
		//vertArray[8 * vert + 7] = 0.0f;
	}
	return vertArray;
}

GLuint* Mesh::getIndexArray() {
	GLuint* indicesArray = new GLuint[mIndices.size() * 3];
	for (int index = 0; index < mIndices.size(); ++index)
	{
		indicesArray[3 * index] = mIndices[index].x;
		indicesArray[3 * index + 1] = mIndices[index].y;
		indicesArray[3 * index + 2] = mIndices[index].z;
	}
	return indicesArray;
}

GLuint Mesh::getVertexCount() { return mVertices.size(); }

GLuint Mesh::getIndixesCount() { return mIndices.size(); }

void Mesh::rotate(const float& deg, const glm::vec3& rotAxis)
{
	glm::mat4 rotMat(1.0f);
	rotMat = glm::rotate(rotMat, glm::radians(deg), rotAxis);
	//rotMat = glm::inverse(rotMat);
	//rotMat = glm::translate(rotMat, glm::vec3(10.0f, 0.0f, 0.0f));
	for (int index = 0; index < mVertices.size(); ++index)
	{
		mVertices[index] = rotMat * glm::vec4(mVertices[index], 1.0);
	}
}
