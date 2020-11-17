#include <clickhouse/client.h>
#include <clickhouse/error_codes.h>
#include <clickhouse/types/type_parser.h>

#include <iostream>

#if defined(_MSC_VER)
#   pragma warning(disable : 4996)
#endif

using namespace clickhouse;
using namespace std;


inline void loadxdr(Client& client) {
    Block b;

    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.xdr (arr Array(UInt64)) ENGINE = Memory");

    auto arr = std::make_shared<ColumnArray>(std::make_shared<ColumnUInt64>());

    auto id = std::make_shared<ColumnUInt64>();
    id->Append(1);
    arr->AppendAsColumn(id);

    id->Append(3);
    arr->AppendAsColumn(id);

    id->Append(7);
    arr->AppendAsColumn(id);

    id->Append(9);
    arr->AppendAsColumn(id);

    b.AppendColumn("arr", arr);
    client.Insert("test.array", b);


    client.Select("SELECT arr FROM test.xdr", [](const Block& block)
        {
            for (size_t c = 0; c < block.GetRowCount(); ++c) {
                auto col = block[0]->As<ColumnArray>()->GetAsColumn(c);
                for (size_t i = 0; i < col->Size(); ++i) {
                    std::cerr << (int)(*col->As<ColumnUInt64>())[i] << " ";
                }
                std::cerr << std::endl;
            }
        }
    );

    /// Delete table.
    //client.Execute("DROP TABLE test.array");
}


static void RunTests(Client& client) {
    loadxdr(client);

}

int main() {
    try {
        {
            Client client(ClientOptions().SetHost("10.8.14.169").SetPort(9901).SetDefaultDatabase("test").SetUser("greenet").SetPassword("gnckbase")
                            .SetPingBeforeQuery(true).SetCompressionMethod(CompressionMethod::LZ4));
            RunTests(client);
        }

    } catch (const std::exception& e) {
        std::cerr << "exception : " << e.what() << std::endl;
    }

    return 0;
}
