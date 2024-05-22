import { RNAbility } from "@rnoh/react-native-openharmony";
import window from '@ohos.window';
import {createNWeb } from 'rnoh-webview'

export default class EntryAbility extends RNAbility {
  getPagePath() {
    return "pages/Index"
  }
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err, data) => {
      // 创建Web动态组件（需传入UIContext），loadContent之后的任意时机均可创建
      createNWeb("https://www.baidu.com/", windowStage.getMainWindowSync().getUIContext());
      createNWeb("https://gitee.com", windowStage.getMainWindowSync().getUIContext());

      if (err.code) {
        return;
      }
    });
  }
};
