/**
 * @file
 * This file contains the implementation of RateMatrix_MtMam, which is
 * class that holds a rate matrix in RevBayes.
 *
 * @brief Implementation of RateMatrix_MtMam
 *
 * (c) Copyright 2009- under GPL version 3
 * @date Last modified: $Date: 2012-12-11 14:46:24 +0100 (Tue, 11 Dec 2012) $
 * @author The RevBayes Development Core Team
 * @license GPL version 3
 * @version 1.0
 * @since 2009-08-27, version 1.0
 * @interface Mcmc
 * @package distributions
 *
 * $Id: RateMatrix_MtMam.cpp 1921 2012-12-11 13:46:24Z hoehna $
 */

#include "RateMatrix_MtMam.h"

#include <cstddef>
#include <vector>

#include "RbVectorUtilities.h"
#include "Cloneable.h"
#include "MatrixReal.h"
#include "RbVector.h"
#include "RbVectorImpl.h"


using namespace RevBayesCore;

/** Construct rate matrix with n states */
RateMatrix_MtMam::RateMatrix_MtMam( void ) : RateMatrix_Empirical( 20 ){
    
    MatrixReal &m = *the_rate_matrix;
    
    /* MtMam */	
	m[ 0][ 0] =   0; m[ 0][ 1] =  32; m[ 0][ 2] =   2; m[ 0][ 3] =  11; m[ 0][ 4] =   0;
	m[ 0][ 5] =   0; m[ 0][ 6] =   0; m[ 0][ 7] =  78; m[ 0][ 8] =   8; m[ 0][ 9] =  75;
	m[ 0][10] =  21; m[ 0][11] =   0; m[ 0][12] =  76; m[ 0][13] =   0; m[ 0][14] =  53;
	m[ 0][15] = 342; m[ 0][16] = 681; m[ 0][17] =   5; m[ 0][18] =   0; m[ 0][19] = 398;
	m[ 1][ 0] =  32; m[ 1][ 1] =   0; m[ 1][ 2] =   4; m[ 1][ 3] =   0; m[ 1][ 4] = 186;
	m[ 1][ 5] = 246; m[ 1][ 6] =   0; m[ 1][ 7] =  18; m[ 1][ 8] = 232; m[ 1][ 9] =   0;
	m[ 1][10] =   6; m[ 1][11] =  50; m[ 1][12] =   0; m[ 1][13] =   0; m[ 1][14] =   9;
	m[ 1][15] =   3; m[ 1][16] =   0; m[ 1][17] =  16; m[ 1][18] =   0; m[ 1][19] =   0;
	m[ 2][ 0] =   2; m[ 2][ 1] =   4; m[ 2][ 2] =   0; m[ 2][ 3] = 864; m[ 2][ 4] =   0;
	m[ 2][ 5] =   8; m[ 2][ 6] =   0; m[ 2][ 7] =  47; m[ 2][ 8] = 458; m[ 2][ 9] =  19;
	m[ 2][10] =   0; m[ 2][11] = 408; m[ 2][12] =  21; m[ 2][13] =   6; m[ 2][14] =  33;
	m[ 2][15] = 446; m[ 2][16] = 110; m[ 2][17] =   6; m[ 2][18] = 156; m[ 2][19] =   0;
	m[ 3][ 0] =  11; m[ 3][ 1] =   0; m[ 3][ 2] = 864; m[ 3][ 3] =   0; m[ 3][ 4] =   0;
	m[ 3][ 5] =  49; m[ 3][ 6] = 569; m[ 3][ 7] =  79; m[ 3][ 8] =  11; m[ 3][ 9] =   0;
	m[ 3][10] =   0; m[ 3][11] =   0; m[ 3][12] =   0; m[ 3][13] =   5; m[ 3][14] =   2;
	m[ 3][15] =  16; m[ 3][16] =   0; m[ 3][17] =   0; m[ 3][18] =   0; m[ 3][19] =  10;
	m[ 4][ 0] =   0; m[ 4][ 1] = 186; m[ 4][ 2] =   0; m[ 4][ 3] =   0; m[ 4][ 4] =   0;
	m[ 4][ 5] =   0; m[ 4][ 6] =   0; m[ 4][ 7] =   0; m[ 4][ 8] = 305; m[ 4][ 9] =  41;
	m[ 4][10] =  27; m[ 4][11] =   0; m[ 4][12] =   0; m[ 4][13] =   7; m[ 4][14] =   0;
	m[ 4][15] = 347; m[ 4][16] = 114; m[ 4][17] =  65; m[ 4][18] = 530; m[ 4][19] =   0;
	m[ 5][ 0] =   0; m[ 5][ 1] = 246; m[ 5][ 2] =   8; m[ 5][ 3] =  49; m[ 5][ 4] =   0;
	m[ 5][ 5] =   0; m[ 5][ 6] = 274; m[ 5][ 7] =   0; m[ 5][ 8] = 550; m[ 5][ 9] =   0;
	m[ 5][10] =  20; m[ 5][11] = 242; m[ 5][12] =  22; m[ 5][13] =   0; m[ 5][14] =  51;
	m[ 5][15] =  30; m[ 5][16] =   0; m[ 5][17] =   0; m[ 5][18] =  54; m[ 5][19] =  33;
	m[ 6][ 0] =   0; m[ 6][ 1] =   0; m[ 6][ 2] =   0; m[ 6][ 3] = 569; m[ 6][ 4] =   0;
	m[ 6][ 5] = 274; m[ 6][ 6] =   0; m[ 6][ 7] =  22; m[ 6][ 8] =  22; m[ 6][ 9] =   0;
	m[ 6][10] =   0; m[ 6][11] = 215; m[ 6][12] =   0; m[ 6][13] =   0; m[ 6][14] =   0;
	m[ 6][15] =  21; m[ 6][16] =   4; m[ 6][17] =   0; m[ 6][18] =   0; m[ 6][19] =  20;
	m[ 7][ 0] =  78; m[ 7][ 1] =  18; m[ 7][ 2] =  47; m[ 7][ 3] =  79; m[ 7][ 4] =   0;
	m[ 7][ 5] =   0; m[ 7][ 6] =  22; m[ 7][ 7] =   0; m[ 7][ 8] =   0; m[ 7][ 9] =   0;
	m[ 7][10] =   0; m[ 7][11] =   0; m[ 7][12] =   0; m[ 7][13] =   0; m[ 7][14] =   0;
	m[ 7][15] = 112; m[ 7][16] =   0; m[ 7][17] =   0; m[ 7][18] =   1; m[ 7][19] =   5;
	m[ 8][ 0] =   8; m[ 8][ 1] = 232; m[ 8][ 2] = 458; m[ 8][ 3] =  11; m[ 8][ 4] = 305;
	m[ 8][ 5] = 550; m[ 8][ 6] =  22; m[ 8][ 7] =   0; m[ 8][ 8] =   0; m[ 8][ 9] =   0;
	m[ 8][10] =  26; m[ 8][11] =   0; m[ 8][12] =   0; m[ 8][13] =   0; m[ 8][14] =  53;
	m[ 8][15] =  20; m[ 8][16] =   1; m[ 8][17] =   0; m[ 8][18] =1525; m[ 8][19] =   0;
	m[ 9][ 0] =  75; m[ 9][ 1] =   0; m[ 9][ 2] =  19; m[ 9][ 3] =   0; m[ 9][ 4] =  41;
	m[ 9][ 5] =   0; m[ 9][ 6] =   0; m[ 9][ 7] =   0; m[ 9][ 8] =   0; m[ 9][ 9] =   0;
	m[ 9][10] = 232; m[ 9][11] =   6; m[ 9][12] = 378; m[ 9][13] =  57; m[ 9][14] =   5;
	m[ 9][15] =   0; m[ 9][16] = 360; m[ 9][17] =   0; m[ 9][18] =  16; m[ 9][19] =2220;
	m[10][ 0] =  21; m[10][ 1] =   6; m[10][ 2] =   0; m[10][ 3] =   0; m[10][ 4] =  27;
	m[10][ 5] =  20; m[10][ 6] =   0; m[10][ 7] =   0; m[10][ 8] =  26; m[10][ 9] = 232;
	m[10][10] =   0; m[10][11] =   4; m[10][12] = 609; m[10][13] = 246; m[10][14] =  43;
	m[10][15] =  74; m[10][16] =  34; m[10][17] =  12; m[10][18] =  25; m[10][19] = 100;
	m[11][ 0] =   0; m[11][ 1] =  50; m[11][ 2] = 408; m[11][ 3] =   0; m[11][ 4] =   0;
	m[11][ 5] = 242; m[11][ 6] = 215; m[11][ 7] =   0; m[11][ 8] =   0; m[11][ 9] =   6;
	m[11][10] =   4; m[11][11] =   0; m[11][12] =  59; m[11][13] =   0; m[11][14] =  18;
	m[11][15] =  65; m[11][16] =  50; m[11][17] =   0; m[11][18] =  67; m[11][19] =   0;
	m[12][ 0] =  76; m[12][ 1] =   0; m[12][ 2] =  21; m[12][ 3] =   0; m[12][ 4] =   0;
	m[12][ 5] =  22; m[12][ 6] =   0; m[12][ 7] =   0; m[12][ 8] =   0; m[12][ 9] = 378;
	m[12][10] = 609; m[12][11] =  59; m[12][12] =   0; m[12][13] =  11; m[12][14] =   0;
	m[12][15] =  47; m[12][16] = 691; m[12][17] =  13; m[12][18] =   0; m[12][19] = 832;
	m[13][ 0] =   0; m[13][ 1] =   0; m[13][ 2] =   6; m[13][ 3] =   5; m[13][ 4] =   7;
	m[13][ 5] =   0; m[13][ 6] =   0; m[13][ 7] =   0; m[13][ 8] =   0; m[13][ 9] =  57;
	m[13][10] = 246; m[13][11] =   0; m[13][12] =  11; m[13][13] =   0; m[13][14] =  17;
	m[13][15] =  90; m[13][16] =   8; m[13][17] =   0; m[13][18] = 682; m[13][19] =   6;
	m[14][ 0] =  53; m[14][ 1] =   9; m[14][ 2] =  33; m[14][ 3] =   2; m[14][ 4] =   0;
	m[14][ 5] =  51; m[14][ 6] =   0; m[14][ 7] =   0; m[14][ 8] =  53; m[14][ 9] =   5;
	m[14][10] =  43; m[14][11] =  18; m[14][12] =   0; m[14][13] =  17; m[14][14] =   0;
	m[14][15] = 202; m[14][16] =  78; m[14][17] =   7; m[14][18] =   8; m[14][19] =   0;
	m[15][ 0] = 342; m[15][ 1] =   3; m[15][ 2] = 446; m[15][ 3] =  16; m[15][ 4] = 347;
	m[15][ 5] =  30; m[15][ 6] =  21; m[15][ 7] = 112; m[15][ 8] =  20; m[15][ 9] =   0;
	m[15][10] =  74; m[15][11] =  65; m[15][12] =  47; m[15][13] =  90; m[15][14] = 202;
	m[15][15] =   0; m[15][16] = 614; m[15][17] =  17; m[15][18] = 107; m[15][19] =   0;
	m[16][ 0] = 681; m[16][ 1] =   0; m[16][ 2] = 110; m[16][ 3] =   0; m[16][ 4] = 114;
	m[16][ 5] =   0; m[16][ 6] =   4; m[16][ 7] =   0; m[16][ 8] =   1; m[16][ 9] = 360;
	m[16][10] =  34; m[16][11] =  50; m[16][12] = 691; m[16][13] =   8; m[16][14] =  78;
	m[16][15] = 614; m[16][16] =   0; m[16][17] =   0; m[16][18] =   0; m[16][19] = 237;
	m[17][ 0] =   5; m[17][ 1] =  16; m[17][ 2] =   6; m[17][ 3] =   0; m[17][ 4] =  65;
	m[17][ 5] =   0; m[17][ 6] =   0; m[17][ 7] =   0; m[17][ 8] =   0; m[17][ 9] =   0;
	m[17][10] =  12; m[17][11] =   0; m[17][12] =  13; m[17][13] =   0; m[17][14] =   7;
	m[17][15] =  17; m[17][16] =   0; m[17][17] =   0; m[17][18] =  14; m[17][19] =   0;
	m[18][ 0] =   0; m[18][ 1] =   0; m[18][ 2] = 156; m[18][ 3] =   0; m[18][ 4] = 530;
	m[18][ 5] =  54; m[18][ 6] =   0; m[18][ 7] =   1; m[18][ 8] =1525; m[18][ 9] =  16;
	m[18][10] =  25; m[18][11] =  67; m[18][12] =   0; m[18][13] = 682; m[18][14] =   8;
	m[18][15] = 107; m[18][16] =   0; m[18][17] =  14; m[18][18] =   0; m[18][19] =   0;
	m[19][ 0] = 398; m[19][ 1] =   0; m[19][ 2] =   0; m[19][ 3] =  10; m[19][ 4] =   0;
	m[19][ 5] =  33; m[19][ 6] =  20; m[19][ 7] =   5; m[19][ 8] =   0; m[19][ 9] =2220;
	m[19][10] = 100; m[19][11] =   0; m[19][12] = 832; m[19][13] =   6; m[19][14] =   0;
	m[19][15] =   0; m[19][16] = 237; m[19][17] =   0; m[19][18] =   0; m[19][19] =   0;
    
	stationary_freqs[ 0] = 0.0692;
	stationary_freqs[ 1] = 0.0184;
	stationary_freqs[ 2] = 0.0400;
	stationary_freqs[ 3] = 0.0186;
	stationary_freqs[ 4] = 0.0065;
	stationary_freqs[ 5] = 0.0238;
	stationary_freqs[ 6] = 0.0236;
	stationary_freqs[ 7] = 0.0557;
	stationary_freqs[ 8] = 0.0277;
	stationary_freqs[ 9] = 0.0905;
	stationary_freqs[10] = 0.1675;
	stationary_freqs[11] = 0.0221;
	stationary_freqs[12] = 0.0561;
	stationary_freqs[13] = 0.0611;
	stationary_freqs[14] = 0.0536;
	stationary_freqs[15] = 0.0725;
	stationary_freqs[16] = 0.0870;
	stationary_freqs[17] = 0.0293;
	stationary_freqs[18] = 0.0340;
	stationary_freqs[19] = 0.0428;

    VectorUtilities::normalize(stationary_freqs);

    // multiply stationary frequencies into exchangeability matrix
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            m[i][j] *= stationary_freqs[j];
        }
    }
    
    // set the diagonal values
    setDiagonal();
    
    // rescale 
    rescaleToAverageRate( 1.0 );
    
    // update the eigensystem
    updateEigenSystem();
    
}


/** Destructor */
RateMatrix_MtMam::~RateMatrix_MtMam(void) {
    
}




RateMatrix_MtMam* RateMatrix_MtMam::clone( void ) const {
    return new RateMatrix_MtMam( *this );
}


