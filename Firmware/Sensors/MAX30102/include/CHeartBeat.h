#ifndef CHEARTBEAT_H
#define CHEARTBEAT_H
#include <iostream>

/**
 * @brief Class to auxiliate the heartbeat detection 
 */
class CHeartBeat
{
    int16_t m_irACMax;
    int16_t m_irACMin;
    int16_t m_irACSignalCurrent;
    int16_t m_irACSignalPrevious;
    int16_t m_irACSignalmin;
    int16_t m_irACSignalmax;
    int16_t m_irAverageEstimated;
    int16_t m_positiveEdge;
    int16_t m_negativeEdge;
    int32_t m_irAvgReg;
    int16_t m_cbuf[32];
    uint8_t m_offset;
    public:
        CHeartBeat();
        ~CHeartBeat();
        bool checkForBeat(int32_t);
        int16_t lowPassFIRFilter(int16_t);
};

#endif