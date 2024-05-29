#include "RNSVGMarkerComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>
#include <string>
#include "SvgMarker.h"
#include "properties/Dimension.h"
#include "utils/StringUtils.h"


namespace rnoh {
namespace svg {

RNSVGMarkerComponentInstance::RNSVGMarkerComponentInstance(Context context) : RNSVGBaseComponentInstance(std::move(context)) {
    SetSvgNode(std::make_shared<SvgMarker>());
}

void RNSVGMarkerComponentInstance::UpdateElementProps(SharedConcreteProps const &props) {


    LOG(INFO) << "[RNSVGMarkerComponentInstance] onPropsChanged markerWidth=" << props->markerWidth
              << " markerHeight=" << props->markerHeight;
    LOG(INFO) << "[RNSVGMarkerComponentInstance] onPropsChanged refX=" << props->refX << " refY=" << props->refY;
    LOG(INFO) << "[RNSVGMarkerComponentInstance] onPropsChanged markerUnits=" << props->markerUnits
              << " orient=" << props->orient;
    LOG(INFO) << "[RNSVGMarkerComponentInstance] onPropsChanged minX=" << props->minX << " minY=" << props->minY;
    LOG(INFO) << "[RNSVGMarkerComponentInstance] onPropsChanged vbWidth=" << props->vbWidth
              << " vbHeight=" << props->vbHeight;
    LOG(INFO) << "[RNSVGMarkerComponentInstance] onPropsChanged align=" << props->align
              << " meetOrSlice=" << props->meetOrSlice;
    auto svgMarker = std::dynamic_pointer_cast<SvgMarker>(GetSvgNode());
    svgMarker->UpdateCommonProps(props);
    svgMarker->setRefX(props->refX);
    svgMarker->setRefY(props->refY);
    svgMarker->setMarkerWidth(props->markerWidth);
    svgMarker->setMarkerHeight(props->markerHeight);
    svgMarker->setMarkerUnits(props->markerUnits);
    svgMarker->setOrient(props->orient);
    svgMarker->setMinX(props->minX);
    svgMarker->setMinY(props->minY);
    svgMarker->setVbWidth(props->vbWidth);
    svgMarker->setVbHeight(props->vbHeight);
    svgMarker->setAlign(props->align);
    svgMarker->setMeetOrSlice(props->meetOrSlice);
}


} // namespace svg
} // namespace rnoh
