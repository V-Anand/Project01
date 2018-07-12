#ifndef QBRECORD_HPP_
#define QBRECORD_HPP_

#include <string>
#include <functional>

namespace db {

    /**
        Represents a Record Object
    */
    class QBRecord
    {
        public:
            using IdType = int;

            QBRecord(IdType id, std::string const& value);
            ~QBRecord();

            //copyable
            QBRecord(QBRecord const&) = default;
            QBRecord& operator=(QBRecord const&) = default;

            // movable
            QBRecord(QBRecord&&) = default;
            QBRecord& operator=(QBRecord&&) = default;

            IdType getId() const;
            std::string getValue() const;

        private:
            IdType id_;
            std::string value_;
    };

    bool operator==(QBRecord const& first, QBRecord const& second);
    bool operator!=(QBRecord const& first, QBRecord const& second);
    bool operator<(QBRecord const& first, QBRecord const& second);
    bool operator<=(QBRecord const& first, QBRecord const& second);
    bool operator>(QBRecord const& first, QBRecord const& second);
    bool operator>=(QBRecord const& first, QBRecord const& second);
}

namespace std {

    template <>
    struct hash<db::QBRecord>
    {
        size_t operator()(db::QBRecord const& rec) const
        {
            return std::hash<db::QBRecord::IdType>()( rec.getId() );
        }
    };

}

#endif // QBRECORD_HPP_
