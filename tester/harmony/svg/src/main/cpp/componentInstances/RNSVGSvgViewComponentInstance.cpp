#include "RNSVGSvgViewComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>
#include "SvgSvg.h"

namespace rnoh {
namespace svg {

RNSVGSvgViewComponentInstance::RNSVGSvgViewComponentInstance(Context context)
    : CppComponentInstance(std::move(context)) {
    SetSvgNode(std::make_shared<SvgSvg>());
    getLocalRootArkUINode().SetSvgNode(GetSvgNode());
    GetSvgNode()->SetContext(std::make_shared<SvgContext>());
}

void RNSVGSvgViewComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->width: " << m_layoutMetrics.frame.size.width;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->height: " << m_layoutMetrics.frame.size.height;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->bbHeight: " << props->bbHeight;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->bbWidth: " << props->bbWidth;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->bbHeight: " << props->bbHeight;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->minX: " << props->minX;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->minY: " << props->minY;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->vbWidth: " << props->vbWidth;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->vbHeight: " << props->vbHeight;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->align: " << props->align;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->meetOrSlice: " << props->meetOrSlice;
    LOG(INFO) << "[SVG] <SVGViewComponentInstance> props->testId: " << props->testId;

    auto svg = dynamic_pointer_cast<SvgSvg>(GetSvgNode());
    auto tintColor = getColorFromDynamic(props->rawProps);
    if (tintColor.has_value()) {
        svg->GetContext()->SetSvgColor(Color::FromString(tintColor.value()));
    }
    svg->SetVbX(props->minX);
    svg->SetVbY(props->minY);
    svg->SetVbWidth(props->vbWidth);
    svg->SetVbHeight(props->vbHeight);
    svg->SetX(0);
    svg->SetY(0);
    svg->SetWidth(props->bbWidth);
    svg->SetHeight(props->bbHeight);
    svg->SetAlign(props->align);
    svg->SetMeetOrSlice(props->meetOrSlice);
}

SvgArkUINode &RNSVGSvgViewComponentInstance::getLocalRootArkUINode() { return m_svgArkUINode; }

std::optional<std::string> RNSVGSvgViewComponentInstance::getColorFromDynamic(folly::dynamic value) {
    auto rawPropsColor = (value.count("color") > 0) ? std::optional(value["color"].asString()) : std::nullopt;
    return rawPropsColor;
}

} // namespace svg
} // namespace rnoh
