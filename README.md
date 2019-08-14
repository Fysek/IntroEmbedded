Copyright 2019 Mateusz Dyrdół<mateuszdyrdol@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



This is a collection of functions that can analyze a given array of unsigned char items and 
provide analytical data like mean,median,maximum and minimum of the data set. All the statistics
are rounded of to the nearest integer.

The input aray is defined in the code. Its total number of elements is defined by  "SIZE"
and its contents by the variable "test[SIZE]". If you require to collect statistics on another 
set of data, edit the "SIZE" and the varibale "test[SIZE]" accrodingly.

Compiling: gcc -o stats.out statc.c

Running: ./stats.out
