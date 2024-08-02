#include "CHeartBeat.h"
#include <iostream>
#include <vector>
#include <math.h>

static const uint16_t FIRCoeffs[12] = {172, 321, 579, 927, 1360, 1858, 2390, 2916, 3391, 3768, 4012, 4096};

/**
 * @brief Multiply two 16-bit numbers and return a 32-bit result
 * @param x First number
 * @param y Second number
 * @return int32_t Result
 */
int32_t mul16(int16_t x, int16_t y)
{
    return ((long)x * (long)y);
}

/**
 * @brief Average DC estimator
 * @param p Array
 * @param x Value
 * @return int16_t Result
 */
int16_t averageDCEstimator(int32_t *p, uint16_t x)
{
    *p += ((((long)x << 15) - *p) >> 4);
    return (*p >> 15);
}

/**
 * @brief Construct a new CHeartBeat object
 *
 */
CHeartBeat::CHeartBeat()
{
    m_irACMax = 20;
    m_irACMin = -20;
    m_irACSignalCurrent = 0;
    m_irACSignalPrevious;
    m_irACSignalmin = 0;
    m_irACSignalmax = 0;
    m_irAverageEstimated;
    m_positiveEdge = 0;
    m_negativeEdge = 0;
    m_irAvgReg;
    m_offset = 0;
}

/**
 * @brief Destroy the CHeartBeat object
 */
CHeartBeat::~CHeartBeat()
{
}

/**
 * @brief Check for beat
 * @param sample Sample
 * @return true Beat detected
 * @return false No beat detected
 */
bool CHeartBeat::checkForBeat(int32_t sample)
{
    bool beatDetected = false;

    /**< Save current state */
    m_irACSignalPrevious = m_irACSignalCurrent;


    /**< Process next data sample */
    m_irAverageEstimated = averageDCEstimator(&m_irAvgReg, sample);
    m_irACSignalCurrent = lowPassFIRFilter(sample - m_irAverageEstimated);

    /**< Detect positive zero crossing (rising edge) */
    if ((m_irACSignalPrevious < 0) & (m_irACSignalCurrent >= 0))
    {

        m_irACMax = m_irACSignalmax; 
        m_irACMin = m_irACSignalmin;

        m_positiveEdge = 1;
        m_negativeEdge = 0;
        m_irACSignalmax = 0;
        if ((m_irACMax - m_irACMin) > 20 & (m_irACMax - m_irACMin) < 1000)
            beatDetected = true;
    }

    /**<  Detect negative zero crossing (falling edge) */
    if ((m_irACSignalPrevious > 0) & (m_irACSignalCurrent <= 0))
    {
        m_positiveEdge = 0;
        m_negativeEdge = 1;
        m_irACSignalmin = 0;
    }

    /**<  Find Maximum value in positive cycle */
    if (m_positiveEdge & (m_irACSignalCurrent > m_irACSignalPrevious))
        m_irACSignalmax = m_irACSignalCurrent;

    /**< Find Minimum value in negative cycle */
    if (m_negativeEdge & (m_irACSignalCurrent < m_irACSignalPrevious))
        m_irACSignalmin = m_irACSignalCurrent;

    return (beatDetected);
}

/**
 * @brief Low pass FIR filter
 * @param cbuf Circular buffer
 * @param offset Offset
 * @param din Input data
 * @return int16_t Result
 */
int16_t CHeartBeat::lowPassFIRFilter(int16_t din)
{
    m_cbuf[m_offset] = din;

    int32_t z = mul16(FIRCoeffs[11], m_cbuf[(m_offset - 11) & 0x1F]);

    for (uint8_t i = 0; i < 11; i++)
    {
        z += mul16(FIRCoeffs[i], m_cbuf[(m_offset - i) & 0x1F] + m_cbuf[(m_offset - 22 + i) & 0x1F]);
    }
    m_offset++;
    m_offset %= 32;
    return (z >> 15);
}
