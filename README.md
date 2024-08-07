# cmake_tutorial
TO PROVIDE ANSWER OF https://cmake.org/getting-started/


# General Introduction for CMake Build System
CMake는 소스 코드를 빌드하는 것을 관리하는 도구이다.
원래 CMake는 다양한 Makefile 방언을 생성하기 위해 설계된 것으로 알려져있다.
CMake는 주로 C와 C++ 언어에 많이 사용되지만, 다른 언어의 소스 코드를 빌드하는 데에도 사용할 수 있다.

CMake-based build system 은 고수준의 논리적 타겟 집합으로 구성되며, 멀티 플랫폼에서 사용 가능하다.
각 타겟은 실행 파일이나 라이브러리에 해당하거나, 사용자 정의 명령을 포함하는 사용자 정의 타겟입니다. 타겟 간의 의존성은 빌드 시스템 내에서 표현되어 빌드 순서와 변경에 따른 재생성 규칙을 결정합니다

* CMake 기반 프로젝트 시작하는 개발자의 경우 CMake 튜토리얼부터 시작.
https://cmake.org/cmake/help/latest/guide/tutorial/index.html

* 인터넷에서 다운로드한 소스 코드 패키지를 빌드하는 방법을 배우려면 사용자 상호작용 가이드(User Interaction Guide)부터 시작.
https://cmake.org/cmake/help/latest/guide/user-interaction/index.html

* 타사 라이브러리를 사용하여 시작하려는 개발자는 의존성 사용 가이드(Using Dependencies Guide) 시작.
https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html

* 빌드 시스템을 유지하고 CMake에서 표현할 수 있는 빌드 타겟에 익숙해지기 위해 지식을 확장하려는 개발자를 대상으로는 cmake-buildsystem(7) 시작.
https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html

* 타사 CMake 기반 빌드 시스템에서 쉽게 사용할 수 있는 패키지를 만드는 방법을 배우려면 cmake-packages(7) 시작. https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html

## Target Definition
CMake에서 "타겟(target)"은 빌드 시스템 내에서 생성되거나 관리되는 주요 개체를 의미한다.
프로그램을 구성하는 모든 요소가 타겟이 된다.
구체적으로, 각 타겟은 실행 파일, 라이브러리가 될 수 있으며 또는 특정 작업을 수행하는 사용자 정의 명령들 집합을 뜻할 수 있다.
타겟은 CMakeLists.txt 파일에서 정의되도록 약속되어 있고, 여기서 빌드 과정에서 만들어질 결과물이 지정된다.
CMakeLists.txt 에 정의된 고수준 (High-level) 의 타겟 집합으로 CMake 기반 빌드 시스템이 구성된다고 이해하면 된다.

타겟의 주요 유형으로는 아래와 같이 분류된다:

1. **실행 파일 타겟 (Executable Target)**: 컴파일 후 실행 파일이 생성되는 타겟이다.
예를 들어, `add_executable(my_executable main.cpp)`와 같이 정의할 수 있다.

2. **라이브러리 타겟 (Library Target)**: 정적 라이브러리 또는 동적 라이브러리가 생성되는 타겟이다.
정적 라이브러리는 컴파일 시간에 프로그램에 링크되는 라이브러리다.
이 라이브러리의 모든 코드와 데이터는 프로그램의 실행 파일에 포함된다.
반면, 동적 라이브러리는 실행 시간에 프로그램에 의해 로드되는 라이브러리다.
이 라이브러리의 코드는 실행 파일과 독립적으로 존재하며, 여러 프로그램이 동일한 라이브러리 파일을 공유할 수 있다.
이러한 정적 및 동적 라이브러리는 `add_library(my_library STATIC library.cpp)` 또는 `add_library(my_library SHARED library.cpp)`와 같이 정의할 수 있다. 

