####
# 
####
cmake_minimum_required(VERSION 3.13)
project(OBC_project C CXX)

###
# F' Core Setup
# This includes all of the F prime core components, and imports the make-system.
###
include("${CMAKE_CURRENT_LIST_DIR}/../cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines
include("${CMAKE_CURRENT_LIST_DIR}/../cmake/FPrime-Code.cmake")


# This includes project-wide objects
include("${CMAKE_CURRENT_LIST_DIR}/project.cmake")
