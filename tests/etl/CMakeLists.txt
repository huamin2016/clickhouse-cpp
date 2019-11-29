ADD_EXECUTABLE (etl
	etl.cpp
	)

TARGET_LINK_LIBRARIES (etl
	clickhouse-cpp-lib
	)
