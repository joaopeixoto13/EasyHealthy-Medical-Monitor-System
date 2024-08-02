#ifndef FIFO_H
#define FIFO_H
#include <queue>
#include <string>
#include <mutex>

/**
 * @brief The CFifo class
 */
template <typename T> class CFifo
{
public:
    CFifo();                        /**< Contructor */
    ~CFifo();                       /**< Destrucor */
    void push(T content);           /**< Add a new element to the fifo */
    void pop();                     /**< Remove the first element of the fifo */
    T front();                      /**< Get the first element of the fifo */
    bool isEmpty();                 /**< Check if the fifo is empty */
private:
    std::queue<T> m_fifo;           /**< The fifo */
    std::mutex m_mtx;               /**< Mutex to protect the fifo */
};

/**
 * @brief Construct a new CFifo object
 */
template <typename T> CFifo<T>::CFifo(){}

/**
 * @brief Destroy the CFifo object
 */
template <typename T> CFifo<T>::~CFifo(){}

/**
 * @brief Push a new element to the fifo
 * @param content to push
 */
template <typename T> void CFifo<T>::push(T content)
{
    m_mtx.lock();
    m_fifo.push(content);
    m_mtx.unlock();
}

/**
 * @brief Pop the first element of the fifo
 */
template <typename T> void CFifo<T>::pop()
{
    m_mtx.lock();
    m_fifo.pop();
    m_mtx.unlock();
}

/**
 * @brief Get the first element of the fifo
 * @return T
 */
template <typename T> T CFifo<T>::front()
{
    T front;
    m_mtx.lock();
    front = m_fifo.front();
    m_mtx.unlock();
    return front;
}

/**
 * @brief Check if the fifo is empty
 * @return true if empty
 * @return false if not empty
 */
template <typename T> bool CFifo<T>::isEmpty()
{
    bool empty;
    m_mtx.lock();
    empty = m_fifo.empty();
    m_mtx.unlock();
    return empty;
}

#endif
