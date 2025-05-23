#pragma once
#include "PyAcadObjectImpl.h"


#pragma pack (push, 8)
//------------------------------------------------------------------------------------
//PyIAcad helpers
IAcadObject* GetIAcadObjectFromAcDbObjectId(const AcDbObjectId& eid);
IAcadObject* GetIAcadObjectFromAcDbObject(AcDbObject* pSrcObject);
IAcadDatabase* GetIAcadDatabaseFromAcDbDatabse(AcDbDatabase* pSrcObject);

class PyAcadApplicationImpl;
using PyAcadApplicationPtr = std::unique_ptr<PyAcadApplicationImpl>;
class PyIAcadDictionaryImpl;
using PyIAcadDictionaryPtr = std::unique_ptr<PyIAcadDictionaryImpl>;
class PyIAcadDocumentImpl;
using PyIAcadDocumentPtr = std::unique_ptr<PyIAcadDocumentImpl>;
class PyIAcadDatabaseImpl;
using PyIAcadDatabasePtr = std::unique_ptr<PyIAcadDatabaseImpl>;
class PyIAcadSectionTypeSettingsImpl;
using PyIAcadSectionTypeSettingsPtr = std::unique_ptr<PyIAcadSectionTypeSettingsImpl>;
class PyIAcadSectionImpl;
using PyIAcadSectionPtr = std::unique_ptr<PyIAcadSectionImpl>;

//------------------------------------------------------------------------------------
//PyIAcadObjectImpl
class PyIAcadObjectImpl
{
public:
    explicit PyIAcadObjectImpl(IAcadObject* ptr);
    virtual ~PyIAcadObjectImpl() = default;
    CString                 GetHandle() const;
    CString                 GetObjectName() const;
    TypedVariants           GetXData(const CString& appName) const;
    void                    SetXData(const TypedVariants& typedVariants) const;
    void                    Delete() const;
    LONG_PTR                GetObjectId() const;
    LONG_PTR                GetOwnerId() const;
    PyIAcadDatabasePtr      GetDatabase() const;
    bool                    GetHasExtensionDictionary() const;
    PyIAcadDictionaryPtr    GetExtensionDictionary() const;
    PyIAcadDocumentPtr      GetDocument() const;
    void                    Erase() const;
    bool                    IsEqualTo(const PyIAcadObjectImpl& other) const;
    bool                    IsNull() const;
    std::size_t             hash() const;
    AcDbObjectId            id() const;
public:
    IAcadObject* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadObjectPtr m_pimpl;
};
using PyIAcadObjectPtr = std::unique_ptr<PyIAcadObjectImpl>;
using PyIAcadObjectPtrArray = std::vector<std::shared_ptr<PyIAcadObjectImpl>>;

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationImpl
class PyIAcadPlotConfigurationImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadPlotConfigurationImpl(IAcadPlotConfiguration* ptr);
    virtual ~PyIAcadPlotConfigurationImpl() = default;
    CString             GetName() const;
    void                SetName(const CString& val) const;
    CString             GetConfigName() const;
    void                SetConfigName(const CString& val) const;
    CString             GetCanonicalMediaName() const;
    void                SetCanonicalMediaName(const CString& val) const;
    PyAcPlotPaperUnits  GetPaperUnits() const;
    void                SetPaperUnits(PyAcPlotPaperUnits val) const;
    bool                GetPlotViewportBorders() const;
    void                SetPlotViewportBorders(bool val) const;
    bool                GetShowPlotStyles() const;
    void                SetShowPlotStyles(bool val) const;
    PyAcPlotRotation    GetPlotRotation() const;
    void                SetPlotRotation(PyAcPlotRotation val) const;
    bool                GetCenterPlot() const;
    void                SetCenterPlot(bool val) const;
    bool                GetPlotHidden() const;
    void                SetPlotHidden(bool val) const;
    PyAcPlotType        GetPlotType() const;
    void                SetPlotType(PyAcPlotType val) const;
    CString             GetViewToPlot() const;
    void                SetViewToPlot(const CString& val) const;
    bool                GetUseStandardScale() const;
    void                SetUseStandardScale(bool val) const;
    PyAcPlotScale       GetStandardScale() const;
    void                SetStandardScale(PyAcPlotScale val) const;
    void                GetCustomScale(double& numerator, double& denominator) const;
    void                SetCustomScale(double numerator, double denominator) const;
    bool                GetScaleLineweights() const;
    void                SetScaleLineweights(bool val) const;
    bool                GetPlotWithLineweights() const;
    void                SetPlotWithLineweights(bool val) const;
    bool                GetPlotViewportsFirst() const;
    void                SetPlotViewportsFirst(bool val) const;
    CString             GetStyleSheet() const;
    void                SetStyleSheet(const CString& val) const;
    void                GetPaperMargins(AcGePoint2d& lowerLeft, AcGePoint2d& upperRight) const;
    void                GetPaperSize(double& width, double& height) const;
    AcGePoint2d         GetPlotOrigin() const;
    void                SetPlotOrigin(const AcGePoint2d& orgin) const;
    void                GetWindowToPlot(AcGePoint2d& lowerLeft, AcGePoint2d& upperRight) const;
    void                SetWindowToPlot(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight) const;
    bool                GetPlotWithPlotStyles() const;
    void                SetPlotWithPlotStyles(bool val) const;
    bool                GetModelType() const;
    void                CopyFrom(const PyIAcadPlotConfigurationImpl& val) const;
    wstringArray        GetCanonicalMediaNames() const;
    wstringArray        GetPlotDeviceNames() const;
    wstringArray        GetPlotStyleTableNames() const;
    void                RefreshPlotDeviceInfo() const;
    CString             GetLocaleMediaName(const CString& name) const;
