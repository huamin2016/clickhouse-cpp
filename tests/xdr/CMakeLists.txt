ADD_EXECUTABLE (xdr-test
	xdr.cpp
)

TARGET_LINK_LIBRARIES (xdr-test
	clickhouse-cpp-lib
)