//
//  MainScene.cpp
//  h
//
//  Created by A on 2018. 4. 5..
//

#include "MainScene.h"

USING_NS_CC;
using namespace std;


bool MainScene::init() {
    auto size = Director::getInstance()->getVisibleSize();
    Vec2 origin = size / 2.0f;

	auto bg = LayerColor::create(Color4B::WHITE);
	this->addChild(bg);
    
    auto lb = Label::createWithBMFont("fonts/NanumGothic.fnt", "https://github.com/nuununuun/msdf_for_cocos2d-x");
	lb->setPosition(origin);
    this->addChild(lb);

	lb->runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.25f), ScaleTo::create(2.0f, 2.0f), DelayTime::create(0.25f), ScaleTo::create(2.0f, 0.25f), nullptr)));
    
    auto msdf = GLProgram::createWithFilenames("shaders/msdf.vsh", "shaders/msdf.fsh");
    msdf->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    msdf->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    msdf->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    msdf->link();
    msdf->updateUniforms();
    auto state = GLProgramState::getOrCreateWithGLProgram(msdf);
	// bmfont texture size
    state->setUniformVec2("textureSize", Vec2(2048, 2048));
    state->setUniformFloat("pxRange", 5);
    state->setUniformVec4("bgColor", Vec4(0, 0, 0, 0));
    state->setUniformVec4("fgColor", Vec4(0, 0, 0, 1));
    
    lb->setGLProgram(msdf);

	auto l = EventListenerMouse::create();
	l->onMouseDown = [=](EventMouse *e) {
		auto v = origin - e->getLocation();
		lb->setRotation(CC_RADIANS_TO_DEGREES(v.getAngle()) - 180);
	};
	l->onMouseMove = [=](EventMouse *e) {
		auto v = origin - e->getLocation();
		lb->setRotation(CC_RADIANS_TO_DEGREES(v.getAngle()) - 180);
	};
	l->onMouseUp = [=](EventMouse *e) {

	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(l, this);
    
    return true;
}
