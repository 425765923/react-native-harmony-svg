/*
 * MIT License
 *
 * Copyright (C) 2023 Huawei Device Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This code was generated by [react-native-codegen](https://www.npmjs.com/package/react-native-codegen).
 *
 * Do not edit this file as changes may cause incorrect behavior and will be lost
 * once the code is regenerated.
 *
 * @generated by codegen project: GeneratePropsCpp.js
 */

#include "Props.h"
#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>

namespace facebook {
namespace react {
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value, WebViewLayerType &result)
{
    auto string = (std::string)value;
    if (string == "none") {
        result = WebViewLayerType::None;
        return;
    }
    if (string == "software") {
        result = WebViewLayerType::Software;
        return;
    }
    if (string == "hardware") {
        result = WebViewLayerType::Hardware;
        return;
    }
}

static inline std::string toString(const WebViewLayerType &value)
{
    switch (value) {
        case WebViewLayerType::None:
            return "none";
        case WebViewLayerType::Software:
            return "software";
        case WebViewLayerType::Hardware:
            return "hardware";
    }
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value, WebViewCacheMode &result)
{
    auto string = (std::string)value;
    if (string == "LOAD_DEFAULT") {
        result = WebViewCacheMode::LOAD_DEFAULT;
        return;
    }
    if (string == "LOAD_CACHE_ELSE_NETWORK") {
        result = WebViewCacheMode::LOAD_CACHE_ELSE_NETWORK;
        return;
    }
    if (string == "LOAD_NO_CACHE") {
        result = WebViewCacheMode::LOAD_NO_CACHE;
        return;
    }
    if (string == "LOAD_CACHE_ONLY") {
        result = WebViewCacheMode::LOAD_CACHE_ONLY;
        return;
    }
}

static inline std::string toString(const WebViewCacheMode &value)
{
    switch (value) {
        case WebViewCacheMode::LOAD_DEFAULT:
            return "LOAD_DEFAULT";
        case WebViewCacheMode::LOAD_CACHE_ELSE_NETWORK:
            return "LOAD_CACHE_ELSE_NETWORK";
        case WebViewCacheMode::LOAD_NO_CACHE:
            return "LOAD_NO_CACHE";
        case WebViewCacheMode::LOAD_CACHE_ONLY:
            return "LOAD_CACHE_ONLY";
    }
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewMixedContentMode &result)
{
    auto string = (std::string)value;
    if (string == "never") {
        result = WebViewMixedContentMode::Never;
        return;
    }
    if (string == "always") {
        result = WebViewMixedContentMode::Always;
        return;
    }
    if (string == "compatibility") {
        result = WebViewMixedContentMode::Compatibility;
        return;
    }
}

static inline std::string toString(const WebViewMixedContentMode &value)
{
    switch (value) {
        case WebViewMixedContentMode::Never:
            return "never";
        case WebViewMixedContentMode::Always:
            return "always";
        case WebViewMixedContentMode::Compatibility:
            return "compatibility";
    }
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewContentInsetAdjustmentBehavior &result)
{
    auto string = (std::string)value;
    if (string == "never") {
        result = WebViewContentInsetAdjustmentBehavior::Never;
        return;
    }
    if (string == "automatic") {
        result = WebViewContentInsetAdjustmentBehavior::Automatic;
        return;
    }
    if (string == "scrollableAxes") {
        result = WebViewContentInsetAdjustmentBehavior::ScrollableAxes;
        return;
    }
    if (string == "always") {
        result = WebViewContentInsetAdjustmentBehavior::Always;
        return;
    }
}

static inline std::string toString(const WebViewContentInsetAdjustmentBehavior &value)
{
    switch (value) {
        case WebViewContentInsetAdjustmentBehavior::Never:
            return "never";
        case WebViewContentInsetAdjustmentBehavior::Automatic:
            return "automatic";
        case WebViewContentInsetAdjustmentBehavior::ScrollableAxes:
            return "scrollableAxes";
        case WebViewContentInsetAdjustmentBehavior::Always:
            return "always";
    }
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value, WebViewContentMode &result)
{
    auto string = (std::string)value;
    if (string == "recommended") {
        result = WebViewContentMode::Recommended;
        return;
    }
    if (string == "mobile") {
        result = WebViewContentMode::Mobile;
        return;
    }
    if (string == "desktop") {
        result = WebViewContentMode::Desktop;
        return;
    }
}

static inline std::string toString(const WebViewContentMode &value)
{
    switch (value) {
        case WebViewContentMode::Recommended:
            return "recommended";
        case WebViewContentMode::Mobile:
            return "mobile";
        case WebViewContentMode::Desktop:
            return "desktop";
    }
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewDataDetectorTypesMask &result)
{
    auto items = std::vector<std::string>{value};
    for (const auto &item : items) {
        if (item == "address") {
            result |= WebViewDataDetectorTypes::Address;
            continue;
        }
        if (item == "link") {
            result |= WebViewDataDetectorTypes::Link;
            continue;
        }
        if (item == "calendarEvent") {
            result |= WebViewDataDetectorTypes::CalendarEvent;
            continue;
        }
        if (item == "trackingNumber") {
            result |= WebViewDataDetectorTypes::TrackingNumber;
            continue;
        }
        if (item == "flightNumber") {
            result |= WebViewDataDetectorTypes::FlightNumber;
            continue;
        }
        if (item == "lookupSuggestion") {
            result |= WebViewDataDetectorTypes::LookupSuggestion;
            continue;
        }
        if (item == "phoneNumber") {
            result |= WebViewDataDetectorTypes::PhoneNumber;
            continue;
        }
        if (item == "all") {
            result |= WebViewDataDetectorTypes::All;
            continue;
        }
        if (item == "none") {
            result |= WebViewDataDetectorTypes::None;
            continue;
        }
    }
}

static inline std::string toString(const WebViewDataDetectorTypesMask &value)
{
    auto result = std::string{};
    auto separator = std::string{", "};

    if (value & WebViewDataDetectorTypes::Address) {
        result += "address" + separator;
    }
    if (value & WebViewDataDetectorTypes::Link) {
        result += "link" + separator;
    }
    if (value & WebViewDataDetectorTypes::CalendarEvent) {
        result += "calendarEvent" + separator;
    }
    if (value & WebViewDataDetectorTypes::TrackingNumber) {
        result += "trackingNumber" + separator;
    }
    if (value & WebViewDataDetectorTypes::FlightNumber) {
        result += "flightNumber" + separator;
    }
    if (value & WebViewDataDetectorTypes::LookupSuggestion) {
        result += "lookupSuggestion" + separator;
    }
    if (value & WebViewDataDetectorTypes::PhoneNumber) {
        result += "phoneNumber" + separator;
    }
    if (value & WebViewDataDetectorTypes::All) {
        result += "all" + separator;
    }
    if (value & WebViewDataDetectorTypes::None) {
        result += "none" + separator;
    }
    if (!result.empty()) {
        result.erase(result.length() - separator.length());
    }
    return result;
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewMediaCapturePermissionGrantType &result)
{
    auto string = (std::string)value;
    if (string == "prompt") {
        result = WebViewMediaCapturePermissionGrantType::Prompt;
        return;
    }
    if (string == "grant") {
        result = WebViewMediaCapturePermissionGrantType::Grant;
        return;
    }
    if (string == "deny") {
        result = WebViewMediaCapturePermissionGrantType::Deny;
        return;
    }
    if (string == "grantIfSameHostElsePrompt") {
        result = WebViewMediaCapturePermissionGrantType::GrantIfSameHostElsePrompt;
        return;
    }
    if (string == "grantIfSameHostElseDeny") {
        result = WebViewMediaCapturePermissionGrantType::GrantIfSameHostElseDeny;
        return;
    }
}

static inline std::string toString(const WebViewMediaCapturePermissionGrantType &value)
{
    switch (value) {
        case WebViewMediaCapturePermissionGrantType::Prompt:
            return "prompt";
        case WebViewMediaCapturePermissionGrantType::Grant:
            return "grant";
        case WebViewMediaCapturePermissionGrantType::Deny:
            return "deny";
        case WebViewMediaCapturePermissionGrantType::GrantIfSameHostElsePrompt:
            return "grantIfSameHostElsePrompt";
        case WebViewMediaCapturePermissionGrantType::GrantIfSameHostElseDeny:
            return "grantIfSameHostElseDeny";
    }
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewContentInsetStruct &result)
{
    auto map = (butter::map<std::string, RawValue>)value;

    auto tmp_top = map.find("top");
    if (tmp_top != map.end()) {
        fromRawValue(context, tmp_top->second, result.top);
    }
    auto tmp_left = map.find("left");
    if (tmp_left != map.end()) {
        fromRawValue(context, tmp_left->second, result.left);
    }
    auto tmp_bottom = map.find("bottom");
    if (tmp_bottom != map.end()) {
        fromRawValue(context, tmp_bottom->second, result.bottom);
    }
    auto tmp_right = map.find("right");
    if (tmp_right != map.end()) {
        fromRawValue(context, tmp_right->second, result.right);
    }
}

static inline std::string toString(const WebViewContentInsetStruct &value)
{
    return "[Object WebViewContentInsetStruct]";
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewMenuItemsStruct &result)
{
    auto map = (butter::map<std::string, RawValue>)value;

    auto tmp_label = map.find("label");
    if (tmp_label != map.end()) {
        fromRawValue(context, tmp_label->second, result.label);
    }
    auto tmp_key = map.find("key");
    if (tmp_key != map.end()) {
        fromRawValue(context, tmp_key->second, result.key);
    }
}

static inline std::string toString(const WebViewMenuItemsStruct &value)
{
    return "[Object WebViewMenuItemsStruct]";
}

static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    std::vector<WebViewMenuItemsStruct> &result)
{
    auto items = (std::vector<RawValue>)value;
    for (const auto &item : items) {
        WebViewMenuItemsStruct newItem;
        fromRawValue(context, item, newItem);
        result.emplace_back(newItem);
    }
}
static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewBasicAuthCredentialStruct &result)
{
    auto map = (butter::map<std::string, RawValue>)value;

    auto tmp_username = map.find("username");
    if (tmp_username != map.end()) {
        fromRawValue(context, tmp_username->second, result.username);
    }
    auto tmp_password = map.find("password");
    if (tmp_password != map.end()) {
        fromRawValue(context, tmp_password->second, result.password);
    }
}

