g++ **/*.cpp -c
g++ *.cpp -c
g++ *.o -o latest-compilation
rm *.o
./latest-compilation
