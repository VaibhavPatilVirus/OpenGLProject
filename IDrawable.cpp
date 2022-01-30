#include "VendorAPIsPCH.h"
#include "IDrawable.h"
#include "VAO.h"
#include "EBO.h"

/**
* @brief Method for drawing Mesh using trianles
* @param mesh Mesh to be drawn
* @return true for success full draw
*/

bool IDrawable::drawMesh(Mesh* mesh)
{
	GLfloat* vertices = mesh->getVertexArray();
	GLuint* indices = mesh->getIndexArray();
	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(GLfloat) * mesh->getVertexCount() * (6));
	EBO EBO1(indices, sizeof(GLuint) * mesh->getIndixesCount() * 3);
	delete vertices;
	delete indices;
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	//VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
	VAO1.Bind();
	glDrawElements(GL_TRIANGLES, mesh->getIndixesCount() * 3, GL_UNSIGNED_INT, 0);
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();

	return true;
}
