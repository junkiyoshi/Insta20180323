#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = 50;
	float small_radius = 0;
	int deg_span = 8;
	for (int i = 0; radius < 330; i++) {

		if (small_radius == 0) {

			ofPoint p1 = ofPoint(radius * cos(0), radius * sin(0));
			ofPoint p2 = ofPoint(radius * cos(deg_span * DEG_TO_RAD), radius * sin(deg_span * DEG_TO_RAD));
			small_radius = p1.distance(p2) * 0.5;
		}

		float noise_value = ofNoise(i * 0.05 + ofGetFrameNum() * 0.01);
		ofPushMatrix();
		ofRotate(noise_value * 360);

		for (int deg = 0; deg < 360; deg += deg_span) {

			ofColor circle_color;
			circle_color.setHsb(ofMap(deg, 0, 360, 0, 255), 239, 239);
			ofSetColor(circle_color, 139 + 39);

			ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			ofDrawCircle(point, small_radius);
		}

		float next_small_radius = 0;
		float tmp_radius = radius;
		while (radius < tmp_radius + small_radius + next_small_radius) {

			ofPoint p1 = ofPoint(radius * cos(0), radius * sin(0));
			ofPoint p2 = ofPoint(radius * cos(deg_span * DEG_TO_RAD), radius * sin(deg_span * DEG_TO_RAD));
			next_small_radius = p1.distance(p2) * 0.5;

			radius += 0.01;
		}

		small_radius = next_small_radius;

		ofPopMatrix();
	}
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}