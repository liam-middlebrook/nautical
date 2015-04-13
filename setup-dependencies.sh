#!/bin/sh

# CMake
wget http://www.cmake.org/files/v3.1/cmake-3.1.2-Linux-x86_64.sh
chmod +x cmake-3.1.2-Linux-x86_64.sh
mkdir cmake
sh cmake-3.1.2-Linux-x86_64.sh --skip-license --prefix=cmake --exclude-subdir

# libglfw3 isn't up to date in apt with precise
wget http://sourceforge.net/projects/glfw/files/glfw/3.0.4/glfw-3.0.4.zip
unzip glfw-3.0.4.zip
cd glfw-3.0.4
	cmake -DBUILD_SHARED_LIBS=ON -G "Unix Makefiles"
	make
	sudo make install
	sudo cp /usr/local/lib/libglfw* /usr/lib/
	sudo cp -R /usr/local/include/GLFW /usr/include/
cd ..

# SWIG
wget http://prdownloads.sourceforge.net/swig/swig-3.0.5.tar.gz
tar -xzf swig-3.0.5.tar.gz
cd swig-3.0.5
	./configure
	make
	sudo make install
cd ..

# RapidJSON
git clone git://github.com/miloyip/rapidjson.git
cd rapidjson
mkdir build
cd build
cmake ..
sudo make install
cd ../..

