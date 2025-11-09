file(GLOB_RECURSE KRANGLED_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/*.h"
)

file(GLOB_RECURSE KRANGLED_MATH_FILES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/KrangledMath/KrangledMath/KRMath/*.h"
)

set(ThirdPartyFolder "${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/")
set(SDL2_INCLUDE_DIR "${ThirdPartyFolder}x64/includes/SDL")
set(SDL2_LIB_DIR "${ThirdPartyFolder}x64/Libs/SDL")
set(SDL_IMAGE_INCLUDE_DIR "${ThirdPartyFolder}x64/includes/SDL_Image")
set(SDL_IMAGE_LIB_DIR "${ThirdPartyFolder}x64/Libs/SDL_Image")
set(OPENAL_INCLUDE_DIR "${ThirdPartyFolder}x64/includes/OpenAL")
set(OPENAL_LIB_DIR "${ThirdPartyFolder}x64/Libs/OpenAL")

Add_library(Krangled STATIC ${KRANGLED_SOURCES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${KRANGLED_SOURCES})

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

target_include_directories(Krangled PRIVATE ${OPENAL_INCLUDE_DIR})

target_link_libraries(Krangled PRIVATE "${OPENAL_LIB_DIR}/OpenAL32.lib")


set(KRANGLED_LIB_DIR "${PROJECT_SOURCE_DIR}/3rdParty/x64/Libs")

add_custom_command(TARGET Krangled POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${KRANGLED_LIB_DIR}/SDL_Image/SDL2_image.dll"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
		
add_custom_command(TARGET Krangled POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${KRANGLED_LIB_DIR}/SDL/SDL2.dll"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
		
add_custom_command(TARGET Krangled POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${KRANGLED_LIB_DIR}/OpenAL/OpenAL32.dll"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")