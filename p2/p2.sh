g++ -c *.cpp -D_GLIBCXX_USE_CXX11_ABI=0
g++ -o driver *.o -D_GLIBCXX_USE_CXX11_ABI=0
echo "Euler:"
./driver 0.1 udo euler 10 0
echo "Symplectic Euler:"
./driver 0.1 udo symplectic 10 0
echo "Fourth Order Runge-Kutta"
./driver 0.1 udo rk4 10 0
