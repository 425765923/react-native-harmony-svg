/**
 * @format
 */

import {AppRegistry} from 'react-native';
import App from './App';
import SVGDemo from './SVGDemo/SVGViewDemo';
import {name as appName} from './app.json';
import SvgDemoCases from './svgDemoCases/App'
import webviewDemo from './webviewDemo'

// AppRegistry.registerComponent(appName, () => App);
// AppRegistry.registerComponent(appName, () => SVGDemo);
AppRegistry.registerComponent(appName, () => webviewDemo);