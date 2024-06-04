/**
 * @format
 */

import {AppRegistry} from 'react-native';
// import App from './App';
// import SVGDemo from './SVGDemo/SVGViewDemo';
import {name as appName} from './app.json';
// import SvgDemoCases from './svgDemoCases/App'
import webviewDemo from './webviewDemo'
// import sqlitedemo from './sqlitedemo'
import autoheightDemo from './webviewDemo/autoheight'



// AppRegistry.registerComponent(appName, () => App);
// AppRegistry.registerComponent(appName, () => SVGDemo);
AppRegistry.registerComponent(appName, () => autoheightDemo);
// AppRegistry.registerComponent(appName, () => webviewDemo);

// AppRegistry.registerComponent(appName, () => sqlitedemo);
