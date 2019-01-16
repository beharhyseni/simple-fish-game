#pragma once

#include "common.hpp"

// Salmon enemy 
class Puffer : public Renderable
{
	// Shared between all puffers, no need to load one for each instance
	static Texture puffer_texture;

public:
	// Creates all the associated render resources and default transform
	bool init();

	// Releases all the associated resources
	void destroy();

	// Update puffer due to current
	// ms represents the number of milliseconds elapsed from the previous update() call
	void update(float ms);

	// Renders the puffer
	// projection is the 2D orthographic projection matrix
	void draw(const mat3& projection)override;

	// Returns the current puffer position
	vec2 get_position()const;

	// Sets the new puffer position
	void set_position(vec2 position);

	// Returns the puffer's bounding box for collision detection, called by collides_with()
	vec2 get_bounding_box()const;

private:
	vec2 m_position; // Window coordinates
	vec2 m_scale; // 1.f in each dimension. 1.f is as big as the associated texture
	float m_rotation; // in radians
};