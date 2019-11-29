#include <clickhouse/client.h>
#include <clickhouse/error_codes.h>
#include <clickhouse/types/type_parser.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#if defined(_MSC_VER)
#pragma warning(disable : 4996)
#endif

using namespace clickhouse;
using namespace std;

inline void PrintBlock(const Block& block) {
    for (Block::Iterator bi(block); bi.IsValid(); bi.Next()) {
        std::cout << bi.Name() << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < block.GetRowCount(); ++i) {
        std::cout << (*block[0]->As<ColumnUInt64>())[i] << " " << (*block[1]->As<ColumnString>())[i] << "\n";
    }
}

void load(string fileName, Client& client) {
    time_t t1 = time(NULL);
    Block block;
    /*
auto c1 = std::make_shared<ColumnString>();
auto c2 = std::make_shared<ColumnString>();
auto c3 = std::make_shared<ColumnString>();
auto c4 = std::make_shared<ColumnDateTime>();
    */
    auto interface                            = std::make_shared<ColumnString>();
    auto imsi                                 = std::make_shared<ColumnString>();
    auto msisdn                               = std::make_shared<ColumnString>();
    auto imei                                 = std::make_shared<ColumnString>();
    auto apn                                  = std::make_shared<ColumnString>();
    auto destinationip                        = std::make_shared<ColumnString>();
    auto destinationport                      = std::make_shared<ColumnString>();
    auto sourceip                             = std::make_shared<ColumnString>();
    auto sourceport                           = std::make_shared<ColumnString>();
    auto sgwip                                = std::make_shared<ColumnString>();
    auto mmeip                                = std::make_shared<ColumnString>();
    auto pgwip                                = std::make_shared<ColumnString>();
    auto ecgi                                 = std::make_shared<ColumnString>();
    auto tai                                  = std::make_shared<ColumnString>();
    auto visitedplmnid                        = std::make_shared<ColumnString>();
    auto rattype                              = std::make_shared<ColumnString>();
    auto protocolid                           = std::make_shared<ColumnString>();
    auto servicetype                          = std::make_shared<ColumnString>();
    auto destinationtype                      = std::make_shared<ColumnString>();
    auto chargingid                           = std::make_shared<ColumnString>();
    auto start_date                           = std::make_shared<ColumnDateTime>();
    auto endtime                              = std::make_shared<ColumnString>();
    auto duration                             = std::make_shared<ColumnString>();
    auto inputoctets                          = std::make_shared<ColumnUInt32>();
    auto outputoctets                         = std::make_shared<ColumnUInt32>();
    auto inputpacket                          = std::make_shared<ColumnUInt32>();
    auto outputpacket                         = std::make_shared<ColumnUInt32>();
    auto pdnconnectionid                      = std::make_shared<ColumnString>();
    auto bearerid                             = std::make_shared<ColumnString>();
    auto bearerqos                            = std::make_shared<ColumnString>();
    auto recordclosecause                     = std::make_shared<ColumnString>();
    auto enbip                                = std::make_shared<ColumnString>();
    auto sgwport                              = std::make_shared<ColumnString>();
    auto enbport                              = std::make_shared<ColumnString>();
    auto enbgtp_teid                          = std::make_shared<ColumnString>();
    auto sgwgtp_teid                          = std::make_shared<ColumnString>();
    auto pgwport                              = std::make_shared<ColumnString>();
    auto mmeues1apid                          = std::make_shared<ColumnString>();
    auto enbues1apid                          = std::make_shared<ColumnString>();
    auto mmegroupid                           = std::make_shared<ColumnString>();
    auto mmecode                              = std::make_shared<ColumnString>();
    auto enbid                                = std::make_shared<ColumnString>();
    auto home_province                        = std::make_shared<ColumnString>();
    auto userip                               = std::make_shared<ColumnString>();
    auto userport                             = std::make_shared<ColumnString>();
    auto l4protocal                           = std::make_shared<ColumnUInt32>();
    auto appserverip                          = std::make_shared<ColumnString>();
    auto appserverport                        = std::make_shared<ColumnString>();
    auto ultcpreorderingpacket                = std::make_shared<ColumnString>();
    auto dltcpreorderingpacket                = std::make_shared<ColumnString>();
    auto ultcpretranspacket                   = std::make_shared<ColumnString>();
    auto dltcpretranspacket                   = std::make_shared<ColumnString>();
    auto tcpsetupresponsedelay                = std::make_shared<ColumnString>();
    auto tcpsetupackdelay                     = std::make_shared<ColumnString>();
    auto ulipfragpacks                        = std::make_shared<ColumnUInt32>();
    auto dlipfragpacks                        = std::make_shared<ColumnString>();
    auto delay_setup_firsttransaction         = std::make_shared<ColumnString>();
    auto delay_firsttransaction_firstrespackt = std::make_shared<ColumnString>();
    auto windowsize                           = std::make_shared<ColumnString>();
    auto msssize                              = std::make_shared<ColumnString>();
    auto tcpsynnumber                         = std::make_shared<ColumnUInt32>();
    auto tcpconnectstate                      = std::make_shared<ColumnString>();
    auto sessionstopflag                      = std::make_shared<ColumnString>();

    ifstream ifs;
    ifs.open(fileName);

    long size = 209714793;

    string buf = "\0";

    while (getline(ifs, buf)) {
        // cout << buf << endl;
        istringstream iss(buf);

        vector<string> v;
        string token;

        while (getline(iss, token, '|')) {
            v.push_back(token);
        }
        // for(auto i : v)
        //{
        //    cout << i << "-";
        //}
        // cout << endl;

        /*
c1->Append(v[0]);
c2->Append(v[1]);
c3->Append(v[2]);
c4->Append(std::time(nullptr));
        */
        interface->Append(v[0]);
        imsi->Append(v[1]);
        msisdn->Append(v[2]);
        imei->Append(v[3]);
        apn->Append(v[4]);
        destinationip->Append(v[5]);
        destinationport->Append(v[6]);
        sourceip->Append(v[7]);
        sourceport->Append(v[8]);
        sgwip->Append(v[9]);
        mmeip->Append(v[10]);
        pgwip->Append(v[11]);
        ecgi->Append(v[12]);
        tai->Append(v[13]);
        visitedplmnid->Append(v[14]);
        rattype->Append(v[15]);
        protocolid->Append(v[16]);
        servicetype->Append(v[17]);
        destinationtype->Append(v[18]);
        chargingid->Append(v[19]);
        start_date->Append(std::time(nullptr));
        endtime->Append(v[21]);
        duration->Append(v[22]);
        inputoctets->Append(stoi(v[23], 0, 10));
        outputoctets->Append(stoi(v[24], 0, 10));
        inputpacket->Append(stoi(v[25], 0, 10));
        outputpacket->Append(stoi(v[26], 0, 10));
        pdnconnectionid->Append(v[27]);
        bearerid->Append(v[28]);
        bearerqos->Append(v[29]);
        recordclosecause->Append(v[30]);
        enbip->Append(v[31]);
        sgwport->Append(v[32]);
        enbport->Append(v[33]);
        enbgtp_teid->Append(v[34]);
        sgwgtp_teid->Append(v[35]);
        pgwport->Append(v[36]);
        mmeues1apid->Append(v[37]);
        enbues1apid->Append(v[38]);
        mmegroupid->Append(v[39]);
        mmecode->Append(v[40]);
        enbid->Append(v[41]);
        home_province->Append(v[42]);
        userip->Append(v[43]);
        userport->Append(v[44]);
        l4protocal->Append(stoi(v[45], 0, 10));
        appserverip->Append(v[46]);
        appserverport->Append(v[47]);
        ultcpreorderingpacket->Append(v[48]);
        dltcpreorderingpacket->Append(v[49]);
        ultcpretranspacket->Append(v[50]);
        dltcpretranspacket->Append(v[51]);
        tcpsetupresponsedelay->Append(v[52]);
        tcpsetupackdelay->Append(v[53]);
        ulipfragpacks->Append(stoi(v[54], 0, 10));
        dlipfragpacks->Append(v[55]);
        delay_setup_firsttransaction->Append(v[56]);
        delay_firsttransaction_firstrespackt->Append(v[57]);
        windowsize->Append(v[58]);
        msssize->Append(v[59]);
        tcpsynnumber->Append(stoi(v[60], 0, 10));
        tcpconnectstate->Append(v[61]);
        sessionstopflag->Append(v[62]);
    }
    ifs.close();

    // client.Execute("CREATE TABLE IF NOT EXISTS test.test (c1 String,c2 String, c3 String) ENGINE = Memory");

    /*
block.AppendColumn("interface", c1);
block.AppendColumn("imsi", c2);
block.AppendColumn("msisdn", c3);
block.AppendColumn("start_date", c4);
    */

    block.AppendColumn("interface", interface);
    block.AppendColumn("imsi", imsi);
    block.AppendColumn("msisdn", msisdn);
    block.AppendColumn("imei", imei);
    block.AppendColumn("apn", apn);
    block.AppendColumn("destinationip", destinationip);
    block.AppendColumn("destinationport", destinationport);
    block.AppendColumn("sourceip", sourceip);
    block.AppendColumn("sourceport", sourceport);
    block.AppendColumn("sgwip", sgwip);
    block.AppendColumn("mmeip", mmeip);
    block.AppendColumn("pgwip", pgwip);
    block.AppendColumn("ecgi", ecgi);
    block.AppendColumn("tai", tai);
    block.AppendColumn("visitedplmnid", visitedplmnid);
    block.AppendColumn("rattype", rattype);
    block.AppendColumn("protocolid", protocolid);
    block.AppendColumn("servicetype", servicetype);
    block.AppendColumn("destinationtype", destinationtype);
    block.AppendColumn("chargingid", chargingid);
    block.AppendColumn("start_date", start_date);
    block.AppendColumn("endtime", endtime);
    block.AppendColumn("duration", duration);
    block.AppendColumn("inputoctets", inputoctets);
    block.AppendColumn("outputoctets", outputoctets);
    block.AppendColumn("inputpacket", inputpacket);
    block.AppendColumn("outputpacket", outputpacket);
    block.AppendColumn("pdnconnectionid", pdnconnectionid);
    block.AppendColumn("bearerid", bearerid);
    block.AppendColumn("bearerqos", bearerqos);
    block.AppendColumn("recordclosecause", recordclosecause);
    block.AppendColumn("enbip", enbip);
    block.AppendColumn("sgwport", sgwport);
    block.AppendColumn("enbport", enbport);
    block.AppendColumn("enbgtp_teid", enbgtp_teid);
    block.AppendColumn("sgwgtp_teid", sgwgtp_teid);
    block.AppendColumn("pgwport", pgwport);
    block.AppendColumn("mmeues1apid", mmeues1apid);
    block.AppendColumn("enbues1apid", enbues1apid);
    block.AppendColumn("mmegroupid", mmegroupid);
    block.AppendColumn("mmecode", mmecode);
    block.AppendColumn("enbid", enbid);
    block.AppendColumn("home_province", home_province);
    block.AppendColumn("userip", userip);
    block.AppendColumn("userport", userport);
    block.AppendColumn("l4protocal", l4protocal);
    block.AppendColumn("appserverip", appserverip);
    block.AppendColumn("appserverport", appserverport);
    block.AppendColumn("ultcpreorderingpacket", ultcpreorderingpacket);
    block.AppendColumn("dltcpreorderingpacket", dltcpreorderingpacket);
    block.AppendColumn("ultcpretranspacket", ultcpretranspacket);
    block.AppendColumn("dltcpretranspacket", dltcpretranspacket);
    block.AppendColumn("tcpsetupresponsedelay", tcpsetupresponsedelay);
    block.AppendColumn("tcpsetupackdelay", tcpsetupackdelay);
    block.AppendColumn("ulipfragpacks", ulipfragpacks);
    block.AppendColumn("dlipfragpacks", dlipfragpacks);
    block.AppendColumn("delay_setup_firsttransaction", delay_setup_firsttransaction);
    block.AppendColumn("delay_firsttransaction_firstrespackt", delay_firsttransaction_firstrespackt);
    block.AppendColumn("windowsize", windowsize);
    block.AppendColumn("msssize", msssize);
    block.AppendColumn("tcpsynnumber", tcpsynnumber);
    block.AppendColumn("tcpconnectstate", tcpconnectstate);
    block.AppendColumn("sessionstopflag", sessionstopflag);

    client.Insert("test.ods_s1u", block);

    /*
client.Select("select count(1) n from test.ods_s1u", [](const Block& block) {
    for (size_t i = 0; i < block.GetRowCount(); ++i) {
        std::cout << block[0]->As<ColumnUInt32>()->At(i) << endl;
    }
});
    */

    /*
    client.Select("SELECT c1,c2,c3 FROM test.test", [] (const Block & block)
    {
        for (size_t i = 0; i < block.GetRowCount(); ++i)
        {
            std::cout << block[0]->As<ColumnString>()->At(i) << " "
                      << block[1]->As<ColumnString>()->At(i) << " "
                      << block[2]->As<ColumnString>()->At(i) << "\n";
        }
    }
                 );
    */
    time_t t2 = time(NULL);
    long cost = t2 - t1;

    cout << "size(MB):" << size / 1024 / 1024 << ",cost(s):" << cost << ",speed(MB/s):" << size / 1024 / 1024 / cost << endl;
}

