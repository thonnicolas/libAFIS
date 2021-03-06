#include "unity.h"
#include "unity_fixture.h"
#include "Utils/IO/ArrayIO.h"
#include "Utils/IO/BlockMapIO.h"
#include "Utils/IO/ImageIO.h"
#include "Utils/IO/HistogramIO.h"
#include "Utils/IO/SimpleDataTypesIO.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

bool OutputDebug = false ;

TEST_GROUP(DataStructures);

TEST_SETUP(DataStructures)
{
     OutputDebug = false;
}

TEST_TEAR_DOWN(DataStructures)
{
}

TEST(DataStructures, BlockMap_SanityCheck)
{
    BlockMap blockMap = BlockMapIO_ConstructFromFile("DataStructures/101_1.tif.12.Equalize.blocks.dat");
    if (OutputDebug)
    {
        BlockMapIO_Printf(&blockMap);
    }
    BlockMap_Destruct(&blockMap);
}

TEST(DataStructures, Image_SanityCheck)
{
    UInt8Array2D image = ImageIO_ConstructFromFile("DataStructures/101_1.tif.12.Equalize.image.dat");
    if (OutputDebug)
    {
        ImageIO_Printf(&image);
    }
    UInt8Array2D_Destruct(&image);
}

TEST(DataStructures, Histogram_SanityCheck)
{
    Int16Array3D histogram = HistogramIO_ConstructFromFile("DataStructures/101_1.tif.12.Equalize.histgram.dat");
    if (OutputDebug)
    {
        HistogramIO_Printf(&histogram);
    }
    Int16Array3D_Destruct(&histogram);
}

TEST(DataStructures, TwoDFloatArray_SanityCheck)
{
    FloatArray2D array = ArrayIO_FloatArray2D_ConstructFromFile("DataStructures/101_1.tif.12.Equalize.2DFloatArray.dat");
    if (OutputDebug)
    {
        ArrayIO_FloatArray2D_Printf(&array);
    }
    FloatArray2D_Destruct(&array);
}

TEST(DataStructures, TwoDByteArray_SanityCheck)
{
    UInt8Array2D array = ArrayIO_UInt8Array2D_ConstructFromFile("DataStructures/101_1.tif.4.ClippedContrast.result.dat");
    if (OutputDebug)
    {
        ArrayIO_UInt8Array2D_Printf(&array);
    }
    UInt8Array2D_Destruct(&array);
}

TEST(DataStructures, Int_SanityCheck)
{
    int32_t  value = Int32_ConstructFromFile("DataStructures/101_1.tif.5.AbsoluteContrast.Limit.dat");
    assert(value == 17);
}

TEST(DataStructures, Float_SanityCheck)
{
    float value = Float_ConstructFromFile("DataStructures/101_1.tif.15.LinesByOrientation.StepFactor.dat");
    float valueToLookFor = 1.59f;
    assert(fabsf(value - valueToLookFor) < 0.001f); // Take into account the extra decimal places...
}

TEST(DataStructures, Two2PointArray_SanityCheck)
{
    PointArray2D array = ArrayIO_Point2D_ConstructFromFile("DataStructures/101_1.tif.17.LinesByOrientation.result.dat");
    if (OutputDebug)
    {
        ArrayIO_PointArray2D_Printf(&array);
    }
    PointArray2D_Destruct(&array);
}