public:
    IAcadPlotConfiguration* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPlotConfigurationPtr = std::unique_ptr<PyIAcadPlotConfigurationImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayoutImpl
class PyIAcadLayoutImpl : public PyIAcadPlotConfigurationImpl
{
public:
    explicit PyIAcadLayoutImpl(IAcadLayout* ptr);
    virtual ~PyIAcadLayoutImpl() = default;
    PyIAcadBlockPtr GetBlock() const;
    long            GetTabOrder() const;
    void            SetTabOrder(long val) const;
public:
    IAcadLayout* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayoutPtr = std::unique_ptr<PyIAcadLayoutImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSectionSettingsImpl
class PyIAcadSectionSettingsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSectionSettingsImpl(IAcadSectionSettings* ptr);
    virtual ~PyIAcadSectionSettingsImpl() = default;
    PyAcSectionType                 GetCurrentSectionType() const;
    void                            SetCurrentSectionType(PyAcSectionType val) const;
    PyIAcadSectionTypeSettingsPtr   GetSectionTypeSettings(PyAcSectionType secType) const;
public:
    IAcadSectionSettings* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSectionSettingsPtr = std::unique_ptr<PyIAcadSectionSettingsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewImpl
class PyIAcadViewImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewImpl(IAcadView* ptr);
    virtual ~PyIAcadViewImpl() = default;
    AcGePoint3d             GetCenter() const;
    void                    SetCenter(const AcGePoint3d& val) const;
    double                  GetHeight() const;
    void                    SetHeight(double val) const;
    double                  GetWidth() const;
    void                    SetWidth(double val) const;
    AcGePoint3d             GetTarget() const;
    void                    SetTarget(const AcGePoint3d& val) const;
    AcGeVector3d            GetDirection() const;
    void                    SetDirection(const AcGeVector3d& val) const;
    CString                 GetName() const;
    void                    SetName(const CString& val) const;
    CString                 GetCategoryName() const;
    void                    SetCategoryName(const CString& val) const;
    AcDbObjectId            GetLayoutId() const;
    void                    SetLayoutId(const AcDbObjectId& val) const;
    CString                 GetLayerState() const;
    void                    SetLayerState(const CString& val) const;
    bool                    GetHasVpAssociation() const;
    void                    SetHasVpAssociation(bool val) const;
public:
    IAcadView* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewPtr = std::unique_ptr<PyIAcadViewImpl>;

//------------------------------------------------------------------------------------
//PyIAcadGroupImpl
class PyIAcadGroupImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadGroupImpl(IAcadGroup* ptr);
    virtual ~PyIAcadGroupImpl() = default;
    PyIAcadEntityPtr        GetItem(long ind) const;
    PyIAcadEntityPtrArray   GetIter() const;
    long                    GetCount() const;
    void                    SetTrueColor(const PyIAcadAcCmColorImpl& val) const;
    void                    SetLayer(const CString& val) const;
    void                    SetLinetype(const CString& val) const;
    void                    SetLinetypeScale(double val) const;
    void                    SetVisible(bool val) const;
    void                    Highlight(bool val) const;
    void                    SetPlotStyleName(const CString& val) const;
    void                    SetLineWeight(PyAcLineWeight val) const;
    CString                 GetName() const;
    void                    SetName(const CString& val) const;
    void                    AppendItems(const PyIAcadEntityImplArray& objects) const;
    void                    RemoveItems(const PyIAcadEntityImplArray& objects) const;
    void                    Update() const;
    void                    SetMaterial(const CString& val) const;
    void                    SetColor(PyAcColor val) const;
public:
    IAcadGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadGroupPtr = std::unique_ptr<PyIAcadGroupImpl>;

//------------------------------------------------------------------------------------
//PyIAcadGroupsImpl
class PyIAcadGroupsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadGroupsImpl(IAcadGroups* ptr);
    virtual ~PyIAcadGroupsImpl() = default;
    PyIAcadGroupPtr         GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadGroupPtr         Add(const CString& name) const;
    PyIAcadGroupPtrArray    GetIter() const;
public:
    IAcadGroups* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadGroupsPtr = std::unique_ptr<PyIAcadGroupsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimStyleImpl
class PyIAcadDimStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDimStyleImpl(IAcadDimStyle* ptr);
    virtual ~PyIAcadDimStyleImpl() = default;
    CString     GetName() const;
    void        SetName(const CString& val) const;
    void        CopyFrom(const PyIAcadObjectImpl& val) const;
public:
    IAcadDimStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimStylePtr = std::unique_ptr<PyIAcadDimStyleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimStylesImpl
class PyIAcadDimStylesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDimStylesImpl(IAcadDimStyles* ptr);
    virtual ~PyIAcadDimStylesImpl() = default;
    PyIAcadDimStylePtr      GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadDimStylePtr      Add(const CString& name) const;
    PyIAcadDimStylePtrArray GetIter() const;
public:
    IAcadDimStyles* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimStylesPtr = std::unique_ptr<PyIAcadDimStylesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayerImpl
class PyIAcadLayerImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayerImpl(IAcadLayer* ptr);
    virtual ~PyIAcadLayerImpl() = default;
    PyAcColor           GetColor() const;
    void                SetColor(PyAcColor val) const;
    PyIAcadAcCmColorPtr GetTrueColor() const;
    void                SetTrueColor(const PyIAcadAcCmColorImpl& val) const;
    bool                GetFreeze() const;
    void                SetFreeze(bool val) const;
    bool                GetLayerOn() const;
    void                SetLayerOn(bool val) const;
    CString             GetLinetype() const;
    void                SetLinetype(const CString& val) const;
    bool                GetLock() const;
    void                SetLock(bool val) const;
    CString             GetName() const;
    void                SetName(const CString& val) const;
    bool                GetPlottable() const;
    void                SetPlottable(bool val) const;
    bool                GetViewportDefault() const;
    void                SetViewportDefault(bool val) const;
    CString             GetPlotStyleName() const;
    void                SetPlotStyleName(const CString& val) const;
    PyAcLineWeight      GetLineweight() const;
    void                SetLineWeight(PyAcLineWeight val) const;
    CString             GetDescription() const;
    void                SetDescription(const CString& val) const;
    bool                GetUsed() const;
    CString             GetMaterial() const;
    void                SetMaterial(const CString& val) const;
public:
    IAcadLayer* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayerPtr = std::unique_ptr<PyIAcadLayerImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayersImpl
class PyIAcadLayersImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayersImpl(IAcadLayers* ptr);
    virtual ~PyIAcadLayersImpl() = default;
    PyIAcadLayerPtr         GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadLayerPtr         Add(const CString& name) const;
    PyIAcadLayerPtrArray    GetIter() const;
public:
    IAcadLayers* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayersPtr = std::unique_ptr<PyIAcadLayersImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLineTypeImpl
class PyIAcadLineTypeImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLineTypeImpl(IAcadLineType* ptr);
    virtual ~PyIAcadLineTypeImpl() = default;
    CString             GetName() const;
    void                SetName(const CString& val) const;
    CString             GetDescription() const;
    void                SetDescription(const CString& val) const;
public:
    IAcadLineType* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLineTypePtr = std::unique_ptr<PyIAcadLineTypeImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLineTypesImpl
class PyIAcadLineTypesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLineTypesImpl(IAcadLineTypes* ptr);
    virtual ~PyIAcadLineTypesImpl() = default;
    PyIAcadLineTypePtr      GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadLineTypePtr      Add(const CString& name) const;
    PyIAcadLineTypePtrArray GetIter() const;
public:
    IAcadLineTypes* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLineTypesPtr = std::unique_ptr<PyIAcadLineTypesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadXRecordImpl
class PyIAcadXRecordImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadXRecordImpl(IAcadXRecord* ptr);
    virtual ~PyIAcadXRecordImpl() = default;

