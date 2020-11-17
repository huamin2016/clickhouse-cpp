ADD_EXECUTABLE (xdr-test
	main.cpp
)

TARGET_LINK_LIBRARIES (xdr-test
	clickhouse-cpp-lib
)