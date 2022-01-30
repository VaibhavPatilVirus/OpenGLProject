#include "VendorAPIsPCH.h"
#include "Plane.h"

Plane::Plane() : mpMesh(nullptr)
{
}

Plane::Plane(const float& length, const float& width, const int& resolution) :
	mLength(length), mWidth(width), mResolution(resolution), mpMesh(nullptr)
{}

Plane::~Plane() {
	if (mpMesh)
		delete mpMesh;
}

/**
* Set new plane size/dimensions
*
* @param[in] length The length of plane
* @param[in] width The width of plane
* @param[in] regenerateMesh Recalculates and regenerate the plane mesh
*            if `regenerateMesh` passed as true. Will force Recalculates and regenerate the plane mesh.
*            else plane mesh will not be regenerated and it is developers responsibility to call createMesh() method before drawing plane on screen
*/

void Plane::setPlaneDimensions(const float& length, const float& width, const bool& regenerateMesh)
{
	mLength = length;
	mWidth = width;
	if (regenerateMesh)
		createMesh();
}

//Generate planar mesh in XY Plane and Z axis as normal

void Plane::createMesh() {
	mNormal = glm::vec3(0.0f, 0.0f, 1.0f);
	mPlaneXAxis = glm::vec3(1.0f, 0.0f, 0.0f);
	VertexVec vertex;
	IndicesVec indices;

	float stepsInXDir = mLength / mResolution;
	float stepsInYDir = mWidth / mResolution;
	//int index = 0;
	glm::vec3 TranslateVec(-(mLength / 2), -(mWidth / 2), 0.0f);
	//Start constructing plane from (0,0) to (mLength, mWidth)
	for (int y = 0; y <= mResolution; ++y)
	{
		for (int x = 0; x <= mResolution; ++x)
		{
			//std::cout << index <<  "=(" << x * steps << "," << y * steps << ")";
			vertex.push_back(glm::vec3(x * stepsInXDir, y * stepsInYDir, 0.0f) + TranslateVec); //Tranlate all points(whole plane) to make (0,0) as center of polygon
																								//++index;
		}
		std::cout << std::endl;
	}

	for (int y = 0; y < mResolution; y++)
	{
		for (int x = 0; x < mResolution; x++)
		{
			unsigned int skip = ((mResolution + 1) * y);
			indices.push_back(glm::uvec3(skip + x, skip + x + 1, skip + x + mResolution + 1));
			//std::cout << "(" << skip + x << "," << skip + x + 1 << "," << skip + x + mResolution + 1 << ")" << "         ";
			indices.push_back(glm::uvec3(skip + x + 1, skip + x + mResolution + 2, skip + x + mResolution + 1));
			//std::cout << "(" << skip + x + 1 << "," << skip + x + mResolution + 2 << "," << skip + x + mResolution + 1 << ")" << std::endl;
		}
	}
	if (mpMesh)
		*mpMesh = Mesh(vertex, indices);
	else
		mpMesh = new Mesh(vertex, indices);
}

void Plane::rotate(const float& deg, const glm::vec3& rotAxis)
{
	mpMesh->rotate(deg, rotAxis);
}

// Inherited via IDrawable

bool Plane::draw()
{
	return drawMesh(mpMesh);
}
