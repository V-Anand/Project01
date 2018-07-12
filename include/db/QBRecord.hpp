#ifndef QBRECORD_HPP_
#define QBRECORD_HPP_

#include <string>

namespace db {

    /**
        Represents a Record Object
    */
    struct QBRecord
    {
        using IdType = int;

        IdType recordId;
        std::string stringValue;
    };

}

#endif // QBRECORD_HPP_
