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
 * @generated by codegen project: GenerateEventEmitterCpp.js
 */

#include "EventEmitters.h"

namespace facebook {
namespace react {

void WebViewEventEmitter::onContentSizeChange(OnContentSizeChange event) const
{
    dispatchEvent("contentSizeChange", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        return payload;
    });
}
void WebViewEventEmitter::onRenderProcessGone(OnRenderProcessGone event) const
{
    dispatchEvent("renderProcessGone", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "didCrash", event.didCrash);
        return payload;
    });
}
void WebViewEventEmitter::onContentProcessDidTerminate(OnContentProcessDidTerminate event) const
{
    dispatchEvent("contentProcessDidTerminate", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        return payload;
    });
}
void WebViewEventEmitter::onCustomMenuSelection(OnCustomMenuSelection event) const
{
    dispatchEvent("customMenuSelection", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "label", event.label);
        payload.setProperty(runtime, "key", event.key);
        payload.setProperty(runtime, "selectedText", event.selectedText);
        return payload;
    });
}
void WebViewEventEmitter::onFileDownload(OnFileDownload event) const
{
    dispatchEvent("fileDownload", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "downloadUrl", event.downloadUrl);
        return payload;
    });
}
void WebViewEventEmitter::onLoadingError(OnLoadingError event) const
{
    dispatchEvent("loadingError", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        payload.setProperty(runtime, "domain", event.domain);
        payload.setProperty(runtime, "code", event.code);
        payload.setProperty(runtime, "description", event.description);
        return payload;
    });
}
void WebViewEventEmitter::onLoadingFinish(OnLoadingFinish event) const
{
    dispatchEvent("loadingFinish", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        payload.setProperty(runtime, "navigationType", event.navigationType);
        payload.setProperty(runtime, "mainDocumentURL", event.mainDocumentURL);
        return payload;
    });
}
void WebViewEventEmitter::onLoadingProgress(OnLoadingProgress event) const
{
    dispatchEvent("loadingProgress", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        payload.setProperty(runtime, "progress", event.progress);
        return payload;
    });
}
void WebViewEventEmitter::onLoadingStart(OnLoadingStart event) const
{
    dispatchEvent("loadingStart", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        payload.setProperty(runtime, "navigationType", toString(event.navigationType));
        payload.setProperty(runtime, "mainDocumentURL", event.mainDocumentURL);
        return payload;
    });
}
void WebViewEventEmitter::onHttpError(OnHttpError event) const
{
    dispatchEvent("httpError", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        payload.setProperty(runtime, "description", event.description);
        payload.setProperty(runtime, "statusCode", event.statusCode);
        return payload;
    });
}
void WebViewEventEmitter::onMessage(OnMessage event) const
{
    dispatchEvent("message", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        payload.setProperty(runtime, "data", event.data);
        return payload;
    });
}
void WebViewEventEmitter::onOpenWindow(OnOpenWindow event) const
{
    dispatchEvent("openWindow", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "targetUrl", event.targetUrl);
        return payload;
    });
}
void WebViewEventEmitter::onScroll(OnScroll event) const
{
    dispatchEvent("scroll", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
            {
                auto contentInset = jsi::Object(runtime);
                contentInset.setProperty(runtime, "bottom", event.contentInset.bottom);
                contentInset.setProperty(runtime, "left", event.contentInset.left);
                contentInset.setProperty(runtime, "right", event.contentInset.right);
                contentInset.setProperty(runtime, "top", event.contentInset.top);
                
                payload.setProperty(runtime, "contentInset", contentInset);
            }
            {
                auto contentOffset = jsi::Object(runtime);
                contentOffset.setProperty(runtime, "y", event.contentOffset.y);
                contentOffset.setProperty(runtime, "x", event.contentOffset.x);
                
                payload.setProperty(runtime, "contentOffset", contentOffset);
            }
            {
                auto contentSize = jsi::Object(runtime);
                contentSize.setProperty(runtime, "height", event.contentSize.height);
                contentSize.setProperty(runtime, "width", event.contentSize.width);
                
                payload.setProperty(runtime, "contentSize", contentSize);
            }
            {
                auto layoutMeasurement = jsi::Object(runtime);
                layoutMeasurement.setProperty(runtime, "height", event.layoutMeasurement.height);
                layoutMeasurement.setProperty(runtime, "width", event.layoutMeasurement.width);
                
                payload.setProperty(runtime, "layoutMeasurement", layoutMeasurement);
            }
            {
                auto targetContentOffset = jsi::Object(runtime);
                targetContentOffset.setProperty(runtime, "y", event.targetContentOffset.y);
                targetContentOffset.setProperty(runtime, "x", event.targetContentOffset.x);
                
                payload.setProperty(runtime, "targetContentOffset", targetContentOffset);
            }
            {
                auto velocity = jsi::Object(runtime);
                velocity.setProperty(runtime, "y", event.velocity.y);
                velocity.setProperty(runtime, "x", event.velocity.x);
                
                payload.setProperty(runtime, "velocity", velocity);
            }
        payload.setProperty(runtime, "zoomScale", event.zoomScale);
        payload.setProperty(runtime, "responderIgnoreScroll", event.responderIgnoreScroll);
        return payload;
    });
}
void WebViewEventEmitter::onShouldStartLoadWithRequest(OnShouldStartLoadWithRequest event) const
{
    dispatchEvent("shouldStartLoadWithRequest", [event = std::move(event)](jsi::Runtime &runtime) {
        auto payload = jsi::Object(runtime);
        payload.setProperty(runtime, "url", event.url);
        payload.setProperty(runtime, "loading", event.loading);
        payload.setProperty(runtime, "title", event.title);
        payload.setProperty(runtime, "canGoBack", event.canGoBack);
        payload.setProperty(runtime, "canGoForward", event.canGoForward);
        payload.setProperty(runtime, "lockIdentifier", event.lockIdentifier);
        payload.setProperty(runtime, "navigationType", event.navigationType);
        payload.setProperty(runtime, "mainDocumentURL", event.mainDocumentURL);
        payload.setProperty(runtime, "isTopFrame", event.isTopFrame);
        return payload;
    });
}

} // namespace react
} // namespace facebook
