#include "matrix_operations.h"
/* * @brief  Add two matrices
 *  
 *  Takes in two matrices defined by rows and columns, then adds them
 *
 * @param   Src_nRows       Number of rows in the input matrices
 *          Src_nColumns    Number of columns in the input matrices
 *          SrcA            First matrix in
 *          SrcB            Second matrix in  
 *          
 * @retval  Dst             Matrix out
 */
void matrix_add_d8 (    const uint32_t   Src_nRows,
                        const uint32_t   Src_nColumns,
                        int8_t    SrcA[Src_nRows][Src_nColumns],
                        int8_t    SrcB[Src_nRows][Src_nColumns],
                        int8_t          Dst[Src_nRows][Src_nColumns]     ){

    for (uint32_t i = 0; i < Src_nRows; i++){
       vect_add(Src_nRows,SrcA[i],SrcB[i],Dst[i]);
    }
}