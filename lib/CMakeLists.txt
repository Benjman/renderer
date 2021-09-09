add_subdirectory(./glad)

add_subdirectory(./entt)
set(ENTT_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/entt/src PARENT_SCOPE)

set(STB_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/stb PARENT_SCOPE)
