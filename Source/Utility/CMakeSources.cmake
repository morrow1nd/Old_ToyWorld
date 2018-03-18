SET(TW_UTILITY_SRC_MATH
	"Math/Math.cpp"
	"Math/Radian.cpp"
	"Math/Degree.cpp"
	"Math/Vector2.cpp"
	"Math/Vector3.cpp"
	"Math/Vector4.cpp"
	"Math/Quaternion.cpp"
	"Math/Matrix3.cpp"
	"Math/Matrix4.cpp"
	"Math/TransformPRS.cpp"
)

SET(TW_UTILITY_INC_MATH
	"Math/MathFwdDecl.h"
	"Math/Math.h"
	"Math/Radian.h"
	"Math/Degree.h"
	"Math/Vector2.h"
	"Math/Vector3.h"
	"Math/Vector4.h"
	"Math/Quaternion.h"
	"Math/Matrix3.h"
	"Math/Matrix4.h"
	"Math/MatrixNxM.h"
	"Math/TransformPRS.h"
)

SET(TW_UTILITY_INC_PREREQUISITES
	"Prerequisites/StdHeaders.h"
	"Prerequisites/Types.h"
)


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

source_group("Header Files\\Math" 						FILES ${TW_UTILITY_INC_MATH})
source_group("Source Files\\Math" 						FILES ${TW_UTILITY_SRC_MATH})
source_group("Header Files\\Prerequisites" 				FILES ${TW_UTILITY_INC_PREREQUISITES})
source_group("CMake" 									FILES "CMakeSources.cmake" "CMakeLists.txt")


set(TW_UTILITY_SRC
	"CMakeSources.cmake" "CMakeLists.txt"
	${TW_UTILITY_INC_MATH}
	${TW_UTILITY_SRC_MATH}
	${TW_UTILITY_INC_PREREQUISITES}
)
