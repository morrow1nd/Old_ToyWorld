SET(TW_ENGINE_INC_SCENE
	"Scene/ComponentBase.h"
	"Scene/ComponentManagerHelper.h"
	"Scene/IComponent.h"
	"Scene/IComponentManager.h"
	"Scene/Scene.h"
	"Scene/SceneManager.h"
	"Scene/SceneObject.h"
	"Scene/SceneObjectManager.h"
)

SET(TW_ENGINE_INC_SCENE_COMPONENTS
	"Scene/Components/CTransform.h"
	#"Scene/Components/CBlock.h"
	#"Scene/Components/CBlockRender.h"
	"Scene/Components/CCamera.h"
	"Scene/Components/CLight.h"
	"Scene/Components/CMeshFilter.h"
	"Scene/Components/CMeshRenderer.h"
)

SET(TW_ENGINE_SRC_SCENE_COMPONENTS
	"Scene/Components/CTransform.cpp"
	#"Scene/Components/CBlock.cpp"
	#"Scene/Components/CBlockRender.cpp"
)


SET(TW_ENGINE_SRC_SCENE
	"Scene/ComponentManagerHelper.cpp"
	"Scene/SceneManager.cpp"
)

SET(TW_ENGINE_SRC_BASE
)

SET(TW_ENGINE_INC_BASE
	"Base/IModule.h"
	"Base/ISingleton.h"
)

SET(TW_ENGINE_SRC_ENGINE
	"Engine/Engine.cpp"
)

SET(TW_ENGINE_INC_ENGINE
	"Engine/Engine.h"
	"Engine/EngineStartUpParam.h"
)

SET(TW_ENGINE_INC_RENDER_API
	"RenderAPI/RenderAPIPlatformSpecific.h"
	"RenderAPI/GpuProgram.h"
	# "RenderAPI/GpuPipelineState.h"
	"RenderAPI/GpuVertexData.h"

	# "RenderAPI/GpuFrameBuffer.h"
	# "RenderAPI/GpuRenderBuffer.h"
	# "RenderAPI/GpuTexture2D.h"
	"RenderAPI/RenderAPI.h"
)

SET(TW_ENGINE_SRC_RENDER_API
	"RenderAPI/RenderAPIPlatformSpecific.cpp"
)

if(TOY_WORLD_RENDER_API_OPENGL)
	SET(TW_ENGINE_SRC_RENDER_API
		${TW_ENGINE_SRC_RENDER_API}
		
		"RenderAPI/OpenGL/GpuProgram.cpp"
		# "RenderAPI/GpuPipelineState.cpp"
		"RenderAPI/OpenGL/GpuVertexData.cpp"

		# "RenderAPI/GpuFrameBuffer.cpp"
		# "RenderAPI/GpuRenderBuffer.cpp"
		# "RenderAPI/GpuTexture2D.cpp"
		"RenderAPI/OpenGL/RenderAPI.cpp"
	)
elseif(TOY_WORLD_RENDER_API_DX11)

elseif(TOY_WORLD_RENDER_API_OPENGLES)

else()
	message(FATAL_ERROR "Can't find a RenderAPI to use.")
endif()


# if(MSVC)
# 	list(APPEND BS_BANSHEECORE_INC_PLATFORM VSVisualizations.natvis)
# endif()

# if(WIN32)
# 	list(APPEND BS_BANSHEECORE_INC_PLATFORM ${BS_BANSHEECORE_INC_PLATFORM_WIN32})
# 	list(APPEND BS_BANSHEECORE_SRC_PLATFORM ${BS_BANSHEECORE_SRC_PLATFORM_WIN32})
# elseif(LINUX)
# 	list(APPEND BS_BANSHEECORE_INC_PLATFORM ${BS_BANSHEECORE_INC_PLATFORM_LINUX})
# 	list(APPEND BS_BANSHEECORE_SRC_PLATFORM ${BS_BANSHEECORE_SRC_PLATFORM_LINUX})
# elseif(APPLE)
# 	list(APPEND BS_BANSHEECORE_INC_PLATFORM ${BS_BANSHEECORE_INC_PLATFORM_MACOS})
# 	list(APPEND BS_BANSHEECORE_SRC_PLATFORM ${BS_BANSHEECORE_SRC_PLATFORM_MACOS})
# endif()

source_group("Header Files\\Scene" 						FILES ${TW_ENGINE_INC_SCENE})
source_group("Source Files\\Scene" 						FILES ${TW_ENGINE_SRC_SCENE})
source_group("Header Files\\Scene\\Components" 			FILES ${TW_ENGINE_INC_SCENE_COMPONENTS})
source_group("Source Files\\Scene\\Components" 			FILES ${TW_ENGINE_SRC_SCENE_COMPONENTS})
source_group("Header Files\\Base" 						FILES ${TW_ENGINE_INC_BASE})
source_group("Source Files\\Base" 						FILES ${TW_ENGINE_SRC_BASE})
source_group("Header Files\\Engine" 					FILES ${TW_ENGINE_INC_ENGINE})
source_group("Source Files\\Engine" 					FILES ${TW_ENGINE_SRC_ENGINE})
source_group("Header Files\\RenderAPI" 					FILES ${TW_ENGINE_INC_RENDER_API})
source_group("Source Files\\RenderAPI" 					FILES ${TW_ENGINE_SRC_RENDER_API})
source_group("CMake" 									FILES "CMakeSources.cmake" "CMakeLists.txt")


set(TW_ENGINE_SRC
	"CMakeSources.cmake" "CMakeLists.txt"
	${TW_ENGINE_INC_SCENE}
	${TW_ENGINE_SRC_SCENE}
	${TW_ENGINE_INC_SCENE_COMPONENTS}
	${TW_ENGINE_SRC_SCENE_COMPONENTS}
	${TW_ENGINE_SRC_BASE}
	${TW_ENGINE_INC_BASE}
	${TW_ENGINE_INC_ENGINE}
	${TW_ENGINE_SRC_ENGINE}
	${TW_ENGINE_INC_RENDER_API}
	${TW_ENGINE_SRC_RENDER_API}
)
