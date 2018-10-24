# these files are safe to remove any way.
rm Makefile -f
rm CMakeCache.txt -f
rm cmake_install.cmake -f
rm CMakeFiles -rf
cmake ..
make
