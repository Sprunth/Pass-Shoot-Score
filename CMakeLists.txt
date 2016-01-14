cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(PassShootScore)

set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set (INC_DIR ${PROJECT_SOURCE_DIR}/include)
set (SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set (MAIN_FILE ${SRC_DIR}/main.cpp)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set (INC_FILES ${INC_FILES})
set (SRC_FILES ${SRC_FILES})

### List headers and source files here

# As a convience, every class listed below will be added (.h and .cpp)
# Assuming they are in the base INC_DIR or SRC_DIR
list (APPEND CLASSES_TO_INCLUDE
	PSSGame
	Player
	)

# Any files that don't have .h and .cpp pairing
set (INC_FILES ${INC_FILES}
	${INC_DIR}/GUI.h
	${INC_DIR}/Globals.h
	)

set (SRC_FILES ${SRC_FILES}
	)

foreach (class_name ${CLASSES_TO_INCLUDE})

	set (INC_FILES ${INC_FILES}
		${INC_DIR}/${class_name}.h)

	set (SRC_FILES ${SRC_FILES}
		${SRC_DIR}/${class_name}.cpp)

endforeach(class_name)

# End Headers and Source files

# BOOST START
set (BOOST_ROOT "C:/Boost/boost_1_60_0")
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)

find_package (Boost 1.58.0 REQUIRED)
if (Boost_FOUND)
	include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif()
set (EXTRA_LIBS ${EXTRA_LIBS} ${Boost_LIBRARIES})
# BOOST END

# OpenGL, GLFW, GL3W
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
set(EXTRA_LIBS ${EXTRA_LIBS} ${OPENGL_LIBRARIES})

find_package(GLFW REQUIRED)
if (GLFW_FOUND)
	set (INC_DIR ${INC_DIR} ${GLFW_INCLUDE_DIR})
	link_directories (${GLFW_LIBRARIES})
	set (EXTRA_LIBS ${EXTRA_LIBS} glfw3)
endif()
find_package(GL3W REQUIRED)
if (GL3W_FOUND)
	set (INC_DIR ${INC_DIR} ${GL3W_INCLUDE_DIR})
	link_directories (${GL3W_LIBRARIES})
	set (EXTRA_LIBS ${EXTRA_LIBS} gl3w)
endif()
# End OpenGL, GLFW, GL3W

# IMGUI START

file (GLOB IMGUI_INC ${INC_DIR}/imgui/*.h)
file (GLOB IMGUI_SRC ${SRC_DIR}/imgui/*.cpp)

set (INC_FILES ${INC_FILES} ${IMGUI_INC})
set (SRC_FILES ${SRC_FILES} ${IMGUI_SRC})

source_group("Imgui" FILES ${IMGUI_INC} ${IMGUI_SRC})

set (INC_DIR ${INC_DIR} ${PROJECT_SOURCE_DIR}/include/imgui)
set (SRC_DIR ${SRC_DIR} ${PROJECT_SOURCE_DIR}/src/imgui)

# set (INC_FILES ${INC_FILES}
# 	${INC_DIR}/imgui/imconfig.h
# 	${INC_DIR}/imgui/imgui.h
# 	${INC_DIR}/imgui/imgui_impl_glfw_gl3.h
# 	${INC_DIR}/imgui/imgui_internal.h
# 	${INC_DIR}/imgui/stb_rect_pack.h
# 	${INC_DIR}/imgui/stb_textedit.h
# 	${INC_DIR}/imgui/stb_truetype.h)

# set (SRC_FILES ${SRC_FILES} 
# 	${SRC_DIR}/imgui/imgui.cpp
# 	${SRC_DIR}/imgui/imgui_demo.cpp
# 	${SRC_DIR}/imgui/imgui_draw.cpp
# 	${SRC_DIR}/imgui/imgui_impl_glfw_gl3.cpp)

# IMGUI END


# BUILD SETUP

include_directories(${INC_DIR})

add_executable (${PROJECT_NAME} ${MAIN_FILE} ${SRC_FILES} ${INC_FILES})

target_link_libraries (${PROJECT_NAME} ${EXTRA_LIBS})
