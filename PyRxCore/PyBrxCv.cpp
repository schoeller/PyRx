#include "stdafx.h"

#ifdef BRXAPP
#include "PyBrxCv.h"
#include "PyBrxCvDbAlignments.h"
#include "PyBrxCvDbObjectManager.h"
#include "PyBrxCvDbPoint.h"
#include "PyBrxCvDbTinSurfaceDef.h"
#include "PyBrxCvDbTinSurface.h"

using namespace boost::python;

void makePyBrxCvTinPointWrapper()
{
    PyDocString DS("CvTinPoint");
    class_<BrxCvTinPoint>("CvTinPoint")
        .def(init<>(DS.ARGS()))
        .def("triangleWithPoint", &BrxCvTinPoint::triangleWithPoint, DS.ARGS())
        .def("location", &BrxCvTinPoint::location, DS.ARGS())
        .def("isValid", &BrxCvTinPoint::isValid, DS.ARGS())
        ;
}

void makePyBrxCvTinTriangleWrapper()
{
    PyDocString DS("CvTinTriangle");
    class_<BrxCvTinTriangle>("CvTinTriangle")
        .def(init<>(DS.ARGS()))
        .def("pointAt", &BrxCvTinTriangle::pointAt, DS.ARGS({ "index: int" }))
        .def("locationAt", &BrxCvTinTriangle::locationAt, DS.ARGS({ "index: int" }))
        .def("isVisible", &BrxCvTinTriangle::isVisible, DS.ARGS())
        .def("isValid", &BrxCvTinTriangle::isValid, DS.ARGS())
        .def("neighborAt", &BrxCvTinTriangle::neighborAt, DS.ARGS({ "index: int" }))
        ;
}

