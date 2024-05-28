import React, { Component } from 'react';
import {
  Image,
    ScrollView
} from 'react-native';
import { SvgCss } from 'react-native-svg';

const svgmsg = `<svg width="240" height="240" viewBox="0 0 240 240" fill="none"
xmlns="http://www.w3.org/2000/svg">
<circle cx="120" cy="120" r="120" fill="#FFECDE"/>
<mask id="mask0_14651_25129" style="mask-type:alpha" maskUnits="userSpaceOnUse" x="0" y="0" width="240" height="240">
<rect width="240" height="240" rx="30" fill="#FF00DC"/>
</mask>
<g mask="url(#mask0_14651_25129)">
<g filter="url(#filter0_d_14651_25129)">
<path fill-rule="evenodd" clip-rule="evenodd" d="M57.1418 157.143C57.1418 169.767 67.3753 180 79.999 180H159.999C172.623 180 182.856 169.767 182.856 157.143V97.1429H57.1418V157.143ZM57.1419 85.7143H182.856L169.147 68.5784C164.81 63.1563 158.243 60 151.299 60H88.699C81.7554 60 75.1882 63.1563 70.8506 68.5784L57.1419 85.7143ZM82.2853 147.429C78.4982 147.429 75.4281 150.499 75.4281 154.286C75.4281 158.073 78.4982 161.143 82.2853 161.143H116.571C120.358 161.143 123.428 158.073 123.428 154.286C123.428 150.499 120.358 147.429 116.571 147.429H82.2853Z" fill="url(#paint0_linear_14651_25129)"/>
</g>
</g>
<defs>
<linearGradient id="paint0_linear_14651_25129" x1="57.1418" y1="180" x2="177.032" y2="54.4397" gradientUnits="userSpaceOnUse">
<stop stop-color="#FF003A"/>
<stop offset="1" stop-color="#FF0056"/>
</linearGradient>
</defs>
</svg>`

export default class VideoCell extends Component {
    render = () => {
        return (
            <ScrollView>
                {/* <SvgCss
                    xml={svgmsg}
                    width={240}
                    height={240}
                /> */}
                <Image source={require('../assets/react-native-logo.png')}></Image>
            </ScrollView>
        )
    }
}