#ifndef QBPROFILER_HPP_
#define QBPROFILER_HPP_

#include <string>
#include <chrono>

namespace db {

    /**
        Used to compute elapsed time of an operation
    */
    class QBProfiler
    {
            std::chrono::steady_clock::time_point start_; 
            std::chrono::steady_clock::time_point end_; 

        public:
            QBProfiler();
            ~QBProfiler();
            void start();
            void stop();
            double elapsedInSecs() const;
    };

}

#endif // QBPROFILER_HPP_