static inline std::string toString(const WebViewBasicAuthCredentialStruct &value)
{
    return "[Object WebViewBasicAuthCredentialStruct]";
}
static inline std::string getValues(const PropsParserContext &context, const RawValue &value) {
    auto map = (butter::map<std::string, RawValue>)value;
    std::string result = "";
    std::string itemValue1;
    auto tmp_name = map.find("name");
    if (tmp_name != map.end()) {
        fromRawValue(context, tmp_name->second, itemValue1);
        result += "\"" + itemValue1 + "\":\"";
    }
    auto tmp_value = map.find("value");
    std::string itemValue2;
    if (tmp_value != map.end()) {
        fromRawValue(context, tmp_value->second, itemValue2);
        result += itemValue2 + "\"";
    }
    return result;
}

static inline std::string toString(const WebViewNewSourceHeadersStruct &value)
{
    return "[Object WebViewNewSourceHeadersStruct]";
}

static inline std::string getSourceHeaders(const PropsParserContext &context, const RawValue &value) {
    auto items = (std::vector<RawValue>)value;
    std::string headers = "{";
    bool isFirst = true;
    for (const auto &item : items) {
        std::string tmp = getValues(context, item);
        if (!isFirst) {
            headers += ",";
        }
        headers += tmp;
        isFirst = false;
    }
    headers += "}";
    return headers;
}

