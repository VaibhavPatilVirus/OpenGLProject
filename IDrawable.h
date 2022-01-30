#pragma once
#include "Mesh.h"
/**
 * @brief Drawable graphics in an view.
*/
class IDrawable
{
public:
	virtual bool draw() = 0;
	/**
	 * @brief Method for drawing Mesh using trianles
	 * @param mesh Mesh to be drawn
	 * @return true for success full draw
	*/
	bool drawMesh(Mesh* mesh);
};
