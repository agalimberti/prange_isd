# README

This is a tutorial of the PrangeISD project.  
For testing purposes, the following files contained in the _test/_ folder can be used:
- a Hamming(7,4) code, which can correct errors with Hamming weight equal to 1, and
- a Goppa(12,4,5) code, which can correct errors with Hamming weight up to 2.

For information about the Prange instruction set decoding algorithm, refer to: https://hackingthe.net/downloads/isd.pdf.

## Compiling instructions

1) Clone the PrangeISD project from the repository:
~~~
:::bash
  $ git clone https://github.com/agalimberti/prange_isd.git
~~~
		
2) Create a _bin/_ folder inside the root of the project, and run make with the chosen N and K parameters:
~~~
:::bash
  $ mkdir bin
  $ make N=(codeword length) K=(message length)
~~~

## Testing instructions (wrt Goppa test)

1) Enter the _test/_ folder, and run g++:

~~~
:::bash
  $ cd test
  $ g++ test_prange_goppa_N12_K4.cpp -c -I../include -DN=12 -DK=4 -o test_prange_goppa_N12_K4.o
  $ g++ test_prange_goppa_N12_K4.o ../bin/prange_N12_K4.a -o test_goppa
~~~

2) Launch the executable:
~~~
:::bash
  $ ./test_goppa
~~~