#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "dbtypes.h"
#include <memory>
#include <vector>

namespace db
{

class Processor
{
public:
    Processor();
    ~Processor();
    std::pair<dbtypes::DBResult,
                std::vector<dbtypes::DBEntry>>
                requestTableData(dbtypes::DBTables table);

private:
        struct ProcessorPrivate;
        std::unique_ptr<ProcessorPrivate> m_d;
};


}

#endif // PROCESSOR_H
