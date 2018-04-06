# MSDF label for cocos2d-x
cocos2d-x에서 [MSDF](https://github.com/Chlumsky/msdfgen)를 사용하기 위한 프로젝트입니다.<br/>
![img1](https://user-images.githubusercontent.com/18157660/38404414-deb03ab4-39a4-11e8-8947-229085c0135d.gif)
## 사용법
1. [msdf-bmfont-xml](https://www.npmjs.com/package/msdf-bmfont-xml)을 이용하여 원하는 MSDF폰트를 생성합니다.
2. cocos2d/2d/CCLabel.cpp파일을 이 프로젝트의 CCLabel.cpp파일로 교체합니다.
3. Label을 만들고 msdf shader를 적용합니다.