inline void insert(Client& client) {
    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.numbers (id UInt64, name String) ENGINE = Memory");

    Block block;

    auto id = std::make_shared<ColumnUInt64>();
    id->Append(1);
    id->Append(2);
    id->Append(7);

    auto name = std::make_shared<ColumnString>();
    name->Append("one");
    name->Append("two");
    name->Append("seven");

    block.AppendColumn("id", id);
    block.AppendColumn("name", name);

    client.Insert("test.numbers", block);

    client.Select("SELECT id, name FROM test.numbers", [](const Block& block) {
        for (size_t i = 0; i < block.GetRowCount(); ++i) {
            std::cout << block[0]->As<ColumnUInt64>()->At(i) << " " << block[1]->As<ColumnString>()->At(i) << "\n";
        }
    });

    client.Execute("DROP TABLE test.numbers");
}

inline void ArrayExample(Client& client) {
    Block b;

    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.array (arr Array(UInt64)) ENGINE = Memory");

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

    id->Append(10);
    arr->AppendAsColumn(id);

    b.AppendColumn("arr", arr);
    client.Insert("test.array", b);

    client.Select("SELECT arr FROM test.array", [](const Block& block) {
        for (size_t c = 0; c < block.GetRowCount(); ++c) {
            auto col = block[0]->As<ColumnArray>()->GetAsColumn(c);
            for (size_t i = 0; i < col->Size(); ++i) {
                std::cerr << (int)(*col->As<ColumnUInt64>())[i] << " ";
            }
            std::cerr << std::endl;
        }
    });

    /// Delete table.
    client.Execute("DROP TABLE test.array");
}

