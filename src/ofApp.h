#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "127.0.0.1"
#define PORT 54321

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void image_update(int num);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    static const int IMAGE_NUM = 136;
    static const int IMAGE_WIDTH = 866;
    static const int IMAGE_HEIGHT = 866;
    ofxOscSender osc_sender;
    ofImage image[IMAGE_NUM];
    int index;
    bool is_show_information;
};
