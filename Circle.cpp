#include "VendorAPIsPCH.h"
#include "Circle.h"

Circle::Circle(const float& radius, const int& resolution) : mRadius(radius), mResolution(resolution), mpMesh(nullptr) {}

Circle::~Circle() {
	if (mpMesh)
		delete mpMesh;
}

void Circle::createMesh() {
	mNormal = glm::vec3(1.0, 0, 0);

	VertexVec vertex;
	IndicesVec indices;

	vertex.push_back(glm::vec3(0.0f));
	float angleStep = (2 * M_PI) / mResolution;

	for (int sector = 0; sector <= mResolution; ++sector)
	{
		float x = mRadius * cos(angleStep * sector);
		float y = mRadius * sin(angleStep * sector);
		//std::cout << sector << " = (" << x << "," << y << ")" << std::endl;
		vertex.push_back(glm::vec3(x, y, 0.0f));

		//std::cout << sector << "," << sector + 1 << "," << "0" << std::endl;
		indices.push_back(glm::uvec3(sector, sector + 1, 0));
	}

	if (mpMesh)
		*mpMesh = Mesh(vertex, indices);
	else
		mpMesh = new Mesh(vertex, indices);
}

// Inherited via IDrawable

bool Circle::draw()
{
	return drawMesh(mpMesh);
}
