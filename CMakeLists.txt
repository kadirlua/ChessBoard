cmake_minimum_required(VERSION 3.16)

project(ChessBoard)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/ChessBoard)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/ChessBoard)

set(PROJECT_SOURCES 
            ${PROJECT_SOURCE_DIR}/main.cpp
            ${PROJECT_SOURCE_DIR}/chessboard.cpp
            ${PROJECT_SOURCE_DIR}/piece.cpp
			${PROJECT_SOURCE_DIR}/pawn.cpp
			${PROJECT_SOURCE_DIR}/knight.cpp
			${PROJECT_SOURCE_DIR}/bishop.cpp
			${PROJECT_SOURCE_DIR}/rook.cpp
			${PROJECT_SOURCE_DIR}/queen.cpp
			${PROJECT_SOURCE_DIR}/king.cpp
    )

set(PROJECT_HEADERS
			${PROJECT_INCLUDE_DIR}/chessboard.h
            ${PROJECT_INCLUDE_DIR}/piece.h
			${PROJECT_INCLUDE_DIR}/pawn.h
			${PROJECT_INCLUDE_DIR}/knight.h
			${PROJECT_INCLUDE_DIR}/bishop.h
			${PROJECT_INCLUDE_DIR}/rook.h
			${PROJECT_INCLUDE_DIR}/queen.h
			${PROJECT_INCLUDE_DIR}/king.h		
    )


target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
