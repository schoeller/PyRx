#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)
void makePyDbDictionaryWrapper();

//---------------------------------------------------------------------------------------- -
//PyDbDictionary
class PyDbDictionary : public PyDbObject
{
public:
    PyDbDictionary();
    PyDbDictionary(AcDbDictionary* ptr, bool autoDelete);
    PyDbDictionary(const PyDbObjectId& id);
    PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbDictionary() override = default;
    PyDbObjectId            getAt(const std::string& entryName);
    bool                    has1(const std::string& entryName);
    bool                    has2(const PyDbObjectId& id);
    std::string             nameAt(const PyDbObjectId& id);
    Adesk::UInt32           numEntries() const;
    PyDbObjectId            setAt(const std::string& srchKey, PyDbObject& newValue);
    void                    remove1(const std::string& key);
    void                    remove2(const std::string& key, PyDbObjectId& returnId);
    void                    remove3(const PyDbObjectId& objId);
    bool                    setName(const std::string& oldName, const std::string& newName);
    boost::python::dict     toDict();
    static std::string      className();
    static PyRxClass        desc();
    static PyDbDictionary   cloneFrom(const PyRxObject& src);
    static PyDbDictionary   cast(const PyRxObject& src);
public:
    AcDbDictionary* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
