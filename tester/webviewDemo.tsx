import React, { useState, useEffect } from 'react';
import { View, Button, TextInput, StyleSheet, Dimensions } from 'react-native';
import { WebView } from 'react-native-webview';

const App = () => {
  const [webViewHeight, setWebViewHeight] = useState(400); // 初始高度
  const [webViewWidth, setWebViewWidth] = useState(360); // 初始宽度（屏幕宽度）

  const increaseHeight = () => {
    setWebViewHeight(prevHeight => prevHeight + 100); // 增加高度
  };

  const decreaseHeight = () => {
    setWebViewHeight(prevHeight => (prevHeight - 100 > 0 ? prevHeight - 100 : 0)); // 减小高度，但不低于0
  };

  const increaseWidth = () => {
    setWebViewWidth(prevWidth => prevWidth + 100); // 增加宽度
  };

  const decreaseWidth = () => {
    setWebViewWidth(prevWidth => (prevWidth - 100 > 0 ? prevWidth - 100 : 0)); // 减小宽度，但不低于0
  };

  return (
    <View style={styles.container}>
      <WebView
        style={{ width: webViewWidth, height: webViewHeight }}
        source={{ uri: 'https://www.baidu.com' }}
      />
      <View style={styles.controls}>
        {/* <Button title="Increase Height" onPress={increaseHeight} /> */}
        {/* <Button title="Decrease Height" onPress={decreaseHeight} /> */}
        <Button title="Increase Width" onPress={increaseWidth} />
        <Button title="Decrease Width" onPress={decreaseWidth} />
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 50,
  },
  controls: {
    flexDirection: 'row',
    justifyContent: 'space-around',
    marginTop: 20,
  },
});

export default App;
