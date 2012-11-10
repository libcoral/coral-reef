/*
 * Component implementation template for 'stubs.TestComponent'.
 * WARNING: remember to copy this file to your project dir before you begin to change it.
 * Generated by the Coral Compiler v0.7.0 on Thu Mar 01 15:35:26 2012.p
 */

#include "TestComponent_Base.h"
#include <stubs/MotherStruct.h>

#include <co/Log.h>
#include <co/IReflector.h>
#include <co/RefPtr.h>

namespace stubs {

class TestComponent : public TestComponent_Base
{
public:
	TestComponent()
	{
		// empty constructor
	}

	virtual ~TestComponent()
	{
		// empty destructor
	}

	// ------ stubs.IComplexTypes Methods ------ //

	stubs::StringNativeClass getStringNativeClass()
	{
		return _stringNativeClass;
	}

	void setStringNativeClass( const stubs::StringNativeClass& stringNativeClass )
	{
		_stringNativeClass = stringNativeClass;
	}

	stubs::MotherStruct getMotherStruct()
	{
		return _motherStruct;
	}

	void setMotherStruct( const stubs::MotherStruct& motherStruct )
	{
		_motherStruct = motherStruct;
	}
//
//    co::TSlice<co::Any> extractChilds( co::Slice<co::Any> mothers )
//	{
//        _anys.clear();
//        _anys.resize( mothers.getSize() );
//        _motherStructs.clear();
//        _childStructs.clear();
//        
//        for( int i = 0; mothers; mothers.popFirst(), i++ )
//        {
//            _motherStructs.push_back( mothers.getFirst().get<const MotherStruct&>() );
//            _childStructs.push_back( _motherStructs[i].child );
//            _anys[i].set<const ChildStruct&>( _childStructs[i] );
//        }
//        
//        return _anys;
//	}
    
	co::AnyValue getChild( const co::Any& motherStruct )
	{
        _childStruct = motherStruct.get<const MotherStruct&>().child;
        _tempAny.set<const ChildStruct&>( _childStruct );
        return _tempAny;
	}
    
	co::AnyValue setNativeClassValue( const co::Any& stringNativeClass, const std::string& value )
	{
		_stringNativeClass = stringNativeClass.get<const StringNativeClass&>();
        _stringNativeClass.data = value;
        _tempAny.set<const StringNativeClass&>( _stringNativeClass );
        return _tempAny;
	}
    
    void setNativeClassField( const co::Any& stringNativeClass )
	{
		_stringNativeClass = stringNativeClass.get<const StringNativeClass&>();
	}
    
	co::TSlice<stubs::MotherStruct> placeChilds( co::Slice<stubs::MotherStruct> mothers, co::Slice<stubs::ChildStruct> childs )
	{
        assert( mothers.getSize() == childs.getSize() );
        _motherStructs.clear();
        
		for( int i = 0; i < mothers.getSize(); i++ )
        {
            _motherStructs.push_back( mothers[i] );
            _motherStructs[i].child = childs[i];
        }
        
        return _motherStructs;
	}
    
	co::TSlice<stubs::ChildStruct> placeNatives( co::Slice<stubs::ChildStruct> childs, co::Slice<stubs::StringNativeClass> natives )
	{
		assert( natives.getSize() == childs.getSize() );
        _childStructs.clear();
        
		for( int i = 0; i < childs.getSize(); i++ )
        {
            _childStructs.push_back( childs[i] );
            _childStructs[i].myNativeClass = natives[i];
        }
        
        return _childStructs;
	}
    
	// ------ stubs.IReferenceTypes Methods ------ //
    
    void setSimple( stubs::ISimpleTypes* simple )
    {
        _storedSimple = simple;
    }
    
    void setParentSimple( stubs::ISimpleTypes* simple )
    {
        _storedParentSimple = simple;
    }
    
    void getSimple( stubs::ISimpleTypesRef& simple )
	{
        simple.set( _storedSimple.get() );
    }
    
    void getParentSimple( stubs::ISimpleTypesRef& parentSimple )
    {
       parentSimple.set( _storedParentSimple.get() );
    }
    
    co::int32 intFromSimple()
    {
        return _storedSimple->getStoredInt();
    }
    
