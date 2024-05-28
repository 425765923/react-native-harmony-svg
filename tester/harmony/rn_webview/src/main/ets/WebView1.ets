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
 */

import { Descriptor, ComponentBuilderContext, RNOHContext, ViewBaseProps } from '@rnoh/react-native-openharmony'
import webview from '@ohos.web.webview';
import { CallbackState, ShouldRequestUrl } from './ShouldRequestUrl';
import { RNViewBase,RNViewBaseAttributeModifier,ViewDescriptorWrapperBase,RNComponentContext } from '@rnoh/react-native-openharmony';
import Logger from './Logger'

// 创建NodeController
// common.ets
import { UIContext } from '@ohos.arkui.UIContext';
import web_webview from '@ohos.web.webview'
import { NodeController, BuilderNode, Size, FrameNode }  from '@ohos.arkui.node';


export class WebViewNewSource {
  uri: string | Resource = ""
  method?: string
  body?: string
  headers?: string
  html?: string
  baseUrl?: string
}

const TAG = "WebView"

export const WEB_VIEW = "RNCWebView"

const JAVASCRIPT_INTERFACE = "ReactNativeWebView";

export interface WebViewProps extends ViewBaseProps {
  newSource: WebViewNewSource
  javaScriptEnabled: boolean
  injectedJavaScript: string
  messagingEnabled: boolean
  showsHorizontalScrollIndicator: boolean
  showsVerticalScrollIndicator: boolean
  textZoom: number
  cacheEnabled: boolean
  cacheMode: number
  domStorageEnabled: boolean
  scalesPageToFit: boolean
  messagingModuleName: string
  shouldStartLoadWithRequestEnabled: boolean
  webviewDebuggingEnabled: boolean
  // nestedScrollEnabled: boolean
}

export class RNCWebViewBridge {
  postMessage!: (data: string) => void;
}

export class WebViewEventParams {
  type: string
  url?: string
  loading?: boolean
  title?: string
  canGoBack?: boolean
  canGoForward?: boolean
  lockIdentifier?: number
  data?: string

  constructor(type: string) {
    this.type = type
  }
}

export type WebViewViewDescriptor = Descriptor<"RNCWebView", WebViewProps>

@Component
export struct WebView {
  ctx!: RNOHContext
  tag: number = 0
  @State descriptor: WebViewViewDescriptor = {} as WebViewViewDescriptor
  @State source: WebViewNewSource = {
    uri: "",
    method: "",
    body: "",
    headers: "",
    html: "",
    baseUrl: ""
  }
  html: string | undefined = ""
  url: string | Resource = ""
  private unregisterDescriptorChangesListener?: () => void = undefined
  private cleanupCommandCallback?: () => void = undefined
  controller: webview.WebviewController = new webview.WebviewController();
  javaScriptEnable: boolean = true
  progress: number = 0
  cacheMode: number = CacheMode.Default
  lockIdentifier: string = "";
  requestUrl: string = "";
  messagingEnabled: boolean = false;
  hasRegisterJavaScriptProxy: boolean = false;
  controllerAttached: boolean = false;
  // nestedScrollFlag: boolean = false;
  renderMode: RenderMode = RenderMode.SYNC_RENDER;
  @State private rnViewAttributeModifier: RNViewBaseAttributeModifier | undefined = undefined