    CString             GetName() const;
    void                SetName(const CString& val) const;
    TypedVariants       GetXRecordData() const;
    void                SetXRecordData(const TypedVariants& typedVariants) const;
    bool                GetTranslateIDs() const;
    void                SetTranslateIDs(bool val) const;

    IAcadXRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadXRecordPtr = std::unique_ptr<PyIAcadXRecordImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDictionaryImpl
class PyIAcadDictionaryImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDictionaryImpl(IAcadDictionary* ptr);
    virtual ~PyIAcadDictionaryImpl() = default;

    CString                 GetName() const;
    void                    SetName(const CString& val) const;
    PyIAcadObjectPtr        AddObject(const CString& keyword, const CString& objectName) const;
    CString                 GetName(const PyIAcadObjectImpl& src) const;
    PyIAcadObjectPtr        GetObject(const CString& objectName) const;
    PyIAcadObjectPtr        Remove(const CString& objectName) const;
    void                    Rename(const CString& oldName, const CString& newName) const;
    void                    Replace(const CString& oldName, const PyIAcadObjectImpl& src) const;
    PyIAcadObjectPtr        GetItem(long idx) const;
    PyIAcadObjectPtrArray   GetIter() const;
    long                    GetCount() const;
    PyIAcadXRecordPtr       AddXRecord(const CString& keyword) const;

