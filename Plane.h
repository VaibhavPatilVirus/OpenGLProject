#pragma once
#include "Mesh.h"
#include "IDrawable.h"
#include "ISelectable.h"
/**
 * @brief Simple 2D plane.
*/
class Plane : public IDrawable, ISelectable
{
public:
	glm::vec3 mNormal;
	glm::vec3 mPlaneXAxis;
	int mResolution = 1;

	float mLength = 1;
	float mWidth = 1;

	Mesh* mpMesh = nullptr;

	Plane();
	Plane(const float& length, const float& width, const int& resolution = 1);

	virtual ~Plane();

	/**
	* Set new plane size/dimensions
	*
	* @param[in] length The length of plane
	* @param[in] width The width of plane
	* @param[in] regenerateMesh Recalculates and regenerate the plane mesh
	*            if `regenerateMesh` passed as true. Will force Recalculates and regenerate the plane mesh.
	*            else plane mesh will not be regenerated and it is developers responsibility to call createMesh() method before drawing plane on screen
	*/
	void setPlaneDimensions(const float& length, const float& width, const bool& regenerateMesh = true);

	//Generate planar mesh in XY Plane and Z axis as normal
	void createMesh();

	void rotate(const float& deg, const glm::vec3& rotAxis);;

	// Inherited via IDrawable
	virtual bool draw() override;
};

