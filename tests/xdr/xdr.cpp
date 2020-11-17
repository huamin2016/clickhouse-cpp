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
    cout << "loadxdr" << endl;
    Block b;

    /// Create a table.
    client.Execute("DROP TABLE IF NOT EXISTS test.xdr");
    client.Execute("CREATE TABLE IF NOT EXISTS test.xdr (c1 String,c2 UInt64) ENGINE = Memory");

    //auto arr = std::make_shared<ColumnArray>(std::make_shared<ColumnUInt64>());
    
	auto c1 = std::make_shared<ColumnString>();

    auto c2 = std::make_shared<ColumnUInt64>();
    
    c1->Append("c1");
    c2->Append(1);

    c1->Append("c2");
    c2->Append(2);


    b.AppendColumn("c1", c1);
    b.AppendColumn("c2", c2);

    client.Insert("test.xdr", b);

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
