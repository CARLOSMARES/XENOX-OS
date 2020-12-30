mkdir build
cd build
cmake ..
make
make DESDIR=boot Install
chmod +x iso.sh
./iso.sh