    IAcadDictionary* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDictionaryPtr = std::unique_ptr<PyIAcadDictionaryImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDictionariesImpl
class PyIAcadDictionariesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadDictionariesImpl(IAcadDictionaries* ptr);
    virtual ~PyIAcadDictionariesImpl() = default;

    PyIAcadDictionaryPtr        GetItem(long ind) const;
    long                        GetCount() const;
    PyIAcadDictionaryPtr        Add(const CString& name) const;
    PyIAcadDictionaryPtrArray   GetIter() const;

    IAcadDictionaries* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDictionariesPtr = std::unique_ptr<PyIAcadDictionariesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationImpl
class PyIAcadRegisteredApplicationImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadRegisteredApplicationImpl(IAcadRegisteredApplication* ptr);
    virtual ~PyIAcadRegisteredApplicationImpl() = default;
    CString     GetName() const;
    void        SetName(const CString& val) const;
    IAcadRegisteredApplication* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadRegisteredApplicationPtr = std::unique_ptr<PyIAcadRegisteredApplicationImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationsImpl
class PyIAcadRegisteredApplicationsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadRegisteredApplicationsImpl(IAcadRegisteredApplications* ptr);
    virtual ~PyIAcadRegisteredApplicationsImpl() = default;

    PyIAcadRegisteredApplicationPtr      GetItem(long ind) const;
    long                                 GetCount() const;
    PyIAcadRegisteredApplicationPtr      Add(const CString& name) const;
    PyIAcadRegisteredApplicationPtrArray GetIter() const;

    IAcadRegisteredApplications* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadRegisteredApplicationsPtr = std::unique_ptr<PyIAcadRegisteredApplicationsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTextStyleImpl
class PyIAcadTextStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTextStyleImpl(IAcadTextStyle* ptr);
    virtual ~PyIAcadTextStyleImpl() = default;

    CString                 GetBigFontFile() const;
    void                    SetBigFontFile(const CString& val) const;
    CString                 GetFontFile() const;
    void                    SetFontFile(const CString& val) const;
    double                  GetHeight() const;
    void                    SetHeight(double val) const;
    double                  GetLastHeight() const;
    void                    SetLastHeight(double val) const;
    CString                 GetName() const;
    double                  GetObliqueAngle() const;
    void                    SetObliqueAngle(double val) const;
    long                    GetTextGenerationFlag() const;
    void                    SetTextGenerationFlag(long val) const;
    double                  GetWidth() const;
    void                    SetWidth(double val) const;
    boost::python::tuple    GetFont() const;
    void                    SetFont(const CString& typeFace, bool bold, bool italic, long charset, long pitchAndFamily) const;

    IAcadTextStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTextStylePtr = std::unique_ptr<PyIAcadTextStyleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTextStylesImpl
class PyIAcadTextStylesImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTextStylesImpl(IAcadTextStyles* ptr);
    virtual ~PyIAcadTextStylesImpl() = default;