  aboutToAppear() {
    this.descriptor = this.ctx.descriptorRegistry.getDescriptor<WebViewViewDescriptor>(this.tag)
    this.unregisterDescriptorChangesListener = this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
      (newDescriptor) => {
        this.descriptor = (newDescriptor as WebViewViewDescriptor)
        Logger.debug(TAG, `[RNOH] newDescriptor props uri, ${JSON.stringify(this.descriptor.props.newSource.uri)}`);
        this.cacheMode = this.descriptor.props.cacheEnabled ? this.transCacheMode(this.descriptor.props.cacheMode) : CacheMode.Online;
        this.javaScriptEnable = this.descriptor.props.javaScriptEnabled;
        this.source = this.descriptor.props.newSource
        if (this.html != "" && this.html != this.source.html) {
          Logger.debug(TAG, "[RNOH] html is update")
          this.html = this.source.html
          if (this.controllerAttached) {
            try {
              this.controller.loadData(
                this.source.html,
                "text/html",
                "UTF-8",
                this.source.baseUrl,
                " "
              );
            } catch (error) {
              Logger.error(TAG, "error: " + error)
            }
          }
        } else if (this.source.uri != "" && this.url != this.source.uri) {
          Logger.debug(TAG, `[RNOH] newDescriptor props update uri: ` + this.source.uri);
          this.url = this.source.uri
          if (this.controllerAttached) {
            this.controller.loadUrl(this.descriptor.props.newSource.uri)
          }
        }
      }
    )
    webview.WebviewController.setWebDebuggingAccess(this.descriptor.props.webviewDebuggingEnabled)
    this.javaScriptEnable = this.descriptor.props.javaScriptEnabled;
    this.cacheMode = this.descriptor.props.cacheEnabled ? this.transCacheMode(this.descriptor.props.cacheMode) : CacheMode.Online;
    this.source = this.descriptor.props.newSource
    this.html = this.source.html
    this.url = this.source.uri;
    // this.nestedScrollFlag = this.descriptor.props.nestedScrollEnabled;
    // nestedScrollEnabled true表示可嵌套滚动，不需要自适应和web统一渲染，默认是false
    // this.renderMode = this.nestedScrollFlag?RenderMode.ASYNC_RENDER:RenderMode.SYNC_RENDER
    this.registerCommandCallback()
    let descriptorWrapper = this.ctx.descriptorRegistry.findDescriptorWrapperByTag<ViewDescriptorWrapperBase>(this.descriptor.tag)
    if (!descriptorWrapper || !(descriptorWrapper instanceof ViewDescriptorWrapperBase)) {
      descriptorWrapper = new ViewDescriptorWrapperBase(this.descriptor)
    }
    if (this.ctx instanceof RNComponentContext) {
      this.rnViewAttributeModifier = new RNViewBaseAttributeModifier(descriptorWrapper, this.ctx)
    }
    getNWeb(this.descriptor.props.newSource.uri.toString())?.setRnParams(this.ctx,this.tag);
    // getNWeb("https://www.baidu.com/")?.rebuild()
  }


  private registerPostMessage() {
    if (this.messagingEnabled == this.descriptor.props.messagingEnabled) {
      return;
    }
    this.messagingEnabled = this.descriptor.props.messagingEnabled;
    if (this.messagingEnabled) {
      let bridge: RNCWebViewBridge = {
        postMessage: (data: string) => {
          Logger.debug(TAG, `[RNOH] bridge postMessage,  ${JSON.stringify(data)}`);
          if (this.controller != null) {
            let result: WebViewEventParams = this.createWebViewEvent("onMessage")
            result.data = data
            result.lockIdentifier = 0
            this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, result);
          }
        }
      };
      this.controller.registerJavaScriptProxy(bridge, JAVASCRIPT_INTERFACE, ["postMessage"])
      this.controller.refresh()
      this.hasRegisterJavaScriptProxy = true
    }
  }

  createWebViewEvent(param: string): WebViewEventParams {
    let result: WebViewEventParams = new WebViewEventParams(param);
    result.loading = this.progress != 100
    try {
      result.url = this.controller.getUrl();
      result.title = this.controller.getTitle();
      result.canGoBack = this.controller.accessBackward();
      result.canGoForward = this.controller.accessForward();
    } catch (error) {
      Logger.error(TAG, `[RNOH]Errorcode: ${error.code}, Message: ${error.message}`);
      result.url = "";
      result.title = "";
      result.canGoBack = false;
      result.canGoForward = false;
    }
    return result;
  }

  aboutToDisappear() {
    this.cleanupCommandCallback?.()
    this.unregisterDescriptorChangesListener?.()
    Logger.debug(TAG, `[RNOH] aboutToDisappear`)
    try {
      this.controller.deleteJavaScriptRegister(JAVASCRIPT_INTERFACE)
      this.controller.refresh()
      this.hasRegisterJavaScriptProxy = false
    } catch (error) {
      Logger.error(TAG, `[RNOH]Errorcode: ${error.code}, Message: ${error.message}`);
    }
  }

  transCacheMode(cacheMode: number): CacheMode {
    let mode = CacheMode.Default
    switch (cacheMode) {
      case 0:
        mode = CacheMode.Default
        break;
      case 1:
        mode = CacheMode.None
        break;
      case 2:
        mode = CacheMode.Online
        break;
      case 3:
        mode = CacheMode.Only
        break;
      default:
        break;
    }
    return mode
  }

  registerCommandCallback() {
    this.cleanupCommandCallback = this.ctx.componentCommandReceiver.registerCommandCallback(
      this.tag,
      (command, args: string[]) => {
        switch (command) {
          case "injectJavaScript":
            Logger.debug(TAG, `[RNOH] injectJavaScript,${JSON.stringify(args)}`)
            if (this.controllerAttached) {
              try {
                this.controller.runJavaScript("(function() {\n" + args[0] + ";\n})();")
              } catch (error) {
                Logger.error(TAG, "error: " + error)
              }
            }
            break
          case "postMessage":
            Logger.debug(TAG, `[RNOH] postMessage,${JSON.stringify(args)}`)
            let data = JSON.stringify({data : args[0]})
            let result: string = "(function () {" +
              "var event;" +
              "var data = " + data.toString() + ";" +
              "try {" +
              "event = new MessageEvent('message', data);" +
              "} catch (e) {" +
              "event = document.createEvent('MessageEvent');" +
              "event.initMessageEvent('message', true, true, data.data, data.origin, data.lastEventId, data.source);" +
              "}" +
              "document.dispatchEvent(event);" +
              "})();"
            if (this.controllerAttached) {
              try {
                this.controller.runJavaScript(result)
              } catch (error) {
                Logger.error(TAG, "error:" + error)
              }
            }
            break;
          case "reload":
            Logger.debug(TAG, `[RNOH] reload,${JSON.stringify(args)}`)
            if (this.controllerAttached) {
              try {
                this.controller.refresh();
              } catch (error) {
                Logger.error(TAG, "error: " + error)
              }
            }
            break
          default:
            break
        }
      });
  }

  onLoadingFinish() {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onLoadingFinish",
      url: this.controller.getUrl(),
      loading: this.progress != 100,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: 0,
      navigationType: "other",
      mainDocumentURL: ""
    })
  }

  onLoadingError(code: number, description: string) {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onLoadingError",
      url: this.controller.getUrl(),
      loading: false,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: 0,
      domain: "",
      code: code,
      description: description
    })
  }

  onShouldStartLoadWithRequest() {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onShouldStartLoadWithRequest",
      url: this.controller.getUrl(),
      loading: this.progress != 100,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: 0,
      navigationType: "other",
      mainDocumentURL: "",
      isTopFrame: false
    })
  }

  onShouldStartLoadCallFunction(lockIdentifier: number, data: WebResourceRequest) {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onShouldStartLoadWithRequest",
      url: data.getRequestUrl(),
      loading: this.progress != 100,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: lockIdentifier,
      navigationType: "other",
      mainDocumentURL: "",
      isTopFrame: data.isMainFrame()
    })
  }

  runInjectedJavaScript() {
    let injectedJS = this.descriptor.props.injectedJavaScript
    if (this.javaScriptEnable && injectedJS != "" && this.controllerAttached) {
      try {
        this.controller.runJavaScript("(function() {\n" + injectedJS + ";\n})();")
          .then((result) => {
            Logger.debug(TAG, '[RNOH] result: ' + result);
          })
          .catch((error: string | Error) => {
            Logger.error(TAG, "[RNOH] error: " + error);
          })
      } catch (error) {
        Logger.error(TAG, `[RNOH]Errorcode: ${error.code}, Message: ${error.message}`);
      }
    }
  }

  build() {
    Stack() {
      if (getNWeb(this.descriptor.props.newSource.uri.toString())){
        NodeContainer(getNWeb(this.descriptor.props.newSource.uri.toString()))
          .height("100%")
          .width("100%")
      }else {
        Web({ src: this.source.uri, controller: this.controller, renderMode: this.renderMode })
          .width(this.descriptor.layoutMetrics.frame.size.width)
          .height(this.descriptor.layoutMetrics.frame.size.height)
          .constraintSize({ minHeight: 1 })
          .backgroundColor(Color.Transparent)
          .javaScriptAccess(this.javaScriptEnable)
          .horizontalScrollBarAccess(this.descriptor.props.showsHorizontalScrollIndicator)
          .verticalScrollBarAccess(this.descriptor.props.showsVerticalScrollIndicator)
          .overviewModeAccess(this.descriptor.props.scalesPageToFit)
          .textZoomRatio(this.descriptor.props.textZoom)
          .cacheMode(this.cacheMode)
          .domStorageAccess(this.descriptor.props.domStorageEnabled)
          .zoomAccess(this.descriptor.props.scalesPageToFit)
          .overScrollMode(OverScrollMode.NEVER)// nestedScrollFlag 为true 表示可以在嵌套滚动中，web自己能滚动
            // .layoutMode(this.nestedScrollFlag ? WebLayoutMode.NONE : WebLayoutMode.FIT_CONTENT)

            // .nestedScroll(this.nestedScrollFlag ? {
            //   scrollForward: NestedScrollMode.SELF_ONLY,
            //   scrollBackward: NestedScrollMode.SELF_ONLY
            // } : { scrollForward: NestedScrollMode.PARENT_FIRST, scrollBackward: NestedScrollMode.PARENT_FIRST })
            // .overScrollMode(OverScrollMode.NEVER)
            // .onSizeChange((event)=>{
            //   Logger.debug(TAG, "[RNOH] event width: " + event.width + "[RNOH] event height: " + event.height)
            // })
          .onProgressChange((event) => {
            if (event) {
              this.progress = event.newProgress
              Logger.debug(TAG, "[RNOH] event progress: " + event.newProgress)
            }
          })
          .onPageEnd(() => {
            Logger.debug(TAG, "[RNOH] onPageEnd")
            this.runInjectedJavaScript()
            this.onLoadingFinish()
          })
          .onErrorReceive((event) => {
            if (event) {
              let errorInfo: string = event.error.getErrorInfo();
              let errorCode: number = event.error.getErrorCode();
              if (errorInfo == "ERR_INTERNET_DISCONNECTED" || errorInfo == "ERR_CACHE_MISS" ||
                !event.request.isMainFrame()) {
                Logger.debug(TAG, "[RNOH] ERR_INTERNET_DISCONNECTED:OR ERR_CACHE_MISS")
                return
              }
              Logger.debug(TAG, "[RNOH] errorInfo:" + errorInfo)
              Logger.debug(TAG, "[RNOH] errorCode:" + errorCode)
              this.onLoadingError(errorCode, errorInfo)
            }
          })
          .onLoadIntercept((event) => {
            if (!this.descriptor.props.shouldStartLoadWithRequestEnabled) {
              Logger.debug(TAG,
                "[RNOH]:shouldStartLoadWithRequestEnabled:" + this.descriptor.props.shouldStartLoadWithRequestEnabled)
              return false
            }
            if (this.source.html != undefined && this.source.html != '') {
              Logger.debug(TAG, "[RNOH]: load html not intercept")
              return false;
            }
            if (event.data.getRequestUrl() == this.source.uri || this.requestUrl != "") {
              Logger.debug(TAG, "[RNOH] first load not intercept")
              this.requestUrl = ""
              return false
            }
            this.requestUrl = event.data.getRequestUrl()
            let lockIdentifier = ShouldRequestUrl.getNewData();
            this.lockIdentifier = lockIdentifier
            Logger.debug(TAG, "[RNOH]:lockIdentifier:" + lockIdentifier)
            ShouldRequestUrl.setCallBack(lockIdentifier, () => {
              let data: CallbackState = ShouldRequestUrl.getValue(this.lockIdentifier);
              let should: boolean = data == CallbackState.SHOULD_OVERRIDE
              Logger.debug(TAG, "[RNOH] should:" + should)
              ShouldRequestUrl.removeData(this.lockIdentifier)
              this.lockIdentifier = ""
              if (!should) {
                this.controller.loadUrl(this.requestUrl)
              } else {
                this.requestUrl = ""
              }
            })
            this.onShouldStartLoadCallFunction(Number(this.lockIdentifier), event.data)
            return true
          })
          .onControllerAttached(() => {
            this.controllerAttached = true;
            Logger.debug(TAG, "[RNOH] onControllerAttached")
            let baseUrl = this.source.baseUrl
            let uri = this.source.uri
            if (this.source.html != undefined && this.source.html != "") {
              try {
                this.controller.loadData(
                  this.source.html,
                  "text/html",
                  "UTF-8",
                  baseUrl,
                  " "
                );
              } catch (error) {
                Logger.error(TAG, "error:" + error)
              }
            } else if (uri != undefined && uri != "") {
              let header = this.source.headers;
              if (header != undefined && header != "") {
                let headers: Array<webview.WebHeader> = [];
                JSON.parse(header, (key: string, value: string) => {
                  if (key && value) {
                    headers.push({ headerKey: key, headerValue: value })
                  }
                  return undefined;
                })
                this.controller.loadUrl(uri, headers);
              }
            }
            if (!this.hasRegisterJavaScriptProxy) {
              this.registerPostMessage()
            }
          })
      }
    }
    .width(this.descriptor.layoutMetrics.frame.size.width)
    .height(this.descriptor.layoutMetrics.frame.size.height)
    .position({x:this.descriptor.layoutMetrics.frame.origin.x,y:this.descriptor.layoutMetrics.frame.origin.y})
    .attributeModifier(this.rnViewAttributeModifier)
    // RNViewBase({ ctx: this.ctx, tag: this.tag }) {
  }
}

