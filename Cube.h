#pragma once
#include "Mesh.h"
#include "IDrawable.h"
#include "TypeDefs.h"
/**
 * @brief Simple 3D cube.
*/
class Cube : public IDrawable
{
	//Plane faces[NUMBER_OF_CUBE_FACES];
	Mesh* mpMesh;
	float mSideLength = 1;

public:
	Cube(const float& sideLength = 1);

	virtual ~Cube();
	//Generate planar mesh in XY Plane and Z axis as normal
	void createMesh();

	void rotate(const float& deg, const glm::vec3& rotAxis);;

	// Inherited via IDrawable
	virtual bool draw() override;
};
