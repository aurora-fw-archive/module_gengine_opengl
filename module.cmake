message(STATUS "Loading gengine-opengl module...")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

if (NOT CONFIGURED_ONCE)
	set(MODULE_GENGINE_OPENGL_SOURCE_DIR ${MODULE_GENGINE_OPENGL_DIR}/src)
endif()

if(OPENGL_FOUND)
    add_definitions(-DAURORA_OPENGL_FOUND)
endif()
if(OPENGL_XMESA_FOUND)
    add_definitions(-DAURORA_OPENGL_XMESA_FOUND)
endif()
if(OPENGL_GLU_FOUND)
    add_definitions(-DAURORA_OPENGL_GLU_FOUND)
endif()

include_directories(${MODULE_GENGINE_OPENGL_DIR}/include)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

add_library (aurorafw-gengine-opengl SHARED ${MODULE_GENGINE_OPENGL_SOURCE_DIR}/OpenGL.cpp)

target_link_libraries(aurorafw-gengine-opengl
					  ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

set_target_properties(aurorafw-gengine-opengl PROPERTIES OUTPUT_NAME aurorafw-gengine-opengl)