3. **사용자 정의 타겟 (Custom Target)**: 사용자 정의 명령을 실행하는 타겟입니다. 빌드 과정에서 특정 작업을 수행하도록 할 수 있습니다. 예를 들어, `add_custom_target(my_custom_target COMMAND echo "Hello, World!")`와 같이 정의할 수 있습니다.

타겟 간의 의존성은 `target_link_libraries` 또는 `add_dependencies` 명령어를 사용하여 지정할 수 있다.
이러한 의존성 컨트롤을 통해 타겟 간의 빌드 순서를 결정하고, 어떤 타겟이 다른 타겟에 의해 필요로 되는지를 명확히 할 수 있다.

## Platform-Specific Binary File Naming Conventions
각 플랫폼마다 실행 파일이나 라이브러리 파일의 이름 형식이 다를 수 있다.
CMake 는 이러한 상황에 대처하기 위해, CMake에서 만든 바이너리 파일은 대상 플랫폼 (Target platform) 에 적합한 접두사(PREFIX), 접미사(SUFFIX) 및 확장자를 갖도록 자동 지원한다.
CMake 에서 아래와 같이 다양한 운영 체제와 플랫폼별 규칙을 자동으로 적용해서 올바른 파일 이름을 생성한다:

- **접두사(PREFIX)**: 파일 이름의 앞에 추가되는 문자열이다.
예를 들어, 일부 플랫폼에서는 라이브러리 파일 이름 앞에 "lib"를 붙이기 때문에 `myapp` 라이브러리가 `libmyapp.a` (정적 라이브러리) 또는 `libmyapp.so` (동적 라이브러리) 와 같은 이름이 된다.
- **접미사(SUFFIX) 및 확장자**: 파일 이름의 뒤에 추가되는 문자열이다.
예를 들어, 윈도우에서는 실행 파일과, 정적 라이브러리와 동적 라이브러리에는 각각 `.exe`, `.lib`, `.dll` 확장자를 사용한다.
반면, 리눅스에서는 실행 파일에 확장자를 붙이지 않고, 정적 라이브러리와 동적 라이브러리에는 각각 `.a` 와 `.so` 를 사용한다.


이러한 규칙에 따라 예를 들어, CMake 가 `add_executable(myapp main.cpp)` 라는 명령으로 생성한 실행 파일은 리눅스에서는 `myapp` 이 되지만, 윈도우에서는 `myapp.exe`가 생성된다.

# Chapter 1: The Basics of cmake-buildsystem
## 1. Minimum Version of CMake Program
모든 CMake 파일의 첫 줄에는  `cmake_minimum_required()` 명령을 통해 CMake 의 버전을 지정한다.
```cmake
cmake_minimum_required(VERSION 3.1)
```
CMake 의 버전을 범위로 지정도 가능하며 각 버전 별로 빌드의 정책을 달리할 수 있다.
```cmake
cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
```

## 2. Setting Project
모든 CMake 의 최상단에는 다음과 같은 프로젝트 명세에 대한 명령이 포함된다.
```cmake
project(MyProject VERSION 1.0 
        DESCRIPTION "Very nice project"
        LANGUAGES CXX)
```

## 3. Making Executables
실행 파일은 `add_executable()` 명령을 통해 실행 파일 이름과 빌드에 필요한 소스 파일 지정하여 실행 파일 타겟을 정의한다.

```cmake
add_executable(zipapp zipapp.cpp mycode.cpp) # zipapp 은 zipapp.cpp 와 mycode.cpp 를 컴파일하고 링킹 (linking) 을 통해 만들어진 실행 파일 (binary executable) 이다.
```
```cmake
add_executable(one two.cpp three.h) # one 은 실행 파일 (executable) 이름, two 는 소스 파일 이름, three 는 헤더파일을 나타낸다.
```

