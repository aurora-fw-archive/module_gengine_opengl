#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GENGINE_OPENGL
#define INCLUDE_H_AURORA_GENGINE_OPENGL

#include <Aurora/GEngine/_OpenGL.h>
#include <Aurora/GEngine/_GLEW.h>

namespace Aurora {
	namespace GEngine {
		const char* getGLVersion();
	}
}

#endif // INCLUDE_H_AURORA_GENGINE_OPENGL