static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
    WebViewNewSourceStruct &result)
{
    auto map = (butter::map<std::string, RawValue>)value;

    auto tmp_uri = map.find("uri");
    if (tmp_uri != map.end()) {
        fromRawValue(context, tmp_uri->second, result.uri);
    }
    auto tmp_method = map.find("method");
    if (tmp_method != map.end()) {
        fromRawValue(context, tmp_method->second, result.method);
    }
    auto tmp_body = map.find("body");
    if (tmp_body != map.end()) {
        fromRawValue(context, tmp_body->second, result.body);
    }
    auto tmp_headers = map.find("headers");
    if (tmp_headers != map.end()) {
        result.headers = getSourceHeaders(context, tmp_headers->second);
    }
    auto tmp_html = map.find("html");
    if (tmp_html != map.end()) {
        fromRawValue(context, tmp_html->second, result.html);
    }
    auto tmp_baseUrl = map.find("baseUrl");
    if (tmp_baseUrl != map.end()) {
        fromRawValue(context, tmp_baseUrl->second, result.baseUrl);
    }
}

static inline std::string toString(const WebViewNewSourceStruct &value)
{
    return "[Object WebViewNewSourceStruct]";
}
WebViewProps::WebViewProps(
    const PropsParserContext &context,
    const WebViewProps &sourceProps,
    const RawProps &rawProps): ViewProps(context, sourceProps, rawProps),

    allowFileAccess(convertRawProp(context, rawProps, "allowFileAccess", sourceProps.allowFileAccess, {false})),
    allowsProtectedMedia(convertRawProp(context, rawProps, "allowsProtectedMedia",
        sourceProps.allowsProtectedMedia, {false})),
    allowsFullscreenVideo(convertRawProp(context, rawProps, "allowsFullscreenVideo",
        sourceProps.allowsFullscreenVideo, {false})),
    androidLayerType(convertRawProp(context, rawProps, "androidLayerType", sourceProps.androidLayerType,
        {WebViewLayerType::None})),
    cacheMode(convertRawProp(context, rawProps, "cacheMode", sourceProps.cacheMode, {WebViewCacheMode::LOAD_DEFAULT})),
    domStorageEnabled(convertRawProp(context, rawProps, "domStorageEnabled", sourceProps.domStorageEnabled, {false})),
    downloadingMessage(convertRawProp(context, rawProps, "downloadingMessage", sourceProps.downloadingMessage, {})),
    forceDarkOn(convertRawProp(context, rawProps, "forceDarkOn", sourceProps.forceDarkOn, {false})),
    geolocationEnabled(convertRawProp(context, rawProps, "geolocationEnabled",
        sourceProps.geolocationEnabled, {false})),
    lackPermissionToDownloadMessage(convertRawProp(context, rawProps, "lackPermissionToDownloadMessage",
        sourceProps.lackPermissionToDownloadMessage, {})),
    messagingModuleName(convertRawProp(context, rawProps, "messagingModuleName", sourceProps.messagingModuleName, {})),
    minimumFontSize(convertRawProp(context, rawProps, "minimumFontSize", sourceProps.minimumFontSize, {0})),
    mixedContentMode(convertRawProp(context, rawProps, "mixedContentMode", sourceProps.mixedContentMode,
        {WebViewMixedContentMode::Never})),
    nestedScrollEnabled(convertRawProp(context, rawProps, "nestedScrollEnabled",
        sourceProps.nestedScrollEnabled, {false})),
    overScrollMode(convertRawProp(context, rawProps, "overScrollMode", sourceProps.overScrollMode, {})),
    saveFormDataDisabled(convertRawProp(context, rawProps, "saveFormDataDisabled",
        sourceProps.saveFormDataDisabled, {false})),
    scalesPageToFit(convertRawProp(context, rawProps, "scalesPageToFit", sourceProps.scalesPageToFit, {false})),
    setBuiltInZoomControls(convertRawProp(context, rawProps, "setBuiltInZoomControls",
        sourceProps.setBuiltInZoomControls, {false})),
    setDisplayZoomControls(convertRawProp(context, rawProps, "setDisplayZoomControls",
        sourceProps.setDisplayZoomControls, {false})),
    setSupportMultipleWindows(convertRawProp(context, rawProps, "setSupportMultipleWindows",
        sourceProps.setSupportMultipleWindows, {false})),
    textZoom(convertRawProp(context, rawProps, "textZoom", sourceProps.textZoom, {0})),
    thirdPartyCookiesEnabled(convertRawProp(context, rawProps, "thirdPartyCookiesEnabled",
        sourceProps.thirdPartyCookiesEnabled, {false})),
    hasOnScroll(convertRawProp(context, rawProps, "hasOnScroll", sourceProps.hasOnScroll, {false})),
    injectedJavaScriptObject(convertRawProp(context, rawProps, "injectedJavaScriptObject",
        sourceProps.injectedJavaScriptObject, {})),
    allowingReadAccessToURL(convertRawProp(context, rawProps, "allowingReadAccessToURL",
        sourceProps.allowingReadAccessToURL, {})),
    allowsBackForwardNavigationGestures(convertRawProp(context, rawProps, "allowsBackForwardNavigationGestures",
        sourceProps.allowsBackForwardNavigationGestures, {false})),
    allowsInlineMediaPlayback(convertRawProp(context, rawProps, "allowsInlineMediaPlayback",
        sourceProps.allowsInlineMediaPlayback, {false})),
    allowsAirPlayForMediaPlayback(convertRawProp(context, rawProps, "allowsAirPlayForMediaPlayback",
        sourceProps.allowsAirPlayForMediaPlayback, {false})),
    allowsLinkPreview(convertRawProp(context, rawProps, "allowsLinkPreview", sourceProps.allowsLinkPreview, {false})),
    automaticallyAdjustContentInsets(convertRawProp(context, rawProps, "automaticallyAdjustContentInsets",
        sourceProps.automaticallyAdjustContentInsets, {false})),
    autoManageStatusBarEnabled(convertRawProp(context, rawProps, "autoManageStatusBarEnabled",
        sourceProps.autoManageStatusBarEnabled, {false})),
    bounces(convertRawProp(context, rawProps, "bounces", sourceProps.bounces, {false})),
    contentInset(convertRawProp(context, rawProps, "contentInset", sourceProps.contentInset, {})),
    contentInsetAdjustmentBehavior(convertRawProp(context, rawProps, "contentInsetAdjustmentBehavior",
        sourceProps.contentInsetAdjustmentBehavior, {WebViewContentInsetAdjustmentBehavior::Never})),
    contentMode(convertRawProp(context, rawProps, "contentMode", sourceProps.contentMode,
        {WebViewContentMode::Recommended})),
    dataDetectorTypes(convertRawProp(context, rawProps, "dataDetectorTypes", sourceProps.dataDetectorTypes,
        {static_cast<WebViewDataDetectorTypesMask>(WebViewDataDetectorTypes::PhoneNumber)})),
    decelerationRate(convertRawProp(context, rawProps, "decelerationRate", sourceProps.decelerationRate, {0.0})),
    directionalLockEnabled(convertRawProp(context, rawProps, "directionalLockEnabled",
        sourceProps.directionalLockEnabled, {false})),
    enableApplePay(convertRawProp(context, rawProps, "enableApplePay", sourceProps.enableApplePay, {false})),
    hideKeyboardAccessoryView(convertRawProp(context, rawProps, "hideKeyboardAccessoryView",
        sourceProps.hideKeyboardAccessoryView, {false})),
    keyboardDisplayRequiresUserAction(convertRawProp(context, rawProps, "keyboardDisplayRequiresUserAction",
        sourceProps.keyboardDisplayRequiresUserAction, {false})),
    limitsNavigationsToAppBoundDomains(convertRawProp(context, rawProps, "limitsNavigationsToAppBoundDomains",
        sourceProps.limitsNavigationsToAppBoundDomains, {false})),
    mediaCapturePermissionGrantType(convertRawProp(context, rawProps, "mediaCapturePermissionGrantType",
        sourceProps.mediaCapturePermissionGrantType, {WebViewMediaCapturePermissionGrantType::Prompt})),
    pagingEnabled(convertRawProp(context, rawProps, "pagingEnabled", sourceProps.pagingEnabled, {false})),
    pullToRefreshEnabled(convertRawProp(context, rawProps, "pullToRefreshEnabled",
        sourceProps.pullToRefreshEnabled, {false})),
    scrollEnabled(convertRawProp(context, rawProps, "scrollEnabled", sourceProps.scrollEnabled, {false})),
    sharedCookiesEnabled(convertRawProp(context, rawProps, "sharedCookiesEnabled",
        sourceProps.sharedCookiesEnabled, {false})),
    textInteractionEnabled(convertRawProp(context, rawProps, "textInteractionEnabled",
        sourceProps.textInteractionEnabled, {false})),
    useSharedProcessPool(convertRawProp(context, rawProps, "useSharedProcessPool",
        sourceProps.useSharedProcessPool, {false})),
    menuItems(convertRawProp(context, rawProps, "menuItems", sourceProps.menuItems, {})),
    suppressMenuItems(convertRawProp(context, rawProps, "suppressMenuItems", sourceProps.suppressMenuItems, {})),
    hasOnFileDownload(convertRawProp(context, rawProps, "hasOnFileDownload", sourceProps.hasOnFileDownload, {false})),
    fraudulentWebsiteWarningEnabled(convertRawProp(context, rawProps, "fraudulentWebsiteWarningEnabled",
        sourceProps.fraudulentWebsiteWarningEnabled, {false})),
    allowFileAccessFromFileURLs(convertRawProp(context, rawProps, "allowFileAccessFromFileURLs",
        sourceProps.allowFileAccessFromFileURLs, {false})),
    allowUniversalAccessFromFileURLs(convertRawProp(context, rawProps, "allowUniversalAccessFromFileURLs",
        sourceProps.allowUniversalAccessFromFileURLs, {false})),
    applicationNameForUserAgent(convertRawProp(context, rawProps, "applicationNameForUserAgent",
        sourceProps.applicationNameForUserAgent, {})),
    basicAuthCredential(convertRawProp(context, rawProps, "basicAuthCredential", sourceProps.basicAuthCredential, {})),
    cacheEnabled(convertRawProp(context, rawProps, "cacheEnabled", sourceProps.cacheEnabled, {false})),
    incognito(convertRawProp(context, rawProps, "incognito", sourceProps.incognito, {false})),
    injectedJavaScript(convertRawProp(context, rawProps, "injectedJavaScript", sourceProps.injectedJavaScript, {})),
    injectedJavaScriptBeforeContentLoaded(convertRawProp(context, rawProps, "injectedJavaScriptBeforeContentLoaded",
        sourceProps.injectedJavaScriptBeforeContentLoaded, {})),
    injectedJavaScriptForMainFrameOnly(convertRawProp(context, rawProps, "injectedJavaScriptForMainFrameOnly",
        sourceProps.injectedJavaScriptForMainFrameOnly, {false})),
    injectedJavaScriptBeforeContentLoadedForMainFrameOnly(convertRawProp(context, rawProps,
        "injectedJavaScriptBeforeContentLoadedForMainFrameOnly",
        sourceProps.injectedJavaScriptBeforeContentLoadedForMainFrameOnly, {false})),
    javaScriptCanOpenWindowsAutomatically(convertRawProp(context, rawProps, "javaScriptCanOpenWindowsAutomatically",
        sourceProps.javaScriptCanOpenWindowsAutomatically, {false})),
    javaScriptEnabled(convertRawProp(context, rawProps, "javaScriptEnabled", sourceProps.javaScriptEnabled, {false})),
    webviewDebuggingEnabled(convertRawProp(context, rawProps, "webviewDebuggingEnabled",
        sourceProps.webviewDebuggingEnabled, {false})),
    mediaPlaybackRequiresUserAction(convertRawProp(context, rawProps, "mediaPlaybackRequiresUserAction",
        sourceProps.mediaPlaybackRequiresUserAction, {false})),
    messagingEnabled(convertRawProp(context, rawProps, "messagingEnabled", sourceProps.messagingEnabled, {false})),
    hasOnOpenWindowEvent(convertRawProp(context, rawProps, "hasOnOpenWindowEvent",
        sourceProps.hasOnOpenWindowEvent, {false})),
    showsHorizontalScrollIndicator(convertRawProp(context, rawProps, "showsHorizontalScrollIndicator",
        sourceProps.showsHorizontalScrollIndicator, {true})),
    showsVerticalScrollIndicator(convertRawProp(context, rawProps, "showsVerticalScrollIndicator",
        sourceProps.showsVerticalScrollIndicator, {true})),
    newSource(convertRawProp(context, rawProps, "newSource", sourceProps.newSource, {})),
    userAgent(convertRawProp(context, rawProps, "userAgent", sourceProps.userAgent, {})),
    shouldStartLoadWithRequestEnabled(convertRawProp(context, rawProps, "shouldStartLoadWithRequestEnabled",
        sourceProps.shouldStartLoadWithRequestEnabled, {false}))
    {}

} // namespace react
} // namespace facebook
