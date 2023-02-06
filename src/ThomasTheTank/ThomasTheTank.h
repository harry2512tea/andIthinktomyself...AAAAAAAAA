#ifndef THOMASTHETANK_THOMASTHETANK_H
#define THOMASTHETANK_THOMASTHETANK_H

//Core Elements
#include "Core.h"
#include "Entity.h"
#include "Time.h"
#include "Input.h"
#include "Cursor.h"
#include "Cache.h"

//GLM Wrapping
#include "Wrapping/ThomasMath.h"

//components
#include "Component.h"
#include "Components/Transform.h"
#include "Components/MeshRenderer.h"
#include "Components/Camera.h"
#include "Components/AudioSource.h"
#include "TriangleRenderer.h"

//Physics
#include "Components/RigidBody.h"
#include "Components/Collider.h"
#include "Components/Colliders/BoxCollider.h"

//Resources
#include "Resources/AudioClip.h"
#include "Resources/Model.h"
#include "Resources/Texture.h"


#define input Input::getInstance()
//#define Resources Cache::getInstance()


#endif