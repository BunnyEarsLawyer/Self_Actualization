//
// IMPORTANT:
// How to build for debug and loading source: 
//   $g++ -g name_of_file.cpp -o blah_binary
// How to debug: 
//   $gdb ./blah_binary
//
// Using GDB Dashboard
// (gdb) break main
// (gdb) n
// (gdb) s
// (gdb) info locals 
// (gdb) list
// (gdb) c
// (gdb) E.g. >>> print p_p_table
// (gdb) E.g. >>> print *p_p_table
// (gdb) E.g. >>> print *(*p_p_table)            // 0
// (gdb) E.g. >>> print *(*p_p_table + 1)        // 1
// (gdb) E.g. >>> print *(*p_p_table + 1) + 1    // 2
// (gdb) b 72 
// (gdb) c // skips to break I set
//
// How to watch memory 
// (gdb) E.g. >>> dashboard memory watch 0x603010 4
// (gdb) p *p_p_table@3  // @ treats parts of memory as arrays. 
// $36 = {[0] = 0x603030, [1] = 0x603050, [2] = 0x0}
// >>> print *(p_p_table)
// $48 = (int *) 0x603030  
// >>> print *(p_p_table + 1)
// $49 = (int *) 0x603050
//
// How to set an expression 
// (gdb) set $i = 0
// (gdb) print $i 
// (gdb) dashboard expression watch $i


#include <iostream>

//
// Builds a two dimensional multiplication table with arbitrary sizes for the two dimensions
// In addition it shows the addresses of each element
//

int main()
{

    //
    // Pointer to array holding n pointers
    //
    int n = 3;

    int array_size = n - 1;

    int ** p_p_table;

    p_p_table = new int*[ n ];

    //
    // { [p1] [p2] [p3] }
    // p1 -> { [0] [1] [2] } -  p2 -> { [0] [1] [2] } - p3 ->  { [0] [1] [2] }
    //


    //
    // Now make each pointer store the address of an array of integers
    //
    for (int ii = 0; ii < n; ++ii)
    {

        p_p_table[ii] = new int[n];
 
    }

    //
    // Now you can use the allocated memory like a 2D array
    //

    for (int ii = 0; ii < n; ++ii)
    {

        for (int jj = 0; jj < n; ++jj)
        {

            p_p_table[ii][jj] = ii;
 
        }

    }

    //
    // Printing out content
    //
    for (int ii = 0; ii < n; ++ii)
    {

        for (int jj = 0; jj < n; ++jj)
        {

            std::cout  << "(" << ii << "," <<  jj << ") = "
                       << p_p_table[ii][jj] << " ";
   
            if( jj == n - 1 )
            {
                std::cout << "." << std::endl;
            }
 
        }

    }

    //
    // Printing out addresses 
    //
    for (int ii = 0; ii < n; ++ii)
    {

        for (int jj = 0; jj < n; ++jj)
        {

            std::cout  << "Address of (" << ii << "," <<  jj << ") = "
                       << & p_p_table[ii][jj] << " ";
   
            if( jj == n - 1 )
            {
                std::cout << std::endl;
            }
 
        }

    }

    std::cout  << "sizeof(int) " << "\n "
               << sizeof(int) << std::endl;

    std::cout  << "Pointer p_p_table " << "\n "
               << p_p_table << std::endl;

    std::cout  << "Pointer Dereferening once *p_p_table " << "\n "
               << *p_p_table << std::endl;

    std::cout  << "Next element *p_p_table + 1" << "\n "
               << *p_p_table + 1 << std::endl;

    std::cout  << "Next element *p_p_table + 2" << "\n "
               << *p_p_table + 2 << std::endl;

    std::cout  << "Next element *p_p_table + array_size" << "\n "
               << *p_p_table + array_size << std::endl;

    std::cout  << "Next element *p_p_table + array_size*sizeof(int)" << "\n "
               << *p_p_table + array_size*sizeof(int) << std::endl;

    std::cout  << "Pointer Dereferencing Twice **p_p_table " << "\n "
               << **p_p_table << std::endl;

    std::cout  << "Pointer Math *(*p_p_table + array_size*sizeof(int) + 1)" << "\n "
               << *(*p_p_table + array_size*sizeof(int) + 1) << std::endl;

    std::cout  << "Pointer Math *(*p_p_table + array_size*sizeof(int) + 2)" << "\n "
               << *(*p_p_table + array_size*sizeof(int) + 2) << std::endl;

    //
    // Delete in reverse order
    //
    for (int ii = 0; ii < n; ++ii)
    {

        delete [] p_p_table [ii];
 
    }
    
    delete [] p_p_table;

}

