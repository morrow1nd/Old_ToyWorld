# Source/ThirdParty


## GLFW
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
ADD_SUBDIRECTORY(GLFW/glfw-3.2.1)
SET(TW_THIRD_PARTY_INCLUDE_GLFW
    "${TW_SOURCE_DIR}/ThirdParty/GLFW/glfw-3.2.1/include"
    CACHE INTERNAL "ToyWorld ThirdParty glfw Include Paths"
)


## lua
SET(TW_THIRD_PARTY_INCLUDE_LUA
    "${TW_SOURCE_DIR}/ThirdParty/lua/include/"
    CACHE INTERNAL "ToyWorld ThirdParty lua Include Paths"
)


## OpenGL Needed Libs

#Clean this variable first
SET(TW_RENDER_API_DEPS_INCLUDE
    CACHE INTERNAL "ToyWorld ThirdParty RenderAPI Libs Include Paths"
)
if(TOY_WORLD_RENDER_API_OPENGL)
    # GLAD
    SET(TW_THIRD_PARTY_INCLUDE_GLAD
        "${TW_SOURCE_DIR}/ThirdParty/GLAD/glad-c/include"
        CACHE INTERNAL "ToyWorld ThirdParty glad Include Paths"
    )

    # RenderAPI Dependence libs include path
    SET(TW_RENDER_API_DEPS_INCLUDE
        ${TW_THIRD_PARTY_INCLUDE_GLAD}
        CACHE INTERNAL "ToyWorld ThirdParty RenderAPI Libs Include Paths"
    )
endif()