inline void DateExample(Client& client) {
    Block b;

    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.date (d DateTime) ENGINE = Memory");

    auto d = std::make_shared<ColumnDateTime>();
    d->Append(std::time(nullptr));
    d->Append(std::time(nullptr));

    b.AppendColumn("d", d);
    client.Insert("test.date", b);

    client.Select("SELECT d FROM test.date", [](const Block& block) {
        for (size_t c = 0; c < block.GetRowCount(); ++c) {
            auto col      = block[0]->As<ColumnDateTime>();
            std::time_t t = col->As<ColumnDateTime>()->At(c);
            std::cerr << std::asctime(std::localtime(&t)) << " " << std::endl;
        }
    });

    /// Delete table.
    client.Execute("DROP TABLE test.date");
}

inline void GenericExample(Client& client) {
    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.client (id UInt64, name String) ENGINE = Memory");

    /// Insert some values.
    {
        Block block;

        auto id = std::make_shared<ColumnUInt64>();
        id->Append(1);
        id->Append(7);

        auto name = std::make_shared<ColumnString>();
        name->Append("one");
        name->Append("seven");

        block.AppendColumn("id", id);
        block.AppendColumn("name", name);

        client.Insert("test.client", block);
    }

    /// Select values inserted in the previous step.
    client.Select("SELECT id, name FROM test.client", [](const Block& block) { PrintBlock(block); });

    /// Delete table.
    client.Execute("DROP TABLE test.client");
}

