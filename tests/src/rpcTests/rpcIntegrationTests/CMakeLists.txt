################################################################################
# IntegrationTests - Tests from the rpc user point of view. 
################################################################################

project( RPCINTEGRATIONTESTS )

CORAL_GENERATE_MAPPINGS( _GENERATED_MAPPINGS "stubs.ITestSetup" "stubs.ISimpleTypes" 
"stubs.IComplexTypes" "stubs.IGrandParent" "stubs.IReferenceTypes" "stubs.IRefParent" 
"stubs.ISimpleParent" "stubs.IFakeLink" )

include_directories(
	${GTEST_INCLUDE_DIRS}
	${CMAKE_BINARY_DIR}/src/rpc/generated
	${CMAKE_SOURCE_DIR}/src/rpc
	${CMAKE_CURRENT_BINARY_DIR}/generated
)

# Gather source files in the current directory
file( GLOB _HEADERS *.h )
file( GLOB _SOURCES *.cpp )

add_executable( rpcIntegrationTests EXCLUDE_FROM_ALL ${_HEADERS} ${_SOURCES} ${_GENERATED_MAPPINGS} )
add_dependencies( rpcIntegrationTests stubs rpc )

CORAL_TARGET( rpcIntegrationTests )

set_target_properties( rpcIntegrationTests PROPERTIES
	PROJECT_LABEL "rpcIntegrationTests"
	FOLDER "rpcTests"
)

target_link_libraries( rpcIntegrationTests ${CORAL_LIBRARIES} ${GTEST_LIBRARIES} )

################################################################################
# Register the test
################################################################################
file( MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/rpcIntegrationTests/output )
add_test(
	NAME rpcIntegrationTests
	COMMAND $<TARGET_FILE:rpcIntegrationTests> --gtest_output=xml:../../output/rpcIntegrationCppTests$<CONFIGURATION>.xml
)
CORAL_TEST_ENVIRONMENT( rpcIntegrationTests )


CORAL_ADD_TEST( rpcIntegrationLuaTests testkit.Run ${CMAKE_CURRENT_SOURCE_DIR} --shuffle -o "output/rpcLuaTests$<CONFIGURATION>.xml" )
################################################################################
# If Valgrind is available, repeat the test checking for memory leaks
################################################################################
if( VALGRIND_COMMAND )
	add_test(
		NAME rpcIntegrationTests_MemoryCheck
		COMMAND ${VALGRIND_COMMAND} --leak-check=full --show-reachable=yes --num-callers=30 --dsymutil=yes
			--gen-suppressions=no --log-file=${CMAKE_BINARY_DIR}/rpcIntegrationTestsValgrind$<CONFIGURATION>.log --error-exitcode=13
			--track-origins=yes --suppressions=${CMAKE_SOURCE_DIR}/tests/valgrind.supp $<TARGET_FILE:rpcIntegrationTests>
	)
	CORAL_TEST_ENVIRONMENT( rpcIntegrationTests_MemoryCheck )
endif()


source_group( "@Generated" FILES ${_GENERATED_MAPPINGS} )