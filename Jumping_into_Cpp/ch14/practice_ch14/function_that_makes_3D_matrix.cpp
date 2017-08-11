//
// IMPORTANT:
// How to build for debug and loading source: 
//   $g++ -g name_of_file.cpp -o blah_binary
#include <iostream>

//
// Builds a two dimensional multiplication page with arbitrary sizes for the two dimensions
// In addition it shows the addresses of each element
//




void print_page( int** & p_p_table, int dim1, int dim2 )
{

    //
    // Printing out content
    //
    for (int ii = 0; ii < dim1; ++ii)
    {

        for (int jj = 0; jj < dim2; ++jj)
        {

            std::cout  << "(" << ii << "," <<  jj << ") = "
                       << p_p_table[ii][jj] << " ";
   
            if( jj == dim2 - 1 )
            {
                std::cout << "." << std::endl;
            }
 
        }

    }

}


int main()
{

    //
    // Pointer to array holding n pointers
    //

    //
    // Pointer to array holding n pointers. Dynamically 
    // allocated space for n types 
    // type * pointer
    // pointer = new type [number_of_elements]
    // Good resource: http://www.cplusplus.com/doc/tutorial/dynamic/ 
    //
    //
    // Array of pointers. Each pointer points to a 2D array page.
    // pp1 -> array of pointers, 
    // each pointer in the array points to an array of ints (row)
    // x:
    // { [pp1] [pp2] [pp3] }
    // y:
    // pp1 -> { [p1] [p2] [p3] } -  
    // pp2 -> { [p1] [p2] [p3] } -  
    // pp3 -> { [p1] [p2] [p3] } -  
    // z:
              // p1-> [1,2,3]
              // p2-> [1,2,3]
              // p3-> [1,2,3]
    // int (*p)[7] = new int[6][7];   // okay

    int dim1 = 2;
    int dim2 = 2;
    int dim3 = 2;

    //
    // Pointer to a pointer to a pointer of an int
    //
    int *** p_p_p_matrix;

    // pointer = new type [number_of_elements]
    p_p_p_matrix = new int** [ dim1 ];

    //
    // Allocate 2nd dimension
    //
    for (int ii = 0; ii < dim1; ++ii)
    {

        // pointer = new type [number_of_elements]
        p_p_p_matrix[ii] = new int* [ dim2 ];

        // Allocate 3d dimension
        for (int jj = 0; jj < dim2; ++jj)
        {

            p_p_p_matrix[ii][jj] = new int [dim3]; 

        }

    }

    //
    // Store multiplication table in each page 
    //
    for (int ii = 0; ii < dim1; ++ii)
    {
       for (int jj = 0; jj < dim2; ++jj)
       {
          for (int kk = 0; kk < dim3; ++kk)
          {

              p_p_p_matrix[ii][jj][kk] = ii*jj;
 
          }
       }
    }

    //
    // Print out all pages 
    //
    for (int ii = 0; ii < dim1; ++ii)
    {
        print_page( p_p_p_matrix[ii], dim2, dim3 );
    }

    //
    // Delete in reverse order
    //
    for (int ii = 0; ii < dim1; ++ii)
    {

        for (int jj = 0; jj < dim2; ++jj)
        {

           // Delete 3rd dimension
           delete[] p_p_p_matrix[ii][jj];

        }

        // Delete 2nd dimension
        delete[] p_p_p_matrix[ii];

    }

    // Delete 1st dimension   
    delete [] p_p_p_matrix;

}