inline void NullableExample(Client& client) {
    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.client (id Nullable(UInt64), date Nullable(Date)) ENGINE = Memory");

    /// Insert some values.
    {
        Block block;

        {
            auto id = std::make_shared<ColumnUInt64>();
            id->Append(1);
            id->Append(2);

            auto nulls = std::make_shared<ColumnUInt8>();
            nulls->Append(0);
            nulls->Append(0);

            block.AppendColumn("id", std::make_shared<ColumnNullable>(id, nulls));
        }

        {
            auto date = std::make_shared<ColumnDate>();
            date->Append(std::time(nullptr));
            date->Append(std::time(nullptr));

            auto nulls = std::make_shared<ColumnUInt8>();
            nulls->Append(0);
            nulls->Append(1);

            block.AppendColumn("date", std::make_shared<ColumnNullable>(date, nulls));
        }

        client.Insert("test.client", block);
    }

    /// Select values inserted in the previous step.
    client.Select("SELECT id, date FROM test.client", [](const Block& block) {
        for (size_t c = 0; c < block.GetRowCount(); ++c) {
            auto col_id   = block[0]->As<ColumnNullable>();
            auto col_date = block[1]->As<ColumnNullable>();

            if (col_id->IsNull(c)) {
                std::cerr << "\\N ";
            } else {
                std::cerr << col_id->Nested()->As<ColumnUInt64>()->At(c) << " ";
            }

            if (col_date->IsNull(c)) {
                std::cerr << "\\N\n";
            } else {
                std::time_t t = col_date->Nested()->As<ColumnDate>()->At(c);
                std::cerr << std::asctime(std::localtime(&t)) << "\n";
            }
        }
    });

    /// Delete table.
    client.Execute("DROP TABLE test.client");
}

