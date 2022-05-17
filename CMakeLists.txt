cmake_minimum_required(VERSION 3.20)
project(ing1_projet_2021_22_dofus_arena_team_ad_1)

set(CMAKE_C_STANDARD 99)

add_executable(ing1_projet_2021_22_dofus_arena_team_ad_1 affichage.c affichage.h arene.c arene.h deplacement.c deplacement.h jeu.c jeu.h general.h personnages.c affichage2.c affichage_jeu.c clavier.c initialisation.c joueur.h main.c)

INCLUDE_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.7.0/include)
LINK_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.7.0/lib)
file(GLOB LIBRARIES "/opt/homebrew/Cellar/allegro/5.2.7.0/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")
TARGET_LINK_LIBRARIES(ing1_projet_2021_22_dofus_arena_team_ad_1 ${LIBRARIES})