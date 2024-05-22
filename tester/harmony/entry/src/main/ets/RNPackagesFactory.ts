import type {RNPackageContext, RNPackage} from '@rnoh/react-native-openharmony/ts';
import {SvgPackage} from '@rnoh/react-native-openharmony-svg/ts';
import { WebViewPackage } from 'rnoh-webview/ts';

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [new SvgPackage(ctx),new WebViewPackage(ctx)];
}