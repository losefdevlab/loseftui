#Loseftui Makefile
CC = clang++
#编译选项
CFLAGS = -std=c++11 -Wall -Wextra -Werror -I src/desktop/include -I src/tool/include -I src/api/include

#源文件指向
DESKTOP_SOURCES = $(wildcard src/desktop/*.cpp)
TOOL_SOURCES = $(wildcard src/tool/*.cpp)
API_SOURCES = $(wildcard src/api/*.cpp)
#源文件指向
SOURCES = boot.cpp $(DESKTOP_SOURCES) $(TOOL_SOURCES) $(API_SOURCES)

#一步到位编译
onestep:
	@echo "Building in one step..."
	@mkdir -p build
	@$(CC) $(CFLAGS) $(SOURCES) -o build/loseftui
	@echo "Done!"

#清理编译产物
clean:
	@echo "Cleaning..."
	@rm -rf build
	@echo "Done!"