inline void NumbersExample(Client& client) {
    size_t num = 0;

    client.Select("SELECT number, number FROM system.numbers LIMIT 100000", [&num](const Block& block) {
        if (Block::Iterator(block).IsValid()) {
            auto col = block[0]->As<ColumnUInt64>();

            for (size_t i = 0; i < col->Size(); ++i) {
                if (col->At(i) < num) {
                    throw std::runtime_error("invalid sequence of numbers");
                }

                num = col->At(i);
            }
        }
    });
}

inline void CancelableExample(Client& client) {
    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.client (x UInt64) ENGINE = Memory");

    /// Insert a few blocks.
    for (unsigned j = 0; j < 10; j++) {
        Block b;

        auto x = std::make_shared<ColumnUInt64>();
        for (uint64_t i = 0; i < 1000; i++) {
            x->Append(i);
        }

        b.AppendColumn("x", x);
        client.Insert("test.client", b);
    }

    /// Send a query which is canceled after receiving the first block (note:
    /// due to the low number of rows in this test, this will not actually have
    /// any effect, it just tests for errors)
    client.SelectCancelable("SELECT * FROM test.client", [](const Block&) { return false; });

    /// Delete table.
    client.Execute("DROP TABLE test.client");
}

inline void ExecptionExample(Client& client) {
    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.exceptions (id UInt64, name String) ENGINE = Memory");
    /// Expect failing on table creation.
    try {
        client.Execute("CREATE TABLE test.exceptions (id UInt64, name String) ENGINE = Memory");
    } catch (const ServerException& e) {
        if (e.GetCode() == ErrorCodes::TABLE_ALREADY_EXISTS) {
            // OK
        } else {
            throw;
        }
    }

    /// Delete table.
    client.Execute("DROP TABLE test.exceptions");
}

