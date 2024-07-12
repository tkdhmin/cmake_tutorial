# 테스트 실행 파일 생성
add_executable(test_factorial test_factorial.cpp)

# 테스트 타겟에 include 디렉토리 추가
target_include_directories(test_factorial PRIVATE ${CMAKE_SOURCE_DIR})

# 테스트 타겟에 라이브러리 링크
target_link_libraries(test_factorial PRIVATE factorial gtest gtest_main)

# 테스트 등록
add_test(NAME test_factorial COMMAND test_factorial)