// @Builder中为动态组件的具体组件内容
// Data为入参封装类
interface onErrorReceiveEvent {
  request: WebResourceRequest;
  error: WebResourceError;
}
interface onLoadInterceptEvent {
  data: WebResourceRequest;
}
class Data{
  url: string = "https://www.example.com";
  controller: WebviewController = new web_webview.WebviewController();
  descriptor?:WebViewViewDescriptor = undefined
  uri: string = "https://www.baidu.com/"
  cacheMode:CacheMode = CacheMode.Default
  onPageEnd?:()=>void = ()=>{}
  onErrorReceive?:(event?:onErrorReceiveEvent) => void
  onLoadIntercept?:(event?:onLoadInterceptEvent) => boolean
  onControllerAttached?:() => void
}

@Builder
function WebBuilder($$:Data) {
    Web({ src: $$.descriptor?.props.newSource.uri ?  $$.descriptor.props.newSource.uri : $$.uri, controller: $$.controller,renderMode: RenderMode.SYNC_RENDER })
      .width($$.descriptor?.layoutMetrics.frame.size.width ?? '100%')
      .height($$.descriptor?.layoutMetrics.frame.size.height ?? '100%')
      .constraintSize({ minHeight: 1 })
      .backgroundColor(Color.Transparent)
      .javaScriptAccess($$.descriptor?.props.javaScriptEnabled)
      .horizontalScrollBarAccess($$.descriptor?.props.showsHorizontalScrollIndicator)
      .verticalScrollBarAccess($$.descriptor?.props.showsVerticalScrollIndicator)
      .overviewModeAccess($$.descriptor?.props.scalesPageToFit)
      .textZoomRatio($$.descriptor?.props.textZoom)
      .cacheMode($$.cacheMode)
      .domStorageAccess($$.descriptor?.props.domStorageEnabled)
      .zoomAccess($$.descriptor?.props.scalesPageToFit)
      .overScrollMode(OverScrollMode.NEVER)
      .onProgressChange($$.onPageEnd)
      .onPageEnd($$.onPageEnd)
      .onErrorReceive($$.onErrorReceive)
      .onLoadIntercept($$.onLoadIntercept)
      .onControllerAttached($$.onControllerAttached)
}

