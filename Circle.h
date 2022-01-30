#pragma once
#include "Mesh.h"
#include "IDrawable.h"
#include "ISelectable.h"
#include "TypeDefs.h"

/**
 * @brief Planar circular drawable shape.
*/
class Circle : public IDrawable, ISelectable
{
public:
	glm::vec3 mNormal;
	int mResolution = 10;
	float mRadius = 10;

	Mesh* mpMesh;

	Circle(const float& radius, const int& resolution = 1000);
	virtual ~Circle();

	void createMesh();

	// Inherited via IDrawable
	virtual bool draw() override;
};

