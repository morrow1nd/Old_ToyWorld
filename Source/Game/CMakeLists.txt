# Source/Game

# Source files and their filters
INCLUDE(CMakeSources.cmake)


SET(TW_GAME_INCLUDE
	${TW_UTILITY_INCLUDE}
	${TW_ENGINE_INCLUDE}
	"${TW_SOURCE_DIR}/Game"
	CACHE INTERNAL "ToyWorld Game Include Paths"
)

INCLUDE_DIRECTORIES(${TW_GAME_INCLUDE})

# Target
add_executable(ToyWorldGame ${TW_GAME_SRC})
# ADD_LIBRARY(ToyUtility SHARED ${TW_UTILITY_SRC})

TARGET_LINK_LIBRARIES(ToyWorldGame ToyUtility)
TARGET_LINK_LIBRARIES(ToyWorldGame ToyEngine)

# IDE specific
SET_PROPERTY(TARGET ToyWorldGame PROPERTY FOLDER Layers)