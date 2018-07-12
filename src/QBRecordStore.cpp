#include <db/QBRecordStore.hpp>

using namespace db;

QBRecordStore::QBRecordStore()
    : records_()
    , indices_()
{
}

QBRecordStore::~QBRecordStore()
{
}

bool QBRecordStore::QBInsert(QBRecord const& rec)
{
    auto result = records_.emplace( rec.getId(), rec );
    return result.second;
}

QBRecordCollection QBRecordStore::QBFindMatchingRecords(std::string const& matchString) const
{
    QBRecordCollection results;
    auto it = indices_.find(matchString);
    if (it != indices_.end())
    {
        for(auto&& recId : it->second)
        {
            auto valIt = records_.find(recId);
            results.emplace_back(valIt->second);
        }
    }
    else
    {
        std::for_each( records_.begin(), 
                       records_.end(), 
                       [&results, &matchString](RecordsType::value_type const& value)
                       {
                         if (value.second.getValue().find(matchString) != std::string::npos)
                         {
                             results.emplace_back(value.second);
                         }
                       } );

        // update index
        for(auto&& e : results)
        {
            indices_[matchString].emplace(e.getId());
        }
    }
    return results;
}

void QBRecordStore::QBDelete(QBRecord::IdType const& id)
{
    records_.erase( id );
    for (auto&& indx : indices_)
    {
        indx.second.erase( id );
    }
}
