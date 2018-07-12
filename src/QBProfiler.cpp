#include <db/QBProfiler.hpp>

using namespace db;

QBProfiler::QBProfiler()
    : start_()
    , end_()
{
}

QBProfiler::~QBProfiler()
{
}

void QBProfiler::start()
{
    start_ = std::chrono::steady_clock::now();
}

void QBProfiler::stop()
{
    end_ = std::chrono::steady_clock::now();
}

double QBProfiler::elapsedInSecs() const
{
    return double((end_ - start_).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
}
