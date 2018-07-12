#include <db/QBRecordStore.hpp>

using namespace db;

QBRecordStore::QBRecordStore()
    : records_()
{
}

QBRecordStore::~QBRecordStore()
{
}

void QBRecordStore::QBInsert(QBRecord const& rec)
{
    records_.emplace_back( rec );
}

QBRecordCollection QBRecordStore::QBFindMatchingRecords(std::string const& matchString) const
{
    QBRecordCollection result;
    std::copy_if( records_.begin(), 
                  records_.end(), 
                  std::back_inserter(result), 
                  [matchString](QBRecord const& rec)
                  {
                     return rec.stringValue.find(matchString) != std::string::npos; 
                  });
    return result;
}

void QBRecordStore::QBDelete(QBRecord::IdType const& id)
{
}
