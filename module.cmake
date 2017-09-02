# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
# A Powerful General Purpose Framework
# More information in: https://aurora-fw.github.io/
#
# Copyright (C) 2017 Aurora Framework, All rights reserved.
#
# This file is part of the Aurora Framework. This framework is free
# software; you can redistribute it and/or modify it under the terms of
# the GNU Lesser General Public License version 3 as published by the
# Free Software Foundation and appearing in the file LICENSE included in
# the packaging of this file. Please review the following information to
# ensure the GNU Lesser General Public License version 3 requirements
# will be met: https://www.gnu.org/licenses/lgpl-3.0.html.

message(STATUS "Loading gengine-opengl module...")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

if (NOT CONFIGURED_ONCE)
	set(AURORAFW_MODULE_GENGINE_OPENGL_SOURCE_DIR ${AURORAFW_MODULE_GENGINE_OPENGL_DIR}/src)
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

include_directories(${AURORAFW_MODULE_GENGINE_OPENGL_DIR}/include)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

add_library (aurorafw-gengine-opengl SHARED ${AURORAFW_MODULE_GENGINE_OPENGL_SOURCE_DIR}/OpenGL.cpp)

target_link_libraries(aurorafw-gengine-opengl
					  ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

set_target_properties(aurorafw-gengine-opengl PROPERTIES OUTPUT_NAME aurorafw-gengine-opengl)
