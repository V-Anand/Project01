#ifndef QBRECORDSTORE_HPP_
#define QBRECORDSTORE_HPP_

#include <db/QBRecordCollection.hpp>

#include <vector>

namespace db {

    /**
     * Represents a Record Store
     */
    class QBRecordStore
    {
            QBRecordCollection records_;

        public:
            QBRecordStore(); 

            ~QBRecordStore(); 

            /**
                Return records that contains a string in the StringValue field
                matchString - the string to search for
            */
            QBRecordCollection QBFindMatchingRecords(std::string const& matchString) const;

            /**
                Insert a record into record collection
                record - record to be inserted
            */
            void QBInsert(QBRecord const& rec);

            /**
                Delete a record from record collection
                id - record id of record to be deleted
            */
            void QBDelete(QBRecord::IdType const& id);

    };

}

#endif // QBRECORDSTORE_HPP_
