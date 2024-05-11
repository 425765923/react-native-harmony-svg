#pragma once

#include <string>
#include "SvgQuote.h"
#include "utils/SvgAttributesParser.h"

namespace rnoh {

class SvgPattern : public SvgQuote {

public:
    SvgPatternAttribute patternAttr_;
    
    SvgPattern();
    ~SvgPattern() = default;
    
    virtual void OnDrawTraversedBefore(OH_Drawing_Canvas *canvas) override;
    virtual void OnDrawTraversedAfter(OH_Drawing_Canvas *canvas) override;
    void SaveDefinition(OH_Drawing_Canvas *canvas);
    void ConcatMatrix(OH_Drawing_Canvas *canvas);
};

}