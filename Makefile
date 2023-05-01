STB_INCLUDE_PATH = /home/tiago-nascimento/tiago/workspace/3d-studies/stb
TINYOBJLOADER_INCLUDE_PATH = /home/tiago-nascimento/tiago/workspace/3d-studies/tinyobjloader

CFLAGS = -std=c++17 -I$(STB_INCLUDE_PATH) -I$(TINYOBJLOADER_INCLUDE_PATH) -O3
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
VulkanTest: main.cpp VulkanApplication.cpp Utils.cpp
	g++ $(CFLAGS) -o VulkanTest main.cpp VulkanApplication.cpp Utils.cpp $(LDFLAGS) -DVERBOSE

.PHONY: run clean

run: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest