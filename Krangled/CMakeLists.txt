file(GLOB_RECURSE KRANGLED_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/*.h"
)

file(GLOB_RECURSE KRANGLED_MATH_FILES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/KrangledMath/KrangledMath/KRMath/*.h"
)

set(3rdPartyFolder "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/")
set(SDL2_INCLUDE_DIR "${3rdPartyFolder}x64/includes/SDL")
set(SDL2_LIB_DIR "${3rdPartyFolder}x64/Libs/SDL")
set(SDL_IMAGE_INCLUDE_DIR "${3rdPartyFolder}x64/includes/SDL_Image")
set(SDL_IMAGE_LIB_DIR "${3rdPartyFolder}x64/Libs/SDL_Image")

Add_library(Krangled STATIC ${KRANGLED_SOURCES})

target_link_libraries(Krangled PUBLIC KrangledMath)
		
target_include_directories(Krangled PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${KRANGLED_MATH_DIR} )

target_include_directories(Krangled
    PRIVATE
		${SDL2_INCLUDE_DIR}
)

target_link_libraries(Krangled PRIVATE "${SDL2_LIB_DIR}/SDL2.lib")

target_include_directories(Krangled
    PRIVATE
		${SDL_IMAGE_INCLUDE_DIR}
)

target_link_libraries(Krangled
    PRIVATE
        "${SDL_IMAGE_LIB_DIR}/SDL2_Image.lib"
)