let wrap = wrapBuilder<Data[]>(WebBuilder);

// 用于控制和反馈对应的NodeContainer上的节点的行为，需要与NodeContainer一起使用
export class myNodeController extends NodeController {
  private rootnode: BuilderNode<Data[]> | null = null;
  ctx!: RNOHContext
  tag: number = 0
  private  descriptor: WebViewViewDescriptor = {} as WebViewViewDescriptor
  private source: WebViewNewSource = {
    uri: "",
    method: "",
    body: "",
    headers: "",
    html: "",
    baseUrl: ""
  }
  html: string | undefined = ""
  url: string | Resource = ""
  private unregisterDescriptorChangesListener?: () => void = undefined
  private cleanupCommandCallback?: () => void = undefined
  controller: webview.WebviewController = new webview.WebviewController();
  javaScriptEnable: boolean = true
  progress: number = 0
  cacheMode: number = CacheMode.Default
  lockIdentifier: string = "";
  requestUrl: string = "";
  messagingEnabled: boolean = false;
  hasRegisterJavaScriptProxy: boolean = false;
  controllerAttached: boolean = false;
  // nestedScrollFlag: boolean = false;
  // renderMode: RenderMode = RenderMode.SYNC_RENDER;
  // 必须要重写的方法，用于构建节点数、返回节点挂载在对应NodeContainer中
  // 在对应NodeContainer创建的时候调用、或者通过rebuild方法调用刷新
  makeNode(uiContext: UIContext): FrameNode | null {
    console.log(" uicontext is undifined : "+ (uiContext === undefined));
    if (this.rootnode != null) {
      // 返回FrameNode节点
      return this.rootnode.getFrameNode();
    }
    // 返回null控制动态组件脱离绑定节点
    return null;
  }