    co::int32 intFromSimpleFromRef( IReferenceTypes* reference, ISimpleTypes* simple )
    {
		ISimpleTypesRef simpleRef;
		reference->getSimple( simpleRef );
		co::int32 refInt = simpleRef->getStoredInt();
        return refInt + reference->callIncrementInt( simple, 1 );
    }
    
    co::int32 meth1( IReferenceTypes* ref2, IReferenceTypes* ref3, IReferenceTypes* ref4, 
                    IReferenceTypes* ref5, ISimpleTypes* simple )
    {
        return ref2->meth2( ref3, ref4, ref5, simple );
    }
    
    co::int32 meth2( IReferenceTypes* ref3, IReferenceTypes* ref4, 
                    IReferenceTypes* ref5, ISimpleTypes* simple )
    {
        return ref3->meth3( ref4, ref5, simple );
    }
    
    co::int32 meth3( IReferenceTypes* ref4, IReferenceTypes* ref5, ISimpleTypes* simple )
    {
        return ref4->meth4( ref5, simple );
    }
    
    co::int32 meth4( IReferenceTypes* ref5, ISimpleTypes* simple )
    {
        return ref5->meth5( simple );
    }
    
    co::int32 meth5( ISimpleTypes* simple )
    {
        return simple->incrementInt( simple->getStoredInt() );
    }
    
	double callDivideDouble( stubs::ISimpleTypes* service, double dividend, double divisor )
	{
		return service->divide( dividend, divisor );
	}
    
	co::int32 callIncrementInt( stubs::ISimpleTypes* service, co::int32 number )
	{
		return service->incrementInt( number );
	}
    
    co::int32 parentCall( stubs::ISimpleTypes* service, co::int32 number )
	{
		return service->incrementInt( number );
	}
    
	std::string concatenateString( stubs::ISimpleTypes* service, const std::string& str1, const std::string& str2 )
	{
		_storedString = service->concatenateString( str1, str2 );
        return _storedString;
	}

	// ------ stubs.ISimpleTypes Methods ------ //

	double getStoredDouble()
	{
		return _storedDouble;
	}

	void setStoredDouble( double storedDouble )
	{
		_storedDouble = storedDouble;
	}

	co::TSlice<double> getStoredDoubleList()
	{
		return _storedDoubleList;
	}

	void setStoredDoubleList( co::Slice<double> storedDoubleList )
	{
		co::assign( storedDoubleList, _storedDoubleList );
	}

	co::int32 getStoredInt()
	{
		return _storedInt;
	}

	void setStoredInt( co::int32 storedInt )
	{
		_storedInt = storedInt;
	}
    
    co::int32 getParentInt()
	{
		return _storedParentInt;
	}
    
	void setGrandParentInt( co::int32 gParentInt )
	{
		_storedGParentInt = gParentInt;
	}
    
    co::int32 getGrandParentInt()
	{
		return _storedGParentInt;
	}
    
	void setParentInt( co::int32 parentInt )
	{
		_storedParentInt = parentInt;
	}

	co::TSlice<co::int32> getStoredIntList()
	{
		return _storedIntList;
	}

	void setStoredIntList( co::Slice<co::int32> storedIntList )
	{
		co::assign( storedIntList, _storedIntList );
        
	}

	std::string getStoredString()
	{
		return _storedString;
	}

	void setStoredString( const std::string& storedString )
	{
		_storedString = storedString;
	}

	co::TSlice<std::string> getStoredStringList()
	{
		return _storedStringList;
	}

	void setStoredStringList( co::Slice<std::string> storedStringList )
	{
		co::assign( storedStringList, _storedStringList );
	}

    co::TSlice<std::string> getParentStringList()
	{
		return _storedParentStringList;
	}
    
	void setParentStringList( co::Slice<std::string> parentStringList )
	{
		co::assign( parentStringList, _storedParentStringList );
	}
    
	// -------------------- Methods --------------------- //

	std::string concatenateString( const std::string& str1, const std::string& str2 )
	{
		_storedString = str1;
		_storedString.append( str2 );
		return _storedString;
	}

	double divide( double dividend, double divisor )
	{
		return dividend / divisor;
	}

	co::int32 get12345( co::int32& two, co::int32& three, co::int32& four, co::int32& five )
	{
		two = 2; three = 3; four = 4; five = 5;
		return 1;
	}

