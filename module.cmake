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

include_directories(${AURORAFW_MODULE_GENGINE_OPENGL_DIR}/include)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

file(GLOB_RECURSE AURORAFW_MODULE_GENGINE_OPENGL_HEADERS ${AURORAFW_MODULE_GENGINE_OPENGL_DIR}/include/*.*)
file(GLOB_RECURSE AURORAFW_MODULE_GENGINE_OPENGL_SOURCE ${AURORAFW_MODULE_GENGINE_OPENGL_SOURCE_DIR}/*.*)

add_library (aurorafw-gengine-opengl SHARED ${AURORAFW_MODULE_GENGINE_OPENGL_SOURCE})
aurora_add_library_target(aurorafw-gengine-opengl SHARED)

if(AURORA_PCH)
add_precompiled_header(aurorafw-gengine-opengl "${AURORAFW_MODULE_GENGINE_OPENGL_HEADERS}")
endif()

if(OPENGL_FOUND)
	set_target_properties(aurorafw-gengine-opengl PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} -DAFW__OPENGL_FOUND")
endif()
if(OPENGL_XMESA_FOUND)
	set_target_properties(aurorafw-gengine-opengl PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} -DAFW__OPENGL_XMESA_FOUND")
endif()
if(OPENGL_GLU_FOUND)
	set_target_properties(aurorafw-gengine-opengl PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} -DAFW__OPENGL_GLU_FOUND")
endif()

target_link_libraries(aurorafw-gengine-opengl aurorafw-cli ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

set_target_properties(aurorafw-gengine-opengl PROPERTIES OUTPUT_NAME "aurorafw-gengine-opengl_${AURORA_PLATFORM_PREFIX}_${AURORA_CPUARCH_PREFIX}")

install(TARGETS aurorafw-gengine-opengl DESTINATION lib)

file(GLOB AURORAFW_MODULE_GENGINE_OPENGL_HEADERS_AURORAFW_GENGINE ${AURORAFW_MODULE_GENGINE_OPENGL_DIR}/include/GEngine/*.*)
file(GLOB AURORAFW_MODULE_GENGINE_OPENGL_HEADERS_AURORAFW_GENGINE_GL ${AURORAFW_MODULE_GENGINE_OPENGL_DIR}/include/AuroraFW/GEngine/GL/*.*)

install(FILES ${AURORAFW_MODULE_GENGINE_OPENGL_HEADERS_AURORAFW_GENGINE} DESTINATION include/AuroraFW/GEngine)
install(FILES ${AURORAFW_MODULE_GENGINE_OPENGL_HEADERS_AURORAFW_GENGINE_GL} DESTINATION include/AuroraFW/GEngine/GL)