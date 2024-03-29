# Source

## CMake Options

### RenderAPI to use
set(TW_RENDER_API_MODULE "OpenGL" CACHE STRING "Render API to use.")
set_property(CACHE TW_RENDER_API_MODULE PROPERTY STRINGS "OpenGL" "DirectX 11" "OpenGL ES")

if(TW_RENDER_API_MODULE MATCHES "DirectX 11")
    set(TOY_WORLD_RENDER_API_DX11 TRUE)
elseif(TW_RENDER_API_MODULE MATCHES "OpenGL")
    set(TOY_WORLD_RENDER_API_OPENGL TRUE)
else()
    set(TOY_WORLD_RENDER_API_OPENGLES TRUE)
endif()
## end of CMake Options

## Configure file
CONFIGURE_FILE(
	"${TW_SOURCE_DIR}/ToyWorldConfig.h.in"
	"${PROJECT_BINARY_DIR}/ToyWorldConfig.h"
	)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

#Only when it's set to TRUE, can we use: SET_PROPERTY(TARGET ToyUtility PROPERTY FOLDER Layers)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

ADD_SUBDIRECTORY(ThirdParty)
ADD_SUBDIRECTORY(Utility)
ADD_SUBDIRECTORY(Engine)
ADD_SUBDIRECTORY(Game)
#ADD_SUBDIRECTORY(Game)
#ADD_SUBDIRECTORY(Plugins)
ADD_SUBDIRECTORY(Examples)