inline void EnumExample(Client& client) {
    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.enums (id UInt64, e Enum8('One' = 1, 'Two' = 2)) ENGINE = Memory");

    /// Insert some values.
    {
        Block block;

        auto id = std::make_shared<ColumnUInt64>();
        id->Append(1);
        id->Append(2);

        auto e = std::make_shared<ColumnEnum8>(Type::CreateEnum8({{"One", 1}, {"Two", 2}}));
        e->Append(1);
        e->Append("Two");

        block.AppendColumn("id", id);
        block.AppendColumn("e", e);

        client.Insert("test.enums", block);
    }

    /// Select values inserted in the previous step.
    client.Select("SELECT id, e FROM test.enums", [](const Block& block) {
        for (Block::Iterator bi(block); bi.IsValid(); bi.Next()) {
            std::cout << bi.Name() << " ";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < block.GetRowCount(); ++i) {
            std::cout << (*block[0]->As<ColumnUInt64>())[i] << " " << (*block[1]->As<ColumnEnum8>()).NameAt(i) << "\n";
        }
    });

    /// Delete table.
    client.Execute("DROP TABLE test.enums");
}

inline void ShowTables(Client& client) {
    /// Select values inserted in the previous step.
    client.Select("SHOW TABLES", [](const Block& block) {
        for (size_t i = 0; i < block.GetRowCount(); ++i) {
            std::cout << (*block[0]->As<ColumnString>())[i] << "\n";
        }
    });
}

inline void IPExample(Client& client) {
    /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS test.ips (id UInt64, v4 IPv4, v6 IPv6) ENGINE = Memory");

    /// Insert some values.
    {
        Block block;

        auto id = std::make_shared<ColumnUInt64>();
        id->Append(1);
        id->Append(2);

        auto v4 = std::make_shared<ColumnUInt32>();
        v4->Append(2130706433);
        v4->Append(3585395774);

        auto v6 = std::make_shared<ColumnFixedString>(16);
        v6->Append("::1");
        v6->Append("aa::ff");

        block.AppendColumn("id", id);
        block.AppendColumn("v4", v4);
        block.AppendColumn("v6", v6);

        client.Insert("test.ips", block);
    }

    /// Select values inserted in the previous step.
    client.Select("SELECT id, v4, v6 FROM test.ips", [](const Block& block) {
        for (Block::Iterator bi(block); bi.IsValid(); bi.Next()) {
            std::cout << bi.Name() << " ";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < block.GetRowCount(); ++i) {
            std::cout << (*block[0]->As<ColumnUInt64>())[i] << " " << (*block[1]->As<ColumnUInt32>())[i] << " "
                      << (*block[2]->As<ColumnFixedString>())[i] << "\n";
        }
    });

    /// Delete table.
    client.Execute("DROP TABLE test.ips");
}

static void RunTests(Client& client) {
    load("/home/huamin/xdr/com.txt", client);
    //    insert(client);

    //    ArrayExample(client);
    //    CancelableExample(client);
    //    DateExample(client);
    //    EnumExample(client);
    //    ExecptionExample(client);
    //    GenericExample(client);
    //    NullableExample(client);
    //    NumbersExample(client);
    //    IPExample(client);
    //    ShowTables(client);
}

int main() {
    try {
        {
            Client client(ClientOptions().SetHost("localhost").SetPingBeforeQuery(true));
            RunTests(client);
        }

        {
            Client client(ClientOptions().SetHost("localhost").SetPingBeforeQuery(true).SetCompressionMethod(CompressionMethod::LZ4));
            // RunTests(client);
        }
    } catch (const std::exception& e) {
        std::cerr << "exception : " << e.what() << std::endl;
    }

    return 0;
}