    PyIAcadTextStylePtr         GetItem(long ind) const;
    long                        GetCount() const;
    PyIAcadTextStylePtr         Add(const CString& name) const;
    PyIAcadTextStylePtrArray    GetIter() const;

    IAcadTextStyles* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTextStylesPtr = std::unique_ptr<PyIAcadTextStylesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadUCSImpl
class PyIAcadUCSImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadUCSImpl(IAcadUCS* ptr);
    virtual ~PyIAcadUCSImpl() = default;

    CString         GetName() const;
    void            SetName(const CString& val) const;
    AcGePoint3d     GetOrigin() const;
    void            SetOrigin(const AcGePoint3d& val) const;
    AcGeVector3d    GetXVector() const;
    void            SetXVector(const AcGeVector3d& val) const;
    AcGeVector3d    GetYVector() const;
    void            SetYVector(const AcGeVector3d& val) const;
    AcGeMatrix3d    GetUCSMatrix() const;

    IAcadUCS* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadUCSPtr = std::unique_ptr<PyIAcadUCSImpl>;

//------------------------------------------------------------------------------------
//PyIAcadUCSsImpl
class PyIAcadUCSsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadUCSsImpl(IAcadUCSs* ptr);
    virtual ~PyIAcadUCSsImpl() = default;

    PyIAcadUCSPtr       GetItem(long ind) const;
    long                GetCount() const;
    PyIAcadUCSPtr       Add(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis, const CString& name) const;
    PyIAcadUCSPtrArray  GetIter() const;

    IAcadUCSs* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadUCSsPtr = std::unique_ptr<PyIAcadUCSsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewsImpl
class PyIAcadViewsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewsImpl(IAcadViews* ptr);
    virtual ~PyIAcadViewsImpl() = default;

    PyIAcadViewPtr      GetItem(long ind) const;
    long                GetCount() const;
    PyIAcadViewPtr      Add(const CString& name) const;
    PyIAcadViewPtrArray GetIter() const;

    IAcadViews* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewsPtr = std::unique_ptr<PyIAcadViewsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewportImpl
class PyIAcadViewportImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewportImpl(IAcadViewport* ptr);
    virtual ~PyIAcadViewportImpl() = default;

    AcGePoint3d         GetCenter() const;
    void                SetCenter(const AcGePoint3d& val) const;
    double              GetHeight() const;
    void                SetHeight(double val) const;
    double              GetWidth() const;
    void                SetWidth(double val) const;
    AcGePoint3d         GetTarget() const;
    void                SetTarget(const AcGePoint3d& val) const;
    AcGeVector3d        GetDirection() const;
    void                SetDirection(const AcGeVector3d& val) const;
    CString             GetName() const;
    void                SetName(const CString& val) const;
    bool                GetGridOn() const;
    void                SetGridOn(bool val) const;
    bool                GetOrthoOn() const;
    void                SetOrthoOn(bool val) const;
    AcGePoint3d         GetSnapBasePoint() const;
    void                SetSnapBasePoint(const AcGePoint3d& val) const;
    bool                GetSnapOn() const;
    void                SetSnapOn(bool val) const;
    double              GetSnapRotationAngle() const;
    void                SetSnapRotationAngle(double val) const;
    bool                GetUCSIconOn() const;
    void                SetUCSIconOn(bool val) const;
    bool                GetUCSIconAtOrigin() const;
    void                SetUCSIconAtOrigin(bool val) const;
    AcGePoint2d         GetLowerLeftCorner() const;
    AcGePoint2d         GetUpperRightCorner() const;
    void                Split(PyAcViewportSplitType val) const;
    void                GetGridSpacing(double& XSpacing, double& YSpacing) const;
    void                SetGridSpacing(double XSpacing, double YSpacing) const;
    void                GetSnapSpacing(double& XSpacing, double& YSpacing) const;
    void                SetSnapSpacing(double XSpacing, double YSpacing) const;
    void                SetView(const PyIAcadViewImpl& scr) const;
    long                GetArcSmoothness() const;
    void                SetArcSmoothness(long val) const;

    IAcadViewport* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewportPtr = std::unique_ptr<PyIAcadViewportImpl>;

//------------------------------------------------------------------------------------
//PyIAcadViewportsImpl
class PyIAcadViewportsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadViewportsImpl(IAcadViewports* ptr);
    virtual ~PyIAcadViewportsImpl() = default;

    PyIAcadViewportPtr      GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadViewportPtr      Add(const CString& name) const;
    PyIAcadViewportPtrArray GetIter() const;

