#pragma once

#pragma pack (push, 8)
class PyDbObjectId;

//-----------------------------------------------------------------------------------------
//PyGsManager
void makePyGsManagerWrapper();

class PyGsManager
{
public:
    PyGsManager();
    static std::string	className();
public:
    AcGsManager* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    AcGsManager* m_pyImp = nullptr;
};
#pragma pack (pop)