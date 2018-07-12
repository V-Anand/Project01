#include <db/QBRecord.hpp>

using namespace db;

QBRecord::QBRecord(QBRecord::IdType id, std::string const& value)
    : id_(id)
    , value_(value)
{
}

QBRecord::~QBRecord()
{
}

QBRecord::IdType QBRecord::getId() const
{
    return id_;
}

std::string QBRecord::getValue() const
{
    return value_;
}

bool db::operator==(QBRecord const& first, QBRecord const& second)
{
    return first.getId() == second.getId();
}
bool db::operator!=(QBRecord const& first, QBRecord const& second)
{
    return !(first.getId() == second.getId());
}
bool db::operator<(QBRecord const& first, QBRecord const& second)
{
    return (first.getValue() < second.getValue());
}
bool db::operator<=(QBRecord const& first, QBRecord const& second)
{
    return ((first == second) || (first < second));
}
bool db::operator>(QBRecord const& first, QBRecord const& second)
{
    return !(first <= second);
}
bool db::operator>=(QBRecord const& first, QBRecord const& second)
{
    return ((first == second) || (first > second));
}