## 4. Making Libraries
라이브러리는 `add_library()` 명령을 사용하여 정의된다.
```cmake
add_library(one STATIC two.cpp three.h) # 여기서 라이브러리 유형을 STATIC, SHARED, MODULE 중 하나를 정해야 한다.
add_library(archive SHARED archive.cpp zip.cpp lzma.cpp)
add_library(archive STATIC archive.cpp zip.cpp lzma.cpp)
```
`add_library()` 명령어의 중간 인자로 어떤 유형으로 라이브러리르 만들 것인지 지정할 수 있다.
STATIC 으로 명시하는 경우엔 정적 라이브러리로, SHARED 로 명시하는 경우엔 동적 라이브러리, 그리고 MODULE 로 명시하면 동적으로 링크되지는 않지만 함수로 런타임 시 모듈 역할로써 불러올 수 있는 라이브러리를 생성한다.

기본적으로 `add_library()` 명령은 타입이 지정되지 않는 한 정적 (STATIC) 라이브러리를 정의한다.

## 5. Assinging Compile Options
컴파일 옵션을 지정하는 경우에는 `target_compile_options()` 명령을 사용하여 지정한다.
```cmake
target_compile_options(targetprogram PUBLIC -Wall -Werror) # targetprogram 을 빌드할 때, 컴파일 옵션으로 -Wall 과 -Werror 을 준다는 의미이다.
```

## 6. Assinging Path of 'include' directory
CMake 에서는 컴파일 시 헤더 파일들을 찾을 경로의 위치를 `target_include_directories()` 명령을 통해 지정할 수 있다.
```cmake
target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/includes) # program 을 빌드 시, includes 디렉토리 경로를 program 에게 인지시킴으로써 헤더 파일 경로 탐색 시 확인 가능해진다.
```

## 7. Linking Targets of Libraries
CMake 에서는 본 타겟을 또 다른 타겟들에 대한 의존성을 `target_link_libraries()` 명령을 통해 지정할 수 있다.
이 명령어 인자로 들어가는 다른 타겟의 이름이 CMake 에 존재하지 않으면 외부 라이브러리라고 자동 인지한다.

```cmake
# 실행 Target 에 정의된 라이브러리를 링크

add_library(library_target STATIC library.cpp) # 라이브러리 타겟 정의

add_executable(executable_target main.cpp) # 실행 파일 타겟 정의

target_link_libraries(executable_target PRIVATE library_target) # 실행 파일 타겟에 라이브러리 타겟을 링크
```

```cmake
# 실행 Target 에 외부 라이브러리를 링크

add_executable(executable_target main.cpp) # 실행 파일 타겟 정의

target_link_libraries(executable_target PRIVATE m) # 실행 파일 타겟에 시스템 라이브러리인 m 링크
```

```cmake
# 라이브러리 정의시 다른 라이브러리 링크

add_library(shape STATIC shape.cc)
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_compile_options(shape PRIVATE -Wall -Werror)

target_link_libraries(shape PRIVATE pthread) # pthread 라이브러리를 링크 # 여기서, pthread 라는 라이브러리를 shape 의 내부 구현 (.cc 파일) 에서만 사용하기 때문에 PRIVATE 으로 지정. 만약, pethread 라이브러리를 shape 의 헤더 파일 (.h 파일) 에서도 같이 사용한다면, PUBLIC 으로 지정하고 헤더 파일에서만 사용하는 경우엔 INTERFACE 로 지정한다.
```

## 8. Example
```cmake
add_library(archive archive.cpp zip.cpp lzma.cpp) # archive 는 archive.cpp zip.cpp lzma.cpp 에서 컴파일된 객체를 포함하는 STATIC 라이브러리 아카이브이다.
add_executable(zipapp zipapp.cpp)
target_link_libraries(zipapp archive) # zipapp 실행 파일을 링킹할 때, archive 정적 라이브러리가 함께 링킹된다.
```

# Chapter 2: Variables and the Cache


# Reference
https://github.com/jacking75/examples_CMake

https://cliutils.gitlab.io/modern-cmake/chapters/basics.html

https://modoocode.com/332
