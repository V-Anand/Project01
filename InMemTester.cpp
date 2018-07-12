#include <db/QBProfiler.hpp>
#include <db/QBRecordStore.hpp>

#include <string>
#include <assert.h>
#include <iostream>

namespace {

    struct TestFixture
    {
        db::QBRecordStore store;

        TestFixture()
          : store()
        {
        }

        void profileQuery(std::string const& query, int expectedCount)
        {
            db::QBProfiler profiler;

            // Find a record that contains and measure the perf
            profiler.start();
            auto filteredSet = store.QBFindMatchingRecords(query);
            profiler.stop();

            std::cout << "profiler: " << profiler.elapsedInSecs() << std::endl;

            // make sure that the function is correct
            assert(filteredSet.size() == expectedCount);
        }

        /**
            Utility to create a record collection
            prefix - prefix for the string value for every record
            numRecords - number of records to populate in the collection
        */
        void populateDummyData(const std::string& prefix, int numRecords)
        {
            for (int i = 0; i < numRecords; i++)
            {
                db::QBRecord rec = { i, prefix + std::to_string(i) };
                store.QBInsert(rec);
            }
        }
    };
}

int main(int argc, const char* argv[])
{
    // populate a bunch of data
    TestFixture t;
    t.populateDummyData("testdata", 1000);
    t.profileQuery("testdata500", 1);

    return 0;
}