    IAcadViewports* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadViewportsPtr = std::unique_ptr<PyIAcadViewportsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationsImpl
class PyIAcadPlotConfigurationsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadPlotConfigurationsImpl(IAcadPlotConfigurations* ptr);
    virtual ~PyIAcadPlotConfigurationsImpl() = default;

    PyIAcadPlotConfigurationPtr         GetItem(long ind) const;
    long                                GetCount() const;
    PyIAcadPlotConfigurationPtr         Add(const CString& name) const;
    PyIAcadPlotConfigurationPtrArray    GetIter() const;

    IAcadPlotConfigurations* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPlotConfigurationsPtr = std::unique_ptr<PyIAcadPlotConfigurationsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSectionManagerImpl
class PyIAcadSectionManagerImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSectionManagerImpl(IAcadSectionManager* ptr);
    virtual ~PyIAcadSectionManagerImpl() = default;

    PyIAcadSectionPtr         GetItem(long ind) const;
    long                      GetCount() const;
    PyIAcadSectionPtr         GetLiveSection() const;
    CString                   GetUniqueSectionName(const CString& val) const;

    IAcadSectionManager* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSectionManagerPtr = std::unique_ptr<PyIAcadSectionManagerImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMaterialImpl
class PyIAcadMaterialImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMaterialImpl(IAcadMaterial* ptr);
    virtual ~PyIAcadMaterialImpl() = default;

    CString         GetDescription() const;
    void            SetDescription(const CString& val) const;
    CString         GetName() const;
    void            SetName(const CString& val) const;

    IAcadMaterial* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMaterialPtr = std::unique_ptr<PyIAcadMaterialImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMaterialsImpl
class PyIAcadMaterialsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMaterialsImpl(IAcadMaterials* ptr);
    virtual ~PyIAcadMaterialsImpl() = default;

    PyIAcadMaterialPtr      GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadMaterialPtr      Add(const CString& name) const;
    PyIAcadMaterialPtrArray GetIter() const;

    IAcadMaterials* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMaterialsPtr = std::unique_ptr<PyIAcadMaterialsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTableStyleImpl
class PyIAcadTableStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadTableStyleImpl(IAcadTableStyle* ptr);
    virtual ~PyIAcadTableStyleImpl() = default;

    CString                     GetName() const;
    void                        SetName(const CString& val) const;
    CString                     GetDescription() const;
    void                        SetDescription(const CString& val) const;
    long                        GetBitFlags() const;
    void                        SetBitFlags(long val) const;
    PyAcTableDirection          GetFlowDirection() const;
    void                        SetFlowDirections(PyAcTableDirection val) const;
    double                      GetHorzCellMargin() const;
    void                        SetHorzCellMargin(double val) const;
    double                      GetVertCellMargin() const;
    void                        SetVertCellMargin(double val) const;
    bool                        GetTitleSuppressed() const;
    void                        SetTitleSuppressed(bool val) const;
    bool                        GetHeaderSuppressed() const;
    void                        SetHeaderSuppressed(bool val) const;
    void                        CreateCellStyle(const CString& cellStyle) const;
    void                        CreateCellStyleFromStyle(const CString& cellStyle, const CString& sourceCellStyle) const;
    void                        RenameCellStyle(const CString& oldName, const CString& newName) const;
    void                        DeleteCellStyle(const CString& cellStyle) const;
    CString                     GetUniqueCellStyleName(const CString& basename) const;
    bool                        GetIsCellStyleInUse(const CString& cellStyle) const;
    long                        GetNumCellStyles() const;
    wstringArray                GetCellStyles() const;
    AcDbObjectId                GetTextStyleId(const CString& cellStyle) const;
    void                        SetTextStyleId(const CString& cellStyle, const AcDbObjectId &oid) const;
    double                      GetTextHeight2(const CString& cellStyle) const;
    void                        SetTextHeight2(const CString& cellStyle, double height) const;
    PyAcCellAlignment           GetAlignment2(const CString& cellStyle) const;
    void                        SetAlignment2(const CString& cellStyle, PyAcCellAlignment val) const;
    PyIAcadAcCmColorPtr         GetColor2(const CString& cellStyle) const;
    void                        SetColor2(const CString& cellStyle, const PyIAcadAcCmColorImpl& val) const;
    PyIAcadAcCmColorPtr         GetBackgroundColor2(const CString& cellStyle) const;
    void                        SetBackgroundColor2(const CString& cellStyle, const PyIAcadAcCmColorImpl& val) const;
    boost::python::tuple        GetDataType2(const CString& cellStyle) const;
    void                        SetDataType2(const CString& cellStyle, PyAcValueDataType nDataType, PyAcValueUnitType nUnitType) const;
    CString                     GetFormat2(const CString& cellStyle) const;
    void                        SetFormat2(const CString& cellStyle, const CString& val) const;
    int                         GetCellClass(const CString& cellStyle) const;
    void                        SetCellClass(const CString& cellStyle, int val) const;
    double                      GetRotation(const CString& cellStyle) const;
    void                        SetRotation(const CString& cellStyle, double val) const;
    bool                        GetIsMergeAllEnabled(const CString& cellStyle) const;
    void                        EnableMergeAll(const CString& cellStyle, bool val) const;
    PyAcLineWeight              GetGridLineWeight2(const CString& cellStyle, PyAcGridLineType gridLineType) const;
    void                        SetGridLineWeight2(const CString& cellStyle, PyAcGridLineType gridLineType, PyAcLineWeight val) const;
    PyIAcadAcCmColorPtr         GetGridColor2(const CString& cellStyle, PyAcGridLineType gridLineType) const;
    void                        SetGridColor2(const CString& cellStyle, PyAcGridLineType gridLineType, const PyIAcadAcCmColorImpl& val) const;
    bool                        GetGridVisibility2(const CString& cellStyle, PyAcGridLineType gridLineType) const;
    void                        SetGridVisibility2(const CString& cellStyle, PyAcGridLineType gridLineType, bool val) const;
    AcDbObjectId                GetTemplateId() const;
    void                        SetTemplateId(const AcDbObjectId& val) const;
    void                        SetTemplateId(const AcDbObjectId& val, PyAcMergeCellStyleOption option) const;

    IAcadTableStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTableStylePtr = std::unique_ptr<PyIAcadTableStyleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMLeaderStyleImpl
class PyIAcadMLeaderStyleImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadMLeaderStyleImpl(IAcadMLeaderStyle* ptr);
    virtual ~PyIAcadMLeaderStyleImpl() = default;

    CString                     GetName() const;
    void                        SetName(const CString& val) const;
    CString                     GetDescription() const;
    void                        SetDescription(const CString& val) const;
    long                        GetBitFlags() const;
    void                        SetBitFlags(long val) const;
    PyAcMLeaderContentType      GetContentType() const;
    void                        SetContentType(PyAcMLeaderContentType val) const;
    PyAcDrawMLeaderOrderType    GetDrawMLeaderOrderType() const;
    void                        SetDrawMLeaderOrderType(PyAcMLeaderContentType val) const;
    PyAcDrawLeaderOrderType     GetDrawLeaderOrderType() const;
    void                        SetDrawLeaderOrderType(PyAcDrawLeaderOrderType val) const;
    int                         GetMaxLeaderSegmentsPoints() const;
    void                        SetMaxLeaderSegmentsPoints(int val) const;
    PyAcSegmentAngleType        GetFirstSegmentAngleConstraint() const;
    void                        SetFirstSegmentAngleConstraint(PyAcSegmentAngleType val) const;
    PyAcSegmentAngleType        GetSecondSegmentAngleConstraint() const;
    void                        SetSecondSegmentAngleConstraint(PyAcSegmentAngleType val) const;
    PyAcMLeaderType             GetLeaderLineType() const;
    void                        SetLeaderLineType(PyAcMLeaderType val) const;
    PyIAcadAcCmColorPtr         GetLeaderLineColor() const;
    void                        SetLeaderLineColor(const PyIAcadAcCmColorImpl& val) const;
    CString                     GetLeaderLineTypeId() const;
    void                        SetLeaderLineTypeId(const CString& val) const;
    PyAcLineWeight              GetLeaderLineWeight() const;
    void                        SetLeaderLineWeight(PyAcLineWeight val) const;
    bool                        GetEnableLanding() const;
    void                        SetEnableLanding(bool val) const;
    double                      GetLandingGap() const;
    void                        SetLandingGap(double val) const;
    bool                        GetEnableDogleg() const;
    void                        SetEnableDogleg(bool val) const;
    double                      GetDoglegLength() const;
    void                        SetDoglegLength(double val) const;
    CString                     GetArrowSymbol() const;
    void                        SetArrowSymbol(const CString& val) const;
    double                      GetArrowSize() const;
    void                        SetArrowSize(double val) const;
    CString                     GetTextStyle() const;
    void                        SetTextStyle(const CString& val) const;
    PyAcTextAttachmentDirection GetTextAttachmentDirection() const;
    void                        SetTextAttachmentDirection(PyAcTextAttachmentDirection val) const;
    PyAcTextAttachmentType      GetTextLeftAttachmentType() const;
    void                        SetTextLeftAttachmentType(PyAcTextAttachmentType val) const;
    PyAcTextAttachmentType      GetTextRightAttachmentType() const;
    void                        SetTextRightAttachmentType(PyAcTextAttachmentType val) const;
    PyAcVerticalTextAttachmentType GetTextTopAttachmentType() const;
    void                           SetTextTopAttachmentType(PyAcVerticalTextAttachmentType val) const;
    PyAcVerticalTextAttachmentType GetTextBottomAttachmentType() const;
    void                           SetTextBottomAttachmentType(PyAcVerticalTextAttachmentType val) const;
    PyIAcadAcCmColorPtr         GetTextColor() const;
    void                        SetTextColor(const PyIAcadAcCmColorImpl& val) const;
    double                      GetTextHeight() const;
    void                        SetTextHeight(double val) const;
    bool                        GetEnableFrameText() const;
    void                        SetEnableFrameText(bool val) const;
    double                      GetAlignSpace() const;
    void                        SetAlignSpace(double val) const;
    CString                     GetBlock() const;
    void                        SetBlock(const CString& val) const;
    PyIAcadAcCmColorPtr         GetBlockColor() const;
    void                        SetBlockColor(const PyIAcadAcCmColorImpl& val) const;
    bool                        GetEnableBlockScale() const;
    void                        SetEnableBlockScale(bool val) const;
    double                      GetBlockScale() const;
    void                        SetBlockScale(double val) const;
    bool                        GetEnableBlockRotation() const;
    void                        SetEnableBlockRotation(bool val) const;
    double                      GetBlockRotation() const;
    void                        SetBlockRotation(double val) const;
    PyAcBlockConnectionType     GetBlockConnectionType() const;
    void                        SetBlockConnectionType(PyAcBlockConnectionType val) const;
    double                      GetScaleFactor() const;
    void                        SetScaleFactor(double val) const;
    bool                        GetOverwritePropChanged() const;
    bool                        GetAnnotative() const;
    void                        SetAnnotative(bool val) const;
    double                      GetBreakSize() const;
    void                        SetBreakSize(double val) const;
    CString                     GetTextString() const;
    void                        SetTextString(const CString& val) const;
    PyAcTextAngleType           GetTextAngleType() const;
    void                        SetTextAngleType(PyAcTextAngleType val) const;
    PyAcTextAlignmentType       GetTextAlignmentType() const;
    void                        SetTextAlignmentType(PyAcTextAlignmentType val) const;

    IAcadMLeaderStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMLeaderStylePtr = std::unique_ptr<PyIAcadMLeaderStyleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLayoutsImpl
class PyIAcadLayoutsImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadLayoutsImpl(IAcadLayouts* ptr);
    virtual ~PyIAcadLayoutsImpl() = default;

    PyIAcadLayoutPtr        GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadLayoutPtr        Add(const CString& name) const;
    PyIAcadLayoutPtrArray   GetIter() const;

    IAcadLayouts* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLayoutsPtr = std::unique_ptr<PyIAcadLayoutsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSortentsTableImpl
class PyIAcadSortentsTableImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadSortentsTableImpl(IAcadSortentsTable* ptr);
    virtual ~PyIAcadSortentsTableImpl() = default;

    void                    MoveToBottom(const PyIAcadEntityImplArray& ents) const;
    void                    MoveToTop(const PyIAcadEntityImplArray& ents) const;
    void                    MoveBelow(const PyIAcadEntityImplArray& ents, const PyIAcadEntityImpl& target) const;
    void                    MoveAbove(const PyIAcadEntityImplArray& ents, const PyIAcadEntityImpl& target) const;
    void                    SwapOrder(const PyIAcadEntityImpl& left, const PyIAcadEntityImpl& right) const;
    PyIAcadBlockPtr         Block() const;
    PyIAcadEntityPtrArray   GetFullDrawOrder(bool honorSortentsSysvar) const;
    PyIAcadEntityPtrArray   GetRelativeDrawOrder(bool honorSortentsSysvar) const;
    void                    SetRelativeDrawOrder(const PyIAcadEntityImplArray& ents) const;

    IAcadSortentsTable* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSortentsTablePtr = std::unique_ptr<PyIAcadSortentsTableImpl>;

#pragma pack (pop)