	co::TSlice<co::int32> get10Ints()
	{
		_storedIntList.clear();

		for( int i = 0; i < 10; i++ )
			_storedIntList.push_back( i );

		return _storedIntList;
	}

	co::TSlice<std::string> getAlphabetList()
	{
		_storedStringList.clear();

		for( int i = 0; i < 24; i++ )
		{
			char letter[2];
			letter[0] = 65 + i;
			letter[1] = '\0';
			_storedStringList.push_back( letter );
		}

		return _storedStringList;
	}

	std::string getHelloString()
	{
		_storedString.assign( "Hello" );
		return _storedString;
	}

	double getNumber4Double()
	{
		return 4.0;
	}

	co::int32 getNumber4Int()
	{
		return 4;
	}

	co::TSlice<std::string> getThirdElements( co::Slice<std::string> list1, co::Slice<std::string> list2 )
	{
		_storedStringList.clear();

		_storedStringList.push_back( list1[2] );
		_storedStringList.push_back( list2[2] );

		return _storedStringList;
	}

	co::int32 incrementInt( co::int32 number )
	{
		number++;
		return number;
	}

	co::TSlice<double> mergeLists( co::Slice<double> list1, co::Slice<double> list2 )
	{
		_storedDoubleList.clear();

		co::assign( list1, _storedDoubleList );

		for( ; list2; list2.popFirst() )
		{
			_storedDoubleList.push_back( list2.getFirst() );
		}

		return _storedDoubleList;
	}

    co::AnyValue addDoublesFromAny( const co::Any& d1, const co::Any& d2 )
	{
        co::AnyValue av( d1.get<double>() + d2.get<double>() );
        return av;
	}
    
	co::AnyValue concatenateFromAny( const co::Any& str1, const co::Any& str2 )
	{
        std::string temp;
        temp = str1.get<const std::string&>();
		temp.append( str2.get<const std::string&>() );
		return co::AnyValue( temp );
	}
    
    co::AnyValue mergeListsFromAny( const co::Any& l1, const co::Any& l2 )
	{
        // NYI
        assert( false );
        static co::Any dummy;
		return dummy;
	}
    
    co::TSlice<double> parentMergeLists( co::Slice<double> list1, co::Slice<double> list2 )
	{
		_storedParentDoubleList.clear();
        
		co::assign( list1, _storedParentDoubleList );
        
		for( ; list2; list2.popFirst() )
		{
			_storedParentDoubleList.push_back( list2.getFirst() );
		}
        
        return _storedParentDoubleList;
	}
    
    double parentMultiply( double number, co::int32 times )
    {
        return number * times;
    }
    
	void setDouble( double number )
	{
		_storedDouble = number;
	}

	void setInt( co::int32 number )
	{
		_storedInt = number;
	}

	void setIntList( co::Slice<co::int32> intList )
	{
		co::assign( intList, _storedIntList );
	}

	void setStrList( co::Slice<std::string> strList )
	{
		co::assign( strList, _storedStringList );
	}

	void setString( const std::string& str )
	{
		_storedString = str;
	}
    
    co::int32 throwException( const std::string& exceptionType, const std::string& exceptionMsg )
    {
        co::getType( exceptionType )->getReflector()->raise( exceptionMsg );
        return 0;
    }

private:
    co::RefPtr<stubs::ISimpleTypes> _storedSimple;
    co::RefPtr<stubs::ISimpleTypes> _storedParentSimple;
    
	// member variables
	stubs::StringNativeClass _stringNativeClass;
	stubs::MotherStruct _motherStruct;
    stubs::ChildStruct _childStruct;
	co::int32 _dummy;
	double _storedDouble;
	std::vector<double> _storedDoubleList;
    std::vector<double> _storedParentDoubleList;
	co::int32 _storedInt;
    co::int32 _storedParentInt;
    co::int32 _storedGParentInt;
	std::vector<co::int32> _storedIntList;
	std::string _storedString;
	std::vector<std::string> _storedStringList;
    std::vector<std::string> _storedParentStringList;
    std::vector<ChildStruct> _childStructs;
    std::vector<MotherStruct> _motherStructs;
    std::vector<StringNativeClass> _natives;
    std::vector<co::Any> _anys;
    co::Any _tempAny;
};

CORAL_EXPORT_COMPONENT( TestComponent, TestComponent );

} // namespace stubs