  setRnParams(  ctx: RNOHContext,tag: number = 0){
    this.ctx = ctx
    this.tag = tag

    this.descriptor = this.ctx.descriptorRegistry.getDescriptor<WebViewViewDescriptor>(this.tag)
    this.unregisterDescriptorChangesListener = this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
      (newDescriptor) => {
        this.descriptor = (newDescriptor as WebViewViewDescriptor)
        Logger.debug(TAG, `[RNOH] newDescriptor props uri, ${JSON.stringify(this.descriptor.props.newSource.uri)}`);
        this.cacheMode = this.descriptor.props.cacheEnabled ? this.transCacheMode(this.descriptor.props.cacheMode) : CacheMode.Online;
        this.javaScriptEnable = this.descriptor.props.javaScriptEnabled;
        this.source = this.descriptor.props.newSource
        if (this.html != "" && this.html != this.source.html) {
          Logger.debug(TAG, "[RNOH] html is update")
          this.html = this.source.html
          if (this.controllerAttached) {
            try {
              this.controller.loadData(
                this.source.html,
                "text/html",
                "UTF-8",
                this.source.baseUrl,
                " "
              );
            } catch (error) {
              Logger.error(TAG, "error: " + error)
            }
          }
        } else if (this.source.uri != "" && this.url != this.source.uri) {
          Logger.debug(TAG, `[RNOH] newDescriptor props update uri: ` + this.source.uri);
          this.url = this.source.uri
          if (this.controllerAttached) {
            this.controller.loadUrl(this.descriptor.props.newSource.uri)
          }
        }
        this.updateNode()
      }
    )
    webview.WebviewController.setWebDebuggingAccess(this.descriptor.props.webviewDebuggingEnabled)
    this.javaScriptEnable = this.descriptor.props.javaScriptEnabled;
    this.cacheMode = this.descriptor.props.cacheEnabled ? this.transCacheMode(this.descriptor.props.cacheMode) : CacheMode.Online;
    this.source = this.descriptor.props.newSource
    this.html = this.source.html
    this.url = this.source.uri;
    this.registerCommandCallback()
    this.updateNode()
   }

  updateNode(){
    this.controller = controllerMap.get(this.descriptor.props.newSource.uri.toString()) ?? this.controller
    this.rootnode?.update({
      url:this.source.uri,
      controller:this.controller ,
      uri:this.source.uri,descriptor:this.descriptor,
      cacheMode:this.cacheMode,
      onPageEnd:()=>this.onPageEnd(),
    } as Data)
  }

  onPageEnd():void{
    Logger.debug(TAG, "[RNOH] onPageEnd")
    this.runInjectedJavaScript()
    this.onLoadingFinish()
  }

  onErrorReceive(event:onErrorReceiveEvent):void{
    if (event) {
      let errorInfo: string = event.error.getErrorInfo();
      let errorCode: number = event.error.getErrorCode();
      if (errorInfo == "ERR_INTERNET_DISCONNECTED" || errorInfo == "ERR_CACHE_MISS" || !event.request.isMainFrame()) {
        Logger.debug(TAG, "[RNOH] ERR_INTERNET_DISCONNECTED:OR ERR_CACHE_MISS")
        return
      }
      Logger.debug(TAG, "[RNOH] errorInfo:" + errorInfo)
      Logger.debug(TAG, "[RNOH] errorCode:" + errorCode)
      this.onLoadingError(errorCode, errorInfo)
    }
  }

  onLoadIntercept(event:onLoadInterceptEvent):boolean{
    if (!this.descriptor.props.shouldStartLoadWithRequestEnabled) {
      Logger.debug(TAG, "[RNOH]:shouldStartLoadWithRequestEnabled:" + this.descriptor.props.shouldStartLoadWithRequestEnabled)
      return false
    }
    if (this.source.html != undefined && this.source.html != '') {
      Logger.debug(TAG, "[RNOH]: load html not intercept")
      return false;
    }
    if (event.data.getRequestUrl() == this.source.uri || this.requestUrl != "") {
      Logger.debug(TAG, "[RNOH] first load not intercept")
      this.requestUrl = ""
      return false
    }
    this.requestUrl = event.data.getRequestUrl()
    let lockIdentifier = ShouldRequestUrl.getNewData();
    this.lockIdentifier = lockIdentifier
    Logger.debug(TAG, "[RNOH]:lockIdentifier:" + lockIdentifier)
    ShouldRequestUrl.setCallBack(lockIdentifier, () => {
      let data: CallbackState = ShouldRequestUrl.getValue(this.lockIdentifier);
      let should: boolean = data == CallbackState.SHOULD_OVERRIDE
      Logger.debug(TAG, "[RNOH] should:" + should)
      ShouldRequestUrl.removeData(this.lockIdentifier)
      this.lockIdentifier = ""
      if (!should) {
        this.controller.loadUrl(this.requestUrl)
      } else {
        this.requestUrl = ""
      }
    })
    this.onShouldStartLoadCallFunction(Number(this.lockIdentifier), event.data)
    return true
  }

  onControllerAttached():void{
    this.controllerAttached = true;
    Logger.debug(TAG, "[RNOH] onControllerAttached")
    let baseUrl = this.source.baseUrl
    let uri = this.source.uri
    if (this.source.html != undefined && this.source.html != "") {
      try {
        this.controller.loadData(
          this.source.html,
          "text/html",
          "UTF-8",
          baseUrl,
          " "
        );
      } catch (error) {
        Logger.error(TAG, "error:" + error)
      }
    } else if (uri != undefined && uri != "") {
      let header = this.source.headers;
      if (header != undefined && header != "") {
        let headers: Array<webview.WebHeader> = [];
        JSON.parse(header,( key: string, value: string) => {
          if(key && value){
            headers.push({ headerKey: key, headerValue: value })
          }
          return undefined;
        })
        this.controller.loadUrl(uri, headers);
      }
    }
    if (!this.hasRegisterJavaScriptProxy) {
      this.registerPostMessage()
    }
  }

  // 当布局大小发生变化时进行回调
  aboutToResize(size: Size) {
    console.log("aboutToResize width : " + size.width  +  " height : " + size.height )
  }

  // 当controller对应的NodeContainer在Appear的时候进行回调
  aboutToAppear() {
    console.log("aboutToAppear")
  }


  private registerPostMessage() {
    if (this.messagingEnabled == this.descriptor.props.messagingEnabled) {
      return;
    }
    this.messagingEnabled = this.descriptor.props.messagingEnabled;
    if (this.messagingEnabled) {
      let bridge: RNCWebViewBridge = {
        postMessage: (data: string) => {
          Logger.debug(TAG, `[RNOH] bridge postMessage,  ${JSON.stringify(data)}`);
          if (this.controller != null) {
            let result: WebViewEventParams = this.createWebViewEvent("onMessage")
            result.data = data
            result.lockIdentifier = 0
            this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, result);
          }
        }
      };
      this.controller.registerJavaScriptProxy(bridge, JAVASCRIPT_INTERFACE, ["postMessage"])
      this.controller.refresh()
      this.hasRegisterJavaScriptProxy = true
    }
  }

  createWebViewEvent(param: string): WebViewEventParams {
    let result: WebViewEventParams = new WebViewEventParams(param);
    result.loading = this.progress != 100
    try {
      result.url = this.controller.getUrl();
      result.title = this.controller.getTitle();
      result.canGoBack = this.controller.accessBackward();
      result.canGoForward = this.controller.accessForward();
    } catch (error) {
      Logger.error(TAG, `[RNOH]Errorcode: ${error.code}, Message: ${error.message}`);
      result.url = "";
      result.title = "";
      result.canGoBack = false;
      result.canGoForward = false;
    }
    return result;
  }

  aboutToDisappear() {
    this.cleanupCommandCallback?.()
    this.unregisterDescriptorChangesListener?.()
    Logger.debug(TAG, `[RNOH] aboutToDisappear`)
    try {
      this.controller.deleteJavaScriptRegister(JAVASCRIPT_INTERFACE)
      this.controller.refresh()
      this.hasRegisterJavaScriptProxy = false
    } catch (error) {
      Logger.error(TAG, `[RNOH]Errorcode: ${error.code}, Message: ${error.message}`);
    }
  }

  transCacheMode(cacheMode: number): CacheMode {
    let mode = CacheMode.Default
    switch (cacheMode) {
      case 0:
        mode = CacheMode.Default
        break;
      case 1:
        mode = CacheMode.None
        break;
      case 2:
        mode = CacheMode.Online
        break;
      case 3:
        mode = CacheMode.Only
        break;
      default:
        break;
    }
    return mode
  }

  registerCommandCallback() {
    this.cleanupCommandCallback = this.ctx.componentCommandReceiver.registerCommandCallback(
      this.tag,
      (command, args: string[]) => {
        switch (command) {
          case "injectJavaScript":
            Logger.debug(TAG, `[RNOH] injectJavaScript,${JSON.stringify(args)}`)
            if (this.controllerAttached) {
              try {
                this.controller.runJavaScript("(function() {\n" + args[0] + ";\n})();")
              } catch (error) {
                Logger.error(TAG, "error: " + error)
              }
            }
            break
          case "postMessage":
            Logger.debug(TAG, `[RNOH] postMessage,${JSON.stringify(args)}`)
            let data = JSON.stringify({data : args[0]})
            let result: string = "(function () {" +
              "var event;" +
              "var data = " + data.toString() + ";" +
              "try {" +
              "event = new MessageEvent('message', data);" +
              "} catch (e) {" +
              "event = document.createEvent('MessageEvent');" +
              "event.initMessageEvent('message', true, true, data.data, data.origin, data.lastEventId, data.source);" +
              "}" +
              "document.dispatchEvent(event);" +
              "})();"
            if (this.controllerAttached) {
              try {
                this.controller.runJavaScript(result)
              } catch (error) {
                Logger.error(TAG, "error:" + error)
              }
            }
            break;
          case "reload":
            Logger.debug(TAG, `[RNOH] reload,${JSON.stringify(args)}`)
            if (this.controllerAttached) {
              try {
                this.controller.refresh();
              } catch (error) {
                Logger.error(TAG, "error: " + error)
              }
            }
            break
          default:
            break
        }
      });
  }

  onLoadingFinish() {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onLoadingFinish",
      url: this.controller.getUrl(),
      loading: this.progress != 100,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: 0,
      navigationType: "other",
      mainDocumentURL: ""
    })
  }

  onLoadingError(code: number, description: string) {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onLoadingError",
      url: this.controller.getUrl(),
      loading: false,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: 0,
      domain: "",
      code: code,
      description: description
    })
  }

  onShouldStartLoadWithRequest() {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onShouldStartLoadWithRequest",
      url: this.controller.getUrl(),
      loading: this.progress != 100,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: 0,
      navigationType: "other",
      mainDocumentURL: "",
      isTopFrame: false
    })
  }

  onShouldStartLoadCallFunction(lockIdentifier: number, data: WebResourceRequest) {
    this.ctx.rnInstance.emitComponentEvent(this.descriptor.tag, WEB_VIEW, {
      type: "onShouldStartLoadWithRequest",
      url: data.getRequestUrl(),
      loading: this.progress != 100,
      title: this.controller.getTitle(),
      canGoBack: this.controller.accessBackward(),
      canGoForward: this.controller.accessForward(),
      lockIdentifier: lockIdentifier,
      navigationType: "other",
      mainDocumentURL: "",
      isTopFrame: data.isMainFrame()
    })
  }

  runInjectedJavaScript() {
    let injectedJS = this.descriptor.props.injectedJavaScript
    if (this.javaScriptEnable && injectedJS != "" && this.controllerAttached) {
      try {
        this.controller.runJavaScript("(function() {\n" + injectedJS + ";\n})();")
          .then((result) => {
            Logger.debug(TAG, '[RNOH] result: ' + result);
          })
          .catch((error: string | Error) => {
            Logger.error(TAG, "[RNOH] error: " + error);
          })
      } catch (error) {
        Logger.error(TAG, `[RNOH]Errorcode: ${error.code}, Message: ${error.message}`);
      }
    }
  }

  // // 当controller对应的NodeContainer在Disappear的时候进行回调
  // aboutToDisappear() {
  //   console.log("aboutToDisappear")
  // }

  // 此函数为自定义函数，可作为初始化函数使用
  // 通过UIContext初始化BuilderNode，再通过BuilderNode中的build接口初始化@Builder中的内容
  initWeb(url:string, uiContext:UIContext, control:WebviewController) {
    if(this.rootnode != null)
    {
      return;
    }
    // 创建节点，需要uiContext
    this.rootnode = new BuilderNode(uiContext)
    // 创建动态Web组件
    this.rootnode.build(wrap, { url:url, controller:control ,uri:url})
  }
}
// 创建Map保存所需要的NodeController
let NodeMap:Map<string, myNodeController | undefined> = new Map();
// 创建Map保存所需要的WebViewController
let controllerMap:Map<string, WebviewController | undefined> = new Map();

// 初始化需要UIContext 需在Ability获取
export const createNWeb = (url: string, uiContext: UIContext) => {
  // 创建NodeController
  let baseNode = new myNodeController();
  let controller = new web_webview.WebviewController() ;
  // 初始化自定义Web组件
  baseNode.initWeb(url, uiContext, controller);
  controllerMap.set(url, controller)
  NodeMap.set(url, baseNode);
}
// 自定义获取NodeController接口
export const getNWeb = (url : string) : myNodeController | undefined => {
  return NodeMap.get(url);
}