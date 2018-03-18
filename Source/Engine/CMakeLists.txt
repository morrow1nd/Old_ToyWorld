# Source/Engine

# Source files and their filters
INCLUDE(CMakeSources.cmake)

SET(TW_ENGINE_INCLUDE
	${TW_UTILITY_INCLUDE}
	"${TW_SOURCE_DIR}/Engine"
    ${TW_THIRD_PARTY_INCLUDE_GLFW}
    ${TW_RENDER_API_DEPS_INCLUDE}
	CACHE INTERNAL "ToyWorld Engine Include Paths"
)

INCLUDE_DIRECTORIES(${TW_ENGINE_INCLUDE})


## Target
ADD_LIBRARY(ToyEngine ${TW_ENGINE_SRC})
# ADD_LIBRARY(ToyEngine SHARED ${TW_ENGINE_SRC})
TARGET_LINK_LIBRARIES(ToyEngine
    ToyUtility
    glfw
    ${GLFW_LIBRARIES}
)

## IDE specific
SET_PROPERTY(TARGET ToyEngine PROPERTY FOLDER Layers)