BOOST_PYTHON_MODULE(PyBrxCv)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyBrxCvTinPointWrapper();
    makePyBrxCvTinTriangleWrapper();
    makePyBrxCvDbSubObjectWrapper();
    makePyBrxCvDbObjectWrapper();
    makePyBrxCvDbEntityWrapper();
    makePyBrxCvDbCurveWrapper();
    makePyBrxCvCivil3dEntityInfoWrapper();
    makePyBrxCvCivil3dConverterWrapper();
    makePyBrxCvDbViewWrapper();
    makePyBrxCvDbVAlignmentViewWrapper();
    makePyBrxCvStationEquationWrapper();
    makePyBrxCvStationEquationsWrapper();
    makePyBrxCvDbHAlignmentWrapper();
    makePyBrxCvDbHAlignmentElementWrapper();
    makePyBrxCvDbHAlignmentPIWrapper();
    makePyBrxCvDbHAlignmentCurveWrapper();
    makePyBrxCvDbHAlignmentLineWrapper();
    makePyBrxCvDbHAlignmentArcWrapper();
    makePyBrxCvDbHAlignmentSpiralWrapper();
    makePyBrxCvDbHAlignmentSCSWrapper();
    makePyBrxCvDbHAlignmentSTSWrapper();
    makePyBrxCvDbHAlignmentSSCSSWrapper();
    makePyBrxCvDbVAlignmentWrapper();
    makePyBrxCvDbVAlignmentElementWrapper();
    makePyBrxCvDbVAlignmentPVIWrapper();
    makePyBrxCvDbVAlignmentCurveWrapper();
    makePyBrxCvDbVAlignmentTangentWrapper();
    makePyBrxCvDbVAlignmentArcWrapper();
    makePyBrxCvDbVAlignmentParabolaWrapper();
    makePyBrxCvDb3dAlignmentWrapper();
    makePyBrxCvDbObjectManagerWrapper();
    makePyBrxCvDbFileFormatManagerWrapper();
    makePyBrxCvDbStyleManagerWrapper();
    makePyBrxCvDbPointGroupManagerWrapper();
    makePyBrxCvDbPointWrapper();
    makePyBrxCvDbPointReferencedEntityWrapper();
    makePyBrxCvDbPointGroupWrapper();
    makePyBrxCvDbTinSurfaceDefinitionWrapper();
    makePyBrxCvDbTinSurfaceDefinitionGroupDefsWrapper();
    makePyBrxCvDbTinSurfaceDefinitionTransformWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddPointWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddPointsWrapper();
    makePyBrxCvDbTinSurfaceDefinitionDeletePointWrapper();
    makePyBrxCvDbTinSurfaceDefinitionSwapEdgeWrapper();
    makePyBrxCvDbTinSurfaceDefinitionMovePointWrapper();
    makePyBrxCvDbTinSurfaceDefinitionMovePointsWrapper();
    makePyBrxCvDbTinSurfaceDefinitionDeleteEdgeWrapper();
    makePyBrxCvDbTinSurfaceDefinitionDeleteEdgesWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddLineWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddLinesWrapper();
    makePyBrxCvDbTinSurfaceDefinitionModifyPointElevationWrapper();
    makePyBrxCvDbTinSurfaceDefinitionModifyPointsElevationWrapper();
    makePyBrxCvDbTinSurfaceDefinitionModifyPointsElevationsWrapper();
    makePyBrxCvDbTinSurfaceDefinitionCreateFromFacesWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddDrawingObjectsWrapper();
    makePyBrxCvDbTinSurfaceDefinitionRiseLowerWrapper();
    makePyBrxCvDbTinSurfaceDefinitionCreateFromLandXMLWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddFromFilesWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddFromPointCloudsWrapper();
    makePyBrxCvDbTinSurfaceDefinitionAddPointGroupsWrapper();
    makePyBrxCvDbTinSurfaceDefinitionCreateFromC3DWrapper();
    makePyBrxCvDbTinSurfaceDefinitionRemoveOuterEdgesWrapper();
    makePyBrxCvDbTinSurfaceDefinitionTrianglesVisibilityWrapper();
    makePyBrxCvDbTinSurfaceDefinitionRemoveElevationsWrapper();
    makePyBrxCvDbTinSurfaceConstraintWrapper();
    makePyBrxCvDbTinSurfaceBreaklineWrapper();
    makePyBrxCvDbTinSurfaceWallWrapper();
    makePyBrxCvDbTinSurfaceBoundaryWrapper();
    makePyBrxCvDbTinSurfaceWrapper();
    makePyBrxCvDbVolumeSurfaceWrapper();
    makePyBrxCvGradingRuleWrapper();
    makePyBrxCvGradingSlopeSurfaceRuleWrapper();
    makePyBrxCvGradingSlopeOffsetRule();
    makePyBrxCvDbGradingWrapper();


    enum_<PyBrxCvDbStyleManager::EStyleManagerType>("StyleManagerType")
        .value("ePointLabel", PyBrxCvDbStyleManager::EStyleManagerType::ePointLabel)
        .value("eContourLabel", PyBrxCvDbStyleManager::EStyleManagerType::eContourLabel)
        .value("eSurfaceElevationLabel", PyBrxCvDbStyleManager::EStyleManagerType::eSurfaceElevationLabel)
        .value("eSurfaceSlopeLabel", PyBrxCvDbStyleManager::EStyleManagerType::eSurfaceSlopeLabel)
        .value("eSymbolStyle", PyBrxCvDbStyleManager::EStyleManagerType::eSymbolStyle)
        .export_values()
        ;
    enum_<BrxCvCivil3dConverter::Civil3dLabels>("Civil3dLabels")
        .value("eNoLabels", BrxCvCivil3dConverter::Civil3dLabels::eNoLabels)
        .value("eSurfaceLabels", BrxCvCivil3dConverter::Civil3dLabels::eSurfaceLabels)
        .value("eAlignmentsLabels", BrxCvCivil3dConverter::Civil3dLabels::eAlignmentsLabels)
        .value("eUnattachedLabels", BrxCvCivil3dConverter::Civil3dLabels::eUnattachedLabels)
        .value("eDefaultLabels", BrxCvCivil3dConverter::Civil3dLabels::eDefaultLabels)
        .value("eAllLabels", BrxCvCivil3dConverter::Civil3dLabels::eAllLabels)
        .export_values()
        ;
    enum_<BrxCvCivil3dEntityInfo::Civil3dEntityType>("Civil3dEntityType")
        .value("eNoEntity", BrxCvCivil3dEntityInfo::Civil3dEntityType::eNoEntity)
        .value("eAlignment", BrxCvCivil3dEntityInfo::Civil3dEntityType::eAlignment)
        .value("eProfile", BrxCvCivil3dEntityInfo::Civil3dEntityType::eProfile)
        .value("eTinSurface", BrxCvCivil3dEntityInfo::Civil3dEntityType::eTinSurface)
        .value("eProfileView", BrxCvCivil3dEntityInfo::Civil3dEntityType::eProfileView)
        .export_values()
        ;
    enum_<BrxCvCivil3dEntityInfo::Civil3dAlignmentType>("Civil3dAlignmentType")
        .value("eNotAlignment", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eNotAlignment)
        .value("eCenterline", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eCenterline)
        .value("eOffset", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eOffset)
        .value("eCurbReturn", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eCurbReturn)
        .value("eRail", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eRail)
        .value("eMiscellaneous", BrxCvCivil3dEntityInfo::Civil3dAlignmentType::eMiscellaneous)
        .export_values()
        ;
    enum_<BrxCvCivil3dEntityInfo::Civil3dProfileType>("Civil3dProfileType")
        .value("eNotProfile", BrxCvCivil3dEntityInfo::Civil3dProfileType::eNotProfile)
        .value("eLayout", BrxCvCivil3dEntityInfo::Civil3dProfileType::eLayout)
        .value("eStaticSurface", BrxCvCivil3dEntityInfo::Civil3dProfileType::eStaticSurface)
        .value("eDynamicSurface", BrxCvCivil3dEntityInfo::Civil3dProfileType::eDynamicSurface)
        .value("eQuick", BrxCvCivil3dEntityInfo::Civil3dProfileType::eQuick)
        .export_values()
        ;
    enum_<BrxCvStationEquation::EStationEquationType>("StationEquationType")
        .value("Increasing", BrxCvStationEquation::EStationEquationType::Increasing)
        .value("Decreasing", BrxCvStationEquation::EStationEquationType::Decreasing)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::EHAlignmentVisualStyle>("HAlignmentVisualStyle")
        .value("eUndefined", BrxCvDbHAlignment::EHAlignmentVisualStyle::eUndefined)
        .value("eElements", BrxCvDbHAlignment::EHAlignmentVisualStyle::eElements)
        .value("eTangentExtensions", BrxCvDbHAlignment::EHAlignmentVisualStyle::eTangentExtensions)
        .value("eElementExtensions", BrxCvDbHAlignment::EHAlignmentVisualStyle::eElementExtensions)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::EArcType>("ArcType")
        .value("eCompound", BrxCvDbHAlignment::EArcType::eCompound)
        .value("eReverse", BrxCvDbHAlignment::EArcType::eReverse)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::EArcParameterType>("ArcParameterType")
        .value("eRadius", BrxCvDbHAlignment::EArcParameterType::eRadius)
        .value("eDegreeOfCurve", BrxCvDbHAlignment::EArcParameterType::eDegreeOfCurve)
        .value("eTangentLength", BrxCvDbHAlignment::EArcParameterType::eTangentLength)
        .value("eChordLength", BrxCvDbHAlignment::EArcParameterType::eChordLength)
        .value("eCurveLength", BrxCvDbHAlignment::EArcParameterType::eCurveLength)
        .value("eExternalDist", BrxCvDbHAlignment::EArcParameterType::eExternalDist)
        .value("eMiddleOrdinate", BrxCvDbHAlignment::EArcParameterType::eMiddleOrdinate)
        .value("eCurveAngle", BrxCvDbHAlignment::EArcParameterType::eCurveAngle)
        .value("eCurveThroughPoint", BrxCvDbHAlignment::EArcParameterType::eCurveThroughPoint)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::ESpiralDefinitionType>("SpiralDefinitionType")
        .value("eClothoid", BrxCvDbHAlignment::ESpiralDefinitionType::eClothoid)
        .value("eCubicParabola", BrxCvDbHAlignment::ESpiralDefinitionType::eCubicParabola)
        .export_values()
        ;
    enum_<BrxCvDbHAlignmentSpiral::ESpiralDefinitionType>("SpiralDefinitionTypeSpiral")
        .value("eClothoid", BrxCvDbHAlignmentSpiral::ESpiralDefinitionType::eClothoid)
        .value("eCubicParabola", BrxCvDbHAlignmentSpiral::ESpiralDefinitionType::eCubicParabola)
        .export_values()
        ;
    enum_<BrxCvDbHAlignment::ESpiralParameterType>("SpiralParameterType2")
        .value("eParamA", BrxCvDbHAlignment::ESpiralParameterType::eParamA)
        .value("eParamLength", BrxCvDbHAlignment::ESpiralParameterType::eParamLength)
        .export_values()
        ;

    enum_<BrxCvDbHAlignmentSpiral::ESpiralCurveType>("SpiralCurveType")
        .value("eInCurve", BrxCvDbHAlignmentSpiral::ESpiralCurveType::eInCurve)
        .value("eOutCurve", BrxCvDbHAlignmentSpiral::ESpiralCurveType::eOutCurve)
        .export_values()
        ;
    enum_<BrxCvDbHAlignmentSpiral::ESpiralParameterType>("SpiralParameterType")
        .value("eClothoid", BrxCvDbHAlignmentSpiral::ESpiralParameterType::eParamA)
        .value("eCubicParabola", BrxCvDbHAlignmentSpiral::ESpiralParameterType::eParamA)
        .export_values()
        ;

    enum_<BrxCvDbHAlignmentSpiral::ESpiralDirectionType>("SpiralDirectionType")
        .value("eDirectionRight", BrxCvDbHAlignmentSpiral::ESpiralDirectionType::eDirectionRight)
        .value("eDirectionLeft", BrxCvDbHAlignmentSpiral::ESpiralDirectionType::eDirectionLeft)
        .export_values()
        ;
    //
    enum_<BrxCvDbHAlignmentElement::EElementType>("HAlignmentElementType")
        .value("eUndefined", BrxCvDbHAlignmentElement::EElementType::eUndefined)
        .value("eLine", BrxCvDbHAlignmentElement::EElementType::eLine)
        .value("eArc", BrxCvDbHAlignmentElement::EElementType::eArc)
        .value("eSpiral", BrxCvDbHAlignmentElement::EElementType::eSpiral)
        .value("eSpiralCurveSpiral", BrxCvDbHAlignmentElement::EElementType::eSpiralCurveSpiral)
        .value("eSpiralLineSpiral", BrxCvDbHAlignmentElement::EElementType::eSpiralLineSpiral)
        .value("eSpiralLine", BrxCvDbHAlignmentElement::EElementType::eSpiralLine)
        .value("eLineSpiral", BrxCvDbHAlignmentElement::EElementType::eLineSpiral)
        .value("eSpiralCurve", BrxCvDbHAlignmentElement::EElementType::eSpiralCurve)
        .value("eCurveSpiral", BrxCvDbHAlignmentElement::EElementType::eCurveSpiral)
        .value("eSpiralSpiralCurveSpiralSpiral", BrxCvDbHAlignmentElement::EElementType::eSpiralSpiralCurveSpiralSpiral)
        .value("eMultipleSegments", BrxCvDbHAlignmentElement::EElementType::eMultipleSegments)
        .value("eSpiralCurveSpiralCurveSpiral", BrxCvDbHAlignmentElement::EElementType::eSpiralCurveSpiralCurveSpiral)
        .value("eSpiralCurveSpiralSpiralCurveSpiral", BrxCvDbHAlignmentElement::EElementType::eSpiralCurveSpiralSpiralCurveSpiral)
        .value("eSpiralSpiral", BrxCvDbHAlignmentElement::EElementType::eSpiralSpiral)
        .value("eSpiralSpiralCurve", BrxCvDbHAlignmentElement::EElementType::eSpiralSpiralCurve)
        .value("eCurveSpiralSpiral", BrxCvDbHAlignmentElement::EElementType::eCurveSpiralSpiral)
        .value("eCurveLineCurve", BrxCvDbHAlignmentElement::EElementType::eCurveLineCurve)
        .value("eCurveReverseCurve", BrxCvDbHAlignmentElement::EElementType::eCurveReverseCurve)
        .value("eCurveCurveReverseCurve", BrxCvDbHAlignmentElement::EElementType::eCurveCurveReverseCurve)
        .value("ePI", BrxCvDbHAlignmentElement::EElementType::ePI)
        .export_values()
        ;
    enum_<BrxCvDbHAlignmentElement::ETangencyConstraint>("HAlignmentTangencyConstraint")
        .value("eUndefined", BrxCvDbHAlignmentElement::ETangencyConstraint::eUndefined)
        .value("eFixed", BrxCvDbHAlignmentElement::ETangencyConstraint::eFixed)
        .value("ePrevious", BrxCvDbHAlignmentElement::ETangencyConstraint::ePrevious)
        .value("eNext", BrxCvDbHAlignmentElement::ETangencyConstraint::eNext)
        .value("eBoth", BrxCvDbHAlignmentElement::ETangencyConstraint::eBoth)
        .export_values()
        ;
    enum_<BrxCvDbHAlignmentElement::EParameterConstraint>("HAlignmentParameterConstraint")
        .value("eUndefined", BrxCvDbHAlignmentElement::EParameterConstraint::eUndefined)
        .value("eAutomatic", BrxCvDbHAlignmentElement::EParameterConstraint::eAutomatic)
        .value("eLine_TwoPoints", BrxCvDbHAlignmentElement::EParameterConstraint::eLine_TwoPoints)
        .value("eLine_ThroughPoint", BrxCvDbHAlignmentElement::EParameterConstraint::eLine_ThroughPoint)
        .value("eLine_Length", BrxCvDbHAlignmentElement::EParameterConstraint::eLine_Length)
        .value("eLine_BestFit", BrxCvDbHAlignmentElement::EParameterConstraint::eLine_BestFit)
        .value("eArc_ThreePoints", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_ThreePoints)
        .value("eArc_CenterRadius", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_CenterRadius)
        .value("eArc_CenterPassThrough", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_CenterPassThrough)
        .value("eArc_PassThroughRadius", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_PassThroughRadius)
        .value("eArc_PassThroughAttachToEnd", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_PassThroughAttachToEnd)
        .value("eArc_PassThroughDirection", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_PassThroughDirection)
        .value("eArc_Radius", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_Radius)
        .value("eArc_PassThrough", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_PassThrough)
        .value("eArc_RadiusAndLength", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_RadiusAndLength)
        .value("eArc_PointOnTangent", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_PointOnTangent)
        .value("eArc_BestFit", BrxCvDbHAlignmentElement::EParameterConstraint::eArc_BestFit)
        .value("eSCS_SpiralInRadiusSpiralOut", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralInRadiusSpiralOut)
        .value("eSCS_SpiralLengthRadiusPassThrough", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralLengthRadiusPassThrough)
        .value("eSCS_SpiralLengthRadiusArcLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralLengthRadiusArcLength)
        .value("eSCS_SpiralLengthRadius", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralLengthRadius)
        .value("eSCS_SpiralLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralLength)
        .value("eSCS_SpiralInLengthSpiralOutLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralInLengthSpiralOutLength)
        .value("eSCS_SpiralInAValSpiralOutAVal", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralInAValSpiralOutAVal)
        .value("eSCS_SpiralInAValRadiusSpiralOutAVal", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralInAValRadiusSpiralOutAVal)
        .value("eSCS_SpiralAValRadiusPassThrough", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralAValRadiusPassThrough)
        .value("eSCS_SpiralAValRadiusArcLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralAValRadiusArcLength)
        .value("eSCS_SpiralAValRadius", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralAValRadius)
        .value("eSCS_SpiralAVal", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_SpiralAVal)
        .value("eSCS_PointOnTangent", BrxCvDbHAlignmentElement::EParameterConstraint::eSCS_PointOnTangent)
        .value("eSpiral_StartPointDirRadiusLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSpiral_StartPointDirRadiusLength)
        .value("eSpiral_StartPointDirStartAndEndRadiusLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSpiral_StartPointDirStartAndEndRadiusLength)
        .value("eSTS_SpiralInLengthSpiralOutLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSTS_SpiralInLengthSpiralOutLength)
        .value("eSTS_TangentLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSTS_TangentLength)
        .value("eSTS_SpiralInAValSpiralOutAVal", BrxCvDbHAlignmentElement::EParameterConstraint::eSTS_SpiralInAValSpiralOutAVal)
        .value("eSTS_SpiralLengthTangentPassThrough", BrxCvDbHAlignmentElement::EParameterConstraint::eSTS_SpiralLengthTangentPassThrough)
        .value("eSTS_SpiralLengthTangentLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSTS_SpiralLengthTangentLength)
        .value("eSTS_SpiralAValTangentPassThrough ", BrxCvDbHAlignmentElement::EParameterConstraint::eSTS_SpiralAValTangentPassThrough)
        .value("eSTS_SpiralAValTangentLength", BrxCvDbHAlignmentElement::EParameterConstraint::eSTS_SpiralAValTangentLength)
        .value("eSSCSS_Sp1LenSp2LenRadiusPt", BrxCvDbHAlignmentElement::EParameterConstraint::eSSCSS_Sp1LenSp2LenRadiusPt)
        .value("eSSCSS_Sp1LenSp2LenPt1Pt2", BrxCvDbHAlignmentElement::EParameterConstraint::eSSCSS_Sp1LenSp2LenPt1Pt2)
        .value("eSSCSS_Sp1AValSp2AValRadiusPt", BrxCvDbHAlignmentElement::EParameterConstraint::eSSCSS_Sp1AValSp2AValRadiusPt)
        .value("eSSCSS_Sp1AValSp2AValPt1Pt2", BrxCvDbHAlignmentElement::EParameterConstraint::eSSCSS_Sp1AValSp2AValPt1Pt2)
        .export_values()
        ;
    enum_<BrxCvDbVAlignment::EVAlignmentType>("VAlignmentType")
        .value("eLayout", BrxCvDbVAlignment::EVAlignmentType::eLayout)
        .value("eStaticSurface", BrxCvDbVAlignment::EVAlignmentType::eStaticSurface)
        .value("eDynamicSurface", BrxCvDbVAlignment::EVAlignmentType::eDynamicSurface)
        .value("eAutomatic", BrxCvDbVAlignment::EVAlignmentType::eAutomatic)
        .export_values()
        ;
    enum_<BrxCvDbVAlignment::EVAlignmentVisualStyle>("VAlignmentVisualStyle")
        .value("eElements", BrxCvDbVAlignment::EVAlignmentVisualStyle::eElements)
        .value("eTangents", BrxCvDbVAlignment::EVAlignmentVisualStyle::eTangents)
        .value("eExtensions", BrxCvDbVAlignment::EVAlignmentVisualStyle::eExtensions)
        .export_values()
        ;
    enum_<BrxCvDbVAlignmentElement::EElementType>("VAlignmentElementType")
        .value("eUndefined", BrxCvDbVAlignmentElement::EElementType::eUndefined)
        .value("eTangent", BrxCvDbVAlignmentElement::EElementType::eTangent)
        .value("eArc", BrxCvDbVAlignmentElement::EElementType::eArc)
        .value("eParabola", BrxCvDbVAlignmentElement::EElementType::eParabola)
        .value("ePVI", BrxCvDbVAlignmentElement::EElementType::ePVI)
        .export_values()
        ;
    enum_<BrxCvDbVAlignmentElement::ETangencyConstraint>("VAlignmentTangencyConstraint")
        .value("eUndefined", BrxCvDbVAlignmentElement::ETangencyConstraint::eUndefined)
        .value("eFixed", BrxCvDbVAlignmentElement::ETangencyConstraint::eFixed)
        .value("ePrevious", BrxCvDbVAlignmentElement::ETangencyConstraint::ePrevious)
        .value("eNext", BrxCvDbVAlignmentElement::ETangencyConstraint::eNext)
        .value("eBoth", BrxCvDbVAlignmentElement::ETangencyConstraint::eBoth)
        .export_values()
        ;
    enum_<BrxCvDbVAlignmentElement::EParameterConstraint>("VAlignmentParameterConstraint")
        .value("eUndefined", BrxCvDbVAlignmentElement::EParameterConstraint::eUndefined)
        .value("ePassThroughPoints", BrxCvDbVAlignmentElement::EParameterConstraint::ePassThroughPoints)
        .value("eRadius", BrxCvDbVAlignmentElement::EParameterConstraint::eRadius)
        .value("eLength", BrxCvDbVAlignmentElement::EParameterConstraint::eLength)
        .value("eAngle", BrxCvDbVAlignmentElement::EParameterConstraint::eAngle)
        .value("eAutomatic", BrxCvDbVAlignmentElement::EParameterConstraint::eAutomatic)
        .value("ePointOnTangent", BrxCvDbVAlignmentElement::EParameterConstraint::ePointOnTangent)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceDefinition::EType>("TinSurfaceDefinitionType")
        .value("eNone", BrxCvDbTinSurfaceDefinition::EType::eNone)
        .value("eTransform", BrxCvDbTinSurfaceDefinition::EType::eTransform)
        .value("eAddPoint", BrxCvDbTinSurfaceDefinition::EType::eAddPoint)
        .value("eAddPoints", BrxCvDbTinSurfaceDefinition::EType::eAddPoints)
        .value("eDeletePoint", BrxCvDbTinSurfaceDefinition::EType::eDeletePoint)
        .value("eDeletePoints", BrxCvDbTinSurfaceDefinition::EType::eDeletePoints)
        .value("eSwapEdge", BrxCvDbTinSurfaceDefinition::EType::eSwapEdge)
        .value("eMovePoint", BrxCvDbTinSurfaceDefinition::EType::eMovePoint)
        .value("eMovePoints", BrxCvDbTinSurfaceDefinition::EType::eMovePoints)
        .value("eAddBreaklines", BrxCvDbTinSurfaceDefinition::EType::eAddBreaklines)
        .value("eAddBoundaries", BrxCvDbTinSurfaceDefinition::EType::eAddBoundaries)
        .value("eAddWalls", BrxCvDbTinSurfaceDefinition::EType::eAddWalls)
        .value("eVolume", BrxCvDbTinSurfaceDefinition::EType::eVolume)
        .value("eMerge", BrxCvDbTinSurfaceDefinition::EType::eMerge)
        .value("eDeleteEdge", BrxCvDbTinSurfaceDefinition::EType::eDeleteEdge)
        .value("eDeleteEdges", BrxCvDbTinSurfaceDefinition::EType::eDeleteEdges)
        .value("eAddLine", BrxCvDbTinSurfaceDefinition::EType::eAddLine)
        .value("eAddLines", BrxCvDbTinSurfaceDefinition::EType::eAddLines)
        .value("eModifyPointElevation", BrxCvDbTinSurfaceDefinition::EType::eModifyPointElevation)
        .value("eModifyPointsElevation", BrxCvDbTinSurfaceDefinition::EType::eModifyPointsElevation)
        .value("eModifyPointsElevations", BrxCvDbTinSurfaceDefinition::EType::eModifyPointsElevations)
        .value("eCreateFromFaces", BrxCvDbTinSurfaceDefinition::EType::eCreateFromFaces)
        .value("eAddDrawingObjects", BrxCvDbTinSurfaceDefinition::EType::eAddDrawingObjects)
        .value("eCreateSnapshot", BrxCvDbTinSurfaceDefinition::EType::eCreateSnapshot)
        .value("eRiseLower", BrxCvDbTinSurfaceDefinition::EType::eRiseLower)
        .value("eLandXML", BrxCvDbTinSurfaceDefinition::EType::eLandXML)
        .value("eAddPointFiles", BrxCvDbTinSurfaceDefinition::EType::eAddPointFiles)
        .value("eAddPointGroups", BrxCvDbTinSurfaceDefinition::EType::eAddPointGroups)
        .value("eAddPointClouds", BrxCvDbTinSurfaceDefinition::EType::eAddPointClouds)
        .value("eGroupDefinitions", BrxCvDbTinSurfaceDefinition::EType::eGroupDefinitions)
        .value("eDeform", BrxCvDbTinSurfaceDefinition::EType::eDeform)
        .value("eSmoothen", BrxCvDbTinSurfaceDefinition::EType::eSmoothen)
        .value("eCreateMerged", BrxCvDbTinSurfaceDefinition::EType::eCreateMerged)
        .value("eIFC", BrxCvDbTinSurfaceDefinition::EType::eIFC)
        .value("eCreateTypedSnapshot", BrxCvDbTinSurfaceDefinition::EType::eCreateTypedSnapshot)
        .value("eCreateFromCorridor", BrxCvDbTinSurfaceDefinition::EType::eCreateFromCorridor)
        .value("eCreateFromC3D", BrxCvDbTinSurfaceDefinition::EType::eCreateFromC3D)
        .value("eRemoveOuterEdges", BrxCvDbTinSurfaceDefinition::EType::eRemoveOuterEdges)
        .value("eCreateFromContours", BrxCvDbTinSurfaceDefinition::EType::eCreateFromContours)
        .value("eMinimizeFlatAreas", BrxCvDbTinSurfaceDefinition::EType::eMinimizeFlatAreas)
        .value("eTrianglesVisibility", BrxCvDbTinSurfaceDefinition::EType::eTrianglesVisibility)
        .value("eRemoveBelowAboveElevation", BrxCvDbTinSurfaceDefinition::EType::eRemoveBelowAboveElevation)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType>("DrawingObjectType")
        .value("eUnknown", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::eUnknown)
        .value("ePoint", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::ePoint)
        .value("eBlock", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::eBlock)
        .value("eText", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::eText)
        .value("eLine", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::eLine)
        .value("eFace", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::eFace)
        .value("ePolyline", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::ePolyline)
        .value("eCivilPoint", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::EDrawingObjectType::eCivilPoint)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation>("TinIntersectionElevation")
        .value("eTinNotAllowed", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation::eTinNotAllowed)
        .value("eTinElevationMin", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation::eTinElevationMin)
        .value("eTinElevationMax", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation::eTinElevationMax)
        .value("eTinElevationMid", BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation::eTinElevationMid)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceConstraint::ETinConstraintType>("TinConstraintType")
        .value("eTinBreakline", BrxCvDbTinSurfaceConstraint::ETinConstraintType::eTinBreakline)
        .value("eTinBoundary", BrxCvDbTinSurfaceConstraint::ETinConstraintType::eTinBoundary)
        .value("eTinWall", BrxCvDbTinSurfaceConstraint::ETinConstraintType::eTinWall)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceBreakline::ETinBreaklineType>("TinBreaklineType")
        .value("eTinBreaklineNormal", BrxCvDbTinSurfaceBreakline::ETinBreaklineType::eTinBreaklineNormal)
        .value("eTinNonDestructive", BrxCvDbTinSurfaceBreakline::ETinBreaklineType::eTinNonDestructive)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation>("BreaklineIntersectionElevation")
        .value("eTinNotAllowed", BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation::eTinNotAllowed)
        .value("eTinElevationMin", BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation::eTinElevationMin)
        .value("eTinElevationMax", BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation::eTinElevationMax)
        .value("eTinElevationMid", BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation::eTinElevationMid)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceWall::ETinWallType>("TinWallType")
        .value("eTinWallNormal", BrxCvDbTinSurfaceWall::ETinWallType::eTinWallNormal)
        .value("eTinWallProjected", BrxCvDbTinSurfaceWall::ETinWallType::eTinWallProjected)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceWall::ETinWallSide>("TinWallSide")
        .value("eTinWallLeft", BrxCvDbTinSurfaceWall::ETinWallSide::eTinWallLeft)
        .value("eTinWallRight", BrxCvDbTinSurfaceWall::ETinWallSide::eTinWallRight)
        .export_values()
        ;
    enum_<BrxCvDbTinSurfaceBoundary::ETinBoundaryType>("TinBoundaryType")
        .value("eTinShow", BrxCvDbTinSurfaceBoundary::ETinBoundaryType::eTinShow)
        .value("eTinHide", BrxCvDbTinSurfaceBoundary::ETinBoundaryType::eTinHide)
        .value("eTinOuter", BrxCvDbTinSurfaceBoundary::ETinBoundaryType::eTinOuter)
        .export_values()
        ;
    enum_<BrxCvDbTinSurface::ETinSurfaceStyle>("TinSurfaceStyle")
        .value("eTinStyleNone", BrxCvDbTinSurface::ETinSurfaceStyle::eTinStyleNone)
        .value("eTinStyleBoundaryLine", BrxCvDbTinSurface::ETinSurfaceStyle::eTinStyleBoundaryLine)
        .value("eTinStylePoints", BrxCvDbTinSurface::ETinSurfaceStyle::eTinStylePoints)
        .value("eTinStyleTriangles", BrxCvDbTinSurface::ETinSurfaceStyle::eTinStyleTriangles)
        .value("eTinStyleContours", BrxCvDbTinSurface::ETinSurfaceStyle::eTinStyleContours)
        .value("eTinStyleElevationTooltip", BrxCvDbTinSurface::ETinSurfaceStyle::eTinStyleElevationTooltip)
        .export_values()
        ;
    enum_<BrxCvDbTinSurface::ETinSurfaceMeshType>("TinSurfaceMeshType")
        .value("eTinSurfaceMeshSurface", BrxCvDbTinSurface::ETinSurfaceMeshType::eTinSurfaceMeshSurface)
        .value("eTinSurfaceMeshElevation", BrxCvDbTinSurface::ETinSurfaceMeshType::eTinSurfaceMeshElevation)
        .value("eTinSurfaceMeshDepth", BrxCvDbTinSurface::ETinSurfaceMeshType::eTinSurfaceMeshDepth)
        .export_values()
        ;
    enum_<BrxCvDbTinSurface::ETinSurfaceIntersectType>("TinSurfaceIntersectType")
        .value("eTinSurfaceFirstOnly", BrxCvDbTinSurface::ETinSurfaceIntersectType::eTinSurfaceFirstOnly)
        .value("eTinSurfaceAll", BrxCvDbTinSurface::ETinSurfaceIntersectType::eTinSurfaceAll)
        .export_values()
        ;
    enum_<BrxCvDbTinSurface::ETinSurfaceSolidType>("TinSurfaceSolidType")
        .value("eSolidTypeSurfaceSurface", BrxCvDbTinSurface::ETinSurfaceSolidType::eSolidTypeSurfaceSurface)
        .value("eSolidTypeSurfaceElevation", BrxCvDbTinSurface::ETinSurfaceSolidType::eSolidTypeSurfaceElevation)
        .value("eSolidTypeSurfaceDepth", BrxCvDbTinSurface::ETinSurfaceSolidType::eSolidTypeSurfaceDepth)
        .export_values()
        ;
    enum_<BrxCvDbVolumeSurface::EVolumeSurfaceType>("VolumeSurfaceType")
        .value("eTinVolumeBaseComparison", BrxCvDbVolumeSurface::EVolumeSurfaceType::eTinVolumeBaseComparison)
        .value("eTinVolumeToElevation", BrxCvDbVolumeSurface::EVolumeSurfaceType::eTinVolumeToElevation)
        .value("eTinVolumeToDepth", BrxCvDbVolumeSurface::EVolumeSurfaceType::eTinVolumeToDepth)
        .export_values()
        ;
    enum_<BrxCvGradingRule::EGradingSide>("GradingSide")
        .value("eGradingSideNone", BrxCvGradingRule::EGradingSide::eGradingSideNone)
        .value("eGradingSideLeft", BrxCvGradingRule::EGradingSide::eGradingSideLeft)
        .value("eGradingSideRight", BrxCvGradingRule::EGradingSide::eGradingSideRight)
        .export_values()
        ;
    enum_<BrxCvGradingRule::EGradingType>("GradingType")
        .value("eGradingTypeNone", BrxCvGradingRule::EGradingType::eGradingTypeNone)
        .value("eGradingTypeSlopeSurface", BrxCvGradingRule::EGradingType::eGradingTypeSlopeSurface)
        .value("eGradingTypeSlopeOffset", BrxCvGradingRule::EGradingType::eGradingTypeSlopeOffset)
        .export_values()
        ;
    enum_<BrxCvGradingRule::EGradingSlopeFormat>("GradingSlopeFormat")
        .value("eSlopeNoFormat", BrxCvGradingRule::EGradingSlopeFormat::eSlopeNoFormat)
        .value("eSlopeRiseRun", BrxCvGradingRule::EGradingSlopeFormat::eSlopeRiseRun)
        .value("eSlopeDegrees", BrxCvGradingRule::EGradingSlopeFormat::eSlopeDegrees)
        .value("eSlopePercent", BrxCvGradingRule::EGradingSlopeFormat::eSlopePercent)
        .value("eSlopeRadians", BrxCvGradingRule::EGradingSlopeFormat::eSlopeRadians)
        .export_values()
        ;
    enum_<BrxCvDbGrading::EGradingStatus>("GradingStatus")
        .value("eGradingNoStatus", BrxCvDbGrading::EGradingStatus::eGradingNoStatus)
        .value("eGradingOk", BrxCvDbGrading::EGradingStatus::eGradingOk)
        .value("eGradingUpdateNeeded", BrxCvDbGrading::EGradingStatus::eGradingUpdateNeeded)
        .value("eGradingIncorrectInputData", BrxCvDbGrading::EGradingStatus::eGradingIncorrectInputData)
        .value("eGradingSurfaceMissing", BrxCvDbGrading::EGradingStatus::eGradingSurfaceMissing)
        .value("eGradingRuleMissing", BrxCvDbGrading::EGradingStatus::eGradingRuleMissing)
        .value("eGradingInputDataOutsideSurface", BrxCvDbGrading::EGradingStatus::eGradingInputDataOutsideSurface)
        .value("eGradingGradingOutsideSurface", BrxCvDbGrading::EGradingStatus::eGradingGradingOutsideSurface)
        .value("eGradingOffsetFailed", BrxCvDbGrading::EGradingStatus::eGradingOffsetFailed)
        .value("eGradingMultipleOffsetResult", BrxCvDbGrading::EGradingStatus::eGradingMultipleOffsetResult)
        .value("eGradingZeroGrading", BrxCvDbGrading::EGradingStatus::eGradingZeroGrading)
        .value("eGradingUnknownError", BrxCvDbGrading::EGradingStatus::eGradingUnknownError)
        .value("eGradingInputDataMissing", BrxCvDbGrading::EGradingStatus::eGradingInputDataMissing)
        .value("eGradingInvalidInput", BrxCvDbGrading::EGradingStatus::eGradingInvalidInput)
        .value("eGradingInvalidRule", BrxCvDbGrading::EGradingStatus::eGradingInvalidRule)
        .value("eGradingTimeout", BrxCvDbGrading::EGradingStatus::eGradingTimeout)
        .export_values()
        ;
    enum_<BrxCvDbGrading::EGradingCalculationMethod>("GradingCalculationMethod")
        .value("eGradingAccurate", BrxCvDbGrading::EGradingCalculationMethod::eGradingAccurate)
        .value("eGradingFast", BrxCvDbGrading::EGradingCalculationMethod::eGradingFast)
        .export_values()
        ;
    enum_<BrxCvDbGrading::EGradingVisualStyle>("GradingVisualStyle")
        .value("eGradingDrawNothing", BrxCvDbGrading::EGradingVisualStyle::eGradingDrawNothing)
        .value("eGradingDrawSurface", BrxCvDbGrading::EGradingVisualStyle::eGradingDrawSurface)
        .value("eGradingDrawRays", BrxCvDbGrading::EGradingVisualStyle::eGradingDrawRays)
        .value("eGradingDrawDaylight", BrxCvDbGrading::EGradingVisualStyle::eGradingDrawDaylight)
        .export_values()
        ;
};

void initPyBrxCvModule()
{
    PyImport_AppendInittab(PyBrxCvNamespace, &PyInit_PyBrxCv);
}

#endif